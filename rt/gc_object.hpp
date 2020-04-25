#pragma once

#include <atomic>
#include <cstdint>
#include <memory>

using namespace std;

namespace meson {

class TypeMetadata {};

class GCObjectHead {
 public:
  void inc_ref_count() noexcept { ++ref_count_; }
  void dec_ref_count() noexcept { --ref_count_; }

 protected:
  bool is_release() noexcept { return --ref_count_ == 0; }

 private:
  atomic_uint32_t ref_count_;
  TypeMetadata* klass_;
};

template <class T>
class GCObject : GCObjectHead {
 public:
  void release() noexcept {
    if (is_release()) {
      delete this; 
    }
  }
 private:
  T ins_;
};

template <class T>
class GCPtr {
 private:
  using GCT = GCObject<T>;

 public:
  explicit GCPtr(GCT* ptr) noexcept { ptr_ = ptr; }

  GCPtr(GCPtr<T>& other) noexcept {
    other.ptr_->inc_ref_count();
    ptr_ = other.ptr_;
  }

  ~GCPtr() noexcept { ptr_->release(); }

 private:
  GCT* ptr_;
};

}  // namespace meson
