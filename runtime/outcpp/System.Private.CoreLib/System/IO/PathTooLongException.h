#pragma once

#include <System.Private.CoreLib/System/IO/IOException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::IO {
namespace PathTooLongExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(PathTooLongException) : public IOException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace PathTooLongExceptionNamespace
using PathTooLongException = PathTooLongExceptionNamespace::PathTooLongException;
} // namespace System::Private::CoreLib::System::IO
