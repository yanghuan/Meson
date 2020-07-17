#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace FILETIMENamespace {
struct FILETIME {
  public: void Ctor();
  public: Int32 dwLowDateTime;
  public: Int32 dwHighDateTime;
};
} // namespace FILETIMENamespace
using FILETIME = FILETIMENamespace::FILETIME;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
