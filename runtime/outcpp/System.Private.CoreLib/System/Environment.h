#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionary)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::Internal::Win32 {
FORWARD(RegistryKey)
} // namespace System::Private::CoreLib::Internal::Win32
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
enum class EnvironmentVariableTarget : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(OperatingSystem)
FORWARD(String)
FORWARD(Version)
namespace EnvironmentNamespace {
using namespace Internal::Win32;
using namespace System::Collections;
using namespace System::Text;
class Environment {
  public: enum class SpecialFolder : int32_t {
    ApplicationData = 26,
    CommonApplicationData = 35,
    LocalApplicationData = 28,
    Cookies = 33,
    Desktop = 0,
    Favorites = 6,
    History = 34,
    InternetCache = 32,
    Programs = 2,
    MyComputer = 17,
    MyMusic = 13,
    MyPictures = 39,
    MyVideos = 14,
    Recent = 8,
    SendTo = 9,
    StartMenu = 11,
    Startup = 7,
    System = 37,
    Templates = 21,
    DesktopDirectory = 16,
    Personal = 5,
    MyDocuments = 5,
    ProgramFiles = 38,
    CommonProgramFiles = 43,
    AdminTools = 48,
    CDBurning = 59,
    CommonAdminTools = 47,
    CommonDocuments = 46,
    CommonMusic = 53,
    CommonOemLinks = 58,
    CommonPictures = 54,
    CommonStartMenu = 22,
    CommonPrograms = 23,
    CommonStartup = 24,
    CommonDesktopDirectory = 25,
    CommonTemplates = 45,
    CommonVideos = 55,
    Fonts = 20,
    NetworkShortcuts = 19,
    PrinterShortcuts = 27,
    UserProfile = 40,
    CommonProgramFilesX86 = 44,
    ProgramFilesX86 = 42,
    Resources = 56,
    LocalizedResources = 57,
    SystemX86 = 41,
    Windows = 36,
  };
  public: enum class SpecialFolderOption : int32_t {
    None = 0,
    Create = 32768,
    DoNotVerify = 16384,
  };
  private: class WindowsVersion {
    private: static Boolean GetIsWindows8OrAbove();
    public: static void cctor();
    public: static Boolean IsWindows8OrAbove;
  };
  public: static Int32 get_CurrentManagedThreadId();
  public: static Int32 get_ExitCode();
  public: static void set_ExitCode(Int32 value);
  public: static String get_StackTrace();
  public: static Int32 get_TickCount();
  public: static Int64 get_TickCount64();
  public: static Int32 get_ProcessorCount();
  public: static Boolean get_IsSingleProcessor();
  public: static Boolean get_HasShutdownStarted();
  public: static String get_CommandLine();
  public: static String get_CurrentDirectory();
  public: static void set_CurrentDirectory(String value);
  public: static Int32 get_ProcessId();
  public: static Boolean get_Is64BitProcess();
  public: static Boolean get_Is64BitOperatingSystem();
  public: static String get_NewLine();
  public: static OperatingSystem get_OSVersion();
  public: static Version get_Version();
  public: static Boolean get_IsWindows8OrAbove();
  public: static String get_UserName();
  public: static String get_UserDomainName();
  private: static String get_CurrentDirectoryCore();
  private: static void set_CurrentDirectoryCore(String value);
  public: static Int32 get_SystemPageSize();
  public: static String get_MachineName();
  public: static String get_SystemDirectory();
  public: static Boolean get_UserInteractive();
  public: static Int64 get_WorkingSet();
  private: static void _Exit(Int32 exitCode);
  public: static void Exit(Int32 exitCode);
  public: static void FailFast(String message);
  public: static void FailFast(String message, Exception exception);
  public: static void FailFast(String message, Exception exception, String errorMessage);
  private: static Array<String> GetCommandLineArgsNative();
  public: static Array<String> GetCommandLineArgs();
  private: static Int32 GetProcessorCount();
  public: static String GetResourceStringLocal(String key);
  public: static String GetEnvironmentVariable(String variable);
  public: static String GetEnvironmentVariable(String variable, EnvironmentVariableTarget target);
  public: static IDictionary GetEnvironmentVariables(EnvironmentVariableTarget target);
  public: static void SetEnvironmentVariable(String variable, String value);
  public: static void SetEnvironmentVariable(String variable, String value, EnvironmentVariableTarget target);
  public: static String ExpandEnvironmentVariables(String name);
  public: static void SetCommandLineArgs(Array<String> cmdLineArgs);
  public: static String GetFolderPath(SpecialFolder folder);
  public: static String GetFolderPath(SpecialFolder folder, SpecialFolderOption option);
  private: static Boolean ValidateAndConvertRegistryTarget(EnvironmentVariableTarget target);
  private: static void ValidateVariableAndValue(String variable, String& value);
  private: static String GetEnvironmentVariableFromRegistry(String variable, Boolean fromMachine);
  private: static void SetEnvironmentVariableFromRegistry(String variable, String value, Boolean fromMachine);
  private: static IDictionary GetEnvironmentVariablesFromRegistry(Boolean fromMachine);
  private: static RegistryKey OpenEnvironmentKeyIfExists(Boolean fromMachine, Boolean writable);
  private: static void GetUserName(ValueStringBuilder& builder);
  private: static String GetFolderPathCore(SpecialFolder folder, SpecialFolderOption option);
  private: static String GetKnownFolderPath(String folderGuid, SpecialFolderOption option);
  public: static Array<String> GetLogicalDrives();
  private: static String ExpandEnvironmentVariablesCore(String name);
  private: static Int32 GetCurrentProcessId();
  private: static OperatingSystem GetOSVersion();
  private: static String GetEnvironmentVariableCore(String variable);
  private: static void SetEnvironmentVariableCore(String variable, String value);
  public: static IDictionary GetEnvironmentVariables();
  public: static void cctor();
  private: static Int32 ProcessorCount;
  private: static Array<String> s_commandLineArgs;
  private: static Int32 s_processId;
  private: static Boolean s_haveProcessId;
  private: static OperatingSystem s_osVersion;
};
} // namespace EnvironmentNamespace
using Environment = EnvironmentNamespace::Environment;
} // namespace System::Private::CoreLib::System
