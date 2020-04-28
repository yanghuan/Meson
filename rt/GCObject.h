#pragma once

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <tuple>
#include <type_traits>

namespace meson {

  void* gcMalloc(size_t n);
  void gcFree(void* p, size_t n);

  class Object;
  class String;

  class TypeMetadata {};

  class GCObjectHead {
  public:
    void refAdd() noexcept {
      printf("refAdd\n");
      ++refs_;
    }

  protected:
    GCObjectHead(const TypeMetadata& klass) noexcept : klass_(klass) {}

    void release(size_t n) noexcept {
      if (--refs_ == 0) {
        printf("release\n");
        gcFree(this, n);
      }
    }

  private:
    std::atomic_uint32_t refs_ = 1;
    const TypeMetadata& klass_;
  };

  template <class T>
  using is_string = std::is_base_of<String, T>;

  template <class T>
  class GCObject : public GCObjectHead {
  private:
    static constexpr bool kIsString = is_string<T>::value;

  public:
    const T& val() const noexcept {
      return v_;
    }
    T* get() noexcept {
      return &v_;
    }

    void release() noexcept {
      size_t n;
      if constexpr (kIsString) {
        n = v_.GetAllocSize();
      }
      else {
        n = sizeof(GCObject);
      }
      GCObjectHead::release(n);
    }

  private:
    GCObject(const TypeMetadata& klass) noexcept : GCObjectHead(klass) {}

  private:
    T v_;

    friend class Object;
    friend class String;
  };

  template <class T>
  class ref {
    template <class T1> 
    struct is_convertible {
      static constexpr bool value = std::is_base_of<Object, T>::value || std::is_convertible<T1*, T*>::value;
    };

  public:
    using GCObject = GCObject<T>;
    static constexpr bool kIsString = is_string<T>::value;

    constexpr ref() noexcept {}

    constexpr ref(nullptr_t) noexcept {}

    explicit ref(GCObject* p) noexcept : p_(p) {}

    ref(const ref& other) noexcept {
      copyOf(other);
    }

    template <class T1, std::enable_if_t<is_convertible<T1>::value, int> = 0>
    ref(const ref<T1>& other) noexcept {
      copyOf(other);
    }

    template <std::enable_if_t<kIsString, int> = 0>
    ref(const char* str) {
      moveOf(String::load(str));
    }

    template <class... _Types, std::enable_if_t<kIsString, int> = 0>
    ref(const std::tuple<_Types...>& t) {
      moveOf(String::cat(t));
    }

    ref(ref&& other) noexcept {
      moveOf(std::move(other));
    }

    ~ref() noexcept {
      if (p_) {
        p_->release();
      }
    }

    ref& operator=(const ref& right) noexcept {
      ref(right).swap(*this);
      return *this;
    }

    bool operator==(nullptr_t) const noexcept {
      return p_ == nullptr;
    }
    bool operator!=(nullptr_t) const noexcept {
      return p_ != nullptr;
    }

    template <std::enable_if_t<kIsString, int> = 0>
    constexpr auto operator+(const ref& right) noexcept {
      T* a = p_ ? get() : nullptr;
      T* b = right != nullptr ? right.get() : nullptr;
      return std::make_tuple(a, b);
    }

    T* get() const noexcept {
      return p_->get();
    }
    T* operator->() const noexcept {
      return p_->get();
    }

    const T& val() const noexcept {
      return p_->val();
    }

  private:
    void swap(ref& right) noexcept {
      std::swap(p_, right.p_);
    }

    template <class T1>
    void copyOf(const ref<T1>& other) noexcept {
      if (other.p_) {
        other.p_->refAdd();
      }
      p_ = reinterpret_cast<GCObject*>(other.p_);
    }

    template <class T1>
    void moveOf(ref<T1>&& other) noexcept {
      p_ = reinterpret_cast<GCObject*>(other.p_);
      other.p_ = nullptr;
    }

  public:
    GCObject* p_ = nullptr;
  };

  template <class T, class... _Types>
  struct StringTrim {
    using type = typename std::remove_pointer<T>::type;
  };

  template <class... _Types>
  constexpr auto operator+(
    const std::tuple<_Types...>& t,
    const ref<typename StringTrim<_Types...>::type>& right) noexcept {
    String* a = right != nullptr ? right.get() : nullptr;
    return std::tuple_cat(t, std::make_tuple(a));
  }

  class Object {};

  class String {
  public:
    using string = ref<String>;

  public:
    static size_t GetAllocSize(size_t n) noexcept {
      return sizeof(GCObject<String>) - sizeof(intptr_t) + n + 1;
    }

    size_t GetAllocSize() noexcept {
      return GetAllocSize(length);
    }

    static string load(const char* str) {
      return load(str, std::char_traits<char>::length(str));
    }

    template <class... _Types>
    static string cat(const std::tuple<_Types...>& t) {
      return cat((String**)&t, sizeof(t) / sizeof(intptr_t));
    }

    char* c_str() noexcept {
      return get();
    }
    const char* c_str() const noexcept {
      return get();
    }

  private:
    char* get() const {
      return reinterpret_cast<char*>(&firstChar);
    }
    static string load(const char* str, size_t n);
    static string cat(String** being, size_t n);

  protected:
    int32_t length;
    mutable intptr_t firstChar;
  };

}  // namespace meson
