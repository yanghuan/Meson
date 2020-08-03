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
using namespace Serialization;
CLASS(SwitchExpressionException) : public InvalidOperationException::in {
  public: Object get_UnmatchedValue() { return UnmatchedValue; }
  public: String get_Message();
  public: void Ctor();
  public: void Ctor(Exception innerException);
  public: void Ctor(Object unmatchedValue);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Object UnmatchedValue;
};
} // namespace SwitchExpressionExceptionNamespace
using SwitchExpressionException = SwitchExpressionExceptionNamespace::SwitchExpressionException;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
