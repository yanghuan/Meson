#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
enum class StreamingContextStates;
namespace StreamingContextNamespace {
struct StreamingContext {
  public: StreamingContextStates get_State();
  public: Object get_Context();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: Object _additionalContext;
  private: StreamingContextStates _state;
};
} // namespace StreamingContextNamespace
using StreamingContext = StreamingContextNamespace::StreamingContext;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
