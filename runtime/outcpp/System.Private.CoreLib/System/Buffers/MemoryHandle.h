#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARD(IPinnable)
namespace MemoryHandleNamespace {
using namespace Runtime::InteropServices;
struct MemoryHandle {
  public: void* get_Pointer();
  public: void Dispose();
  private: void* _pointer;
  private: GCHandle _handle;
  private: IPinnable _pinnable;
};
} // namespace MemoryHandleNamespace
using MemoryHandle = MemoryHandleNamespace::MemoryHandle;
} // namespace System::Private::CoreLib::System::Buffers
