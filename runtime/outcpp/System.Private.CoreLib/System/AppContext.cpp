#include "AppContext-dep.h"

namespace System::Private::CoreLib::System::AppContextNamespace {
String AppContext::get_BaseDirectory() {
  return nullptr;
};
String AppContext::get_TargetFrameworkName() {
  return nullptr;
};
Object AppContext::GetData(String name) {
  return nullptr;
};
void AppContext::SetData(String name, Object data) {
};
void AppContext::OnProcessExit() {
};
Boolean AppContext::TryGetSwitch(String switchName, Boolean& isEnabled) {
  return Boolean();
};
void AppContext::SetSwitch(String switchName, Boolean isEnabled) {
};
void AppContext::Setup(Char** pNames, Char** pValues, Int32 count) {
};
String AppContext::GetBaseDirectoryCore() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::AppContextNamespace
