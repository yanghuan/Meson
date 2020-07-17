#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace TaskSchedulerExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(TaskSchedulerException) {
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(Exception innerException);
  public: void Ctor(String message, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
};
} // namespace TaskSchedulerExceptionNamespace
using TaskSchedulerException = TaskSchedulerExceptionNamespace::TaskSchedulerException;
} // namespace System::Private::CoreLib::System::Threading::Tasks
