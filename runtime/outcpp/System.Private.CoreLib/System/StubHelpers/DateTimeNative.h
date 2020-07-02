#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace DateTimeNativeNamespace {
struct DateTimeNative {
  public: Int64 UniversalTime;
};
} // namespace DateTimeNativeNamespace
using DateTimeNative = DateTimeNativeNamespace::DateTimeNative;
} // namespace System::Private::CoreLib::System::StubHelpers
