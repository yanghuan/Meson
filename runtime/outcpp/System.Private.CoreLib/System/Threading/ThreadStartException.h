#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
namespace ThreadStartExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ThreadStartException) : public SystemException::in {
  public: void ctor();
  public: void ctor(Exception reason);
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ThreadStartExceptionNamespace
using ThreadStartException = ThreadStartExceptionNamespace::ThreadStartException;
} // namespace System::Private::CoreLib::System::Threading
