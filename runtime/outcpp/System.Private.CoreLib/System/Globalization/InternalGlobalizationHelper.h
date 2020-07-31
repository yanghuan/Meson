#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace InternalGlobalizationHelperNamespace {
class InternalGlobalizationHelper : public Object::in {
  public: static Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second);
};
} // namespace InternalGlobalizationHelperNamespace
using InternalGlobalizationHelper = InternalGlobalizationHelperNamespace::InternalGlobalizationHelper;
} // namespace System::Private::CoreLib::System::Globalization
