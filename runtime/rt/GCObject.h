#pragma once

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
#include <tuple>
#include <type_traits>
#include <compare>

#include "Preprocessor.h"

namespace rt {
  enum class TypeCode {
    None,
    Object,
    Array,
    String,
    Boolean,
    Char,
    SByte,
    Byte,
    Int16,
    UInt16,
    Int32,
    UInt32,
    Int64,
    UInt64,
    Single,
    Double,
    Class,
    Struct,
    Interface,
    Delegate,
  };

  template <class... Args>
  using TypeList = std::tuple<Args...>;

  class object;
  class string;
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
  public:
    GCObjectHead(const TypeMetadata& metadata) noexcept : metadata_(metadata) {}
  
  protected:
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

  template <class T, class = void>
  struct IsComplete : std::false_type {
  };

  template <class T>
  struct IsComplete<T, decltype(void(sizeof(T))) > : std::true_type {
  };

  template <class Base, class Derived>
  static constexpr bool IsDerived = std::is_convertible<Derived*, Base*>::value;

  template <typename, typename = void>
  struct GetTypeCode {
    static constexpr TypeCode value = TypeCode::None;
  };

  template <typename T>
  struct GetTypeCode<T, std::void_t<decltype(T::code != TypeCode::None)>> {
    static constexpr TypeCode value = T::code;
  };

  template <class T>
  static constexpr TypeCode CodeOf = GetTypeCode<T>::value;

  template <class T> 
  static constexpr bool IsString = CodeOf<T> == TypeCode::String;

  template <class T> 
  static constexpr bool IsArray = CodeOf<T> == TypeCode::Array;

  template <class T>
  static constexpr bool IsDelegate = CodeOf<T> == TypeCode::Delegate;

  template <class T>
  static constexpr bool IsInterface = CodeOf<T> == TypeCode::Interface;

  template <class T>
  static constexpr bool IsObject = CodeOf<T> == TypeCode::Object;

  template <class T>
  class GCObject : public GCObjectHead {
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

    static GCObject<T>* From(T* p) {
      return reinterpret_cast<GCObject<T>*>(reinterpret_cast<int8_t*>(p) - sizeof(GCObjectHead));
    }

  private:
    constexpr size_t GetAllocSize() noexcept {
      if constexpr (IsArray<T> || IsString<T>) {
        return get()->GetAllocSize();
      }
      return sizeof(GCObject);
    }

    T v_;
    friend class object;
    friend class string;

    template <class T, class Base>
    friend class Array;
  };

  template <class T, class T1>
  static constexpr bool IsEquatable = IsDerived<T, T1> || IsDerived<T1, T> || IsInterface<T> || IsInterface<T1>;

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
  static constexpr bool IsRef = RefElementType<T>::value;

  template <class T>
  struct ArrayElementType {
    static_assert(IsComplete<T>::value, "not complete type");
    struct __Type {
      struct element_type;
    };
    using element_type = typename std::conditional_t<IsArray<T>, T, __Type>::element_type;
    using type = typename RefElementType<element_type>::type;
    static constexpr bool value = RefElementType<element_type>::value;
  };

  template <class To, class From>
  struct IsArrayConvertible {
    using ElementTypeTo = ArrayElementType<To>;
    using ElementTypeFrom = ArrayElementType<From>;
    static constexpr bool value = ElementTypeTo::value && ElementTypeFrom::value && IsDerived<ElementTypeTo::type, ElementTypeFrom::type>;
  };

  template <class To, class From>
  struct IsInterfaceConvertible {
    static constexpr bool value = CodeOf<To> == TypeCode::Interface;
  };

  template <class To, class From>
  static constexpr bool IsConvertible = IsDerived<To, From> || IsArrayConvertible<To, From>::value || IsInterfaceConvertible<To, From>::value;

  template <class T>
  static constexpr bool AlwaysTrue = true;

  template <class T>
  class ref {
  public:
    using GCObject = GCObject<T>;
    using in = T;

