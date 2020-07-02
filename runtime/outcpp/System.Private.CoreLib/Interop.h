#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARDS(NativeOverlapped)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeFileHandle)
FORWARD(SafeFindHandle)
FORWARD(SafeLibraryHandle)
FORWARD(SafeWaitHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::System::IO {
enum class FileMode;
enum class FileShare;
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Security {
FORWARD(SafeBSTRHandle)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(EventDescriptor)
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
FORWARD(SafeRegistryHandle)
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
namespace System::Private::CoreLib {
namespace InteropNamespace {
using namespace ::System::Private::CoreLib::Internal::Win32::SafeHandles;
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Diagnostics::Tracing;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
using namespace ::System::Private::CoreLib::System::Security;
using namespace ::System::Private::CoreLib::System::Threading;
class Interop {
  public: enum class BOOL {
    FALSE = 0,
    TRUE = 1,
  };
  public: enum class BOOLEAN : uint8_t {
    FALSE = 0,
    TRUE = 1,
  };
  public: class Kernel32 {
    public: enum class FILE_INFO_BY_HANDLE_CLASS : uint32_t {
      FileBasicInfo = 0,
      FileStandardInfo = 1,
      FileNameInfo = 2,
      FileRenameInfo = 3,
      FileDispositionInfo = 4,
      FileAllocationInfo = 5,
      FileEndOfFileInfo = 6,
      FileStreamInfo = 7,
      FileCompressionInfo = 8,
      FileAttributeTagInfo = 9,
      FileIdBothDirectoryInfo = 10,
      FileIdBothDirectoryRestartInfo = 11,
      FileIoPriorityHintInfo = 12,
      FileRemoteProtocolInfo = 13,
      FileFullDirectoryInfo = 14,
      FileFullDirectoryRestartInfo = 15,
      FileStorageInfo = 16,
      FileAlignmentInfo = 17,
      FileIdInfo = 18,
      FileIdExtdDirectoryInfo = 19,
      FileIdExtdDirectoryRestartInfo = 20,
      MaximumFileInfoByHandleClass = 21,
    };
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
    public: struct SYSTEMTIME {
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
    public: struct FILE_TIME {
      public: UInt32 dwLowDateTime;
      public: UInt32 dwHighDateTime;
    };
    public: struct TIME_DYNAMIC_ZONE_INFORMATION {
      public: String GetTimeZoneKeyName();
      public: Int32 Bias;
      public: rt::FixedBuffer<Char, 32> StandardName;
      public: SYSTEMTIME StandardDate;
      public: Int32 StandardBias;
      public: rt::FixedBuffer<Char, 32> DaylightName;
      public: SYSTEMTIME DaylightDate;
      public: Int32 DaylightBias;
      public: rt::FixedBuffer<Char, 128> TimeZoneKeyName;
      public: Byte DynamicDaylightTimeDisabled;
    };
    public: struct WIN32_FIND_DATA {
      public: UInt32 dwFileAttributes;
      public: FILE_TIME ftCreationTime;
      public: FILE_TIME ftLastAccessTime;
      public: FILE_TIME ftLastWriteTime;
      public: UInt32 nFileSizeHigh;
      public: UInt32 nFileSizeLow;
      public: UInt32 dwReserved0;
      public: UInt32 dwReserved1;
      private: rt::FixedBuffer<Char, 260> _cFileName;
      private: rt::FixedBuffer<Char, 14> _cAlternateFileName;
    };
    public: struct TIME_ZONE_INFORMATION {
      public: String GetStandardName();
      public: String GetDaylightName();
      public: Int32 Bias;
      public: rt::FixedBuffer<Char, 32> StandardName;
      public: SYSTEMTIME StandardDate;
      public: Int32 StandardBias;
      public: rt::FixedBuffer<Char, 32> DaylightName;
      public: SYSTEMTIME DaylightDate;
      public: Int32 DaylightBias;
    };
    public: struct CPINFO {
      public: Int32 MaxCharSize;
      public: rt::FixedBuffer<Byte, 2> DefaultChar;
      public: rt::FixedBuffer<Byte, 12> LeadByte;
    };
    public: struct FILE_STANDARD_INFO {
      public: Int64 AllocationSize;
      public: Int64 EndOfFile;
      public: UInt32 NumberOfLinks;
      public: BOOL DeletePending;
      public: BOOL Directory;
    };
    public: struct PROCESS_MEMORY_COUNTERS {
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
    public: CLASS(EnumLocalesProcEx) {
      public: BOOL Invoke(Char* lpLocaleString, UInt32 dwFlags, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpLocaleString, UInt32 dwFlags, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
    };
    public: CLASS(EnumTimeFormatsProcEx) {
      public: BOOL Invoke(Char* lpTimeFormatString, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpTimeFormatString, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
    };
    public: CLASS(EnumCalendarInfoProcExEx) {
      public: BOOL Invoke(Char* lpCalendarInfoString, UInt32 Calendar, IntPtr lpReserved, void* lParam);
      public: IAsyncResult BeginInvoke(Char* lpCalendarInfoString, UInt32 Calendar, IntPtr lpReserved, void* lParam, AsyncCallback callback, Object object);
      public: BOOL EndInvoke(IAsyncResult result);
    };
    public: struct NlsVersionInfoEx {
      public: Int32 dwNLSVersionInfoSize;
      public: Int32 dwNLSVersion;
      public: Int32 dwDefinedVersion;
      public: Int32 dwEffectiveId;
      public: Guid guidCustomVersion;
    };
    public: struct MEMORY_BASIC_INFORMATION {
      public: void* BaseAddress;
      public: void* AllocationBase;
      public: UInt32 AllocationProtect;
      public: UIntPtr RegionSize;
      public: UInt32 State;
      public: UInt32 Protect;
      public: UInt32 Type;
    };
    public: struct MEMORYSTATUSEX {
      public: Int32 length;
      public: Int32 memoryLoad;
      public: UInt64 totalPhys;
      public: UInt64 availPhys;
      public: UInt64 totalPageFile;
      public: UInt64 availPageFile;
      public: UInt64 totalVirtual;
      public: UInt64 availVirtual;
      public: UInt64 availExtendedVirtual;
    };
    public: struct SECURITY_ATTRIBUTES {
      public: UInt32 nLength;
      public: IntPtr lpSecurityDescriptor;
      public: BOOL bInheritHandle;
    };
    public: struct SYSTEM_INFO {
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
    public: struct WIN32_FILE_ATTRIBUTE_DATA {
      public: void PopulateFrom(WIN32_FIND_DATA& findData);
      public: Int32 dwFileAttributes;
      public: FILE_TIME ftCreationTime;
      public: FILE_TIME ftLastAccessTime;
      public: FILE_TIME ftLastWriteTime;
      public: UInt32 nFileSizeHigh;
      public: UInt32 nFileSizeLow;
    };
    public: struct REG_TZI_FORMAT {
      public: Int32 Bias;
      public: Int32 StandardBias;
      public: Int32 DaylightBias;
      public: SYSTEMTIME StandardDate;
      public: SYSTEMTIME DaylightDate;
    };
    public: struct OSVERSIONINFOEX {
      public: Int32 dwOSVersionInfoSize;
      public: Int32 dwMajorVersion;
      public: Int32 dwMinorVersion;
      public: Int32 dwBuildNumber;
      public: Int32 dwPlatformId;
      public: rt::FixedBuffer<Char, 128> szCSDVersion;
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
    public: static Boolean CancelIoEx(SafeHandle handle, NativeOverlapped* lpOverlapped);
    public: static UInt32 ExpandEnvironmentStrings(String lpSrc, Char& lpDst, UInt32 nSize);
    public: static Boolean FindClose(IntPtr hFindFile);
    private: static SafeFindHandle FindFirstFileExPrivate(String lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, WIN32_FIND_DATA& lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, IntPtr lpSearchFilter, Int32 dwAdditionalFlags);
    public: static SafeFindHandle FindFirstFile(String fileName, WIN32_FIND_DATA& data);
    public: static Boolean FlushFileBuffers(SafeHandle hHandle);
    private: static Int32 GetComputerName(Char& lpBuffer, UInt32& nSize);
    public: static String GetComputerName();
    public: static BOOL GetCPInfo(UInt32 codePage, CPINFO* lpCpInfo);
    public: static UInt32 GetCurrentProcessId();
    public: static IntPtr GetCurrentProcess();
    public: static UInt32 GetCurrentDirectory(UInt32 nBufferLength, Char& lpBuffer);
    private: static Boolean GetFileAttributesExPrivate(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation);
    public: static Boolean GetFileAttributesEx(String name, GET_FILEEX_INFO_LEVELS fileInfoLevel, WIN32_FILE_ATTRIBUTE_DATA& lpFileInformation);
    public: static Boolean GetFileInformationByHandleEx(SafeFileHandle hFile, FILE_INFO_BY_HANDLE_CLASS FileInformationClass, FILE_STANDARD_INFO& lpFileInformation, UInt32 dwBufferSize);
    public: static Int32 GetFileType(SafeHandle hFile);
    public: static UInt32 GetFullPathNameW(Char& lpFileName, UInt32 nBufferLength, Char& lpBuffer, IntPtr lpFilePart);
    public: static UInt32 GetLongPathNameW(Char& lpszShortPath, Char& lpszLongPath, UInt32 cchBuffer);
    public: static Int32 GetLogicalDrives();
    public: static Boolean GetProcessMemoryInfo(IntPtr Process, PROCESS_MEMORY_COUNTERS& ppsmemCounters, UInt32 cb);
    public: static Boolean GetProcessTimes(IntPtr handleProcess, Int64& creation, Int64& exit, Int64& kernel, Int64& user);
    public: static UInt32 GetSystemDirectoryW(Char& lpBuffer, UInt32 uSize);
    public: static void GetSystemInfo(SYSTEM_INFO& lpSystemInfo);
    public: static Boolean GetSystemTimes(Int64& idle, Int64& kernel, Int64& user);
    public: static UInt32 GetTempFileNameW(Char& lpPathName, String lpPrefixString, UInt32 uUnique, Char& lpTempFileName);
    public: static UInt32 GetTempPathW(Int32 bufferLen, Char& buffer);
    public: static Boolean GetVersionExW(OSVERSIONINFOEX& osvi);
    public: static Int32 LCIDToLocaleName(Int32 locale, Char* pLocaleName, Int32 cchName, UInt32 dwFlags);
    public: static Int32 LocaleNameToLCID(String lpName, UInt32 dwFlags);
    public: static Int32 LCMapStringEx(String lpLocaleName, UInt32 dwMapFlags, Char* lpSrcStr, Int32 cchSrc, void* lpDestStr, Int32 cchDest, void* lpVersionInformation, void* lpReserved, IntPtr sortHandle);
    public: static Int32 FindNLSStringEx(Char* lpLocaleName, UInt32 dwFindNLSStringFlags, Char* lpStringSource, Int32 cchSource, Char* lpStringValue, Int32 cchValue, Int32* pcchFound, void* lpVersionInformation, void* lpReserved, IntPtr sortHandle);
    public: static Int32 CompareStringEx(Char* lpLocaleName, UInt32 dwCmpFlags, Char* lpString1, Int32 cchCount1, Char* lpString2, Int32 cchCount2, void* lpVersionInformation, void* lpReserved, IntPtr lParam);
    public: static Int32 CompareStringOrdinal(Char* lpString1, Int32 cchCount1, Char* lpString2, Int32 cchCount2, Boolean bIgnoreCase);
    public: static Int32 FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, Char* lpStringSource, Int32 cchSource, Char* lpStringValue, Int32 cchValue, Int32 bIgnoreCase);
    public: static Boolean IsNLSDefinedString(Int32 Function, UInt32 dwFlags, IntPtr lpVersionInformation, Char* lpString, Int32 cchStr);
    public: static BOOL GetUserPreferredUILanguages(UInt32 dwFlags, UInt32* pulNumLanguages, Char* pwszLanguagesBuffer, UInt32* pcchLanguagesBuffer);
    public: static Int32 GetLocaleInfoEx(String lpLocaleName, UInt32 LCType, void* lpLCData, Int32 cchData);
    public: static Boolean EnumSystemLocalesEx(EnumLocalesProcEx lpLocaleEnumProcEx, UInt32 dwFlags, void* lParam, IntPtr reserved);
    public: static Boolean EnumTimeFormatsEx(EnumTimeFormatsProcEx lpTimeFmtEnumProcEx, String lpLocaleName, UInt32 dwFlags, void* lParam);
    public: static Int32 GetCalendarInfoEx(String lpLocaleName, UInt32 Calendar, IntPtr lpReserved, UInt32 CalType, IntPtr lpCalData, Int32 cchData, Int32& lpValue);
    public: static Int32 GetCalendarInfoEx(String lpLocaleName, UInt32 Calendar, IntPtr lpReserved, UInt32 CalType, IntPtr lpCalData, Int32 cchData, IntPtr lpValue);
    public: static Boolean EnumCalendarInfoExEx(EnumCalendarInfoProcExEx pCalInfoEnumProcExEx, String lpLocaleName, UInt32 Calendar, String lpReserved, UInt32 CalType, void* lParam);
    public: static Boolean GetNLSVersionEx(Int32 function, String localeName, NlsVersionInfoEx* lpVersionInformation);
    public: static Boolean GlobalMemoryStatusEx(MEMORYSTATUSEX& buffer);
    private: static Boolean GlobalMemoryStatusExNative(MEMORYSTATUSEX& lpBuffer);
    public: static Boolean IsWow64Process(IntPtr hProcess, Boolean& Wow64Process);
    public: static Boolean LockFile(SafeFileHandle handle, Int32 offsetLow, Int32 offsetHigh, Int32 countLow, Int32 countHigh);
    public: static Boolean UnlockFile(SafeFileHandle handle, Int32 offsetLow, Int32 offsetHigh, Int32 countLow, Int32 countHigh);
    public: static Int32 MultiByteToWideChar(UInt32 CodePage, UInt32 dwFlags, Byte* lpMultiByteStr, Int32 cbMultiByte, Char* lpWideCharStr, Int32 cchWideChar);
    public: static void OutputDebugString(String message);
    public: static Boolean QueryUnbiasedInterruptTime(UInt64& UnbiasedTime);
    public: static Int32 ReadFile(SafeHandle handle, Byte* bytes, Int32 numBytesToRead, Int32& numBytesRead, IntPtr mustBeZero);
    public: static Int32 ReadFile(SafeHandle handle, Byte* bytes, Int32 numBytesToRead, IntPtr numBytesRead_mustBeZero, NativeOverlapped* overlapped);
    public: static Int32 ResolveLocaleName(String lpNameToResolve, Char* lpLocaleName, Int32 cchLocaleName);
    public: static Boolean SetCurrentDirectory(String path);
    public: static Boolean SetEndOfFile(SafeFileHandle hFile);
    public: static Boolean SetThreadErrorMode(UInt32 dwNewMode, UInt32& lpOldMode);
    public: static Boolean SetFilePointerEx(SafeFileHandle hFile, Int64 liDistanceToMove, Int64& lpNewFilePointer, UInt32 dwMoveMethod);
    public: static UInt32 GetDynamicTimeZoneInformation(TIME_DYNAMIC_ZONE_INFORMATION& pTimeZoneInformation);
    public: static UInt32 GetTimeZoneInformation(TIME_ZONE_INFORMATION& lpTimeZoneInformation);
    public: static void* VirtualAlloc(void* lpAddress, UIntPtr dwSize, Int32 flAllocationType, Int32 flProtect);
    public: static Boolean VirtualFree(void* lpAddress, UIntPtr dwSize, Int32 dwFreeType);
    public: static UIntPtr VirtualQuery(void* lpAddress, MEMORY_BASIC_INFORMATION& lpBuffer, UIntPtr dwLength);
    public: static Int32 WideCharToMultiByte(UInt32 CodePage, UInt32 dwFlags, Char* lpWideCharStr, Int32 cchWideChar, Byte* lpMultiByteStr, Int32 cbMultiByte, IntPtr lpDefaultChar, IntPtr lpUsedDefaultChar);
    public: static Int32 WriteFile(SafeHandle handle, Byte* bytes, Int32 numBytesToWrite, IntPtr numBytesWritten_mustBeZero, NativeOverlapped* lpOverlapped);
    private: static SafeFileHandle CreateFilePrivate(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES& securityAttrs, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile);
    public: static SafeFileHandle CreateFile(String lpFileName, Int32 dwDesiredAccess, FileShare dwShareMode, SECURITY_ATTRIBUTES& securityAttrs, FileMode dwCreationDisposition, Int32 dwFlagsAndAttributes, IntPtr hTemplateFile);
    public: static Boolean FreeLibrary(IntPtr hModule);
    public: static SafeLibraryHandle LoadLibraryEx(String libFilename, IntPtr reserved, Int32 flags);
    public: static Boolean GetFileMUIPath(UInt32 dwFlags, String pcwszFilePath, Char* pwszLanguage, Int32& pcchLanguage, Char* pwszFileMUIPath, Int32& pcchFileMUIPath, Int64& pululEnumerator);
    public: static Boolean VerifyVersionInfoW(OSVERSIONINFOEX& lpVersionInfo, UInt32 dwTypeMask, UInt64 dwlConditionMask);
    public: static UInt64 VerSetConditionMask(UInt64 ConditionMask, UInt32 TypeMask, Byte Condition);
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
  public: CLASS(OleAut32) {
    public: static IntPtr SysAllocStringByteLen(Array<Byte> str, UInt32 len);
    public: static SafeBSTRHandle SysAllocStringLen(IntPtr src, UInt32 len);
    public: static IntPtr SysAllocStringLen(String src, Int32 len);
    public: static void SysFreeString(IntPtr bstr);
    public: static UInt32 SysStringLen(SafeBSTRHandle bstr);
    public: static UInt32 SysStringLen(IntPtr bstr);
  };
  public: CLASS(Advapi32) {
    public: enum class ActivityControl : uint32_t {
      EVENT_ACTIVITY_CTRL_GET_ID = 1,
      EVENT_ACTIVITY_CTRL_SET_ID = 2,
      EVENT_ACTIVITY_CTRL_CREATE_ID = 3,
      EVENT_ACTIVITY_CTRL_GET_SET_ID = 4,
      EVENT_ACTIVITY_CTRL_CREATE_SET_ID = 5,
    };
    public: enum class EVENT_INFO_CLASS {
      BinaryTrackInfo = 0,
      SetEnableAllKeywords = 1,
      SetTraits = 2,
    };
    public: enum class TRACE_QUERY_INFO_CLASS {
      TraceGuidQueryList = 0,
      TraceGuidQueryInfo = 1,
      TraceGuidQueryProcess = 2,
      TraceStackTracingInfo = 3,
      MaxTraceSetInfoClass = 4,
    };
    public: struct EVENT_FILTER_DESCRIPTOR {
      public: Int64 Ptr;
      public: Int32 Size;
      public: Int32 Type;
    };
    public: CLASS(EtwEnableCallback) {
      public: void Invoke(Guid& sourceId, Int32 isEnabled, Byte level, Int64 matchAnyKeywords, Int64 matchAllKeywords, EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext);
      public: IAsyncResult BeginInvoke(Guid& sourceId, Int32 isEnabled, Byte level, Int64 matchAnyKeywords, Int64 matchAllKeywords, EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext, AsyncCallback callback, Object object);
      public: void EndInvoke(Guid& sourceId, IAsyncResult result);
    };
    public: struct TRACE_GUID_INFO {
      public: Int32 InstanceCount;
      public: Int32 Reserved;
    };
    public: struct TRACE_PROVIDER_INSTANCE_INFO {
      public: Int32 NextOffset;
      public: Int32 EnableCount;
      public: Int32 Pid;
      public: Int32 Flags;
    };
    public: struct TRACE_ENABLE_INFO {
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
  public: CLASS(BCrypt) {
    public: enum class NTSTATUS : uint32_t {
      STATUS_SUCCESS = 0,
      STATUS_NOT_FOUND = 3221226021,
      STATUS_INVALID_PARAMETER = 3221225485,
      STATUS_NO_MEMORY = 3221225495,
      STATUS_AUTH_TAG_MISMATCH = 3221266434,
    };
    public: static NTSTATUS BCryptGenRandom(IntPtr hAlgorithm, Byte* pbBuffer, Int32 cbBuffer, Int32 dwFlags);
  };
  public: CLASS(Crypt32) {
    public: static Boolean CryptProtectMemory(SafeBSTRHandle pData, UInt32 cbData, UInt32 dwFlags);
    public: static Boolean CryptUnprotectMemory(SafeBSTRHandle pData, UInt32 cbData, UInt32 dwFlags);
  };
  public: CLASS(Normaliz) {
    public: static Int32 IdnToAscii(UInt32 dwFlags, Char* lpUnicodeCharStr, Int32 cchUnicodeChar, Char* lpASCIICharStr, Int32 cchASCIIChar);
    public: static Int32 IdnToUnicode(UInt32 dwFlags, Char* lpASCIICharStr, Int32 cchASCIIChar, Char* lpUnicodeCharStr, Int32 cchUnicodeChar);
    public: static Boolean IsNormalizedString(Int32 normForm, String source, Int32 length);
    public: static Int32 NormalizeString(Int32 normForm, String source, Int32 sourceLength, Array<Char> destination, Int32 destinationLength);
  };
  public: CLASS(Secur32) {
    public: static BOOLEAN GetUserNameExW(Int32 NameFormat, Char& lpNameBuffer, UInt32& lpnSize);
  };
  public: CLASS(Shell32) {
    public: static Int32 SHGetKnownFolderPath(Guid rfid, UInt32 dwFlags, IntPtr hToken, String& ppszPath);
  };
  public: CLASS(NtDll) {
    public: struct IO_STATUS {
      private: Int32 Status;
      private: IntPtr Pointer;
    };
    public: struct SYSTEM_LEAP_SECOND_INFORMATION {
      public: Boolean Enabled;
      public: UInt32 Flags;
    };
    public: struct IO_STATUS_BLOCK {
      private: IO_STATUS Status;
      private: IntPtr Information;
    };
    public: static Int32 NtQuerySystemInformation(Int32 SystemInformationClass, void* SystemInformation, Int32 SystemInformationLength, UInt32* ReturnLength);
    public: static Int32 NtQueryInformationFile(SafeFileHandle FileHandle, IO_STATUS_BLOCK& IoStatusBlock, void* FileInformation, UInt32 Length, UInt32 FileInformationClass);
  };
  public: CLASS(User32) {
    public: static Int32 LoadString(SafeLibraryHandle hInstance, UInt32 uID, Char* lpBuffer, Int32 cchBufferMax);
    public: static IntPtr SendMessageTimeout(IntPtr hWnd, Int32 msg, IntPtr wParam, String lParam, Int32 flags, Int32 timeout, IntPtr pdwResult);
  };
  public: static void GetRandomBytes(Byte* buffer, Int32 length);
  public: static UInt32 GetCurrentProcessId();
};
} // namespace InteropNamespace
using Interop = InteropNamespace::Interop;
} // namespace System::Private::CoreLib
