#include "ExecutionContext-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocalValueMap-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace {
using namespace System::Runtime::ExceptionServices;

Boolean ExecutionContext___::get_HasChangeNotifications() {
  return m_localChangeNotifications != nullptr;
}

Boolean ExecutionContext___::get_IsDefault() {
  return m_isDefault;
}

void ExecutionContext___::ctor(Boolean isDefault) {
  m_isDefault = isDefault;
}

void ExecutionContext___::ctor(IAsyncLocalValueMap localValues, Array<IAsyncLocal> localChangeNotifications, Boolean isFlowSuppressed) {
  m_localValues = localValues;
  m_localChangeNotifications = localChangeNotifications;
  m_isFlowSuppressed = isFlowSuppressed;
}

void ExecutionContext___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

ExecutionContext ExecutionContext___::Capture() {
  ExecutionContext executionContext = Thread::in::get_CurrentThread()->_executionContext;
  if (executionContext == nullptr) {
    executionContext = Default;
  } else if (executionContext->m_isFlowSuppressed) {
    executionContext = nullptr;
  }

  return executionContext;
}

ExecutionContext ExecutionContext___::ShallowClone(Boolean isFlowSuppressed) {
  if (m_localValues == nullptr || AsyncLocalValueMap::IsEmpty(m_localValues)) {
    if (!isFlowSuppressed) {
      return nullptr;
    }
    return DefaultFlowSuppressed;
  }
  return rt::newobj<ExecutionContext>(m_localValues, m_localChangeNotifications, isFlowSuppressed);
}

AsyncFlowControl ExecutionContext___::SuppressFlow() {
  Thread currentThread = Thread::in::get_CurrentThread();
  ExecutionContext as = currentThread->_executionContext;
  ExecutionContext executionContext = as != nullptr ? as : Default;
  if (executionContext->m_isFlowSuppressed) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotSupressFlowMultipleTimes());
  }
  executionContext = executionContext->ShallowClone(true);
  AsyncFlowControl result = AsyncFlowControl();
  currentThread->_executionContext = executionContext;
  result.Initialize(currentThread);
  return result;
}

void ExecutionContext___::RestoreFlow() {
  Thread currentThread = Thread::in::get_CurrentThread();
  ExecutionContext executionContext = currentThread->_executionContext;
  if (executionContext == nullptr || !executionContext->m_isFlowSuppressed) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CannotRestoreUnsupressedFlow());
  }
  currentThread->_executionContext = executionContext->ShallowClone(false);
}

Boolean ExecutionContext___::IsFlowSuppressed() {
  ExecutionContext executionContext = Thread::in::get_CurrentThread()->_executionContext;
  if (executionContext != nullptr) {
    return executionContext->m_isFlowSuppressed;
  }
  return false;
}

void ExecutionContext___::Run(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  if (executionContext == nullptr) {
    ThrowNullContext();
  }
  RunInternal(executionContext, callback, state);
}

void ExecutionContext___::RunInternal(ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  Thread currentThread = Thread::in::get_CurrentThread();
  Thread thread = currentThread;
  ExecutionContext executionContext2 = currentThread->_executionContext;
  if (executionContext2 != nullptr && executionContext2->m_isDefault) {
    executionContext2 = nullptr;
  }
  ExecutionContext executionContext3 = executionContext2;
  SynchronizationContext synchronizationContext = currentThread->_synchronizationContext;
  if (executionContext != nullptr && executionContext->m_isDefault) {
    executionContext = nullptr;
  }
  if (executionContext2 != executionContext) {
    RestoreChangedContextToThread(currentThread, executionContext, executionContext2);
  }
  ExceptionDispatchInfo exceptionDispatchInfo = nullptr;
  try {
    callback(state);
  } catch (Exception source) {
  }
  SynchronizationContext synchronizationContext2 = synchronizationContext;
  Thread thread2 = thread;
  if (thread2->_synchronizationContext != synchronizationContext2) {
    thread2->_synchronizationContext = synchronizationContext2;
  }
  ExecutionContext executionContext4 = executionContext3;
  ExecutionContext executionContext5 = thread2->_executionContext;
  if (executionContext5 != executionContext4) {
    RestoreChangedContextToThread(thread2, executionContext4, executionContext5);
  }
  if (exceptionDispatchInfo != nullptr) {
    exceptionDispatchInfo->Throw();
  }
}

