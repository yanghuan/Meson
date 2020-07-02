#include "Environment-dep.h"

namespace System::Private::CoreLib::System::EnvironmentNamespace {
String Environment::WinRTFolderPaths::GetFolderPath(SpecialFolder folder, SpecialFolderOption option) {
  return nullptr;
};
Boolean Environment::WindowsVersion::GetIsWindows8OrAbove() {
  return Boolean();
};
Int32 Environment::get_CurrentManagedThreadId() {
  return Int32();
};
Boolean Environment::get_HasShutdownStarted() {
  return Boolean();
};
Int32 Environment::get_ProcessorCount() {
  return Int32();
};
String Environment::get_StackTrace() {
  return nullptr;
};
Boolean Environment::get_IsWinRTSupported() {
  return Boolean();
};
String Environment::get_CommandLine() {
  return nullptr;
};
String Environment::get_CurrentDirectory() {
  return nullptr;
};
void Environment::set_CurrentDirectory(String value) {
  return void();
};
Boolean Environment::get_Is64BitProcess() {
  return Boolean();
};
Boolean Environment::get_Is64BitOperatingSystem() {
  return Boolean();
};
OperatingSystem Environment::get_OSVersion() {
  return nullptr;
};
Boolean Environment::get_UserInteractive() {
  return Boolean();
};
Version Environment::get_Version() {
  return nullptr;
};
String Environment::get_CurrentDirectoryCore() {
  return nullptr;
};
void Environment::set_CurrentDirectoryCore(String value) {
  return void();
};
String Environment::get_NewLine() {
  return nullptr;
};
Int32 Environment::get_SystemPageSize() {
  return Int32();
};
Boolean Environment::get_Is64BitOperatingSystemWhen32BitProcess() {
  return Boolean();
};
String Environment::get_MachineName() {
  return nullptr;
};
String Environment::get_SystemDirectory() {
  return nullptr;
};
Int64 Environment::get_WorkingSet() {
  return Int64();
};
Boolean Environment::get_IsWindows8OrAbove() {
  return Boolean();
};
String Environment::get_UserName() {
  return nullptr;
};
String Environment::get_UserDomainName() {
  return nullptr;
};
void Environment::Exit(Int32 exitCode) {
  return void();
};
Array<String> Environment::GetCommandLineArgs() {
  return Array<String>();
};
String Environment::GetResourceStringLocal(String key) {
  return nullptr;
};
String Environment::GetEnvironmentVariable(String variable) {
  return nullptr;
};
String Environment::GetEnvironmentVariable(String variable, EnvironmentVariableTarget target) {
  return nullptr;
};
IDictionary Environment::GetEnvironmentVariables(EnvironmentVariableTarget target) {
  return nullptr;
};
void Environment::SetEnvironmentVariable(String variable, String value) {
  return void();
};
void Environment::SetEnvironmentVariable(String variable, String value, EnvironmentVariableTarget target) {
  return void();
};
String Environment::ExpandEnvironmentVariables(String name) {
  return nullptr;
};
void Environment::SetCommandLineArgs(Array<String> cmdLineArgs) {
  return void();
};
String Environment::GetFolderPath(SpecialFolder folder) {
  return nullptr;
};
String Environment::GetFolderPath(SpecialFolder folder, SpecialFolderOption option) {
  return nullptr;
};
Boolean Environment::ValidateAndConvertRegistryTarget(EnvironmentVariableTarget target) {
  return Boolean();
};
void Environment::ValidateVariableAndValue(String variable, String& value) {
  return void();
};
Array<String> Environment::GetLogicalDrives() {
  return Array<String>();
};
String Environment::ExpandEnvironmentVariablesCore(String name) {
  return nullptr;
};
OperatingSystem Environment::GetOSVersion() {
  return nullptr;
};
String Environment::GetEnvironmentVariableFromRegistry(String variable, Boolean fromMachine) {
  return nullptr;
};
void Environment::SetEnvironmentVariableFromRegistry(String variable, String value, Boolean fromMachine) {
  return void();
};
IDictionary Environment::GetEnvironmentVariablesFromRegistry(Boolean fromMachine) {
  return nullptr;
};
RegistryKey Environment::OpenEnvironmentKeyIfExists(Boolean fromMachine, Boolean writable) {
  return nullptr;
};
void Environment::GetUserName(ValueStringBuilder& builder) {
  return void();
};
String Environment::GetFolderPathCore(SpecialFolder folder, SpecialFolderOption option) {
  return nullptr;
};
String Environment::GetKnownFolderPath(String folderGuid, SpecialFolderOption option) {
  return nullptr;
};
String Environment::GetEnvironmentVariableCore(String variable) {
  return nullptr;
};
void Environment::SetEnvironmentVariableCore(String variable, String value) {
  return void();
};
IDictionary Environment::GetEnvironmentVariables() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::EnvironmentNamespace
