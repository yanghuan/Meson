#pragma once

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <tuple>
#include <type_traits>

#define INSERT_METADATA_OBJ     public:\
                                  static const meson::TypeMetadata& getTypeMetadata() {\
                                    return typeMetadata_;\
                                  };\
                                private:\
                                  static meson::TypeMetadata typeMetadata_;

namespace meson {
  class Object;
  class String;
  template <class T>
  class ref;

  class TypeMetadata {};

  class GCObjectHead {
  protected:
    GCObjectHead(const TypeMetadata& metadata) noexcept : metadata_(metadata) {}
    bool refDec() noexcept {
      return --refs_ == 0;
    }
  private:
    void refAdd() noexcept {
      printf("refAdd\n");
      ++refs_;
    }
  private:
    std::atomic_uint32_t refs_ = 1;
    const TypeMetadata& metadata_;

    template <class T>
    friend class ref;
  };

  template <class T>
  struct IsString {
    static constexpr bool value = std::is_base_of<String, T>::value;
  };

  template <class T>
  class GCObject : public GCObjectHead {
    static constexpr bool IsSpeicalObject = IsString<T>::value;

  public:
    T* get() noexcept {
      return reinterpret_cast<T*>(memory_.data());
    }

    void release() noexcept {
      if (refDec()) {
        Object::free(this, GetAllocSize());
      }
    }

  private:
    GCObject(const TypeMetadata& klass) noexcept : GCObjectHead(klass) {}

    size_t GetAllocSize() noexcept {
      if constexpr (IsSpeicalObject) {
        return get()->GetAllocSize();
      }
      return sizeof(GCObject);
    }
  private:
    std::array<int8_t, sizeof(T)> memory_ = {};

    friend class Object;
    friend class String;
  };

  template <class T, class T1>
  struct IsEquatable {
    static constexpr bool value = std::is_base_of<Object, T>::value
      || std::is_base_of<Object, T1>::value
      || std::is_convertible<T*, T1*>::value
      || std::is_convertible<T1*, T*>::value;
  };

  template <class T>
  class ref {
  public:
    template <class T1>
    struct IsConvertible {
      static constexpr bool value = std::is_base_of<Object, T>::value ||
        std::is_convertible<T1*, T*>::value;
    };

    using GCObject = GCObject<T>;
    using element_type = T;

    constexpr ref() noexcept {}

    constexpr ref(nullptr_t) noexcept {}

    explicit ref(GCObject* p) noexcept : p_(p) {}

    ref(const ref& other) noexcept {
      copyOf(other);
    }

    template <class T1,
      typename std::enable_if_t<IsConvertible<T1>::value, int> = 0>
      ref(const ref<T1>& other) noexcept {
      copyOf(other);
    }

    template <class T1 = T,
      typename std::enable_if_t<IsString<T1>::value, int> = 0>
      ref(const char* str) {
      moveOf(String::load(str));
    }

    template <class... _Types, class T1 = T,
      typename std::enable_if_t<IsString<T1>::value, int> = 0>
      ref(const std::tuple<_Types...>& t) {
      moveOf(String::cat(t));
    }

    ref(ref&& other) noexcept {
      moveOf(std::move(other));
    }

    template <class T1,
      typename std::enable_if_t<IsConvertible<T1>::value, int> = 0>
      ref(ref<T1>&& other) noexcept {
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

    template <class T1,
      typename std::enable_if_t<IsConvertible<T1>::value, int> = 0>
      ref& operator=(const ref<T1>& right) noexcept {
      ref(p_);
      copyOf(right);
      return *this;
    }

    bool operator==(nullptr_t) const noexcept {
      return p_ == nullptr;
    }

    bool operator!=(nullptr_t) const noexcept {
      return p_ != nullptr;
    }

    template <class T1,
      typename std::enable_if_t<IsEquatable<T, T1>::value, int> = 0>
      bool operator==(const ref<T1>& right) const noexcept {
      return p_ == reinterpret_cast<void*>(right.p_);
    }

    template <class T1,
      typename std::enable_if_t<IsEquatable<T, T1>::value, int> = 0>
      bool operator!=(const ref<T1>& right) const noexcept {
      return p_ != reinterpret_cast<void*>(right.p_);
    }

    template <class T1 = T,
      typename std::enable_if_t<IsString<T1>::value, int> = 0>
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

  class Object {
  public:
    template <class T, class... Args>
    static T newobj(Args&&... args) {
      using GCObject = typename T::GCObject;
      using element_type = typename T::element_type;
      void* address = alloc(sizeof(GCObject));
      GCObject* temp = new (address) GCObject(element_type::getTypeMetadata());
      new (temp->get()) element_type(std::forward<Args>(args)...);
      return T(temp);
    }
  private:
    static void* alloc(size_t size);
    static void free(void* p, size_t size);

    template <class T>
    friend class GCObject;
  };

  class String {
  public:
    using string = ref<String>;

  public:
    static size_t GetAllocSize(size_t n) noexcept  {
      return sizeof(GCObject<String>) - sizeof(firstChar) + n + 1;
    }

    size_t GetAllocSize() const noexcept {
      return GetAllocSize(length);
    }

    static string load(const char* str) {
      return load(str, std::char_traits<char>::length(str));
    }

    template <class... _Types>
    static string cat(const std::tuple<_Types...>& t) {
      return cat((String**)(&t), sizeof(t) / sizeof(intptr_t));
    }

    char* c_str() noexcept {
      return firstChar;
    }
    const char* c_str() const noexcept {
      return firstChar;
    }

  private:
    static string load(const char* str, size_t n);
    static string cat(String** being, size_t n);
    static GCObject<String>* alloc(size_t n);

  protected:
    int32_t length;
    char firstChar[1];
  };

}  // namespace meson

template <class Ex>
[[noreturn]] void throw_exception(Ex&& ex) {
#if MESON_HAS_EXCEPTIONS
  throw ex;
#else
  (void)ex;
  std::terminate();
#endif
}

template <class Ex, class... Args>
[[noreturn]] void throw_exception(Args&&... args) {
  throw_exception<Ex>(Ex(std::forward<Args>(args)...));
}

template <class T, class... Args>
inline T newobj(Args&&... args) {
  return meson::Object::newobj<T>(std::forward<Args>(args)...);
}