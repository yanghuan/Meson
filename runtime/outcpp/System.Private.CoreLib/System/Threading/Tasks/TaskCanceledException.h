#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskCanceledExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(TaskCanceledException) {
  public: Task<> get_Task();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, Exception innerException, CancellationToken token);
  public: void Ctor(Task<> task);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  private: Task<> _canceledTask;
};
} // namespace TaskCanceledExceptionNamespace
using TaskCanceledException = TaskCanceledExceptionNamespace::TaskCanceledException;
} // namespace System::Private::CoreLib::System::Threading::Tasks
