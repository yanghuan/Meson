#include "WeakReference-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>

namespace System::Private::CoreLib::System::WeakReferenceNamespace {
Boolean WeakReference___<>::get_TrackResurrection() {
  return IsTrackResurrection();
}

void WeakReference___<>::ctor() {
  rt::throw_exception<NotImplementedException>();
}

void WeakReference___<>::ctor(Object target) {
}

void WeakReference___<>::ctor(Object target, Boolean trackResurrection) {
  Create(target, trackResurrection);
}

void WeakReference___<>::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  Object value = info->GetValue("TrackedObject", typeof<Object>());
  Boolean boolean = info->GetBoolean("TrackResurrection");
  Create(value, boolean);
}

void WeakReference___<>::GetObjectData(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("TrackedObject", get_Target(), typeof<Object>());
  info->AddValue("TrackResurrection", IsTrackResurrection());
}

} // namespace System::Private::CoreLib::System::WeakReferenceNamespace
