#pragma once

#include <System.Private.CoreLib/System/MissingMemberException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MissingMethodExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(MissingMethodException) : public MissingMemberException::in {
  public: String get_Message();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String className, String methodName);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingMethodExceptionNamespace
using MissingMethodException = MissingMethodExceptionNamespace::MissingMethodException;
} // namespace System::Private::CoreLib::System
