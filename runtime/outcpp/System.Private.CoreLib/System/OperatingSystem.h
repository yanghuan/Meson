#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class PlatformID : int32_t;
FORWARDS(Boolean)
FORWARD(ICloneable)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Version)
namespace OperatingSystemNamespace {
using namespace System::Runtime::Serialization;
CLASS(OperatingSystem) : public object {
  public: using interface = rt::TypeList<ISerializable, ICloneable>;
  public: PlatformID get_Platform();
  public: String get_ServicePack();
  public: Version get_Version();
  public: String get_VersionString();
  public: void ctor(PlatformID platform, Version version);
  public: void ctor(PlatformID platform, Version version, String servicePack);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Object Clone();
  public: String ToString();
  public: static Boolean IsOSPlatform(String platform);
  public: static Boolean IsOSPlatformVersionAtLeast(String platform, Int32 major, Int32 minor = 0, Int32 build = 0, Int32 revision = 0);
  public: static Boolean IsBrowser();
  public: static Boolean IsLinux();
  public: static Boolean IsFreeBSD();
  public: static Boolean IsFreeBSDVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0, Int32 revision = 0);
  public: static Boolean IsAndroid();
  public: static Boolean IsAndroidVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0, Int32 revision = 0);
  public: static Boolean IsIOS();
  public: static Boolean IsIOSVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0);
  public: static Boolean IsMacOS();
  public: static Boolean IsMacOSVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0);
  public: static Boolean IsTvOS();
  public: static Boolean IsTvOSVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0);
  public: static Boolean IsWatchOS();
  public: static Boolean IsWatchOSVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0);
  public: static Boolean IsWindows();
  public: static Boolean IsWindowsVersionAtLeast(Int32 major, Int32 minor = 0, Int32 build = 0, Int32 revision = 0);
  private: static Boolean IsOSVersionAtLeast(Int32 major, Int32 minor, Int32 build, Int32 revision);
  private: Version _version;
  private: PlatformID _platform;
  private: String _servicePack;
  private: String _versionString;
};
} // namespace OperatingSystemNamespace
using OperatingSystem = OperatingSystemNamespace::OperatingSystem;
} // namespace System::Private::CoreLib::System
