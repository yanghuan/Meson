#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace TaskSchedulerExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(TaskSchedulerException) : public Exception::in {
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(Exception innerException);
  public: void ctor(String message, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TaskSchedulerExceptionNamespace
using TaskSchedulerException = TaskSchedulerExceptionNamespace::TaskSchedulerException;
} // namespace System::Private::CoreLib::System::Threading::Tasks
