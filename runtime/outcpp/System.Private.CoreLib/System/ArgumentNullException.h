#pragma once

#include <rt/GCObject.h>
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
  public: void Ctor();
  public: void Ctor(String paramName);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String paramName, String message);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ArgumentNullExceptionNamespace
using ArgumentNullException = ArgumentNullExceptionNamespace::ArgumentNullException;
} // namespace System::Private::CoreLib::System
