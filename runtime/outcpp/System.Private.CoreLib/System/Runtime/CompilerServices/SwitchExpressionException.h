#pragma once

#include <System.Private.CoreLib/System/InvalidOperationException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SwitchExpressionExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(SwitchExpressionException) : public InvalidOperationException::in {
  public: Object get_UnmatchedValue() { return UnmatchedValue; }
  public: String get_Message();
  public: void ctor();
  public: void ctor(Exception innerException);
  public: void ctor(Object unmatchedValue);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object UnmatchedValue;
};
} // namespace SwitchExpressionExceptionNamespace
using SwitchExpressionException = SwitchExpressionExceptionNamespace::SwitchExpressionException;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
