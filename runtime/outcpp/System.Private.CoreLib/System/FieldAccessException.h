#pragma once

#include <System.Private.CoreLib/System/MemberAccessException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace FieldAccessExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(FieldAccessException) : public MemberAccessException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace FieldAccessExceptionNamespace
using FieldAccessException = FieldAccessExceptionNamespace::FieldAccessException;
} // namespace System::Private::CoreLib::System
