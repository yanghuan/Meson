#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComEventsHelperNamespace {
class ComEventsHelper {
  public: static void Combine(Object rcw, Guid iid, Int32 dispid, Delegate d);
  public: static Delegate Remove(Object rcw, Guid iid, Int32 dispid, Delegate d);
};
} // namespace ComEventsHelperNamespace
using ComEventsHelper = ComEventsHelperNamespace::ComEventsHelper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
