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
namespace TargetParameterCountExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TargetParameterCountException) : public ApplicationException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TargetParameterCountExceptionNamespace
using TargetParameterCountException = TargetParameterCountExceptionNamespace::TargetParameterCountException;
} // namespace System::Private::CoreLib::System::Reflection
