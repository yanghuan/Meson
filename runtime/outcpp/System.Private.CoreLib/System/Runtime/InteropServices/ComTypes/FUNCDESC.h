#pragma once

#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/ELEMDESC.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class CALLCONV : int32_t;
enum class FUNCKIND : int32_t;
enum class INVOKEKIND : int32_t;
namespace FUNCDESCNamespace {
struct FUNCDESC : public valueType<FUNCDESC> {
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
