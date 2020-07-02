#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace CONNECTDATANamespace {
struct CONNECTDATA {
  public: Object pUnk;
  public: Int32 dwCookie;
};
} // namespace CONNECTDATANamespace
using CONNECTDATA = CONNECTDATANamespace::CONNECTDATA;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
