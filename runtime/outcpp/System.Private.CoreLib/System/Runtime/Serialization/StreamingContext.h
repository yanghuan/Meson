#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
enum class StreamingContextStates;
namespace StreamingContextNamespace {
struct StreamingContext {
  public: StreamingContextStates get_State();
  public: Object get_Context();
  public: void Ctor(StreamingContextStates state);
  public: void Ctor(StreamingContextStates state, Object additional);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
  private: Object _additionalContext;
  private: StreamingContextStates _state;
};
} // namespace StreamingContextNamespace
using StreamingContext = StreamingContextNamespace::StreamingContext;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
