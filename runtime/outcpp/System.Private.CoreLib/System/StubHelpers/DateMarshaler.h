#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(DateTime)
FORWARDS(Double)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace DateMarshalerNamespace {
class DateMarshaler {
  public: static Double ConvertToNative(DateTime managedDate);
  public: static Int64 ConvertToManaged(Double nativeDate);
};
} // namespace DateMarshalerNamespace
using DateMarshaler = DateMarshalerNamespace::DateMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
