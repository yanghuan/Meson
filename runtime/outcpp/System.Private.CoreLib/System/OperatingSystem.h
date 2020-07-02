#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class PlatformID;
FORWARD(String)
FORWARD(Version)
FORWARD(Object)
namespace OperatingSystemNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(OperatingSystem) {
  public: PlatformID get_Platform();
  public: String get_ServicePack();
  public: Version get_Version();
  public: String get_VersionString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Object Clone();
  public: String ToString();
  private: Version _version;
  private: PlatformID _platform;
  private: String _servicePack;
  private: String _versionString;
};
} // namespace OperatingSystemNamespace
using OperatingSystem = OperatingSystemNamespace::OperatingSystem;
} // namespace System::Private::CoreLib::System
