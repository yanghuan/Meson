#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(StringComparer)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions;
FORWARD(CompareInfo)
namespace GlobalizationExtensionsNamespace {
class GlobalizationExtensions : public Object::in {
  public: static StringComparer GetStringComparer(CompareInfo compareInfo, CompareOptions options);
};
} // namespace GlobalizationExtensionsNamespace
using GlobalizationExtensions = GlobalizationExtensionsNamespace::GlobalizationExtensions;
} // namespace System::Private::CoreLib::System::Globalization
