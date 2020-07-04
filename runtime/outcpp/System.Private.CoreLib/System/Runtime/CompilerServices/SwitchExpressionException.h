#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SwitchExpressionExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(SwitchExpressionException) {
  public: Object get_UnmatchedValue() { return UnmatchedValue; }
  public: String get_Message();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object UnmatchedValue;
};
} // namespace SwitchExpressionExceptionNamespace
using SwitchExpressionException = SwitchExpressionExceptionNamespace::SwitchExpressionException;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
