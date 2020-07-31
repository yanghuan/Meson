#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MissingMemberException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace MissingMethodExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingMethodException) : public MissingMemberException::in {
  public: String get_Message();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String className, String methodName);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace MissingMethodExceptionNamespace
using MissingMethodException = MissingMethodExceptionNamespace::MissingMethodException;
} // namespace System::Private::CoreLib::System
