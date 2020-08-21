#include "Environment-dep.h"

#include <System.Private.CoreLib/Internal/Win32/Registry-dep.h>
#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ApplicationModel-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/DriveInfoInternal-dep.h>
#include <System.Private.CoreLib/System/IO/PathHelper-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/PasteArguments-dep.h>
#include <System.Private.CoreLib/System/PlatformID.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::EnvironmentNamespace {
using namespace Internal::Win32;
using namespace System::Buffers;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading;

String Environment::WinRTFolderPaths::GetFolderPath(SpecialFolder folder, SpecialFolderOption option) {
  if (s_winRTFolderPathsGetFolderPath == nullptr) {
    auto& as = Type::in::GetType("System.WinRTFolderPaths, System.Runtime.WindowsRuntime, Version=4.0.14.0, Culture=neutral, PublicKeyToken=b77a5c561934e089", false);
    auto& as = (as == nullptr ? nullptr : as->GetMethod("GetFolderPath", BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic, nullptr, rt::newarr<Array<Type>>(2), nullptr));
    Func<SpecialFolder, SpecialFolderOption, String> func = (Func<SpecialFolder, SpecialFolderOption, String>)(as == nullptr ? nullptr : as->CreateDelegate(rt::typeof<Func<SpecialFolder, SpecialFolderOption, String>>()));
  }
  return s_winRTFolderPathsGetFolderPath(folder, option);
}

Boolean Environment::WindowsVersion::GetIsWindows8OrAbove() {
  UInt64 conditionMask = Interop::Kernel32::VerSetConditionMask(0, 2u, 3);
  conditionMask = Interop::Kernel32::VerSetConditionMask(conditionMask, 1u, 3);
  conditionMask = Interop::Kernel32::VerSetConditionMask(conditionMask, 32u, 3);
  conditionMask = Interop::Kernel32::VerSetConditionMask(conditionMask, 16u, 3);
  Interop::Kernel32::OSVERSIONINFOEX lpVersionInfo = Interop::Kernel32::OSVERSIONINFOEX();
  lpVersionInfo.dwOSVersionInfoSize = sizeof(Interop::Kernel32::OSVERSIONINFOEX);
  lpVersionInfo.dwMajorVersion = 6;
  lpVersionInfo.dwMinorVersion = 2;
  lpVersionInfo.wServicePackMajor = 0;
  lpVersionInfo.wServicePackMinor = 0;
  return Interop::Kernel32::VerifyVersionInfoW(lpVersionInfo, 51u, conditionMask);
}

void Environment::WindowsVersion::cctor() {
  IsWindows8OrAbove = GetIsWindows8OrAbove();
}

Int32 Environment::get_CurrentManagedThreadId() {
  return Thread::in::get_CurrentThread()->get_ManagedThreadId();
}

String Environment::get_StackTrace() {
  return rt::newobj<StackTrace>(true)->ToString(StackTrace::in::TraceFormat::Normal);
}

Int32 Environment::get_ProcessorCount() {
  return ProcessorCount;
}

Boolean Environment::get_IsSingleProcessor() {
  return ProcessorCount == 1;
}

Boolean Environment::get_HasShutdownStarted() {
  return false;
}

String Environment::get_CommandLine() {
  return PasteArguments::Paste(GetCommandLineArgs(), true);
}

String Environment::get_CurrentDirectory() {
  return get_CurrentDirectoryCore();
}

void Environment::set_CurrentDirectory(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_PathEmpty(), "value");
  }
  get_CurrentDirectoryCore(value);
}

Boolean Environment::get_Is64BitProcess() {
  return IntPtr::get_Size() == 8;
}

Boolean Environment::get_Is64BitOperatingSystem() {
  if (!get_Is64BitProcess()) {
    return get_Is64BitOperatingSystemWhen32BitProcess();
  }
  return true;
}

String Environment::get_NewLine() {
  return "
";
}

OperatingSystem Environment::get_OSVersion() {
  if (s_osVersion == nullptr) {
    Interlocked::CompareExchange(s_osVersion, GetOSVersion(), (OperatingSystem)nullptr);
  }
  return s_osVersion;
}

