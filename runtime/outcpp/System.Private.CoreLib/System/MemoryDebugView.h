#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Memory, T)
namespace MemoryDebugViewNamespace {
CLASS(MemoryDebugView, T) : public object {
  public: Array<T> get_Items();
  public: void ctor(Memory<T> memory);
  public: void ctor(ReadOnlyMemory<T> memory);
  private: ReadOnlyMemory<T> _memory;
};
} // namespace MemoryDebugViewNamespace
template <class T>
using MemoryDebugView = MemoryDebugViewNamespace::MemoryDebugView<T>;
} // namespace System::Private::CoreLib::System
