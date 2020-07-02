#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(StringComparer)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
enum class CompareOptions;
namespace GlobalizationExtensionsNamespace {
class GlobalizationExtensions {
  public: static StringComparer GetStringComparer(CompareInfo compareInfo, CompareOptions options);
};
} // namespace GlobalizationExtensionsNamespace
using GlobalizationExtensions = GlobalizationExtensionsNamespace::GlobalizationExtensions;
} // namespace System::Private::CoreLib::System::Globalization