    constexpr ref() noexcept : p_(nullptr)  {}
    constexpr ref(std::nullptr_t) noexcept : p_(nullptr) {}
    explicit ref(GCObject* p) noexcept : p_(p) {}
    explicit ref(T* p) noexcept : p_(GCObject::From(p)) {}

    ref(const ref& other) noexcept {
      copyOf(other);
    }

    template <class T1> requires(IsConvertible<T, T1>)
    ref(const ref<T1>& other) noexcept {
      copyOf(other);
    }

    template <class T1 = T> requires(IsString<T1>)
    ref(const char* str) {
      moveOf(string::load(str));
    }

    template <class... _Types, class T1 = T> requires(IsString<T1>)
    ref(const std::tuple<_Types...>& t) {
      moveOf(string::cat(t));
    }

    template <class T1> requires(IsObject<T> && !IsRef<T1>)
    ref(const T1 other) {
    }

    ref(ref&& other) noexcept {
      moveOf(std::move(other));
    }

    template <class T1> requires(IsConvertible<T, T1>)
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

    template <class T1> requires(!std::is_same_v<T, T1> && IsConvertible<T, T1>)
    ref& operator =(const ref<T1>& right) noexcept {
      ref(p_);
      copyOf(right);
      return *this;
    }

    template <class T1, class T2 = T> requires(std::is_pointer_v<T1> && IsDelegate<T2>)
    ref& operator =(const T1& right) noexcept {
      //TODO
      return *this;
    }

    bool operator ==(nullptr_t) const noexcept {
      return p_ == nullptr;
    }

    bool operator !=(nullptr_t) const noexcept {
      return p_ != nullptr;
    }

    template <class T1> requires(IsEquatable<T, T1>)
    bool operator ==(const ref<T1>& right) const noexcept {
      return p_ == reinterpret_cast<void*>(right.p_);
    }

    template <class T1> requires(IsEquatable<T, T1>)
    bool operator !=(const ref<T1>& right) const noexcept {
      return p_ != reinterpret_cast<void*>(right.p_);
    }

    template <class T1 = T> requires(IsString<T1>)
    constexpr auto operator +(const ref& right) noexcept {
      T* a = p_ ? get() : nullptr;
      T* b = right != nullptr ? right.get() : nullptr;
      return std::make_tuple(a, b);
    }

    template <class R, class T1 = T> requires(std::is_same_v<R, decltype(T1::op_Implicit(ref<T1>()))>)
    operator R() {
      return T1::op_Implicit(*this);
    }

    /*
    template <class R, class T1 = T> requires(std::is_same_v<R, decltype(R::op_Implicit(ref<T1>()))>)
    operator R() {
      return R::op_Implicit(*this);
    }*/

    template <class R, class T1 = T> requires(std::is_pointer_v<R> && std::is_same_v<R, decltype(&(T1().GetPinnableReference()))>)
    operator R() {
      return p_ == nullptr ? nullptr : &(get()->GetPinnableReference());
    }

    template <class R, class T1 = T> requires(IsObject<T1>)
    explicit operator R() {
      return R();
    }

    template <class... Args>
    auto& operator [](Args&&... args) {
      return get()->operator[](std::forward<Args>(args)...);
    }

    template <class... Args>
    auto operator ()(Args&&... args) requires(IsDelegate<T>) {
      return get()->Invoke(std::forward<Args>(args)...);
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
    string* a = right != nullptr ? reinterpret_cast<string*>(right.get()) : nullptr;
    return std::tuple_cat(t, std::make_tuple(a));
  }

  class object {
  public:
    template <class T, class... Args>
    static T newobj(Args&&... args) {
      using GCObject = typename T::GCObject;
      using element_type = typename T::in;
      void* p = alloc(sizeof(GCObject));
      auto temp = static_cast<GCObject*>(new (p) GCObjectHead(getTypeMetadata<T>()));
      temp->get()->ctor(std::forward<Args>(args)...);
      return T(temp);
    }
  private:
    static void* alloc(size_t size);
    static void free(void* p, size_t size);

