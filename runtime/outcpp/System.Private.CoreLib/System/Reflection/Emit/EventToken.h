#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EventTokenNamespace {
struct EventToken {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(EventToken obj);
  public: static EventToken Empty;
};
} // namespace EventTokenNamespace
using EventToken = EventTokenNamespace::EventToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
