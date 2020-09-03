#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope : int32_t;
enum class SxSRequirements : int32_t;
namespace VersioningHelperNamespace {
class VersioningHelper {
  public: static String MakeVersionSafeName(String name, ResourceScope from, ResourceScope to);
  public: static String MakeVersionSafeName(String name, ResourceScope from, ResourceScope to, Type type);
  private: static String GetCLRInstanceString();
  private: static SxSRequirements GetRequirements(ResourceScope consumeAsScope, ResourceScope calleeScope);
};
} // namespace VersioningHelperNamespace
using VersioningHelper = VersioningHelperNamespace::VersioningHelper;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
