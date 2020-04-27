#pragma once

#include <atomic>
#include <cstdint>
#include <cstdio>
#include <memory>
#include <string>
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
 public:
  static constexpr bool kIsString = is_string<T>::value;

 public:
  T* get() noexcept { return &v_; }

  void release() noexcept {
    size_t n;
    if constexpr (kIsString) {
      n = v_.GetAllocSize();
    } else {
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

template <class _T>
class ref {
 private:
  using T = GCObject<_T>;

 public:
  constexpr ref() noexcept {}

  constexpr ref(nullptr_t) noexcept {}

  constexpr ref(const char* str) : ref(String::load(str)) {
    static_assert(T::kIsString,
                  "This constructor is only available for String");
  }

  explicit ref(T* p) noexcept : p_(p) {}

  ref(const ref& other) noexcept {
    if (other.p_) {
      other.p_->refAdd();
    }
    p_ = other.p_;
  }

  ref(ref&& other) noexcept {
    p_ = other.p_;
    other.p_ = nullptr;
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

  bool operator==(nullptr_t) const noexcept { return p_ == nullptr; }
  bool operator!=(nullptr_t) const noexcept { return p_ != nullptr; }

  template <std::enable_if_t<T::kIsString, int> = 0>
  ref& operator+(const ref& right) {
    return *this;
  }

  template <std::enable_if_t<T::kIsString, int> = 0>
  ref& operator+(ref<String> right) {
    return *this;
  }

  _T* operator->() const noexcept { return p_->get(); }

 private:
  void swap(ref& right) noexcept { std::swap(p_, right.p_); }

  template <class T1>
  ref(ref<T1>&& other) noexcept {
    p_ = reinterpret_cast<T*>(other.p_);
    other.p_ = nullptr;
  }

 public:
  T* p_ = nullptr;
};

using object = ref<Object>;
using string = ref<String>;

class Object {};

class String {
 public:
  static size_t GetAllocSize(size_t n) {
    return sizeof(GCObject<String>) - sizeof(intptr_t) + n + 1;
  }

  size_t GetAllocSize() { return GetAllocSize(length); }

  static string load(const char* str) {
    return load(str, std::char_traits<char>::length(str));
  }

  char* c_str() { return reinterpret_cast<char*>(&firstChar); }

 private:
  static string load(const char* str, size_t n);

 protected:
  int32_t length;
  intptr_t firstChar;
};

}  // namespace meson
