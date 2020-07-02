#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace TargetFrameworkAttributeNamespace {
CLASS(TargetFrameworkAttribute) {
  public: String get_FrameworkName();
  public: String get_FrameworkDisplayName();
  public: void set_FrameworkDisplayName(String value);
  private: String _frameworkName;
  private: String _frameworkDisplayName;
};
} // namespace TargetFrameworkAttributeNamespace
using TargetFrameworkAttribute = TargetFrameworkAttributeNamespace::TargetFrameworkAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
