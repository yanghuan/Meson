#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace BIND_OPTSNamespace {
struct BIND_OPTS {
  public: Int32 cbStruct;
  public: Int32 grfFlags;
  public: Int32 grfMode;
  public: Int32 dwTickCountDeadline;
};
} // namespace BIND_OPTSNamespace
using BIND_OPTS = BIND_OPTSNamespace::BIND_OPTS;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
