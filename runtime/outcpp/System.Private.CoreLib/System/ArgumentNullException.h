#pragma once

#include <System.Private.CoreLib/System/ArgumentException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace ArgumentNullExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ArgumentNullException) : public ArgumentException::in {
  public: void ctor();
  public: void ctor(String paramName);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String paramName, String message);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ArgumentNullExceptionNamespace
using ArgumentNullException = ArgumentNullExceptionNamespace::ArgumentNullException;
} // namespace System::Private::CoreLib::System
