#include "Interop-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::InteropNamespace {
using namespace System;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Boolean Interop::Kernel32::SYSTEMTIME::Equals(SYSTEMTIME& other) {
  if (Year == other.Year && Month == other.Month && DayOfWeek == other.DayOfWeek && Day == other.Day && Hour == other.Hour && Minute == other.Minute && Second == other.Second) {
    return Milliseconds == other.Milliseconds;
  }
  return false;
}

String Interop::Kernel32::TIME_DYNAMIC_ZONE_INFORMATION::GetTimeZoneKeyName() {
  {
    Char* value = rt::fixed(TimeZoneKeyName);
    return rt::newstr<String>(value);
  }
}

Interop::Kernel32::TIME_ZONE_INFORMATION::TIME_ZONE_INFORMATION(TIME_DYNAMIC_ZONE_INFORMATION& dtzi) {
  {
    TIME_ZONE_INFORMATION* ptr = rt::fixed(&*this);
    {
      TIME_DYNAMIC_ZONE_INFORMATION* ptr2 = rt::fixed(&dtzi);
      *ptr = *(TIME_ZONE_INFORMATION*)ptr2;
    }
  }
}

String Interop::Kernel32::TIME_ZONE_INFORMATION::GetStandardName() {
  {
    Char* value = rt::fixed(StandardName);
    return rt::newstr<String>(value);
  }
}

String Interop::Kernel32::TIME_ZONE_INFORMATION::GetDaylightName() {
  {
    Char* value = rt::fixed(DaylightName);
    return rt::newstr<String>(value);
  }
}

Interop::Kernel32::REG_TZI_FORMAT::REG_TZI_FORMAT(TIME_ZONE_INFORMATION& tzi) {
  Bias = tzi.Bias;
  StandardDate = tzi.StandardDate;
  StandardBias = tzi.StandardBias;
  DaylightDate = tzi.DaylightDate;
  DaylightBias = tzi.DaylightBias;
}

void Interop::Kernel32::WIN32_FILE_ATTRIBUTE_DATA::PopulateFrom(WIN32_FIND_DATA& findData) {
  dwFileAttributes = (Int32)findData.dwFileAttributes;
  ftCreationTime = findData.ftCreationTime;
  ftLastAccessTime = findData.ftLastAccessTime;
  ftLastWriteTime = findData.ftLastWriteTime;
  nFileSizeHigh = findData.nFileSizeHigh;
  nFileSizeLow = findData.nFileSizeLow;
}

SafeFileHandle Interop::Kernel32::CreateFile(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile) {
  lpFileName = PathInternal::EnsureExtendedPrefixIfNeeded(lpFileName);
  return CreateFilePrivate(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

SafeFindHandle Interop::Kernel32::FindFirstFile(String fileName, WIN32_FIND_DATA& data) {
  fileName = PathInternal::EnsureExtendedPrefixIfNeeded(fileName);
  return FindFirstFileExPrivate(fileName, FINDEX_INFO_LEVELS::FindExInfoBasic, data, FINDEX_SEARCH_OPS::FindExSearchNameMatch, IntPtr::Zero, 0);
}

String Interop::Kernel32::GetComputerName() {
  Char as[16] = {};
  Span<Char> span = as;
  UInt32 nSize = (UInt32)span.get_Length();
  if (GetComputerName(MemoryMarshal::GetReference(span), nSize) == 0) {
    return nullptr;
  }
  return span.Slice(0, (Int32)nSize).ToString();
}

Boolean Interop::Kernel32::GetFileAttributesEx(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation) {
  name = PathInternal::EnsureExtendedPrefixIfNeeded(name);
  return GetFileAttributesExPrivate(name, fileInfoLevel, lpFileInformation);
}

Int32 Interop::Kernel32::GetEnvironmentVariable(String lpName, Span<Char> buffer) {
  {
    Char* lpBuffer = rt::fixed(&MemoryMarshal::GetReference(buffer));
    return GetEnvironmentVariable(lpName, lpBuffer, buffer.get_Length());
  }
}

String Interop::Kernel32::GetMessage(Int32 errorCode) {
  return GetMessage(errorCode, IntPtr::Zero);
}

String Interop::Kernel32::GetMessage(Int32 errorCode, IntPtr moduleHandle) {
  Int32 num = 12800;
  if (moduleHandle != IntPtr::Zero) {
    num |= 2048;
  }
  Char as[256] = {};
  Span<Char> span = as;
  {
    Char* lpBuffer = rt::fixed(span);
    Int32 num2 = FormatMessage(num, moduleHandle, (UInt32)errorCode, 0, lpBuffer, span.get_Length(), IntPtr::Zero);
    if (num2 > 0) {
      return GetAndTrimString(span.Slice(0, num2));
    }
  }
  if (Marshal::GetLastWin32Error() == 122) {
    IntPtr intPtr;
    try {
      Int32 num3 = FormatMessage(num | 256, moduleHandle, (UInt32)errorCode, 0, &intPtr, 0, IntPtr::Zero);
      if (num3 > 0) {
        return GetAndTrimString(Span<Char>((void*)intPtr, num3));
      }
    } catch (...) {
    } finally: {
      Marshal::FreeHGlobal(intPtr);
    }
  }
  return String::in::Format("Unknown error (0x{0:x})", errorCode);
}

String Interop::Kernel32::GetAndTrimString(Span<Char> buffer) {
  Int32 num = buffer.get_Length();
  while (num > 0 && buffer[num - 1] <= u' ') {
    num--;
  }
  return buffer.Slice(0, num).ToString();
}

void Interop::Globalization::InitICUFunctions(IntPtr icuuc, IntPtr icuin, ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix) {
  InitICUFunctions(icuuc, icuin, version.ToString(), (suffix.get_Length() > 0) ? suffix.ToString() : nullptr);
}

Int32 Interop::Advapi32::EventWriteTransfer(Int64 registrationHandle, EventDescriptor& eventDescriptor, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, void/*EventProvider.EventData*/* userData) {
  Int32 num = EventWriteTransfer_PInvoke(registrationHandle, eventDescriptor, activityId, relatedActivityId, userDataCount, userData);
  if (num == 87 && relatedActivityId == nullptr) {
    Guid empty = Guid::Empty;
    num = EventWriteTransfer_PInvoke(registrationHandle, eventDescriptor, activityId, &empty, userDataCount, userData);
  }
  return num;
}

Int32 Interop::NtDll::RtlGetVersionEx(RTL_OSVERSIONINFOEX& osvi) {
  osvi = rt::default__;
  osvi.dwOSVersionInfoSize = (UInt32)sizeof(RTL_OSVERSIONINFOEX);
  return RtlGetVersion(osvi);
}

void Interop::GetRandomBytes(Byte* buffer, Int32 length) {
  switch (BCrypt::BCryptGenRandom(IntPtr::Zero, buffer, length, 2)) {
    case BCrypt::NTSTATUS::STATUS_NO_MEMORY:
      rt::throw_exception<OutOfMemoryException>();
    default:
      rt::throw_exception<InvalidOperationException>();
    case BCrypt::NTSTATUS::STATUS_SUCCESS:
      break;
  }
}

} // namespace System::Private::CoreLib::InteropNamespace
