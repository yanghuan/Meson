#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EventTokenNamespace {
struct EventToken : public valueType<EventToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit EventToken(Int32 eventToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(EventToken obj);
  public: static Boolean op_Equality(EventToken a, EventToken b);
  public: static Boolean op_Inequality(EventToken a, EventToken b);
  public: explicit EventToken() {}
  public: static EventToken Empty;
  private: Int32 Token;
};
} // namespace EventTokenNamespace
using EventToken = EventTokenNamespace::EventToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
