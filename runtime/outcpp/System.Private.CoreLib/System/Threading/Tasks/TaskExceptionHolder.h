#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(AggregateException)
FORWARD(Exception)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskExceptionHolderNamespace {
using namespace Collections::Generic;
using namespace Collections::ObjectModel;
using namespace Runtime::ExceptionServices;
CLASS(TaskExceptionHolder) {
  public: Boolean get_ContainsFaultList();
  public: void Ctor(Task<> task);
  protected: void Finalize();
  public: void Add(Object exceptionObject, Boolean representsCancellation);
  private: void SetCancellationException(Object exceptionObject);
  private: void AddFaultException(Object exceptionObject);
  private: void MarkAsUnhandled();
  public: void MarkAsHandled(Boolean calledFromFinalizer);
  public: AggregateException CreateExceptionObject(Boolean calledFromFinalizer, Exception includeThisException);
  public: ReadOnlyCollection<ExceptionDispatchInfo> GetExceptionDispatchInfos();
  public: ExceptionDispatchInfo GetCancellationExceptionDispatchInfo();
  private: Task<> m_task;
  private: List<ExceptionDispatchInfo> m_faultExceptions;
  private: ExceptionDispatchInfo m_cancellationException;
  private: Boolean m_isHandled;
};
} // namespace TaskExceptionHolderNamespace
using TaskExceptionHolder = TaskExceptionHolderNamespace::TaskExceptionHolder;
} // namespace System::Private::CoreLib::System::Threading::Tasks
