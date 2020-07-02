#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace EventRegistrationTokenNamespace {
struct EventRegistrationToken {
  public: UInt64 get_Value();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Boolean Equals(EventRegistrationToken other);
  private: UInt64 _value;
};
} // namespace EventRegistrationTokenNamespace
using EventRegistrationToken = EventRegistrationTokenNamespace::EventRegistrationToken;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
