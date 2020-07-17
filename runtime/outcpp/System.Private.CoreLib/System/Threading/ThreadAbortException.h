#pragma once

#include <rt/GCObject.h>

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
CLASS(ThreadAbortException) {
  public: Object get_ExceptionState();
  public: void Ctor();
  private: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace ThreadAbortExceptionNamespace
using ThreadAbortException = ThreadAbortExceptionNamespace::ThreadAbortException;
} // namespace System::Private::CoreLib::System::Threading
