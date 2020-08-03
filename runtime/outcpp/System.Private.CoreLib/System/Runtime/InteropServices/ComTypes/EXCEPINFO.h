#pragma once

#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace EXCEPINFONamespace {
struct EXCEPINFO : public valueType<EXCEPINFO> {
  public: Int16 wCode;
  public: Int16 wReserved;
  public: String bstrSource;
  public: String bstrDescription;
  public: String bstrHelpFile;
  public: Int32 dwHelpContext;
  public: IntPtr pvReserved;
  public: IntPtr pfnDeferredFillIn;
  public: Int32 scode;
};
} // namespace EXCEPINFONamespace
using EXCEPINFO = EXCEPINFONamespace::EXCEPINFO;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
