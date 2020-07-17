#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class PARAMFLAG : int16_t;
namespace PARAMDESCNamespace {
struct PARAMDESC {
  public: void Ctor();
  public: IntPtr lpVarValue;
  public: PARAMFLAG wParamFlags;
};
} // namespace PARAMDESCNamespace
using PARAMDESC = PARAMDESCNamespace::PARAMDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
