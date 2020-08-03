#pragma once

#include <System.Private.CoreLib/System/MissingMemberException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MissingFieldExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingFieldException) : public MissingMemberException::in {
  public: String get_Message();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String className, String fieldName);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingFieldExceptionNamespace
using MissingFieldException = MissingFieldExceptionNamespace::MissingFieldException;
} // namespace System::Private::CoreLib::System
