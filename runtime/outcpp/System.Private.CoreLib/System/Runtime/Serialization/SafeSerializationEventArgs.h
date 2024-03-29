#pragma once

#include <System.Private.CoreLib/System/EventArgs.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/StreamingContext.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISafeSerializationData)
namespace SafeSerializationEventArgsNamespace {
CLASS(SafeSerializationEventArgs) : public EventArgs::in {
  public: StreamingContext get_StreamingContext() { return StreamingContext; }
  public: void AddSerializedState(ISafeSerializationData serializedState);
  private: StreamingContext StreamingContext;
};
} // namespace SafeSerializationEventArgsNamespace
using SafeSerializationEventArgs = SafeSerializationEventArgsNamespace::SafeSerializationEventArgs;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
