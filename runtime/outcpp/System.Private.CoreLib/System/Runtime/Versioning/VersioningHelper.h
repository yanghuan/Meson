#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope;
enum class SxSRequirements;
namespace VersioningHelperNamespace {
class VersioningHelper {
  public: static String MakeVersionSafeName(String name, ResourceScope from, ResourceScope to);
  public: static String MakeVersionSafeName(String name, ResourceScope from, ResourceScope to, Type type);
  private: static String GetCLRInstanceString();
  private: static SxSRequirements GetRequirements(ResourceScope consumeAsScope, ResourceScope calleeScope);
  private: static Int32 GetCurrentProcessId();
};
} // namespace VersioningHelperNamespace
using VersioningHelper = VersioningHelperNamespace::VersioningHelper;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
