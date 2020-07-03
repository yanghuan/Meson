#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace DeserializationTrackerNamespace {
CLASS(DeserializationTracker) {
  private: Boolean DeserializationInProgress;
};
} // namespace DeserializationTrackerNamespace
using DeserializationTracker = DeserializationTrackerNamespace::DeserializationTracker;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
