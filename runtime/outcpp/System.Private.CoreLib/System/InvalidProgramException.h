#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace InvalidProgramExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(InvalidProgramException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace InvalidProgramExceptionNamespace
using InvalidProgramException = InvalidProgramExceptionNamespace::InvalidProgramException;
} // namespace System::Private::CoreLib::System
