#include "AppContext-dep.h"

namespace System::Private::CoreLib::System::AppContextNamespace {
String AppContext::get_BaseDirectory() {
  return nullptr;
};
String AppContext::get_TargetFrameworkName() {
  return nullptr;
};
void AppContext::Setup(Char** pNames, Char** pValues, Int32 count) {
  return void();
};
String AppContext::GetBaseDirectoryCore() {
  return nullptr;
};
Object AppContext::GetData(String name) {
  return nullptr;
};
void AppContext::SetData(String name, Object data) {
  return void();
};
void AppContext::OnProcessExit() {
  return void();
};
Boolean AppContext::TryGetSwitch(String switchName, Boolean& isEnabled) {
  return Boolean();
};
void AppContext::SetSwitch(String switchName, Boolean isEnabled) {
  return void();
};
} // namespace System::Private::CoreLib::System::AppContextNamespace
