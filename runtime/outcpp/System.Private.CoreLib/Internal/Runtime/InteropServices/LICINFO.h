#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace LICINFONamespace {
using namespace ::System::Private::CoreLib::System;
struct LICINFO {
  public: void Ctor();
  public: Int32 cbLicInfo;
  public: Boolean fRuntimeKeyAvail;
  public: Boolean fLicVerified;
};
} // namespace LICINFONamespace
using LICINFO = LICINFONamespace::LICINFO;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
