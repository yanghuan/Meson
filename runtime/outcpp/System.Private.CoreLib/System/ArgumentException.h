#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ArgumentExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ArgumentException) : public SystemException::in {
  public: String get_Message();
  public: String get_ParamName();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String message, String paramName, Exception innerException);
  public: void ctor(String message, String paramName);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: void SetMessageField();
  private: String _paramName;
};
} // namespace ArgumentExceptionNamespace
using ArgumentException = ArgumentExceptionNamespace::ArgumentException;
} // namespace System::Private::CoreLib::System
