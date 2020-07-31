#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(DateTime)
FORWARDS(Double)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace DateMarshalerNamespace {
class DateMarshaler : public Object::in {
  public: static Double ConvertToNative(DateTime managedDate);
  public: static Int64 ConvertToManaged(Double nativeDate);
};
} // namespace DateMarshalerNamespace
using DateMarshaler = DateMarshalerNamespace::DateMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
