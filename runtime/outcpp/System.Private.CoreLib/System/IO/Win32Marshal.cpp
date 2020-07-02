#include "Win32Marshal-dep.h"

namespace System::Private::CoreLib::System::IO::Win32MarshalNamespace {
Exception Win32Marshal::GetExceptionForLastWin32Error(String path) {
  return nullptr;
};
Exception Win32Marshal::GetExceptionForWin32Error(Int32 errorCode, String path) {
  return nullptr;
};
Int32 Win32Marshal::MakeHRFromErrorCode(Int32 errorCode) {
  return Int32();
};
String Win32Marshal::GetMessage(Int32 errorCode) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::IO::Win32MarshalNamespace
