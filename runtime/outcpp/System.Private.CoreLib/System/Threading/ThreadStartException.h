#pragma once

#include <rt/GCObject.h>
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
using namespace Runtime::Serialization;
CLASS(ThreadStartException) : public SystemException::in {
  public: void Ctor();
  public: void Ctor(Exception reason);
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ThreadStartExceptionNamespace
using ThreadStartException = ThreadStartExceptionNamespace::ThreadStartException;
} // namespace System::Private::CoreLib::System::Threading
