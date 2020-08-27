#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(PortableTailCallFrame)
namespace TailCallTlsNamespace {
struct TailCallTls : public valueType<TailCallTls> {
  public: PortableTailCallFrame* Frame;
  public: IntPtr ArgBuffer;
  private: IntPtr _argBufferSize;
  private: IntPtr _argBufferGCDesc;
  private: Byte _argBufferInline[64];
};
} // namespace TailCallTlsNamespace
using TailCallTls = TailCallTlsNamespace::TailCallTls;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
