#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace FILETIMENamespace {
struct FILETIME : public valueType<FILETIME> {
  public: Int32 dwLowDateTime;
  public: Int32 dwHighDateTime;
};
} // namespace FILETIMENamespace
using FILETIME = FILETIMENamespace::FILETIME;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
