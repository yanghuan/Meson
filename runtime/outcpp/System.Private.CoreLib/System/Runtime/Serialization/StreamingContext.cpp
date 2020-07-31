#include "StreamingContext-dep.h"

namespace System::Private::CoreLib::System::Runtime::Serialization::StreamingContextNamespace {
StreamingContextStates StreamingContext::get_State() {
  return StreamingContextStates::All;
}

Object StreamingContext::get_Context() {
  return nullptr;
}

StreamingContext::StreamingContext(StreamingContextStates state) {
}

StreamingContext::StreamingContext(StreamingContextStates state, Object additional) {
}

Boolean StreamingContext::Equals(Object obj) {
  return Boolean();
}

Int32 StreamingContext::GetHashCode() {
  return Int32();
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::StreamingContextNamespace