Version Environment::get_Version() {
  auto& as = CustomAttributeExtensions::GetCustomAttribute(rt::typeof<Object>()->get_Assembly());
  String text = as == nullptr ? nullptr : as->get_InformationalVersion();
  ReadOnlySpan<Char> readOnlySpan = MemoryExtensions::AsSpan(text);
  Int32 num = MemoryExtensions::IndexOfAny(readOnlySpan, 45, 43, 32);
  if (num != -1) {
    readOnlySpan = readOnlySpan.Slice(0, num);
  }
  Version result;
  if (!Version::in::TryParse(readOnlySpan, result)) {
    return rt::newobj<Version>();
  }
  return result;
}

Boolean Environment::get_IsWindows8OrAbove() {
  return WindowsVersion::IsWindows8OrAbove;
}

String Environment::get_UserName() {
  if (ApplicationModel::IsUap) {
    return "Windows User";
  }
  Char as[40] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetUserName(builder);
  ReadOnlySpan<Char> span = builder.AsSpan();
  Int32 num = MemoryExtensions::IndexOf(span, 92);
  if (num != -1) {
    span = span.Slice(num + 1);
  }
  String result = span.ToString();
  builder.Dispose();
  return result;
}

String Environment::get_UserDomainName() {
  if (ApplicationModel::IsUap) {
    return "Windows Domain";
  }
  Char as[40] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder builder = ValueStringBuilder(initialBuffer);
  GetUserName(builder);
  ReadOnlySpan<Char> span = builder.AsSpan();
  Int32 num = MemoryExtensions::IndexOf(span, 92);
  if (num != -1) {
    builder.set_Length(num);
    return builder.ToString();
  }
  Char as[64] = {};
  initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  UInt32 cchReferencedDomainName = (UInt32)valueStringBuilder.get_Capacity();
  Byte in[68] = {};
  Span<Byte> span2 = Span<Byte>(in, 68);
  Span<Byte> span3 = span2;
  UInt32 cbSid = 68u;
  UInt32 peUse;
  while (!Interop::Advapi32::LookupAccountNameW(nullptr, builder.GetPinnableReference(), MemoryMarshal::GetReference(span3), cbSid, valueStringBuilder.GetPinnableReference(), cchReferencedDomainName, peUse)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    if (lastWin32Error != 122) {
      rt::throw_exception<InvalidOperationException>(Win32Marshal::GetMessage(lastWin32Error));
    }
    valueStringBuilder.EnsureCapacity((Int32)cchReferencedDomainName);
  }
  builder.Dispose();
  valueStringBuilder.set_Length((Int32)cchReferencedDomainName);
  return valueStringBuilder.ToString();
}

String Environment::get_CurrentDirectoryCore() {
  Char as[260] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder outputBuilder = ValueStringBuilder(initialBuffer);
  UInt32 currentDirectory;
  while ((currentDirectory = Interop::Kernel32::GetCurrentDirectory((UInt32)outputBuilder.get_Capacity(), outputBuilder.GetPinnableReference())) > outputBuilder.get_Capacity()) {
    outputBuilder.EnsureCapacity((Int32)currentDirectory);
  }
  if (currentDirectory == 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  outputBuilder.set_Length((Int32)currentDirectory);
  if (MemoryExtensions::Contains(outputBuilder.AsSpan(), 126)) {
    String result = PathHelper::TryExpandShortFileName(outputBuilder, nullptr);
    outputBuilder.Dispose();
    return result;
  }
  return outputBuilder.ToString();
}

void Environment::set_CurrentDirectoryCore(String value) {
  if (!Interop::Kernel32::SetCurrentDirectory(value)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    rt::throw_exception(Win32Marshal::GetExceptionForWin32Error((lastWin32Error == 2) ? 3 : lastWin32Error, value));
  }
}

Int32 Environment::get_SystemPageSize() {
  Interop::Kernel32::SYSTEM_INFO lpSystemInfo;
  Interop::Kernel32::GetSystemInfo(lpSystemInfo);
  return lpSystemInfo.dwPageSize;
}

Boolean Environment::get_Is64BitOperatingSystemWhen32BitProcess() {
  Boolean Wow64Process;
  return Interop::Kernel32::IsWow64Process(Interop::Kernel32::GetCurrentProcess(), Wow64Process) && Wow64Process;
}

String Environment::get_MachineName() {
  String computerName = Interop::Kernel32::GetComputerName();
  if (computerName == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ComputerName());
  }
  return computerName;
}

