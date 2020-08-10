#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
namespace ThreadAbortExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ThreadAbortException) : public SystemException::in {
  public: Object get_ExceptionState();
  public: void ctor();
  private: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ThreadAbortExceptionNamespace
using ThreadAbortException = ThreadAbortExceptionNamespace::ThreadAbortException;
} // namespace System::Private::CoreLib::System::Threading
