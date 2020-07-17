#include "CancellationTokenRegistration-dep.h"

namespace System::Private::CoreLib::System::Threading::CancellationTokenRegistrationNamespace {
CancellationToken CancellationTokenRegistration::get_Token() {
  return CancellationToken();
};

void CancellationTokenRegistration::Ctor(Int64 id, Object/*CancellationTokenSource.CallbackNode*/ node) {
};

void CancellationTokenRegistration::Dispose() {
};

ValueTask<> CancellationTokenRegistration::DisposeAsync() {
  return ValueTask<>();
};

Boolean CancellationTokenRegistration::Unregister() {
  return Boolean();
};

void CancellationTokenRegistration::WaitForCallbackIfNecessary() {
};

ValueTask<> CancellationTokenRegistration::WaitForCallbackIfNecessaryAsync() {
  return ValueTask<>();
};

Boolean CancellationTokenRegistration::op_Equality(CancellationTokenRegistration left, CancellationTokenRegistration right) {
  return Boolean();
};

Boolean CancellationTokenRegistration::op_Inequality(CancellationTokenRegistration left, CancellationTokenRegistration right) {
  return Boolean();
};

Boolean CancellationTokenRegistration::Equals(Object obj) {
  return Boolean();
};

Boolean CancellationTokenRegistration::Equals(CancellationTokenRegistration other) {
  return Boolean();
};

Int32 CancellationTokenRegistration::GetHashCode() {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Threading::CancellationTokenRegistrationNamespace
