#include "YieldAwaitable-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/YieldAwaitable-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace {
Boolean YieldAwaitable::YieldAwaiter::get_IsCompleted() {
  return Boolean();
}

void YieldAwaitable::YieldAwaiter::OnCompleted(Action<> continuation) {
}

void YieldAwaitable::YieldAwaiter::UnsafeOnCompleted(Action<> continuation) {
}

void YieldAwaitable::YieldAwaiter::QueueContinuation(Action<> continuation, Boolean flowContext) {
}

Action<> YieldAwaitable::YieldAwaiter::OutputCorrelationEtwEvent(Action<> continuation) {
  return nullptr;
}

void YieldAwaitable::YieldAwaiter::RunAction(Object state) {
}

void YieldAwaitable::YieldAwaiter::GetResult() {
}

void YieldAwaitable::YieldAwaiter::SCtor() {
}

YieldAwaitable::YieldAwaiter YieldAwaitable::GetAwaiter() {
  return YieldAwaitable::YieldAwaiter();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace
