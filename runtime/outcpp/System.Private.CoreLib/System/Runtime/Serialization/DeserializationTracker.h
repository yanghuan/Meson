#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace DeserializationTrackerNamespace {
CLASS(DeserializationTracker) : public object {
  public: Boolean get_DeserializationInProgress() { return DeserializationInProgress; }
  public: void set_DeserializationInProgress(Boolean value) { DeserializationInProgress = value; }
  public: void ctor();
  private: Boolean DeserializationInProgress;
};
} // namespace DeserializationTrackerNamespace
using DeserializationTracker = DeserializationTrackerNamespace::DeserializationTracker;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
