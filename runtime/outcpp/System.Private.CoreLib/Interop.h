#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/UIntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeBuffer)
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARDS(NativeOverlapped)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
enum class FileMode : int32_t;
enum class FileShare : int32_t;
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeFileHandle)
FORWARD(SafeFindHandle)
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarDataType : int32_t;
enum class CalendarId : uint16_t;
enum class CompareOptions : int32_t;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm : int32_t;
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(EventDescriptor)
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
FORWARD(SafeRegistryHandle)
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanFunc, TSpan, T1, T2, T3, TResult)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib {
namespace InteropNamespace {
using namespace Internal::Win32::SafeHandles;
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
using namespace System::Buffers;
using namespace System::Diagnostics::Tracing;
using namespace System::Globalization;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading;
class Interop {
  public: enum class BOOL : int32_t {
    FALSE = 0,
    TRUE = 1,
  };
  public: enum class BOOLEAN : uint8_t {
    FALSE = 0,
    TRUE = 1,
  };
  public: class Kernel32 {
    public: enum class FINDEX_INFO_LEVELS : uint32_t {
      FindExInfoStandard = 0,
      FindExInfoBasic = 1,
      FindExInfoMaxInfoLevel = 2,
    };
    public: enum class FINDEX_SEARCH_OPS : uint32_t {
      FindExSearchNameMatch = 0,
      FindExSearchLimitToDirectories = 1,
      FindExSearchLimitToDevices = 2,
      FindExSearchMaxSearchOp = 3,
    };
    public: enum class GET_FILEEX_INFO_LEVELS : uint32_t {
      GetFileExInfoStandard = 0,
      GetFileExMaxInfoLevel = 1,
    };
    public: struct SYSTEMTIME : public valueType<SYSTEMTIME> {
      public: Boolean Equals(SYSTEMTIME& other);
      public: UInt16 Year;
      public: UInt16 Month;
      public: UInt16 DayOfWeek;
      public: UInt16 Day;
      public: UInt16 Hour;
      public: UInt16 Minute;
      public: UInt16 Second;
      public: UInt16 Milliseconds;
    };
    public: struct TIME_DYNAMIC_ZONE_INFORMATION : public valueType<TIME_DYNAMIC_ZONE_INFORMATION> {
      public: String GetTimeZoneKeyName();
      public: Int32 Bias;
      public: Char StandardName[32];
      public: SYSTEMTIME StandardDate;
      public: Int32 StandardBias;
      public: Char DaylightName[32];
      public: SYSTEMTIME DaylightDate;
      public: Int32 DaylightBias;
      public: Char TimeZoneKeyName[128];
      public: Byte DynamicDaylightTimeDisabled;
    };
    public: struct FILE_TIME : public valueType<FILE_TIME> {
      public: UInt32 dwLowDateTime;
      public: UInt32 dwHighDateTime;
    };
    public: struct TIME_ZONE_INFORMATION : public valueType<TIME_ZONE_INFORMATION> {
      public: explicit TIME_ZONE_INFORMATION(TIME_DYNAMIC_ZONE_INFORMATION& dtzi);
      public: String GetStandardName();
      public: String GetDaylightName();
      public: explicit TIME_ZONE_INFORMATION() {}
      public: Int32 Bias;
      public: Char StandardName[32];
      public: SYSTEMTIME StandardDate;
      public: Int32 StandardBias;
      public: Char DaylightName[32];
      public: SYSTEMTIME DaylightDate;
      public: Int32 DaylightBias;
    };
    public: struct WIN32_FIND_DATA : public valueType<WIN32_FIND_DATA> {
      public: UInt32 dwFileAttributes;
      public: FILE_TIME ftCreationTime;
      public: FILE_TIME ftLastAccessTime;
      public: FILE_TIME ftLastWriteTime;
      public: UInt32 nFileSizeHigh;
      public: UInt32 nFileSizeLow;
      public: UInt32 dwReserved0;
      public: UInt32 dwReserved1;
      private: Char _cFileName[260];
      private: Char _cAlternateFileName[14];
    };
    public: CLASS(EnumLocalesProcEx) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: BOOL Invoke(Char* lpLocaleString, UInt32 dwFlags, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpLocaleString, UInt32 dwFlags, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: CLASS(EnumTimeFormatsProcEx) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: BOOL Invoke(Char* lpTimeFormatString, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpTimeFormatString, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: CLASS(EnumCalendarInfoProcExEx) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: BOOL Invoke(Char* lpCalendarInfoString, UInt32 Calendar, IntPtr lpReserved, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpCalendarInfoString, UInt32 Calendar, IntPtr lpReserved, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: struct NlsVersionInfoEx : public valueType<NlsVersionInfoEx> {
      public: Int32 dwNLSVersionInfoSize;
      public: Int32 dwNLSVersion;
      public: Int32 dwDefinedVersion;
      public: Int32 dwEffectiveId;
      public: Guid guidCustomVersion;
    };
    public: struct FILE_STANDARD_INFO : public valueType<FILE_STANDARD_INFO> {
      public: Int64 AllocationSize;
      public: Int64 EndOfFile;
      public: UInt32 NumberOfLinks;
      public: BOOL DeletePending;
      public: BOOL Directory;
    };
    public: struct CPINFO : public valueType<CPINFO> {
      public: Int32 MaxCharSize;
      public: Byte DefaultChar[2];
      public: Byte LeadByte[12];
    };
    public: struct PROCESS_MEMORY_COUNTERS : public valueType<PROCESS_MEMORY_COUNTERS> {
      public: UInt32 cb;
      public: UInt32 PageFaultCount;
      public: UIntPtr PeakWorkingSetSize;
      public: UIntPtr WorkingSetSize;
      public: UIntPtr QuotaPeakPagedPoolUsage;
      public: UIntPtr QuotaPagedPoolUsage;
      public: UIntPtr QuotaPeakNonPagedPoolUsage;
      public: UIntPtr QuotaNonPagedPoolUsage;
      public: UIntPtr PagefileUsage;
      public: UIntPtr PeakPagefileUsage;
    };
    public: struct MEMORY_BASIC_INFORMATION : public valueType<MEMORY_BASIC_INFORMATION> {
      public: void* BaseAddress;
      public: void* AllocationBase;
      public: UInt32 AllocationProtect;
      public: UIntPtr RegionSize;
      public: UInt32 State;
      public: UInt32 Protect;
      public: UInt32 Type;
    };
    public: struct MEMORYSTATUSEX : public valueType<MEMORYSTATUSEX> {
      public: UInt32 dwLength;
      public: UInt32 dwMemoryLoad;
      public: UInt64 ullTotalPhys;
      public: UInt64 ullAvailPhys;
      public: UInt64 ullTotalPageFile;
      public: UInt64 ullAvailPageFile;
      public: UInt64 ullTotalVirtual;
      public: UInt64 ullAvailVirtual;
      public: UInt64 ullAvailExtendedVirtual;
    };
    public: struct SECURITY_ATTRIBUTES : public valueType<SECURITY_ATTRIBUTES> {
      public: UInt32 nLength;
      public: IntPtr lpSecurityDescriptor;
      public: BOOL bInheritHandle;
    };
    public: struct SYSTEM_INFO : public valueType<SYSTEM_INFO> {
      public: UInt16 wProcessorArchitecture;
      public: UInt16 wReserved;
      public: Int32 dwPageSize;
      public: IntPtr lpMinimumApplicationAddress;
      public: IntPtr lpMaximumApplicationAddress;
      public: IntPtr dwActiveProcessorMask;
      public: Int32 dwNumberOfProcessors;
      public: Int32 dwProcessorType;
      public: Int32 dwAllocationGranularity;
      public: Int16 wProcessorLevel;
      public: Int16 wProcessorRevision;
    };
    public: struct REG_TZI_FORMAT : public valueType<REG_TZI_FORMAT> {
      public: explicit REG_TZI_FORMAT(TIME_ZONE_INFORMATION& tzi);
      public: explicit REG_TZI_FORMAT() {}
      public: Int32 Bias;
      public: Int32 StandardBias;
      public: Int32 DaylightBias;
      public: SYSTEMTIME StandardDate;
      public: SYSTEMTIME DaylightDate;
    };
    public: struct WIN32_FILE_ATTRIBUTE_DATA : public valueType<WIN32_FILE_ATTRIBUTE_DATA> {
      public: void PopulateFrom(WIN32_FIND_DATA& findData);
      public: Int32 dwFileAttributes;
      public: FILE_TIME ftCreationTime;
      public: FILE_TIME ftLastAccessTime;
      public: FILE_TIME ftLastWriteTime;
      public: UInt32 nFileSizeHigh;
      public: UInt32 nFileSizeLow;
    };
    public: struct OSVERSIONINFOEX : public valueType<OSVERSIONINFOEX> {
      public: Int32 dwOSVersionInfoSize;
      public: Int32 dwMajorVersion;
      public: Int32 dwMinorVersion;
      public: Int32 dwBuildNumber;
      public: Int32 dwPlatformId;
      public: Char szCSDVersion[128];
      public: UInt16 wServicePackMajor;
      public: UInt16 wServicePackMinor;
      public: UInt16 wSuiteMask;
      public: Byte wProductType;
      public: Byte wReserved;
    };
    public: static IntPtr GetStdHandle(Int32 nStdHandle);
    public: static IntPtr LocalAlloc(UInt32 uFlags, UIntPtr uBytes);
    public: static IntPtr LocalReAlloc(IntPtr hMem, IntPtr uBytes, UInt32 uFlags);
    public: static IntPtr LocalFree(IntPtr hMem);
    public: static Int32 LCIDToLocaleName(Int32 locale, Char* pLocaleName, Int32 cchName, UInt32 dwFlags);
    public: static Int32 LocaleNameToLCID(String lpName, UInt32 dwFlags);
    public: static Int32 LCMapStringEx(String lpLocaleName, UInt32 dwMapFlags, Char* lpSrcStr, Int32 cchSrc, void* lpDestStr, Int32 cchDest, void* lpVersionInformation, void* lpReserved, IntPtr sortHandle);
    public: static Int32 FindNLSStringEx(Char* lpLocaleName, UInt32 dwFindNLSStringFlags, Char* lpStringSource, Int32 cchSource, Char* lpStringValue, Int32 cchValue, Int32* pcchFound, void* lpVersionInformation, void* lpReserved, IntPtr sortHandle);
    public: static Int32 CompareStringEx(Char* lpLocaleName, UInt32 dwCmpFlags, Char* lpString1, Int32 cchCount1, Char* lpString2, Int32 cchCount2, void* lpVersionInformation, void* lpReserved, IntPtr lParam);
    public: static Int32 CompareStringOrdinal(Char* lpString1, Int32 cchCount1, Char* lpString2, Int32 cchCount2, Boolean bIgnoreCase);
    public: static Int32 FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, Char* lpStringSource, Int32 cchSource, Char* lpStringValue, Int32 cchValue, BOOL bIgnoreCase);
    public: static Boolean IsNLSDefinedString(Int32 Function, UInt32 dwFlags, IntPtr lpVersionInformation, Char* lpString, Int32 cchStr);
    public: static BOOL GetUserPreferredUILanguages(UInt32 dwFlags, UInt32* pulNumLanguages, Char* pwszLanguagesBuffer, UInt32* pcchLanguagesBuffer);
    public: static Int32 GetLocaleInfoEx(String lpLocaleName, UInt32 LCType, void* lpLCData, Int32 cchData);
    public: static Boolean EnumSystemLocalesEx(EnumLocalesProcEx lpLocaleEnumProcEx, UInt32 dwFlags, void* lParam, IntPtr reserved);
    public: static Boolean EnumTimeFormatsEx(EnumTimeFormatsProcEx lpTimeFmtEnumProcEx, String lpLocaleName, UInt32 dwFlags, void* lParam);
    public: static Int32 GetCalendarInfoEx(String lpLocaleName, UInt32 Calendar, IntPtr lpReserved, UInt32 CalType, IntPtr lpCalData, Int32 cchData, Int32& lpValue);
    public: static Int32 GetCalendarInfoEx(String lpLocaleName, UInt32 Calendar, IntPtr lpReserved, UInt32 CalType, IntPtr lpCalData, Int32 cchData, IntPtr lpValue);
    public: static Int32 GetUserGeoID(Int32 geoClass);
    public: static Int32 GetGeoInfo(Int32 location, Int32 geoType, Char* lpGeoData, Int32 cchData, Int32 LangId);
    public: static Boolean EnumCalendarInfoExEx(EnumCalendarInfoProcExEx pCalInfoEnumProcExEx, String lpLocaleName, UInt32 Calendar, String lpReserved, UInt32 CalType, void* lParam);
    public: static Boolean GetNLSVersionEx(Int32 function, String localeName, NlsVersionInfoEx* lpVersionInformation);
    public: static Int32 ResolveLocaleName(String lpNameToResolve, Char* lpLocaleName, Int32 cchLocaleName);
    public: static Boolean CancelIoEx(SafeHandle handle, NativeOverlapped* lpOverlapped);
    private: static SafeFileHandle CreateFilePrivate(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile);
    public: static SafeFileHandle CreateFile(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES* lpSecurityAttributes, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile);
    public: static UInt32 ExpandEnvironmentStrings(String lpSrc, Char& lpDst, UInt32 nSize);
    public: static Boolean FindClose(IntPtr hFindFile);
    private: static SafeFindHandle FindFirstFileExPrivate(String lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, WIN32_FIND_DATA& lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, IntPtr lpSearchFilter, Int32 dwAdditionalFlags);
    public: static SafeFindHandle FindFirstFile(String fileName, WIN32_FIND_DATA& data);
    public: static Boolean FlushFileBuffers(SafeHandle hHandle);
    public: static Boolean FreeLibrary(IntPtr hModule);
    private: static Int32 GetComputerName(Char& lpBuffer, UInt32& nSize);
    public: static String GetComputerName();
    public: static BOOL GetCPInfo(UInt32 codePage, CPINFO* lpCpInfo);
    public: static UInt32 GetCurrentDirectory(UInt32 nBufferLength, Char& lpBuffer);
    public: static IntPtr GetCurrentProcess();
    public: static UInt32 GetCurrentProcessId();
    private: static Boolean GetFileAttributesExPrivate(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation);
    public: static Boolean GetFileAttributesEx(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation);
    public: static Boolean GetFileInformationByHandleEx(SafeFileHandle hFile, Int32 FileInformationClass, void* lpFileInformation, UInt32 dwBufferSize);
    public: static Int32 GetFileType(SafeHandle hFile);
    public: static UInt32 GetFullPathNameW(Char& lpFileName, UInt32 nBufferLength, Char& lpBuffer, IntPtr lpFilePart);
    public: static Int32 GetLogicalDrives();
    public: static UInt32 GetLongPathNameW(Char& lpszShortPath, Char& lpszLongPath, UInt32 cchBuffer);
    public: static Boolean GetProcessMemoryInfo(IntPtr Process, PROCESS_MEMORY_COUNTERS& ppsmemCounters, UInt32 cb);
    public: static Boolean GetProcessTimes(IntPtr handleProcess, Int64& creation, Int64& exit, Int64& kernel, Int64& user);
    public: static UInt32 GetSystemDirectoryW(Char& lpBuffer, UInt32 uSize);
    public: static void GetSystemInfo(SYSTEM_INFO& lpSystemInfo);
    public: static Boolean GetSystemTimes(Int64& idle, Int64& kernel, Int64& user);
    public: static UInt32 GetTempFileNameW(Char& lpPathName, String lpPrefixString, UInt32 uUnique, Char& lpTempFileName);
    public: static UInt32 GetTempPathW(Int32 bufferLen, Char& buffer);
    public: static Boolean GlobalMemoryStatusEx(MEMORYSTATUSEX& lpBuffer);
    public: static Boolean IsWow64Process(IntPtr hProcess, Boolean& Wow64Process);
    public: static IntPtr LoadLibraryEx(String libFilename, IntPtr reserved, Int32 flags);
    public: static Boolean LockFile(SafeFileHandle handle, Int32 offsetLow, Int32 offsetHigh, Int32 countLow, Int32 countHigh);
    public: static Boolean UnlockFile(SafeFileHandle handle, Int32 offsetLow, Int32 offsetHigh, Int32 countLow, Int32 countHigh);
    public: static Boolean GetFileMUIPath(UInt32 dwFlags, String pcwszFilePath, Char* pwszLanguage, Int32& pcchLanguage, Char* pwszFileMUIPath, Int32& pcchFileMUIPath, Int64& pululEnumerator);
    public: static Int32 MultiByteToWideChar(UInt32 CodePage, UInt32 dwFlags, Byte* lpMultiByteStr, Int32 cbMultiByte, Char* lpWideCharStr, Int32 cchWideChar);
    public: static void OutputDebugString(String message);
    public: static BOOL QueryPerformanceCounter(Int64* lpPerformanceCount);
    public: static BOOL QueryPerformanceFrequency(Int64* lpFrequency);
    public: static Boolean QueryUnbiasedInterruptTime(UInt64& UnbiasedTime);
    public: static Int32 ReadFile(SafeHandle handle, Byte* bytes, Int32 numBytesToRead, Int32& numBytesRead, IntPtr mustBeZero);
    public: static Int32 ReadFile(SafeHandle handle, Byte* bytes, Int32 numBytesToRead, IntPtr numBytesRead_mustBeZero, NativeOverlapped* overlapped);
    public: static Boolean SetCurrentDirectory(String path);
    public: static Boolean SetEndOfFile(SafeFileHandle hFile);
    public: static Boolean SetFilePointerEx(SafeFileHandle hFile, Int64 liDistanceToMove, Int64& lpNewFilePointer, UInt32 dwMoveMethod);
    public: static Boolean SetThreadErrorMode(UInt32 dwNewMode, UInt32& lpOldMode);
    public: static UInt32 GetDynamicTimeZoneInformation(TIME_DYNAMIC_ZONE_INFORMATION& pTimeZoneInformation);
    public: static UInt32 GetTimeZoneInformation(TIME_ZONE_INFORMATION& lpTimeZoneInformation);
    public: static Boolean VerifyVersionInfoW(OSVERSIONINFOEX& lpVersionInfo, UInt32 dwTypeMask, UInt64 dwlConditionMask);
    public: static UInt64 VerSetConditionMask(UInt64 ConditionMask, UInt32 TypeMask, Byte Condition);
    public: static void* VirtualAlloc(void* lpAddress, UIntPtr dwSize, Int32 flAllocationType, Int32 flProtect);
    public: static Boolean VirtualFree(void* lpAddress, UIntPtr dwSize, Int32 dwFreeType);
    public: static UIntPtr VirtualQuery(void* lpAddress, MEMORY_BASIC_INFORMATION& lpBuffer, UIntPtr dwLength);
    public: static Int32 WideCharToMultiByte(UInt32 CodePage, UInt32 dwFlags, Char* lpWideCharStr, Int32 cchWideChar, Byte* lpMultiByteStr, Int32 cbMultiByte, IntPtr lpDefaultChar, IntPtr lpUsedDefaultChar);
    public: static Int32 WriteFile(SafeHandle handle, Byte* bytes, Int32 numBytesToWrite, IntPtr numBytesWritten_mustBeZero, NativeOverlapped* lpOverlapped);
    public: static Boolean CloseHandle(IntPtr handle);
    public: static Boolean SetEvent(SafeWaitHandle handle);
    public: static Boolean ResetEvent(SafeWaitHandle handle);
    public: static SafeWaitHandle CreateEventEx(IntPtr lpSecurityAttributes, String name, UInt32 flags, UInt32 desiredAccess);
    public: static SafeWaitHandle OpenEvent(UInt32 desiredAccess, Boolean inheritHandle, String name);
    public: static Int32 GetEnvironmentVariable(String lpName, Span<Char> buffer);
    private: static Int32 GetEnvironmentVariable(String lpName, Char* lpBuffer, Int32 nSize);
    public: static Char* GetEnvironmentStrings();
    public: static Boolean FreeEnvironmentStrings(Char* lpszEnvironmentBlock);
    private: static Int32 FormatMessage(Int32 dwFlags, IntPtr lpSource, UInt32 dwMessageId, Int32 dwLanguageId, void* lpBuffer, Int32 nSize, IntPtr arguments);
    public: static String GetMessage(Int32 errorCode);
    public: static String GetMessage(Int32 errorCode, IntPtr moduleHandle);
    private: static String GetAndTrimString(Span<Char> buffer);
    public: static SafeWaitHandle OpenMutex(UInt32 desiredAccess, Boolean inheritHandle, String name);
    public: static SafeWaitHandle CreateMutexEx(IntPtr lpMutexAttributes, String name, UInt32 flags, UInt32 desiredAccess);
    public: static Boolean ReleaseMutex(SafeWaitHandle handle);
    public: static SafeWaitHandle OpenSemaphore(UInt32 desiredAccess, Boolean inheritHandle, String name);
    public: static SafeWaitHandle CreateSemaphoreEx(IntPtr lpSecurityAttributes, Int32 initialCount, Int32 maximumCount, String name, UInt32 flags, UInt32 desiredAccess);
    public: static Boolean ReleaseSemaphore(SafeWaitHandle handle, Int32 releaseCount, Int32& previousCount);
    public: static Boolean SetEnvironmentVariable(String lpName, String lpValue);
    public: static Int32 WriteFile(SafeHandle handle, Byte* bytes, Int32 numBytesToWrite, Int32& numBytesWritten, IntPtr mustBeZero);
  };
  public: class Ole32 {
    public: static IntPtr CoTaskMemAlloc(UIntPtr cb);
    public: static IntPtr CoTaskMemRealloc(IntPtr pv, UIntPtr cb);
    public: static void CoTaskMemFree(IntPtr ptr);
    public: static Int32 CoCreateGuid(Guid& guid);
  };
  public: class OleAut32 {
    public: static IntPtr SysAllocStringByteLen(Array<Byte> str, UInt32 len);
    public: static void VariantClear(IntPtr variant);
    public: static IntPtr SysAllocStringLen(String src, Int32 len);
    public: static void SysFreeString(IntPtr bstr);
  };
  public: class Globalization {
    public: enum class ResultCode : int32_t {
      Success = 0,
      UnknownError = 1,
      InsufficentBuffer = 2,
      OutOfMemory = 3,
    };
    public: CLASS(EnumCalendarInfoCallback) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: void Invoke(String calendarString, IntPtr context);
      public: IAsyncResult BeginInvoke(String calendarString, IntPtr context, AsyncCallback callback, Object object);
      public: void EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: static Int32 GetCalendars(String localeName, Array<CalendarId> calendars, Int32 calendarsCapacity);
    public: static ResultCode GetCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType calendarDataType, Char* result, Int32 resultCapacity);
    public: static Boolean EnumCalendarInfo(EnumCalendarInfoCallback callback, String localeName, CalendarId calendarId, CalendarDataType calendarDataType, IntPtr context);
    public: static Int32 GetLatestJapaneseEra();
    public: static Boolean GetJapaneseEraStartDate(Int32 era, Int32& startYear, Int32& startMonth, Int32& startDay);
    public: static void ChangeCase(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper);
    public: static void ChangeCaseInvariant(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper);
    public: static void ChangeCaseTurkish(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper);
    public: static ResultCode GetSortHandle(String localeName, IntPtr& sortHandle);
    public: static void CloseSortHandle(IntPtr handle);
    public: static Int32 CompareString(IntPtr sortHandle, Char* lpStr1, Int32 cwStr1Len, Char* lpStr2, Int32 cwStr2Len, CompareOptions options);
    public: static Int32 IndexOf(IntPtr sortHandle, Char* target, Int32 cwTargetLength, Char* pSource, Int32 cwSourceLength, CompareOptions options, Int32* matchLengthPtr);
    public: static Int32 LastIndexOf(IntPtr sortHandle, Char* target, Int32 cwTargetLength, Char* pSource, Int32 cwSourceLength, CompareOptions options, Int32* matchLengthPtr);
    public: static Int32 IndexOfOrdinalIgnoreCase(Char* target, Int32 cwTargetLength, Char* pSource, Int32 cwSourceLength, Boolean findLast);
    public: static Boolean StartsWith(IntPtr sortHandle, Char* target, Int32 cwTargetLength, Char* source, Int32 cwSourceLength, CompareOptions options);
    public: static Boolean EndsWith(IntPtr sortHandle, Char* target, Int32 cwTargetLength, Char* source, Int32 cwSourceLength, CompareOptions options);
    public: static Int32 GetSortKey(IntPtr sortHandle, Char* str, Int32 strLength, Byte* sortKey, Int32 sortKeyLength, CompareOptions options);
    public: static Int32 CompareStringOrdinalIgnoreCase(Char* lpStr1, Int32 cwStr1Len, Char* lpStr2, Int32 cwStr2Len);
    public: static Int32 GetSortVersion(IntPtr sortHandle);
    public: static Int32 LoadICU();
    public: static void InitICUFunctions(IntPtr icuuc, IntPtr icuin, ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix);
    public: static void InitICUFunctions(IntPtr icuuc, IntPtr icuin, String version, String suffix);
    public: static Int32 GetICUVersion();
    public: static Int32 ToAscii(UInt32 flags, Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity);
    public: static Int32 ToUnicode(UInt32 flags, Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity);
    public: static Boolean GetLocaleInfoString(String localeName, UInt32 localeStringData, Char* value, Int32 valueLength);
    public: static Boolean IsPredefinedLocale(String localeName);
    public: static Boolean GetLocaleTimeFormat(String localeName, Boolean shortFormat, Char* value, Int32 valueLength);
    public: static Boolean GetLocaleInfoInt(String localeName, UInt32 localeNumberData, Int32& value);
    public: static Boolean GetLocaleInfoGroupingSizes(String localeName, UInt32 localeGroupingData, Int32& primaryGroupSize, Int32& secondaryGroupSize);
    public: static Int32 GetLocales(Array<Char> value, Int32 valueLength);
    public: static Int32 IsNormalized(NormalizationForm normalizationForm, Char* src, Int32 srcLen);
    public: static Int32 NormalizeString(NormalizationForm normalizationForm, Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity);
  };
  public: class Normaliz {
    public: static Int32 IdnToAscii(UInt32 dwFlags, Char* lpUnicodeCharStr, Int32 cchUnicodeChar, Char* lpASCIICharStr, Int32 cchASCIIChar);
    public: static Int32 IdnToUnicode(UInt32 dwFlags, Char* lpASCIICharStr, Int32 cchASCIIChar, Char* lpUnicodeCharStr, Int32 cchUnicodeChar);
    public: static BOOL IsNormalizedString(NormalizationForm normForm, Char* source, Int32 length);
    public: static Int32 NormalizeString(NormalizationForm normForm, Char* source, Int32 sourceLength, Char* destination, Int32 destinationLength);
  };
  public: class Advapi32 {
    public: enum class ActivityControl : uint32_t {
      EVENT_ACTIVITY_CTRL_GET_ID = 1,
      EVENT_ACTIVITY_CTRL_SET_ID = 2,
      EVENT_ACTIVITY_CTRL_CREATE_ID = 3,
      EVENT_ACTIVITY_CTRL_GET_SET_ID = 4,
      EVENT_ACTIVITY_CTRL_CREATE_SET_ID = 5,
    };
    public: enum class EVENT_INFO_CLASS : int32_t {
      BinaryTrackInfo = 0,
      SetEnableAllKeywords = 1,
      SetTraits = 2,
    };
    public: enum class TRACE_QUERY_INFO_CLASS : int32_t {
      TraceGuidQueryList = 0,
      TraceGuidQueryInfo = 1,
      TraceGuidQueryProcess = 2,
      TraceStackTracingInfo = 3,
      MaxTraceSetInfoClass = 4,
    };
    public: struct EVENT_FILTER_DESCRIPTOR : public valueType<EVENT_FILTER_DESCRIPTOR> {
      public: Int64 Ptr;
      public: Int32 Size;
      public: Int32 Type;
    };
    public: CLASS(EtwEnableCallback) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: void Invoke(Guid& sourceId, Int32 isEnabled, Byte level, Int64 matchAnyKeywords, Int64 matchAllKeywords, EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext);
      public: IAsyncResult BeginInvoke(Guid& sourceId, Int32 isEnabled, Byte level, Int64 matchAnyKeywords, Int64 matchAllKeywords, EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext, AsyncCallback callback, Object object);
      public: void EndInvoke(Guid& sourceId, IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: struct TRACE_GUID_INFO : public valueType<TRACE_GUID_INFO> {
      public: Int32 InstanceCount;
      public: Int32 Reserved;
    };
    public: struct TRACE_PROVIDER_INSTANCE_INFO : public valueType<TRACE_PROVIDER_INSTANCE_INFO> {
      public: Int32 NextOffset;
      public: Int32 EnableCount;
      public: Int32 Pid;
      public: Int32 Flags;
    };
    public: struct TRACE_ENABLE_INFO : public valueType<TRACE_ENABLE_INFO> {
      public: Int32 IsEnabled;
      public: Byte Level;
      public: Byte Reserved1;
      public: UInt16 LoggerId;
      public: Int32 EnableProperty;
      public: Int32 Reserved2;
      public: Int64 MatchAnyKeyword;
      public: Int64 MatchAllKeyword;
    };
    public: static Int32 EventActivityIdControl(ActivityControl ControlCode, Guid& ActivityId);
    public: static UInt32 EventRegister(Guid& providerId, EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle);
    public: static Int32 EventSetInformation(Int64 registrationHandle, EVENT_INFO_CLASS informationClass, void* eventInformation, Int32 informationLength);
    public: static Int32 EnumerateTraceGuidsEx(TRACE_QUERY_INFO_CLASS TraceQueryInfoClass, void* InBuffer, Int32 InBufferSize, void* OutBuffer, Int32 OutBufferSize, Int32& ReturnLength);
    public: static UInt32 EventUnregister(Int64 registrationHandle);
    public: static Int32 EventWriteTransfer(Int64 registrationHandle, EventDescriptor& eventDescriptor, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, void/*EventProvider.EventData*/* userData);
    private: static Int32 EventWriteTransfer_PInvoke(Int64 registrationHandle, EventDescriptor& eventDescriptor, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, void/*EventProvider.EventData*/* userData);
    public: static Boolean LookupAccountNameW(String lpSystemName, Char& lpAccountName, Byte& Sid, UInt32& cbSid, Char& ReferencedDomainName, UInt32& cchReferencedDomainName, UInt32& peUse);
    public: static Int32 RegCloseKey(IntPtr hKey);
    public: static Int32 RegDeleteValue(SafeRegistryHandle hKey, String lpValueName);
    public: static Int32 RegEnumKeyEx(SafeRegistryHandle hKey, Int32 dwIndex, Array<Char> lpName, Int32& lpcbName, Array<Int32> lpReserved, Array<Char> lpClass, Array<Int32> lpcbClass, Array<Int64> lpftLastWriteTime);
    public: static Int32 RegEnumValue(SafeRegistryHandle hKey, Int32 dwIndex, Array<Char> lpValueName, Int32& lpcbValueName, IntPtr lpReserved_MustBeZero, Array<Int32> lpType, Array<Byte> lpData, Array<Int32> lpcbData);
    public: static Int32 RegOpenKeyEx(SafeRegistryHandle hKey, String lpSubKey, Int32 ulOptions, Int32 samDesired, SafeRegistryHandle& hkResult);
    public: static Int32 RegQueryValueEx(SafeRegistryHandle hKey, String lpValueName, Array<Int32> lpReserved, Int32& lpType, Array<Byte> lpData, Int32& lpcbData);
    public: static Int32 RegQueryValueEx(SafeRegistryHandle hKey, String lpValueName, Array<Int32> lpReserved, Int32& lpType, Int32& lpData, Int32& lpcbData);
    public: static Int32 RegQueryValueEx(SafeRegistryHandle hKey, String lpValueName, Array<Int32> lpReserved, Int32& lpType, Int64& lpData, Int32& lpcbData);
    public: static Int32 RegQueryValueEx(SafeRegistryHandle hKey, String lpValueName, Array<Int32> lpReserved, Int32& lpType, Array<Char> lpData, Int32& lpcbData);
    public: static Int32 RegSetValueEx(SafeRegistryHandle hKey, String lpValueName, Int32 Reserved, Int32 dwType, String lpData, Int32 cbData);
  };
  public: class HostPolicy {
    public: CLASS(corehost_resolve_component_dependencies_result_fn) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: void Invoke(String assemblyPaths, String nativeSearchPaths, String resourceSearchPaths);
      public: IAsyncResult BeginInvoke(String assemblyPaths, String nativeSearchPaths, String resourceSearchPaths, AsyncCallback callback, Object object);
      public: void EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: CLASS(corehost_error_writer_fn) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: void Invoke(String message);
      public: IAsyncResult BeginInvoke(String message, AsyncCallback callback, Object object);
      public: void EndInvoke(IAsyncResult result);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    public: static Int32 corehost_resolve_component_dependencies(String componentMainAssemblyPath, corehost_resolve_component_dependencies_result_fn result);
    public: static IntPtr corehost_set_error_writer(IntPtr errorWriter);
  };
  public: class BCrypt {
    public: enum class NTSTATUS : uint32_t {
      STATUS_SUCCESS = 0,
      STATUS_NOT_FOUND = 3221226021,
      STATUS_INVALID_PARAMETER = 3221225485,
      STATUS_NO_MEMORY = 3221225495,
      STATUS_AUTH_TAG_MISMATCH = 3221266434,
    };
    public: static NTSTATUS BCryptGenRandom(IntPtr hAlgorithm, Byte* pbBuffer, Int32 cbBuffer, Int32 dwFlags);
  };
  public: class Crypt32 {
    public: static Boolean CryptProtectMemory(SafeBuffer pData, UInt32 cbData, UInt32 dwFlags);
    public: static Boolean CryptUnprotectMemory(SafeBuffer pData, UInt32 cbData, UInt32 dwFlags);
  };
  public: class NtDll {
    public: struct IO_STATUS_BLOCK : public valueType<IO_STATUS_BLOCK> {
      private: UInt32 Status;
      private: IntPtr Information;
    };
    public: struct RTL_OSVERSIONINFOEX : public valueType<RTL_OSVERSIONINFOEX> {
      public: UInt32 dwOSVersionInfoSize;
      public: UInt32 dwMajorVersion;
      public: UInt32 dwMinorVersion;
      public: UInt32 dwBuildNumber;
      public: UInt32 dwPlatformId;
      public: Char szCSDVersion[128];
    };
    public: struct SYSTEM_LEAP_SECOND_INFORMATION : public valueType<SYSTEM_LEAP_SECOND_INFORMATION> {
      public: BOOLEAN Enabled;
      public: UInt32 Flags;
    };
    public: static Int32 NtQueryInformationFile(SafeFileHandle FileHandle, IO_STATUS_BLOCK& IoStatusBlock, void* FileInformation, UInt32 Length, UInt32 FileInformationClass);
    public: static UInt32 NtQuerySystemInformation(Int32 SystemInformationClass, void* SystemInformation, UInt32 SystemInformationLength, UInt32* ReturnLength);
    private: static Int32 RtlGetVersion(RTL_OSVERSIONINFOEX& lpVersionInformation);
    public: static Int32 RtlGetVersionEx(RTL_OSVERSIONINFOEX& osvi);
  };
  public: class Secur32 {
    public: static BOOLEAN GetUserNameExW(Int32 NameFormat, Char& lpNameBuffer, UInt32& lpnSize);
  };
  public: class Shell32 {
    public: static Int32 SHGetKnownFolderPath(Guid rfid, UInt32 dwFlags, IntPtr hToken, String& ppszPath);
  };
  public: class User32 {
    public: struct USEROBJECTFLAGS : public valueType<USEROBJECTFLAGS> {
      public: Int32 fInherit;
      public: Int32 fReserved;
      public: Int32 dwFlags;
    };
    public: static Int32 LoadString(IntPtr hInstance, UInt32 uID, Char* lpBuffer, Int32 cchBufferMax);
    public: static IntPtr SendMessageTimeout(IntPtr hWnd, Int32 msg, IntPtr wParam, IntPtr lParam, Int32 flags, Int32 timeout, IntPtr& pdwResult);
    public: static IntPtr GetProcessWindowStation();
    public: static Boolean GetUserObjectInformationW(IntPtr hObj, Int32 nIndex, void* pvBuffer, UInt32 nLength, UInt32& lpnLengthNeeded);
  };
  public: template <class TArg1, class TArg2, class TArg3>
  static Boolean CallStringMethod(SpanFunc<Char, TArg1, TArg2, TArg3, Globalization::ResultCode> interopCall, TArg1 arg1, TArg2 arg2, TArg3 arg3, String& result);
  public: static void GetRandomBytes(Byte* buffer, Int32 length);
  public: static UInt32 GetCurrentProcessId();
};
} // namespace InteropNamespace
using Interop = InteropNamespace::Interop;
} // namespace System::Private::CoreLib