String Environment::get_SystemDirectory() {
  Char as[32] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  UInt32 systemDirectoryW;
  while ((systemDirectoryW = Interop::Kernel32::GetSystemDirectoryW(valueStringBuilder.GetPinnableReference(), (UInt32)valueStringBuilder.get_Capacity())) > valueStringBuilder.get_Capacity()) {
    valueStringBuilder.EnsureCapacity((Int32)systemDirectoryW);
  }
  if (systemDirectoryW == 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  valueStringBuilder.set_Length((Int32)systemDirectoryW);
  return valueStringBuilder.ToString();
}

Boolean Environment::get_UserInteractive() {
  IntPtr processWindowStation = Interop::User32::GetProcessWindowStation();
  if (processWindowStation != IntPtr::Zero) {
    Interop::User32::USEROBJECTFLAGS uSEROBJECTFLAGS = Interop::User32::USEROBJECTFLAGS();
    UInt32 lpnLengthNeeded = 0u;
    if (Interop::User32::GetUserObjectInformationW(processWindowStation, 1, &uSEROBJECTFLAGS, (UInt32)sizeof(Interop::User32::USEROBJECTFLAGS), lpnLengthNeeded)) {
      return (uSEROBJECTFLAGS.dwFlags & 1) != 0;
    }
  }
  return true;
}

Int64 Environment::get_WorkingSet() {
  Interop::Kernel32::PROCESS_MEMORY_COUNTERS ppsmemCounters = Interop::Kernel32::PROCESS_MEMORY_COUNTERS();
  ppsmemCounters.cb = (UInt32)sizeof(Interop::Kernel32::PROCESS_MEMORY_COUNTERS);
  if (!Interop::Kernel32::GetProcessMemoryInfo(Interop::Kernel32::GetCurrentProcess(), ppsmemCounters, ppsmemCounters.cb)) {
    return 0;
  }
  return (Int64)(UInt64)ppsmemCounters.WorkingSetSize;
}

void Environment::Exit(Int32 exitCode) {
  _Exit(exitCode);
}

Array<String> Environment::GetCommandLineArgs() {
  if (s_commandLineArgs == nullptr) {
    return GetCommandLineArgsNative();
  }
  return (Array<String>)s_commandLineArgs->Clone();
}

String Environment::GetResourceStringLocal(String key) {
  return SR::GetResourceString(key);
}

String Environment::GetEnvironmentVariable(String variable) {
  if (variable == nullptr) {
    rt::throw_exception<ArgumentNullException>("variable");
  }
  return GetEnvironmentVariableCore(variable);
}

String Environment::GetEnvironmentVariable(String variable, EnvironmentVariableTarget target) {
  if (target == EnvironmentVariableTarget::Process) {
    return GetEnvironmentVariable(variable);
  }
  if (variable == nullptr) {
    rt::throw_exception<ArgumentNullException>("variable");
  }
  Boolean fromMachine = ValidateAndConvertRegistryTarget(target);
  return GetEnvironmentVariableFromRegistry(variable, fromMachine);
}

IDictionary Environment::GetEnvironmentVariables(EnvironmentVariableTarget target) {
  if (target == EnvironmentVariableTarget::Process) {
    return GetEnvironmentVariables();
  }
  Boolean fromMachine = ValidateAndConvertRegistryTarget(target);
  return GetEnvironmentVariablesFromRegistry(fromMachine);
}

void Environment::SetEnvironmentVariable(String variable, String value) {
  ValidateVariableAndValue(variable, value);
  SetEnvironmentVariableCore(variable, value);
}

void Environment::SetEnvironmentVariable(String variable, String value, EnvironmentVariableTarget target) {
  if (target == EnvironmentVariableTarget::Process) {
    SetEnvironmentVariable(variable, value);
    return;
  }
  ValidateVariableAndValue(variable, value);
  Boolean fromMachine = ValidateAndConvertRegistryTarget(target);
  SetEnvironmentVariableFromRegistry(variable, value, fromMachine);
}

String Environment::ExpandEnvironmentVariables(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    return name;
  }
  return ExpandEnvironmentVariablesCore(name);
}

