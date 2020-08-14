#include "PinnedBufferMemoryStream-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>

namespace System::Private::CoreLib::System::IO::PinnedBufferMemoryStreamNamespace {
using namespace System::Runtime::InteropServices;

void PinnedBufferMemoryStream___::ctor(Array<Byte> array) {
  _array = array;
  _pinningHandle = GCHandle::Alloc(array, GCHandleType::Pinned);
  Int32 num = array->get_Length();
  {
    Byte* pointer = &MemoryMarshal::GetReference<Byte>(array);
    Initialize(pointer, num, num, FileAccess::Read);
  }
}

Int32 PinnedBufferMemoryStream___::Read(Span<Byte> buffer) {
  return ReadCore(buffer);
}

void PinnedBufferMemoryStream___::Write(ReadOnlySpan<Byte> buffer) {
  WriteCore(buffer);
}

void PinnedBufferMemoryStream___::Finalize() {
  Dispose(false);
}

void PinnedBufferMemoryStream___::Dispose(Boolean disposing) {
  if (_pinningHandle.get_IsAllocated()) {
    _pinningHandle.Free();
  }
}

} // namespace System::Private::CoreLib::System::IO::PinnedBufferMemoryStreamNamespace
