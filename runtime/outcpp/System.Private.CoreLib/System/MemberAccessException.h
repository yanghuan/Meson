#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MemberAccessExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MemberAccessException) : public SystemException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MemberAccessExceptionNamespace
using MemberAccessException = MemberAccessExceptionNamespace::MemberAccessException;
} // namespace System::Private::CoreLib::System
