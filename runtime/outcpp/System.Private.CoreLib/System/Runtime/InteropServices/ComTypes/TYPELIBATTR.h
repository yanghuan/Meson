#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class LIBFLAGS : int16_t;
enum class SYSKIND;
namespace TYPELIBATTRNamespace {
struct TYPELIBATTR : public valueType<TYPELIBATTR> {
  public: Guid guid;
  public: Int32 lcid;
  public: SYSKIND syskind;
  public: Int16 wMajorVerNum;
  public: Int16 wMinorVerNum;
  public: LIBFLAGS wLibFlags;
};
} // namespace TYPELIBATTRNamespace
using TYPELIBATTR = TYPELIBATTRNamespace::TYPELIBATTR;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
