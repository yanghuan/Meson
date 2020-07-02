#pragma once

#include <rt/GCObject.h>

namespace System::Runtime::System {
namespace LazyNamespace {
CLASS(Lazy, T, TMetadata) {
  public: TMetadata get_Metadata();
  private: TMetadata _metadata;
};
} // namespace LazyNamespace
template <class T, class TMetadata>
using Lazy = LazyNamespace::Lazy<T, TMetadata>;
} // namespace System::Runtime::System
