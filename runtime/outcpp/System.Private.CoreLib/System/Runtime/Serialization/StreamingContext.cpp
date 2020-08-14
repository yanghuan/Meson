#include "StreamingContext-dep.h"

#include <System.Private.CoreLib/System/Runtime/Serialization/StreamingContext-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::StreamingContextNamespace {
StreamingContextStates StreamingContext::get_State() {
  return _state;
}

Object StreamingContext::get_Context() {
  return _additionalContext;
}

StreamingContext::StreamingContext(StreamingContextStates state) {
}

StreamingContext::StreamingContext(StreamingContextStates state, Object additional) {
  _state = state;
  _additionalContext = additional;
}

Boolean StreamingContext::Equals(Object obj) {
  if (!rt::is<StreamingContext>(obj)) {
    return false;
  }
  StreamingContext streamingContext = (StreamingContext)obj;
  if (streamingContext._additionalContext == _additionalContext) {
    return streamingContext._state == _state;
  }
  return false;
}

Int32 StreamingContext::GetHashCode() {
  return (Int32)_state;
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::StreamingContextNamespace
