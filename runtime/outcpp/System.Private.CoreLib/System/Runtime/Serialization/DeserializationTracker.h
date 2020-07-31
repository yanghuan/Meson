#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace DeserializationTrackerNamespace {
CLASS(DeserializationTracker) : public Object::in {
  public: Boolean get_DeserializationInProgress() { return DeserializationInProgress; }
  public: void set_DeserializationInProgress(Boolean value) { DeserializationInProgress = value; }
  public: void Ctor();
  private: Boolean DeserializationInProgress;
};
} // namespace DeserializationTrackerNamespace
using DeserializationTracker = DeserializationTrackerNamespace::DeserializationTracker;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
