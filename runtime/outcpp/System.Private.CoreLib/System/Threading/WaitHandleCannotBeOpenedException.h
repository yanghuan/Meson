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
namespace System::Private::CoreLib::System::Threading {
namespace WaitHandleCannotBeOpenedExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(WaitHandleCannotBeOpenedException) : public ApplicationException::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace WaitHandleCannotBeOpenedExceptionNamespace
using WaitHandleCannotBeOpenedException = WaitHandleCannotBeOpenedExceptionNamespace::WaitHandleCannotBeOpenedException;
} // namespace System::Private::CoreLib::System::Threading
