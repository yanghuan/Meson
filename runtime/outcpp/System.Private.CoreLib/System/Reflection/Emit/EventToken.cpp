#include "EventToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/EventToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::EventTokenNamespace {
EventToken::EventToken(Int32 eventToken) {
  Token = eventToken;
}

Int32 EventToken::GetHashCode() {
  return Token;
}

Boolean EventToken::Equals(Object obj) {
  if (rt::is<EventToken>(obj)) {
    EventToken obj2 = (EventToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean EventToken::Equals(EventToken obj) {
  return obj.get_Token() == Token;
}

Boolean EventToken::op_Equality(EventToken a, EventToken b) {
  return a.Equals(b);
}

Boolean EventToken::op_Inequality(EventToken a, EventToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::EventTokenNamespace