    template <class T>
    friend class GCObject;

    template <class T, class Base>
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

    static ref<string> load(const char* str, size_t n);

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
    static ref<string> cat(string** being, size_t n);
    static GCObject<string>* alloc(size_t n);
  };

  template <class T, class Base>
  class Array : public Base {
    struct array {
      int32_t length;
      T first[];
    };
  public:
    using element_type = T;
    static constexpr TypeCode code = TypeCode::Array;

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

    template <class Size> 
    constexpr T& operator [](const Size& index) {
      return begin()[index.get()];
    }

    static size_t GetAllocSize(size_t n) noexcept {
      return sizeof(GCObject<array>) + n * sizeof(T);
    }

    static ref<array> newarr(size_t n) {
      void* p = object::alloc(GetAllocSize(n));
      auto temp = static_cast<GCObject<array>*>(new (p) GCObjectHead(gTypeMetadata));
      temp->get()->length = static_cast<int32_t>(n);
      return ref<array>(temp);
    }

    template <class T1 = T> requires(!IsRef<T1>)
    T& GetPinnableReference() {
      return *begin();
    }
  protected:
    int32_t length;
  };

  template <class T>
  static constexpr float NaN = 0b11111111110000000000000000000000;
  template <class T>
  static constexpr float PositiveInfinity = 0b1111111100000000000000000000000;
  template <class T>
  static constexpr float NegativeInfinity = 0b11111111100000000000000000000000;

  template <class T>
  static constexpr bool IsPrimitive = CodeOf<T> != TypeCode::None;

  constexpr bool IsArithmeticCode(TypeCode code) {
    return code >= TypeCode::Char && code <= TypeCode::Double;
  }
  
  constexpr bool IsPrimitiveValueCode(TypeCode code) {
    return code >= TypeCode::Boolean && code <= TypeCode::Double;
  }

  template <class T>
  static constexpr bool IsArithmetic = IsArithmeticCode(CodeOf<T>);

  template <class T>
  static constexpr bool IsNumerical = std::is_arithmetic_v<T> || IsArithmetic<T>;

  template <class T>
  auto GetPrimitiveValue(const T& index) {
    if constexpr (CodeOf<T> == TypeCode::None) {
      return index;
    }  else {
      return index.get();
    }
  }

  template <class To, class From>
  constexpr bool IsImplicitPrimitive() {
    constexpr TypeCode codeOfFrom = CodeOf<From>;
    constexpr TypeCode codeOfTo = CodeOf<To>;
    if constexpr (IsArithmeticCode(codeOfFrom) && IsArithmeticCode(codeOfTo)) {
      if constexpr (sizeof(To) > sizeof(From)) {
        return true;
      }
    }
    return false;
  }

  template <class T>
  constexpr bool IsValueType() {
    if constexpr (std::is_enum_v<T>) {
      return true;
    }

    constexpr TypeCode code = CodeOf<T>;
    if constexpr (IsPrimitiveValueCode(code) || code == TypeCode::Struct) {
      return true;
    }
    return false;
  }

  template <class T, class Base, TypeCode code>
  struct ValueOperator {
    static_assert(IsArithmeticCode(code));

