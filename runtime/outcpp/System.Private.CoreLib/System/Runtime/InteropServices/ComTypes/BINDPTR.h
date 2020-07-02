#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace BINDPTRNamespace {
struct BINDPTR {
  public: IntPtr lpfuncdesc;
  public: IntPtr lpvardesc;
  public: IntPtr lptcomp;
};
} // namespace BINDPTRNamespace
using BINDPTR = BINDPTRNamespace::BINDPTR;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
