#pragma once

#include <System.Private.CoreLib/System/MemberAccessException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MethodAccessExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MethodAccessException) : public MemberAccessException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MethodAccessExceptionNamespace
using MethodAccessException = MethodAccessExceptionNamespace::MethodAccessException;
} // namespace System::Private::CoreLib::System
