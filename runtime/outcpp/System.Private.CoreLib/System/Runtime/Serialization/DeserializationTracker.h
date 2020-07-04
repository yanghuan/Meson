#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace DeserializationTrackerNamespace {
CLASS(DeserializationTracker) {
  public: Boolean get_DeserializationInProgress() { return DeserializationInProgress; }
  public: void set_DeserializationInProgress(Boolean value) { DeserializationInProgress = value; }
  private: Boolean DeserializationInProgress;
};
} // namespace DeserializationTrackerNamespace
using DeserializationTracker = DeserializationTrackerNamespace::DeserializationTracker;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
