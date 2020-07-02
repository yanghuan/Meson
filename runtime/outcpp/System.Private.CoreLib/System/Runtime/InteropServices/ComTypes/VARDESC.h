#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/ELEMDESC.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class VARKIND;
namespace VARDESCNamespace {
struct VARDESC {
  public: struct DESCUNION {
    public: Int32 oInst;
    public: IntPtr lpvarValue;
  };
  public: Int32 memid;
  public: String lpstrSchema;
  public: DESCUNION desc;
  public: ELEMDESC elemdescVar;
  public: Int16 wVarFlags;
  public: VARKIND varkind;
};
} // namespace VARDESCNamespace
using VARDESC = VARDESCNamespace::VARDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
