#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(DateTimeOffset)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
FORWARDS(DateTimeNative)
namespace DateTimeOffsetMarshalerNamespace {
class DateTimeOffsetMarshaler {
  public: static void ConvertToNative(DateTimeOffset& managedDTO, DateTimeNative& dateTime);
  public: static void ConvertToManaged(DateTimeOffset& managedLocalDTO, DateTimeNative& nativeTicks);
};
} // namespace DateTimeOffsetMarshalerNamespace
using DateTimeOffsetMarshaler = DateTimeOffsetMarshalerNamespace::DateTimeOffsetMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