void Environment::SetCommandLineArgs(Array<String> cmdLineArgs) {
  s_commandLineArgs = cmdLineArgs;
}

String Environment::GetFolderPath(SpecialFolder folder) {
  return GetFolderPath(folder, SpecialFolderOption::None);
}

String Environment::GetFolderPath(SpecialFolder folder, SpecialFolderOption option) {
  if (!Enum::in::IsDefined(rt::typeof<SpecialFolder>(), folder)) {
    rt::throw_exception<ArgumentOutOfRangeException>("folder", folder, SR::Format(SR::get_Arg_EnumIllegalVal(), folder));
  }
  if (option != 0 && !Enum::in::IsDefined(rt::typeof<SpecialFolderOption>(), option)) {
    rt::throw_exception<ArgumentOutOfRangeException>("option", option, SR::Format(SR::get_Arg_EnumIllegalVal(), option));
  }
  return GetFolderPathCore(folder, option);
}

Boolean Environment::ValidateAndConvertRegistryTarget(EnvironmentVariableTarget target) {
  switch (target) {
    case EnvironmentVariableTarget::Machine:
      return true;
    case EnvironmentVariableTarget::User:
      return false;
    default:
      rt::throw_exception<ArgumentOutOfRangeException>("target", target, SR::Format(SR::get_Arg_EnumIllegalVal(), target));
  }
}

void Environment::ValidateVariableAndValue(String variable, String& value) {
  if (variable == nullptr) {
    rt::throw_exception<ArgumentNullException>("variable");
  }
  if (variable->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StringZeroLength(), "variable");
  }
  if (variable[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StringFirstCharIsZero(), "variable");
  }
  if (variable->Contains(61)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalEnvVarName(), "variable");
  }
  if (String::in::IsNullOrEmpty(value) || value[0] == 0) {
    value = nullptr;
  }
}

String Environment::GetEnvironmentVariableFromRegistry(String variable, Boolean fromMachine) {
  if (ApplicationModel::IsUap) {
    return nullptr;
  }
  {
    RegistryKey registryKey = OpenEnvironmentKeyIfExists(fromMachine, false);
    rt::Using(registryKey);
    auto& as = registryKey;
    return rt::as<String>(as == nullptr ? nullptr : as->GetValue(variable));
  }
}

void Environment::SetEnvironmentVariableFromRegistry(String variable, String value, Boolean fromMachine) {
  if (ApplicationModel::IsUap) {
    return;
  }
  if (!fromMachine && variable->get_Length() >= 255) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_LongEnvVarValue(), "variable");
  }
  {
    RegistryKey registryKey = OpenEnvironmentKeyIfExists(fromMachine, true);
    rt::Using(registryKey);
    if (registryKey != nullptr) {
      if (value == nullptr) {
        registryKey->DeleteValue(variable, false);
      } else {
        registryKey->SetValue(variable, value);
      }
    }
  }
  {
    Char* value2 = "Environment";
    IntPtr pdwResult;
    IntPtr intPtr = Interop::User32::SendMessageTimeout(IntPtr(65535), 26, IntPtr::Zero, (IntPtr)(void*)value2, 0, 1000, pdwResult);
  }
}

IDictionary Environment::GetEnvironmentVariablesFromRegistry(Boolean fromMachine) {
  Hashtable hashtable = rt::newobj<Hashtable>();
  if (ApplicationModel::IsUap) {
    return hashtable;
  }
  {
    RegistryKey registryKey = OpenEnvironmentKeyIfExists(fromMachine, false);
    rt::Using(registryKey);
    if (registryKey != nullptr) {
      Array<String> valueNames = registryKey->GetValueNames();
    }
    return hashtable;
  }
}

RegistryKey Environment::OpenEnvironmentKeyIfExists(Boolean fromMachine, Boolean writable) {
  RegistryKey registryKey;
  String name;
  if (fromMachine) {
    registryKey = Registry::LocalMachine;
    name = "System\CurrentControlSet\Control\Session Manager\Environment";
  } else {
    registryKey = Registry::CurrentUser;
    name = "Environment";
  }
  return registryKey->OpenSubKey(name, writable);
}

