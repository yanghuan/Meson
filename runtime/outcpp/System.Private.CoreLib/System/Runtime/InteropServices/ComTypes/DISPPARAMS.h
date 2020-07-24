#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace DISPPARAMSNamespace {
struct DISPPARAMS {
  public: IntPtr rgvarg;
  public: IntPtr rgdispidNamedArgs;
  public: Int32 cArgs;
  public: Int32 cNamedArgs;
};
} // namespace DISPPARAMSNamespace
using DISPPARAMS = DISPPARAMSNamespace::DISPPARAMS;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
