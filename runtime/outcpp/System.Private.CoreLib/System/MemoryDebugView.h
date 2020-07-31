#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Memory, T)
namespace MemoryDebugViewNamespace {
CLASS(MemoryDebugView, T) : public Object::in {
  public: Array<T> get_Items();
  public: void Ctor(Memory<T> memory);
  public: void Ctor(ReadOnlyMemory<T> memory);
  private: ReadOnlyMemory<T> _memory;
};
} // namespace MemoryDebugViewNamespace
template <class T>
using MemoryDebugView = MemoryDebugViewNamespace::MemoryDebugView<T>;
} // namespace System::Private::CoreLib::System
