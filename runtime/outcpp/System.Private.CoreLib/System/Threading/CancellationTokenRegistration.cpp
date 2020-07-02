#include "CancellationTokenRegistration-dep.h"

namespace System::Private::CoreLib::System::Threading::CancellationTokenRegistrationNamespace {
CancellationToken CancellationTokenRegistration::get_Token() {
  return CancellationToken();
};
void CancellationTokenRegistration::Dispose() {
  return void();
};
ValueTask<> CancellationTokenRegistration::DisposeAsync() {
  return ValueTask<>();
};
Boolean CancellationTokenRegistration::Unregister() {
  return Boolean();
};
void CancellationTokenRegistration::WaitForCallbackIfNecessary() {
  return void();
};
ValueTask<> CancellationTokenRegistration::WaitForCallbackIfNecessaryAsync() {
  return ValueTask<>();
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
