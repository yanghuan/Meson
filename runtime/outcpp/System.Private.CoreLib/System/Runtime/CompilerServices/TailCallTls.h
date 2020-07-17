#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(PortableTailCallFrame)
namespace TailCallTlsNamespace {
struct TailCallTls {
  public: void Ctor();
  public: PortableTailCallFrame* Frame;
  public: IntPtr ArgBuffer;
  private: IntPtr _argBufferSize;
  private: IntPtr _argBufferGCDesc;
  private: rt::FixedBuffer<Byte, 64> _argBufferInline;
};
} // namespace TailCallTlsNamespace
using TailCallTls = TailCallTlsNamespace::TailCallTls;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
