#include "DeserializationToken-dep.h"

namespace System::Private::CoreLib::System::Runtime::Serialization::DeserializationTokenNamespace {
DeserializationToken::DeserializationToken(DeserializationTracker tracker) {
  _tracker = tracker;
}

void DeserializationToken::Dispose() {
  if (_tracker == nullptr || !_tracker->get_DeserializationInProgress()) {
    return;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::DeserializationTokenNamespace
