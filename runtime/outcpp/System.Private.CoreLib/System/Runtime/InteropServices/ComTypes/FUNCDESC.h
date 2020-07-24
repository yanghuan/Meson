#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/ELEMDESC.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class CALLCONV;
enum class FUNCKIND;
enum class INVOKEKIND;
namespace FUNCDESCNamespace {
struct FUNCDESC {
  public: Int32 memid;
  public: IntPtr lprgscode;
  public: IntPtr lprgelemdescParam;
  public: FUNCKIND funckind;
  public: INVOKEKIND invkind;
  public: CALLCONV callconv;
  public: Int16 cParams;
  public: Int16 cParamsOpt;
  public: Int16 oVft;
  public: Int16 cScodes;
  public: ELEMDESC elemdescFunc;
  public: Int16 wFuncFlags;
};
} // namespace FUNCDESCNamespace
using FUNCDESC = FUNCDESCNamespace::FUNCDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
