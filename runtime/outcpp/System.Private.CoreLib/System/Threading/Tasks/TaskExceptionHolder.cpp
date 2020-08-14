#include "TaskExceptionHolder-dep.h"

#include <System.Private.CoreLib/System/AggregateException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskExceptionHolder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/UnobservedTaskExceptionEventArgs-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskExceptionHolderNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::ExceptionServices;

Boolean TaskExceptionHolder___::get_ContainsFaultList() {
  return m_faultExceptions != nullptr;
}

void TaskExceptionHolder___::ctor(Task<> task) {
  m_task = task;
}

void TaskExceptionHolder___::Finalize() {
  if (m_faultExceptions != nullptr && !m_isHandled) {
    AggregateException exception = rt::newobj<AggregateException>(SR::get_TaskExceptionHolder_UnhandledException(), m_faultExceptions);
    UnobservedTaskExceptionEventArgs ueea = rt::newobj<UnobservedTaskExceptionEventArgs>(exception);
    TaskScheduler::in::PublishUnobservedTaskException(m_task, ueea);
  }
}

void TaskExceptionHolder___::Add(Object exceptionObject, Boolean representsCancellation) {
  if (representsCancellation) {
    SetCancellationException(exceptionObject);
  } else {
    AddFaultException(exceptionObject);
  }
}

void TaskExceptionHolder___::SetCancellationException(Object exceptionObject) {
  OperationCanceledException ex = rt::as<OperationCanceledException>(exceptionObject);
  if (ex == nullptr) {
    ExceptionDispatchInfo exceptionDispatchInfo = m_cancellationException = (rt::as<ExceptionDispatchInfo>(exceptionObject));
  } else {
    m_cancellationException = ExceptionDispatchInfo::in::Capture(ex);
  }
  MarkAsHandled(false);
}

void TaskExceptionHolder___::AddFaultException(Object exceptionObject) {
  List<ExceptionDispatchInfo> list = m_faultExceptions;
  if (list == nullptr) {
    list = (m_faultExceptions = rt::newobj<List<ExceptionDispatchInfo>>(1));
  }
  Exception ex = rt::as<Exception>(exceptionObject);
  if (ex != nullptr) {
    list->Add(ExceptionDispatchInfo::in::Capture(ex));
  } else {
    ExceptionDispatchInfo exceptionDispatchInfo = rt::as<ExceptionDispatchInfo>(exceptionObject);
    if (exceptionDispatchInfo != nullptr) {
      list->Add(exceptionDispatchInfo);
    } else {
      IEnumerable<Exception> enumerable = rt::as<IEnumerable<Exception>>(exceptionObject);
      if (enumerable != nullptr) {
      } else {
        IEnumerable<ExceptionDispatchInfo> enumerable2 = rt::as<IEnumerable<ExceptionDispatchInfo>>(exceptionObject);
        if (enumerable2 == nullptr) {
          rt::throw_exception<ArgumentException>(SR::get_TaskExceptionHolder_UnknownExceptionType(), "exceptionObject");
        }
        list->AddRange(enumerable2);
      }
    }
  }
  if (list->get_Count() > 0) {
    MarkAsUnhandled();
  }
}

void TaskExceptionHolder___::MarkAsUnhandled() {
  if (m_isHandled) {
    GC::ReRegisterForFinalize((TaskExceptionHolder)this);
    m_isHandled = false;
  }
}

void TaskExceptionHolder___::MarkAsHandled(Boolean calledFromFinalizer) {
  if (!m_isHandled) {
    if (!calledFromFinalizer) {
      GC::SuppressFinalize((TaskExceptionHolder)this);
    }
    m_isHandled = true;
  }
}

AggregateException TaskExceptionHolder___::CreateExceptionObject(Boolean calledFromFinalizer, Exception includeThisException) {
  List<ExceptionDispatchInfo> faultExceptions = m_faultExceptions;
  MarkAsHandled(calledFromFinalizer);
  if (includeThisException == nullptr) {
    return rt::newobj<AggregateException>(faultExceptions);
  }
  Array<Exception> array = rt::newarr<Array<Exception>>(faultExceptions->get_Count() + 1);
  for (Int32 i = 0; i < array->get_Length() - 1; i++) {
    array[i] = faultExceptions[i]->get_SourceException();
  }
}

ReadOnlyCollection<ExceptionDispatchInfo> TaskExceptionHolder___::GetExceptionDispatchInfos() {
  List<ExceptionDispatchInfo> faultExceptions = m_faultExceptions;
  MarkAsHandled(false);
  return rt::newobj<ReadOnlyCollection<ExceptionDispatchInfo>>(faultExceptions);
}

ExceptionDispatchInfo TaskExceptionHolder___::GetCancellationExceptionDispatchInfo() {
  return m_cancellationException;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskExceptionHolderNamespace
