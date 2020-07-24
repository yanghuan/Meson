#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IDLDESC.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/PARAMDESC.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/TYPEDESC.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace ELEMDESCNamespace {
struct ELEMDESC {
  public: struct DESCUNION {
    public: IDLDESC idldesc;
    public: PARAMDESC paramdesc;
  };
  public: TYPEDESC tdesc;
  public: DESCUNION desc;
};
} // namespace ELEMDESCNamespace
using ELEMDESC = ELEMDESCNamespace::ELEMDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
