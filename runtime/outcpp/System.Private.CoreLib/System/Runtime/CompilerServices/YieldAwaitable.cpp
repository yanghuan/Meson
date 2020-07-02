#include "YieldAwaitable-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/YieldAwaitable-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace {
Boolean YieldAwaitable::YieldAwaiter::get_IsCompleted() {
  return Boolean();
};
void YieldAwaitable::YieldAwaiter::OnCompleted(Action<> continuation) {
  return void();
};
void YieldAwaitable::YieldAwaiter::UnsafeOnCompleted(Action<> continuation) {
  return void();
};
void YieldAwaitable::YieldAwaiter::QueueContinuation(Action<> continuation, Boolean flowContext) {
  return void();
};
Action<> YieldAwaitable::YieldAwaiter::OutputCorrelationEtwEvent(Action<> continuation) {
  return nullptr;
};
void YieldAwaitable::YieldAwaiter::RunAction(Object state) {
  return void();
};
void YieldAwaitable::YieldAwaiter::GetResult() {
  return void();
};
YieldAwaitable::YieldAwaiter YieldAwaitable::GetAwaiter() {
  return YieldAwaitable::YieldAwaiter();
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::YieldAwaitableNamespace