    template <class T1> requires(IsNumerical<T1>) 
    auto operator <=>(const T1& other) const noexcept {
      return static_cast<const T*>(this)->get() <=> GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>) 
    bool operator ==(const T1& other) const noexcept {
      return static_cast<const T*>(this)->get() == GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator +=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() += GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator -=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() -= GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator *=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() *= GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator /=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() /= GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator %=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() %= GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator |=(const T1& other) {
      auto p = static_cast<T*>(this);
      p->get() |= GetPrimitiveValue(other);
      return *p;
    }

    template <class T1> requires(IsNumerical<T1>) 
    T operator +(const T1& other) const {
      return static_cast<const T*>(this)->get() + GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator -(const T1& other) const {
      return static_cast<const T*>(this)->get() - GetPrimitiveValue(other);
    }
    
    template <class T1> requires(IsNumerical<T1>)
    T operator *(const T1& other) const {
      return static_cast<const T*>(this)->get() * GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator /(const T1& other) const {
      return static_cast<const T*>(this)->get() / GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator |(const T1& other) const {
      return static_cast<const T*>(this)->get() | GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator &(const T1& other) const {
      return static_cast<const T*>(this)->get() & GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator >>(const T1& other) const {
      return static_cast<const T*>(this)->get() >> GetPrimitiveValue(other);
    }

    template <class T1> requires(IsNumerical<T1>)
    T operator <<(const T1& other) const {
      return static_cast<const T*>(this)->get() << GetPrimitiveValue(other);
    }

    template <class T1 = T> requires(IsArithmetic<T1>) 
    T operator ~() const noexcept {
      return ~static_cast<const T*>(this)->get();
    }

    template <class T1 = T> requires(IsArithmetic<T1>) 
    T operator ++() {
      auto p = static_cast<T*>(this);
      ++p->get();
      return *p;
    }

    template <class T1 = T> requires(IsArithmetic<T1>) 
    T operator ++(int) {
      auto p = static_cast<T*>(this);
      T tmp = *p;
      ++p->get();
      return tmp;
    }

    template <class T1 = T> requires(IsArithmetic<T1>) 
    T operator --() {
      auto p = static_cast<T*>(this);
      --p->get();
      return *p;
    }

    template <class T1 = T> requires(IsArithmetic<T1>) 
    T operator --(int) {
      auto p = static_cast<T*>(this);
      T tmp = *p;
      --p->get();
      return tmp;
    }

    template <class R> requires(IsImplicitPrimitive<R, T>())
    operator R() {
      return static_cast<T*>(this)->get();
    }

    template <class R> requires(IsArithmetic<R>)
    explicit operator R() const {
      return static_cast<std::remove_reference_t<decltype(R().get())>>(static_cast<const T*>(this)->get());
    }

    template <class R> requires(std::is_enum_v<R>)
    explicit operator R() const {
      return static_cast<R>(static_cast<const T*>(this)->get());
    }

    explicit operator void*() const noexcept {
      return (void*)(static_cast<const T*>(this)->get());
    }

    template <class R> requires(IsValueType<R>())
    explicit operator R*() const noexcept {
      return (R*)(static_cast<const T*>(this)->get());
    }
  };

  template <class T, class Base>
  struct ValueOperator<T, Base, TypeCode::Struct> : public Base  {
    template <class T1, class T2 = T> requires(AlwaysTrue<decltype(T2::op_Equality(T2(), T1()))>) 
    auto operator ==(const T1& other) {
      return T::op_Equality(*static_cast<T*>(this), other);
    }

    template <class T1, class T2 = T> requires(AlwaysTrue<decltype(T2::op_Inequality(T2(), T1()))>) 
    auto operator !=(const T1& other) {
      return T::op_Inequality(*static_cast<T*>(this), other);
    }

    template <class R, class T1 = T> requires(std::is_same_v<R, decltype(&(T1().GetPinnableReference()))>)
    operator R() {
      return &(static_cast<T*>(this)->GetPinnableReference());
    }

    template <class R, class T1 = T> requires(std::is_same_v<R, decltype(T1::op_Explicit(T1()))>)
    explicit operator R() {
      return T::op_Explicit(*static_cast<T*>(this));
    }

    template <class R, class T1 = T> requires(std::is_same_v<R, decltype(T1::op_Explicit(T1(), R()))>)
    explicit operator R() {
      return T::op_Explicit(*static_cast<T*>(this), R());
    }

    template <class... Args>
    constexpr auto operator [](Args&&... args) {
      return static_cast<T*>(this)->get_Item(std::forward<Args>(args)...);
    }
  };

  template <class T, class Base>
  struct ValueOperator<T, Base, TypeCode::Boolean> : public Base  {
    operator bool() const noexcept {
      return static_cast<const T*>(this)->get();
    }
  };

  template <class T, class Base, TypeCode code>
  struct ValueType : public ValueOperator<T, Base, code> {
  };

  template <class T, size_t N>
  struct FixedBuffer {
    T v[N];

    template <class Size> 
    constexpr T& operator [](const Size& index) {
      return v[GetPrimitiveValue(index)];
    }
  };

  struct Default {
    template <class R>
    constexpr operator R() const {
      return R();
    }
  };

  inline constexpr Default default__;
  
  template <class T, class V>
  bool is(const V& v) {
    return false;
  }

  template <class T, class V>
  T as(const V& v) {
    return nullptr;
  }

  template <class T>
  inline void lock(const T& obj) {
  }

  template <class T>
  inline void Using(const T& obj) {
  }

  template <class R, class Arg>
  int init(int argc, char* argv[], R (*f)(Arg)) {
    auto args = Array<ref<string>, object>::newarr(argc - 1);
    f(*reinterpret_cast<Arg*>(&args));
    return 0;
  }

  template <class Ex>
  [[noreturn]] void throw_exception(Ex&& ex) {
  #if !MESON_NO_EXCEPTIONS
    throw ex;
  #else
    (void)ex;
    std::terminate();
  #endif
  }

  template <class T, class... Args>
  inline T newobj(Args&&... args) {
    if constexpr (IsString<T::in>) { 
      return T::in::Ctor(std::forward<Args>(args)...); 
    }
    return rt::object::newobj<T>(std::forward<Args>(args)...);
  }

  template <class Ex, class... Args>
  [[noreturn]] void throw_exception(Args&&... args) {
    throw_exception(newobj<Ex>(std::forward<Args>(args)...));
  }

  template <class A, class Size>
  inline auto newarr(const Size& n) {
    using T = typename A::in::element_type;
    return *reinterpret_cast<A*>(&rt::Array<T, object>::newarr(GetPrimitiveValue(n)));
  }
}  // namespace rt

template <class T> requires(std::is_enum_v<T>) 
inline constexpr bool operator ==(T a, int32_t b) { 
  return (int32_t)a == b;
}

template <class T> requires(std::is_enum_v<T>) 
inline constexpr bool operator !=(T a, int32_t b) { 
  return (int32_t)a != b;
}

template <class T, class T1> requires(std::is_pointer_v<T> && rt::IsArithmetic<T1>) 
inline constexpr T operator +(T a, T1 b) { 
  return a + b.get();
}

template <class T, class T1> requires(std::is_arithmetic_v<T> && rt::IsArithmetic<T1>) 
inline constexpr auto operator -(T a, T1 b) { 
  return a - b.get();
}

template <class T, class T1> requires(std::is_arithmetic_v<T> && rt::IsArithmetic<T1>) 
inline constexpr auto operator *(T a, T1 b) { 
  return b * a;
}

template <class T, class T1> requires(std::is_arithmetic_v<T> && rt::IsArithmetic<T1>) 
inline constexpr auto operator &(T a, T1 b) { 
  return b & a;
}

template <class T, class T1> requires(std::is_arithmetic_v<T> && rt::IsArithmetic<T1>) 
inline constexpr auto operator |(T a, T1 b) { 
  return b | a;
}

template <class T> requires(std::is_enum_v<T>) 
inline constexpr auto operator &(T a, T b) { 
  return (T)((int)a & (int)b);
}

template <class T> requires(std::is_enum_v<T>) 
inline constexpr auto operator |(T a, T b) { 
  return (T)((int)a | (int)b);
}

template <class T> requires(std::is_enum_v<T>) 
inline constexpr auto operator |=(T a, T b) { 
  return a = (T)((int)a | (int)b);
}

#if defined(_MSC_VER)
  #pragma warning(disable:4674)
#endif