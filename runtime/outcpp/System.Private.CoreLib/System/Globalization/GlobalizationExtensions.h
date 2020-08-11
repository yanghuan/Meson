#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(StringComparer)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions : int32_t;
FORWARD(CompareInfo)
namespace GlobalizationExtensionsNamespace {
class GlobalizationExtensions {
  public: static StringComparer GetStringComparer(CompareInfo compareInfo, CompareOptions options);
};
} // namespace GlobalizationExtensionsNamespace
using GlobalizationExtensions = GlobalizationExtensionsNamespace::GlobalizationExtensions;
} // namespace System::Private::CoreLib::System::Globalization
