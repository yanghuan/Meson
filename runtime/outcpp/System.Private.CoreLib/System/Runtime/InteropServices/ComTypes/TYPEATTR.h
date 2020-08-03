#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IDLDESC.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/TYPEDESC.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class TYPEFLAGS : int16_t;
enum class TYPEKIND;
namespace TYPEATTRNamespace {
struct TYPEATTR : public valueType<TYPEATTR> {
  public: static constexpr Int32 MEMBER_ID_NIL = -1;
  public: Guid guid;
  public: Int32 lcid;
  public: Int32 dwReserved;
  public: Int32 memidConstructor;
  public: Int32 memidDestructor;
  public: IntPtr lpstrSchema;
  public: Int32 cbSizeInstance;
  public: TYPEKIND typekind;
  public: Int16 cFuncs;
  public: Int16 cVars;
  public: Int16 cImplTypes;
  public: Int16 cbSizeVft;
  public: Int16 cbAlignment;
  public: TYPEFLAGS wTypeFlags;
  public: Int16 wMajorVerNum;
  public: Int16 wMinorVerNum;
  public: TYPEDESC tdescAlias;
  public: IDLDESC idldescType;
};
} // namespace TYPEATTRNamespace
using TYPEATTR = TYPEATTRNamespace::TYPEATTR;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
