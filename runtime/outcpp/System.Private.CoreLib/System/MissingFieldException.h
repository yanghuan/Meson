#pragma once

#include <System.Private.CoreLib/System/MissingMemberException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MissingFieldExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(MissingFieldException) : public MissingMemberException::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: String get_Message();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String className, String fieldName);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingFieldExceptionNamespace
using MissingFieldException = MissingFieldExceptionNamespace::MissingFieldException;
} // namespace System::Private::CoreLib::System