void ExecutionContext___::RunFromThreadPoolDispatchLoop(Thread threadPoolThread, ExecutionContext executionContext, ContextCallback<> callback, Object state) {
  if (executionContext != nullptr && !executionContext->m_isDefault) {
    RestoreChangedContextToThread(threadPoolThread, executionContext, nullptr);
  }
  ExceptionDispatchInfo exceptionDispatchInfo = nullptr;
  try {
    callback(state);
  } catch (Exception source) {
  }
  ExecutionContext executionContext2 = threadPoolThread->_executionContext;
  threadPoolThread->_synchronizationContext = nullptr;
  if (executionContext2 != nullptr) {
    RestoreChangedContextToThread(threadPoolThread, nullptr, executionContext2);
  }
  if (exceptionDispatchInfo != nullptr) {
    exceptionDispatchInfo->Throw();
  }
}

void ExecutionContext___::RestoreChangedContextToThread(Thread currentThread, ExecutionContext contextToRestore, ExecutionContext currentContext) {
  currentThread->_executionContext = contextToRestore;
  if ((currentContext != nullptr && currentContext->get_HasChangeNotifications()) || (contextToRestore != nullptr && contextToRestore->get_HasChangeNotifications())) {
    OnValuesChanged(currentContext, contextToRestore);
  }
}

void ExecutionContext___::ResetThreadPoolThread(Thread currentThread) {
  ExecutionContext executionContext = currentThread->_executionContext;
  currentThread->_synchronizationContext = nullptr;
  currentThread->_executionContext = nullptr;
  if (executionContext != nullptr && executionContext->get_HasChangeNotifications()) {
    OnValuesChanged(executionContext, nullptr);
    currentThread->_synchronizationContext = nullptr;
    currentThread->_executionContext = nullptr;
  }
}

void ExecutionContext___::OnValuesChanged(ExecutionContext previousExecutionCtx, ExecutionContext nextExecutionCtx) {
  Array<IAsyncLocal> array = (previousExecutionCtx != nullptr) ? previousExecutionCtx->m_localChangeNotifications : nullptr;
  Array<IAsyncLocal> array2 = (nextExecutionCtx != nullptr) ? nextExecutionCtx->m_localChangeNotifications : nullptr;
  try {
    if (array != nullptr && array2 != nullptr) {
      Array<IAsyncLocal> array3 = array;
    }
    if (array != nullptr) {
      Array<IAsyncLocal> array5 = array;
    }
    Array<IAsyncLocal> array6 = array2;
  } catch (Exception exception) {
  }
}

void ExecutionContext___::ThrowNullContext() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NullContext());
}

Object ExecutionContext___::GetLocalValue(IAsyncLocal local) {
  ExecutionContext executionContext = Thread::in::get_CurrentThread()->_executionContext;
  if (executionContext == nullptr) {
    return nullptr;
  }
  Object value;
  executionContext->m_localValues->TryGetValue(local, value);
  return value;
}

void ExecutionContext___::SetLocalValue(IAsyncLocal local, Object newValue, Boolean needChangeNotifications) {
  ExecutionContext executionContext = Thread::in::get_CurrentThread()->_executionContext;
  Object value = nullptr;
  Boolean flag = false;
  if (executionContext != nullptr) {
    flag = executionContext->m_localValues->TryGetValue(local, value);
  }
  if (value == newValue) {
    return;
  }
  Array<IAsyncLocal> array = nullptr;
  Boolean flag2 = false;
  IAsyncLocalValueMap asyncLocalValueMap;
  if (executionContext != nullptr) {
    flag2 = executionContext->m_isFlowSuppressed;
    asyncLocalValueMap = executionContext->m_localValues->Set(local, newValue, !needChangeNotifications);
    array = executionContext->m_localChangeNotifications;
  } else {
    asyncLocalValueMap = AsyncLocalValueMap::Create(local, newValue, !needChangeNotifications);
  }
  if (needChangeNotifications && !flag) {
    if (array == nullptr) {
      array = rt::newarr<Array<IAsyncLocal>>(1);
    } else {
      Int32 num = array->get_Length();
      Array<>::in::Resize(array, num + 1);
      array[num] = local;
    }
  }
  Thread::in::get_CurrentThread()->_executionContext = ((!flag2 && AsyncLocalValueMap::IsEmpty(asyncLocalValueMap)) ? nullptr : rt::newobj<ExecutionContext>(asyncLocalValueMap, array, flag2));
  if (needChangeNotifications) {
    local->OnValueChanged(value, newValue, false);
  }
}

ExecutionContext ExecutionContext___::CreateCopy() {
  return (ExecutionContext)this;
}

void ExecutionContext___::Dispose() {
}

void ExecutionContext___::cctor() {
  Default = rt::newobj<ExecutionContext>(true);
  DefaultFlowSuppressed = rt::newobj<ExecutionContext>(AsyncLocalValueMap::get_Empty(), Array<>::in::Empty<IAsyncLocal>(), true);
}

} // namespace System::Private::CoreLib::System::Threading::ExecutionContextNamespace