void Environment::GetUserName(ValueStringBuilder& builder) {
  UInt32 lpnSize = 0u;
  while (Interop::Secur32::GetUserNameExW(2, builder.GetPinnableReference(), lpnSize) == Interop::BOOLEAN::FALSE) {
    if (Marshal::GetLastWin32Error() == 234) {
      builder.EnsureCapacity((Int32)lpnSize);
      continue;
    }
    builder.set_Length(0);
    return;
  }
  builder.set_Length((Int32)lpnSize);
}

String Environment::GetFolderPathCore(SpecialFolder folder, SpecialFolderOption option) {
  if (ApplicationModel::IsUap) {
    return WinRTFolderPaths::GetFolderPath(folder, option);
  }
  String folderGuid;
  switch (folder) {
    case SpecialFolder::ApplicationData:
      folderGuid = "{3EB685DB-65F9-4CF6-A03A-E3EF65729F3D}";
      break;
    case SpecialFolder::CommonApplicationData:
      folderGuid = "{62AB5D82-FDC1-4DC3-A9DD-070D1D495D97}";
      break;
    case SpecialFolder::LocalApplicationData:
      folderGuid = "{F1B32785-6FBA-4FCF-9D55-7B8E7F157091}";
      break;
    case SpecialFolder::Cookies:
      folderGuid = "{2B0F765D-C0E9-4171-908E-08A611B84FF6}";
      break;
    case SpecialFolder::Desktop:
      folderGuid = "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}";
      break;
    case SpecialFolder::Favorites:
      folderGuid = "{1777F761-68AD-4D8A-87BD-30B759FA33DD}";
      break;
    case SpecialFolder::History:
      folderGuid = "{D9DC8A3B-B784-432E-A781-5A1130A75963}";
      break;
    case SpecialFolder::InternetCache:
      folderGuid = "{352481E8-33BE-4251-BA85-6007CAEDCF9D}";
      break;
    case SpecialFolder::Programs:
      folderGuid = "{A77F5D77-2E2B-44C3-A6A2-ABA601054A51}";
      break;
    case SpecialFolder::MyComputer:
      folderGuid = "{0AC0837C-BBF8-452A-850D-79D08E667CA7}";
      break;
    case SpecialFolder::MyMusic:
      folderGuid = "{4BD8D571-6D19-48D3-BE97-422220080E43}";
      break;
    case SpecialFolder::MyPictures:
      folderGuid = "{33E28130-4E1E-4676-835A-98395C3BC3BB}";
      break;
    case SpecialFolder::MyVideos:
      folderGuid = "{18989B1D-99B5-455B-841C-AB7C74E4DDFC}";
      break;
    case SpecialFolder::Recent:
      folderGuid = "{AE50C081-EBD2-438A-8655-8A092E34987A}";
      break;
    case SpecialFolder::SendTo:
      folderGuid = "{8983036C-27C0-404B-8F08-102D10DCFD74}";
      break;
    case SpecialFolder::StartMenu:
      folderGuid = "{625B53C3-AB48-4EC1-BA1F-A1EF4146FC19}";
      break;
    case SpecialFolder::Startup:
      folderGuid = "{B97D20BB-F46A-4C97-BA10-5E3608430854}";
      break;
    case SpecialFolder::System:
      folderGuid = "{1AC14E77-02E7-4E5D-B744-2EB1AE5198B7}";
      break;
    case SpecialFolder::Templates:
      folderGuid = "{A63293E8-664E-48DB-A079-DF759E0509F7}";
      break;
    case SpecialFolder::DesktopDirectory:
      folderGuid = "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}";
      break;
    case SpecialFolder::Personal:
      folderGuid = "{FDD39AD0-238F-46AF-ADB4-6C85480369C7}";
      break;
    case SpecialFolder::ProgramFiles:
      folderGuid = "{905e63b6-c1bf-494e-b29c-65b732d3d21a}";
      break;
    case SpecialFolder::CommonProgramFiles:
      folderGuid = "{F7F1ED05-9F6D-47A2-AAAE-29D317C6F066}";
      break;
    case SpecialFolder::AdminTools:
      folderGuid = "{724EF170-A42D-4FEF-9F26-B60E846FBA4F}";
      break;
    case SpecialFolder::CDBurning:
      folderGuid = "{9E52AB10-F80D-49DF-ACB8-4330F5687855}";
      break;
    case SpecialFolder::CommonAdminTools:
      folderGuid = "{D0384E7D-BAC3-4797-8F14-CBA229B392B5}";
      break;
    case SpecialFolder::CommonDocuments:
      folderGuid = "{ED4824AF-DCE4-45A8-81E2-FC7965083634}";
      break;
    case SpecialFolder::CommonMusic:
      folderGuid = "{3214FAB5-9757-4298-BB61-92A9DEAA44FF}";
      break;
    case SpecialFolder::CommonOemLinks:
      folderGuid = "{C1BAE2D0-10DF-4334-BEDD-7AA20B227A9D}";
      break;
    case SpecialFolder::CommonPictures:
      folderGuid = "{B6EBFB86-6907-413C-9AF7-4FC2ABF07CC5}";
      break;
    case SpecialFolder::CommonStartMenu:
      folderGuid = "{A4115719-D62E-491D-AA7C-E74B8BE3B067}";
      break;
    case SpecialFolder::CommonPrograms:
      folderGuid = "{0139D44E-6AFE-49F2-8690-3DAFCAE6FFB8}";
      break;
    case SpecialFolder::CommonStartup:
      folderGuid = "{82A5EA35-D9CD-47C5-9629-E15D2F714E6E}";
      break;
    case SpecialFolder::CommonDesktopDirectory:
      folderGuid = "{C4AA340D-F20F-4863-AFEF-F87EF2E6BA25}";
      break;
    case SpecialFolder::CommonTemplates:
      folderGuid = "{B94237E7-57AC-4347-9151-B08C6C32D1F7}";
      break;
    case SpecialFolder::CommonVideos:
      folderGuid = "{2400183A-6185-49FB-A2D8-4A392A602BA3}";
      break;
    case SpecialFolder::Fonts:
      folderGuid = "{FD228CB7-AE11-4AE3-864C-16F3910AB8FE}";
      break;
    case SpecialFolder::NetworkShortcuts:
      folderGuid = "{C5ABBF53-E17F-4121-8900-86626FC2C973}";
      break;
    case SpecialFolder::PrinterShortcuts:
      folderGuid = "{76FC4E2D-D6AD-4519-A663-37BD56068185}";
      break;
    case SpecialFolder::UserProfile:
      folderGuid = "{5E6C858F-0E22-4760-9AFE-EA3317B67173}";
      break;
    case SpecialFolder::CommonProgramFilesX86:
      folderGuid = "{DE974D24-D9C6-4D3E-BF91-F4455120B917}";
      break;
    case SpecialFolder::ProgramFilesX86:
      folderGuid = "{7C5A40EF-A0FB-4BFC-874A-C0F2E0B9FA8E}";
      break;
    case SpecialFolder::Resources:
      folderGuid = "{8AD10C31-2ADB-4296-A8F7-E4701232C972}";
      break;
    case SpecialFolder::LocalizedResources:
      folderGuid = "{2A00375E-224C-49DE-B8D1-440DF7EF3DDC}";
      break;
    case SpecialFolder::SystemX86:
      folderGuid = "{D65231B0-B2F1-4857-A4CE-A8E7C6EA7D27}";
      break;
    case SpecialFolder::Windows:
      folderGuid = "{F38BF404-1D43-42F2-9305-67DE0B28FC23}";
      break;
    default:
      return String::in::Empty;
  }
  return GetKnownFolderPath(folderGuid, option);
}

