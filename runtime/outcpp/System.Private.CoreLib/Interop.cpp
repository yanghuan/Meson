#include "Interop-dep.h"

namespace System::Private::CoreLib::InteropNamespace {
Boolean Interop::Kernel32::SYSTEMTIME::Equals(SYSTEMTIME& other) {
  return Boolean();
};

String Interop::Kernel32::TIME_DYNAMIC_ZONE_INFORMATION::GetTimeZoneKeyName() {
  return nullptr;
};

void Interop::Kernel32::TIME_ZONE_INFORMATION::Ctor(TIME_DYNAMIC_ZONE_INFORMATION& dtzi) {
};

String Interop::Kernel32::TIME_ZONE_INFORMATION::GetStandardName() {
  return nullptr;
};

String Interop::Kernel32::TIME_ZONE_INFORMATION::GetDaylightName() {
  return nullptr;
};

void Interop::Kernel32::REG_TZI_FORMAT::Ctor(TIME_ZONE_INFORMATION& tzi) {
};

void Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA::PopulateFrom(WIN32_FIND_DATA& findData) {
};

SafeFileHandle Interop::Kernel32::CreateFile(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile) {
  return nullptr;
};

SafeFindHandle Interop::Kernel32::FindFirstFile(String fileName, WIN32_FIND_DATA& data) {
  return nullptr;
};

String Interop::Kernel32::GetComputerName() {
  return nullptr;
};

Boolean Interop::Kernel32::GetFileAttributesEx(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation) {
  return Boolean();
};

Int32 Interop::Kernel32::GetEnvironmentVariable(String lpName, Span<Char> buffer) {
  return Int32();
};

String Interop::Kernel32::GetMessage(Int32 errorCode) {
  return nullptr;
};

String Interop::Kernel32::GetMessage(Int32 errorCode, IntPtr moduleHandle) {
  return nullptr;
};

String Interop::Kernel32::GetAndTrimString(Span<Char> buffer) {
  return nullptr;
};

void Interop::Globalization::InitICUFunctions(IntPtr icuuc, IntPtr icuin, ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix) {
};

Int32 Interop::Advapi32::EventWriteTransfer(Int64 registrationHandle, EventDescriptor& eventDescriptor, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, void/*EventProvider.EventData*/* userData) {
  return Int32();
};

Int32 Interop::NtDll::RtlGetVersionEx(RTL_OSVERSIONINFOEX& osvi) {
  return Int32();
};

void Interop::GetRandomBytes(Byte* buffer, Int32 length) {
};

UInt32 Interop::GetCurrentProcessId() {
  return UInt32();
};

} // namespace System::Private::CoreLib::InteropNamespace
