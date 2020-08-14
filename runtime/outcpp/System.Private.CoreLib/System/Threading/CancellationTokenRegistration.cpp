#include "CancellationTokenRegistration-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenSource-dep.h>

namespace System::Private::CoreLib::System::Threading::CancellationTokenRegistrationNamespace {
CancellationToken CancellationTokenRegistration::get_Token() {
  CancellationTokenSource::in::CallbackNode node = _node;
  if (node == nullptr) {
    return CancellationToken();
  }
  return CancellationToken(node->Partition->Source);
}

CancellationTokenRegistration::CancellationTokenRegistration(Int64 id, Object/*CancellationTokenSource.CallbackNode*/ node) {
  _id = id;
  _node = node;
}

void CancellationTokenRegistration::Dispose() {
  CancellationTokenSource::in::CallbackNode node = _node;
  if (node != nullptr && !node->Partition->Unregister(_id, node)) {
    WaitForCallbackIfNecessary();
  }
}

ValueTask<> CancellationTokenRegistration::DisposeAsync() {
  CancellationTokenSource::in::CallbackNode node = _node;
  if (node == nullptr || node->Partition->Unregister(_id, node)) {
    return ValueTask();
  }
  return WaitForCallbackIfNecessaryAsync();
}

Boolean CancellationTokenRegistration::Unregister() {
  CancellationTokenSource::in::CallbackNode node = _node;
}

void CancellationTokenRegistration::WaitForCallbackIfNecessary() {
  CancellationTokenSource source = _node->Partition->Source;
  if (source->get_IsCancellationRequested() && !source->get_IsCancellationCompleted() && source->get_ThreadIDExecutingCallbacks() != Environment::get_CurrentManagedThreadId()) {
    source->WaitForCallbackToComplete(_id);
  }
}

ValueTask<> CancellationTokenRegistration::WaitForCallbackIfNecessaryAsync() {
  CancellationTokenSource source = _node->Partition->Source;
  if (source->get_IsCancellationRequested() && !source->get_IsCancellationCompleted() && source->get_ThreadIDExecutingCallbacks() != Environment::get_CurrentManagedThreadId()) {
    return source->WaitForCallbackToCompleteAsync(_id);
  }
  return ValueTask();
}

Boolean CancellationTokenRegistration::op_Equality(CancellationTokenRegistration left, CancellationTokenRegistration right) {
  return left.Equals(right);
}

Boolean CancellationTokenRegistration::op_Inequality(CancellationTokenRegistration left, CancellationTokenRegistration right) {
  return !left.Equals(right);
}

Boolean CancellationTokenRegistration::Equals(Object obj) {
  if (rt::is<CancellationTokenRegistration>(obj)) {
    return Equals((CancellationTokenRegistration)obj);
  }
  return false;
}

Boolean CancellationTokenRegistration::Equals(CancellationTokenRegistration other) {
  if (_node == other._node) {
    return _id == other._id;
  }
  return false;
}

Int32 CancellationTokenRegistration::GetHashCode() {
  if (_node == nullptr) {
    return _id.GetHashCode();
  }
}

} // namespace System::Private::CoreLib::System::Threading::CancellationTokenRegistrationNamespace
