#include "DeserializationToken-dep.h"

#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationInfo-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::DeserializationTokenNamespace {
DeserializationToken::DeserializationToken(DeserializationTracker tracker) {
  _tracker = tracker;
}

void DeserializationToken::Dispose() {
  if (_tracker == nullptr || !_tracker->get_DeserializationInProgress()) {
    return;
  }
  {
    rt::lock(_tracker);
    if (_tracker->get_DeserializationInProgress()) {
      _tracker->set_DeserializationInProgress = false;
      SerializationInfo::in::get_AsyncDeserializationInProgress()->set_Value = false;
    }
  }
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::DeserializationTokenNamespace