String Environment::GetKnownFolderPath(String folderGuid, SpecialFolderOption option) {
  Guid rfid = Guid(folderGuid);
  String ppszPath;
  if (Interop::Shell32::SHGetKnownFolderPath(rfid, (UInt32)option, IntPtr::Zero, ppszPath) != 0) {
    return String::in::Empty;
  }
  return ppszPath;
}

Array<String> Environment::GetLogicalDrives() {
  return DriveInfoInternal::GetLogicalDrives();
}

String Environment::ExpandEnvironmentVariablesCore(String name) {
  Char as[128] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  UInt32 num;
  while ((num = Interop::Kernel32::ExpandEnvironmentStrings(name, valueStringBuilder.GetPinnableReference(), (UInt32)valueStringBuilder.get_Capacity())) > valueStringBuilder.get_Capacity()) {
    valueStringBuilder.EnsureCapacity((Int32)num);
  }
  if (num == 0) {
    Marshal::ThrowExceptionForHR(Marshal::GetHRForLastWin32Error());
  }
  valueStringBuilder.set_Length((Int32)(num - 1));
  return valueStringBuilder.ToString();
}

OperatingSystem Environment::GetOSVersion() {
  Interop::NtDll::RTL_OSVERSIONINFOEX osvi;
  if (Interop::NtDll::RtlGetVersionEx(osvi) != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_GetVersion());
  }
  Version version = rt::newobj<Version>((Int32)osvi.dwMajorVersion, (Int32)osvi.dwMinorVersion, (Int32)osvi.dwBuildNumber, 0);
  if (*osvi.szCSDVersion == 0) {
    return rt::newobj<OperatingSystem>(PlatformID::Win32NT, version);
  }
  return rt::newobj<OperatingSystem>(PlatformID::Win32NT, version, rt::newobj<String>(osvi.szCSDVersion));
}

