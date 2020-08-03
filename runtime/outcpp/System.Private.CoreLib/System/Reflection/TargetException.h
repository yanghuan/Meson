#pragma once

#include <System.Private.CoreLib/System/ApplicationException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace TargetExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(TargetException) : public ApplicationException::in {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TargetExceptionNamespace
using TargetException = TargetExceptionNamespace::TargetException;
} // namespace System::Private::CoreLib::System::Reflection
