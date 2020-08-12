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
namespace EndOfStreamExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(EndOfStreamException) : public IOException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace EndOfStreamExceptionNamespace
using EndOfStreamException = EndOfStreamExceptionNamespace::EndOfStreamException;
} // namespace System::Private::CoreLib::System::IO
