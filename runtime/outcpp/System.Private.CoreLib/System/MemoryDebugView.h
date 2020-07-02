#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
namespace MemoryDebugViewNamespace {
CLASS(MemoryDebugView, T) {
  public: Array<T> get_Items();
  private: ReadOnlyMemory<T> _memory;
};
} // namespace MemoryDebugViewNamespace
template <class T>
using MemoryDebugView = MemoryDebugViewNamespace::MemoryDebugView<T>;
} // namespace System::Private::CoreLib::System
