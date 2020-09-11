#include "AsyncMethodBuilderCore-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachineBox.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncMethodBuilderCoreNamespace {
using namespace System::Diagnostics::Tracing;
using namespace System::Reflection;
using namespace System::Text;
using namespace System::Threading::Tasks;

void AsyncMethodBuilderCore::ContinuationWrapper___::ctor(Action<> continuation, Action<Action<>, Task<>> invokeAction, Task<> innerTask) {
  _invokeAction = invokeAction;
  _continuation = continuation;
  _innerTask = innerTask;
}

void AsyncMethodBuilderCore::ContinuationWrapper___::Invoke() {
  _invokeAction(_continuation, _innerTask);
}

Boolean AsyncMethodBuilderCore::get_TrackAsyncMethodCompletion() {
  return TplEventSource::in::Log->IsEnabled(EventLevel::Warning, (EventKeywords)256);
}

void AsyncMethodBuilderCore::SetStateMachine(IAsyncStateMachine stateMachine, Task<> task) {
  if (stateMachine == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::stateMachine);
  }
  if (task != nullptr) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::AsyncMethodBuilder_InstanceNotInitialized);
  }
}

String AsyncMethodBuilderCore::GetAsyncStateMachineDescription(IAsyncStateMachine stateMachine) {
  Type type = stateMachine->GetType();
  Array<FieldInfo> fields = type->GetFields(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  stringBuilder->AppendLine(type->get_FullName());
  Array<FieldInfo> array = fields;
  for (FieldInfo&& fieldInfo : *array) {
    stringBuilder->Append((String)"    ")->Append(fieldInfo->get_Name())->Append((String)": ")->Append(fieldInfo->GetValue(stateMachine))->AppendLine();
  }
  return stringBuilder->ToString();
}

Action<> AsyncMethodBuilderCore::CreateContinuationWrapper(Action<> continuation, Action<Action<>, Task<>> invokeAction, Task<> innerTask) {
  return {rt::newobj<ContinuationWrapper>(continuation, invokeAction, innerTask), &ContinuationWrapper::in::Invoke};
}

Action<> AsyncMethodBuilderCore::TryGetStateMachineForDebugger(Action<> action) {
  Object target = action->get_Target();
  IAsyncStateMachineBox asyncStateMachineBox = rt::as<IAsyncStateMachineBox>(target);
  if (asyncStateMachineBox == nullptr) {
    ContinuationWrapper continuationWrapper = rt::as<ContinuationWrapper>(target);
    if (continuationWrapper == nullptr) {
      return action;
    }
    return TryGetStateMachineForDebugger(continuationWrapper->_continuation);
  }
  return {asyncStateMachineBox->GetStateMachineObject(), &IAsyncStateMachine::in::MoveNext};
}

Task<> AsyncMethodBuilderCore::TryGetContinuationTask(Action<> continuation) {
  ContinuationWrapper continuationWrapper = rt::as<ContinuationWrapper>(continuation->get_Target());
  if (continuationWrapper == nullptr) {
    return rt::as<Task<>>(continuation->get_Target());
  }
  return continuationWrapper->_innerTask;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncMethodBuilderCoreNamespace
