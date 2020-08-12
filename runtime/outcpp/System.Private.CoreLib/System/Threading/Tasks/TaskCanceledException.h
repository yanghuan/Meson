#pragma once

#include <System.Private.CoreLib/System/OperationCanceledException.h>

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
using namespace System::Runtime::Serialization;
CLASS(TaskCanceledException) : public OperationCanceledException::in {
  public: Task<> get_Task();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String message, Exception innerException, CancellationToken token);
  public: void ctor(Task<> task);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  private: Task<> _canceledTask;
};
} // namespace TaskCanceledExceptionNamespace
using TaskCanceledException = TaskCanceledExceptionNamespace::TaskCanceledException;
} // namespace System::Private::CoreLib::System::Threading::Tasks
