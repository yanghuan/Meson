#pragma once

#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(IPinnable)
namespace MemoryHandleNamespace {
using namespace System::Runtime::InteropServices;
struct MemoryHandle : public valueType<MemoryHandle> {
  public: using interface = rt::TypeList<IDisposable>;
  public: void* get_Pointer();
  public: explicit MemoryHandle(void* pointer, GCHandle handle = rt::default__, IPinnable pinnable = nullptr);
  public: void Dispose();
  public: explicit MemoryHandle() {}
  private: void* _pointer;
  private: GCHandle _handle;
  private: IPinnable _pinnable;
};
} // namespace MemoryHandleNamespace
using MemoryHandle = MemoryHandleNamespace::MemoryHandle;
} // namespace System::Private::CoreLib::System::Buffers
