#pragma once

#include <System.Private.CoreLib/System/IO/UnmanagedMemoryStream.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace PinnedBufferMemoryStreamNamespace {
using namespace System::Runtime::InteropServices;
CLASS(PinnedBufferMemoryStream) : public UnmanagedMemoryStream::in {
  public: void ctor(Array<Byte> array);
  public: Int32 Read(Span<Byte> buffer);
  public: void Write(ReadOnlySpan<Byte> buffer);
  protected: void Finalize();
  protected: void Dispose(Boolean disposing);
  private: Array<Byte> _array;
  private: GCHandle _pinningHandle;
};
} // namespace PinnedBufferMemoryStreamNamespace
using PinnedBufferMemoryStream = PinnedBufferMemoryStreamNamespace::PinnedBufferMemoryStream;
} // namespace System::Private::CoreLib::System::IO
