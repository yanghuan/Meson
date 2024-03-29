#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace LICINFONamespace {
using namespace System;
struct LICINFO : public valueType<LICINFO> {
  public: Int32 cbLicInfo;
  public: Boolean fRuntimeKeyAvail;
  public: Boolean fLicVerified;
};
} // namespace LICINFONamespace
using LICINFO = LICINFONamespace::LICINFO;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