String Environment::GetEnvironmentVariableCore(String variable) {
  Char as[128] = {};
  Span<Char> buffer = as;
  Int32 environmentVariable = Interop::Kernel32::GetEnvironmentVariable(variable, buffer);
  if (environmentVariable == 0 && Marshal::GetLastWin32Error() == 203) {
    return nullptr;
  }
  if (environmentVariable <= buffer.get_Length()) {
    return rt::newobj<String>(buffer.Slice(0, environmentVariable));
  }
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(environmentVariable);
  try {
    buffer = array;
    environmentVariable = Interop::Kernel32::GetEnvironmentVariable(variable, buffer);
    if ((environmentVariable == 0 && Marshal::GetLastWin32Error() == 203) || environmentVariable > buffer.get_Length()) {
      return nullptr;
    }
    return rt::newobj<String>(buffer.Slice(0, environmentVariable));
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
}

void Environment::SetEnvironmentVariableCore(String variable, String value) {
  if (!Interop::Kernel32::SetEnvironmentVariable(variable, value)) {
    Int32 lastWin32Error = Marshal::GetLastWin32Error();
    switch (lastWin32Error.get()) {
      case 203:
        break;
      case 206:
        rt::throw_exception<ArgumentException>(SR::get_Argument_LongEnvVarValue());
      case 8:
      case 1450:
        rt::throw_exception<OutOfMemoryException>(Interop::Kernel32::GetMessage(lastWin32Error));
      default:
        rt::throw_exception<ArgumentException>(Interop::Kernel32::GetMessage(lastWin32Error));
    }
  }
}

IDictionary Environment::GetEnvironmentVariables() {
  Char* environmentStrings = Interop::Kernel32::GetEnvironmentStrings();
  if (environmentStrings == nullptr) {
    rt::throw_exception<OutOfMemoryException>();
  }
  try {
    Char* ptr;
    for (ptr = environmentStrings; *ptr != 0 || ptr[1] != 0; ptr++) {
    }
    Span<Char> span = Span<Char>(environmentStrings, (Int32)(ptr - environmentStrings + 1));
    Hashtable hashtable = rt::newobj<Hashtable>();
    for (Int32 i = 0; i < span.get_Length(); i++) {
      Int32 num = i;
      for (; span[i] != 61 && span[i] != 0; i++) {
      }
      if (span[i] == 0) {
        continue;
      }
      if (i - num == 0) {
        for (; span[i] != 0; i++) {
        }
        continue;
      }
      String key = rt::newobj<String>(span.Slice(num, i - num));
      i++;
      Int32 num2 = i;
      for (; span[i] != 0; i++) {
      }
      String value = rt::newobj<String>(span.Slice(num2, i - num2));
      try {
        hashtable->Add(key, value);
      } catch (ArgumentException) {
      }
    }
    return hashtable;
  } catch (...) {
  } finally: {
    Boolean flag = Interop::Kernel32::FreeEnvironmentStrings(environmentStrings);
  }
}

void Environment::cctor() {
  ProcessorCount = GetProcessorCount();
}

} // namespace System::Private::CoreLib::System::EnvironmentNamespace
