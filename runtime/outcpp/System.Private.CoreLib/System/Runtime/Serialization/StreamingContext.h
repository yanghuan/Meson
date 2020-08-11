#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
enum class StreamingContextStates : int32_t;
namespace StreamingContextNamespace {
struct StreamingContext : public valueType<StreamingContext> {
  public: StreamingContextStates get_State();
  public: Object get_Context();
  public: explicit StreamingContext(StreamingContextStates state);
  public: explicit StreamingContext(StreamingContextStates state, Object additional);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: explicit StreamingContext() {}
  private: Object _additionalContext;
  private: StreamingContextStates _state;
};
} // namespace StreamingContextNamespace
using StreamingContext = StreamingContextNamespace::StreamingContext;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
