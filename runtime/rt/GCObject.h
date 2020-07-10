#pragma once

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <tuple>
#include <type_traits>

#include "Preprocessor.h"

namespace rt {
  class object;
  class string;
  class Array_;
  template <class T>
  class ref;

  struct TypeMetadata {
  };

  template <class T>
  struct TypeMetadataHolder {
    static TypeMetadata data;
  };

  template <class T>
  inline static const TypeMetadata& getTypeMetadata() {
    return TypeMetadataHolder<T>::data;
  }

  inline TypeMetadata gTypeMetadata;

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

    std::atomic_uint32_t refs_ = 1;
    const TypeMetadata& metadata_;

    template <class T>
    friend class ref;
  };

  template <class Base, class Derived>
  struct IsDerived {
    static constexpr bool value = std::is_convertible<Derived*, Base*>::value;
  };

  template <class T>
  struct IsString {
    static constexpr bool value = IsDerived<string, T>::value;
  };

  template <class T>
  struct IsObject {
    static constexpr bool value = IsDerived<object, T>::value;
  };

  template <class T>
  class GCObject : public GCObjectHead {
    static constexpr bool IsSpeicalObject = IsString<T>::value || IsDerived<Array_, T>::value;
  public:
    T* get() noexcept {
      return &v_;
    }

    void release() noexcept {
      if (refDec()) {
        get()->~T();
        object::free(this, GetAllocSize());
      }
    }

  private:
    GCObject(const TypeMetadata& klass) noexcept : GCObjectHead(klass) {}

    constexpr size_t GetAllocSize() noexcept {
      if constexpr (IsSpeicalObject) {
        return get()->GetAllocSize();
      }
      return sizeof(GCObject);
    }

    T v_;
    friend class object;
    friend class string;

    template <class T>
    friend class Array;
  };

  template <class T, class T1>
  struct IsEquatable {
    static constexpr bool value = IsObject<T>::value
      || IsObject<T1>::value
      || IsDerived<T, T1>::value
      || IsDerived<T1, T>::value;
  };

  template <class T, class T1>
  struct IsDerivedConvertible {
    static constexpr bool value = IsObject<T>::value || IsDerived<T, T1>::value;
  };

  template <class T>
  struct RefElementType {
    using type = T;
    static constexpr bool value = false;
  };

  template <class T>
  struct RefElementType<ref<T>> {
    using type = T;
    static constexpr bool value = true;
  };

  template <class T>
  struct ArrayElementType {
    struct __Type {
      struct element_type;
    };
    using element_type = typename std::conditional_t<IsDerived<Array_, T>::value, T, __Type>::element_type;
    using type = typename RefElementType<element_type>::type;
    static constexpr bool value = RefElementType<element_type>::value;
  };

  template <class T, class T1>
  struct IsArrayConvertible__ {
    using ElementTypeT = ArrayElementType<T>;
    using ElementTypeT1 = ArrayElementType<T1>;
    static constexpr bool value = (IsObject<ElementTypeT::type>::value && ElementTypeT1::value) || IsDerived<ElementTypeT::type, ElementTypeT1::type>::value;
  };

  template <class T, class T1>
  struct IsArrayConvertible {
    static constexpr bool value = IsDerived<Array_, T>::value && IsDerived<Array_, T1>::value && IsArrayConvertible__<T, T1>::value;
  };

  template <class T, class T1>
  struct IsConvertible {
    static constexpr bool value = IsDerivedConvertible<T, T1>::value || IsArrayConvertible<T, T1>::value;
  };

  template <class T>
  class ref {
  public:
    using GCObject = GCObject<T>;
    using in = T;

    constexpr ref() noexcept : p_(nullptr)  {}

    constexpr ref(nullptr_t) noexcept : p_(nullptr) {}

    explicit ref(GCObject* p) noexcept : p_(p) {}

    ref(const ref& other) noexcept {
      copyOf(other);
    }

    template <class T1, typename std::enable_if_t<IsConvertible<T, T1>::value, int> = 0>
    ref(const ref<T1>& other) noexcept {
      copyOf(other);
    }

    template <class T1 = T, typename std::enable_if_t<IsString<T1>::value, int> = 0>
    ref(const char* str) {
      moveOf(string::load(str));
    }

    template <class... _Types, class T1 = T, typename std::enable_if_t<IsString<T1>::value, int> = 0>
    ref(const std::tuple<_Types...>& t) {
      moveOf(string::cat(t));
    }

    ref(ref&& other) noexcept {
      moveOf(std::move(other));
    }

    template <class T1, typename std::enable_if_t<IsConvertible<T, T1>::value, int> = 0>
    ref(ref<T1>&& other) noexcept {
      moveOf(std::move(other));
    }

    ~ref() noexcept {
      if (p_) {
        p_->release();
      }
    }

    ref& operator =(const ref& right) noexcept {
      ref(right).swap(*this);
      return *this;
    }

    template <class T1, typename std::enable_if_t<IsConvertible<T, T1>::value, int> = 0>
    ref& operator = (const ref<T1>& right) noexcept {
      ref(p_);
      copyOf(right);
      return *this;
    }

    bool operator ==(nullptr_t) const noexcept {
      return p_ == nullptr;
    }

    bool operator !=(nullptr_t) const noexcept {
      return p_ != nullptr;
    }

    template <class T1, typename std::enable_if_t<IsEquatable<T, T1>::value, int> = 0>
    bool operator ==(const ref<T1>& right) const noexcept {
      return p_ == reinterpret_cast<void*>(right.p_);
    }

    template <class T1, typename std::enable_if_t<IsEquatable<T, T1>::value, int> = 0>
    bool operator !=(const ref<T1>& right) const noexcept {
      return p_ != reinterpret_cast<void*>(right.p_);
    }

    template <class T1 = T, typename std::enable_if_t<IsString<T1>::value, int> = 0>
    constexpr auto operator +(const ref& right) noexcept {
      T* a = p_ ? get() : nullptr;
      T* b = right != nullptr ? right.get() : nullptr;
      return std::make_tuple(a, b);
    }

    template <class R, class T1 = T, typename std::enable_if_t<IsObject<T1>::value, int> = 0>
    explicit operator R() {
      return R();
    }

    template <class R, class T1 = T, typename std::enable_if_t<std::is_same<R, decltype(T1::op_Implicit(ref<T1>()))>::value, int> = 0>
    operator R() {
      return T1::op_Implicit(*this);
    }

    template<class size_t>
    constexpr auto& operator [](size_t index) {
      return (*get())[index];
    }

    T* get() const noexcept {
      return p_->get();
    }

    T* operator->() const noexcept {
      return get();
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
    
    GCObject* p_;
    friend class ref;
  };

  template <class T, class... _Types>
  struct StringTrim {
    using type = typename std::remove_pointer<T>::type;
  };

  template <class... _Types>
  constexpr auto operator +(const std::tuple<_Types...>& t, const ref<typename StringTrim<_Types...>::type>& right) noexcept {
    string* a = right != nullptr ? right.get() : nullptr;
    return std::tuple_cat(t, std::make_tuple(a));
  }

  class object {
  public:
    template <class T, class... Args>
    static T newobj(Args&&... args) {
      using GCObject = typename T::GCObject;
      using element_type = typename T::in;
      void* p = alloc(sizeof(GCObject));
      GCObject* temp = new (p) GCObject(getTypeMetadata<T>());
      new (temp->get()) element_type(std::forward<Args>(args)...);
      return T(temp);
    }
  private:
    static void* alloc(size_t size);
    static void free(void* p, size_t size);

    template <class T>
    friend class GCObject;

    template <class T>
    friend class Array;
  };

  class string {
    struct str {
      int32_t length;
      char first[];
    };
  public:
    static size_t GetAllocSize(size_t n) noexcept {
      return sizeof(GCObject<str>) + n + 1;
    }

    size_t GetAllocSize() const noexcept {
      return GetAllocSize(length());
    }

    static ref<string> load(const char* str) {
      return load(str, std::char_traits<char>::length(str));
    }

    template <class... _Types>
    static ref<string> cat(const std::tuple<_Types...>& t) {
      return cat((string**)(&t), sizeof(t) / sizeof(string*));
    }

    char* c_str() noexcept {
      auto p = reinterpret_cast<str*>(this);
      return p->first; 
    }

    const char* c_str() const noexcept {
      auto p = reinterpret_cast<const str*>(this);
      return p->first; 
    }

  private:
    int32_t& length() {
      auto p = reinterpret_cast<str*>(this);
      return p->length;
    }
    int32_t length() const {
      auto p = reinterpret_cast<const str*>(this);
      return p->length;
    }
    static ref<string> load(const char* str, size_t n);
    static ref<string> cat(string** being, size_t n);
    static GCObject<string>* alloc(size_t n);
  };

  class Array_ {};
  template <class T>
  class Array : public Array_ {
    struct array {
      int32_t length;
      T first[];
    };
  public:
    using element_type = T;

    ~Array() noexcept {
      for (const T& i : *this) {
        i.~T();
      }
    }

    size_t GetAllocSize() const noexcept {
      return GetAllocSize(length);
    }

    T* begin() noexcept {
      auto p = reinterpret_cast<array*>(this);
      return p->first;
    }

    T* begin() const noexcept {
      auto p = reinterpret_cast<const array*>(this);
      return p->first;
    }

    T* end() noexcept {
      return begin() + length;
    }

    T* end() const noexcept {
      return begin() + length;
    }

    constexpr T& operator [](int32_t index) {
      return begin()[index];
    }

    static size_t GetAllocSize(size_t n) noexcept {
      return sizeof(GCObject<array>) + n * sizeof(T);
    }

    static ref<array> newarr(size_t n) {
      void* p = object::alloc(GetAllocSize(n));
      auto temp = new (p) GCObject<array>(gTypeMetadata);
      temp->get()->length = static_cast<int32_t>(n);
      return ref<array>(temp);
    }

  protected:
    int32_t length;
  };

  template <class T, size_t N>
  struct FixedBuffer {
    T v[N];
  };

  template <class T, class V>
  bool is(const V& v) {
    return false;
  }

  template <class T, class V>
  T cast(const V& v) {
    return T();
  }

  template <class R, class Arg>
  int init(int argc, char* argv[], R (*f)(Arg)) {
    auto args = Array<ref<string>>::newarr(argc - 1);
    f(*reinterpret_cast<Arg*>(&args));
    return 0;
  }

}  // namespace rt

template <class Ex>
[[noreturn]] void throw_exception(Ex&& ex) {
#if !MESON_NO_EXCEPTIONS
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
  return rt::object::newobj<T>(std::forward<Args>(args)...);
}

template <class A>
inline auto newarr(int32_t n) {
  using T = A::in::element_type;
  return *reinterpret_cast<A*>(&rt::Array<T>::newarr(n));
}