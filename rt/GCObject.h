#pragma once

#include <atomic>
#include <cstdint>
#include <memory>

using namespace std;

namespace meson {

void* gcMalloc(size_t n);
void gcFree(void* p, size_t n);

class TypeMetadata {};

class GCObjectHead {
 public:
  void refAdd() noexcept { ++refs_; }
  void refDec() noexcept { --refs_; }

 protected:
  void release(size_t n) noexcept {
    if (--refs_ == 0) {
      gcFree(this, n);
    }
  }

 private:
  atomic_uint32_t refs_;
  TypeMetadata* klass_;
};

template <class T>
class GCObject : GCObjectHead {
 public:
  T* get() noexcept { return &v_; }
  void release() noexcept { GCObjectHead::release(sizeof(GCObject)); }

 private:
  T v_;
};

template <class _T>
class ref {
 private:
  using T = GCObject<_T>;

 public:
  constexpr ref() noexcept {}

  constexpr ref(nullptr_t) noexcept {}

  explicit ref(T* p) noexcept { p_ = p; }

  ref(const ref& other) noexcept {
    other.p_->refAdd();
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

  _T* operator->() const noexcept { return p_->get(); }

 private:
  T* p_{nullptr};
};

}  // namespace meson
