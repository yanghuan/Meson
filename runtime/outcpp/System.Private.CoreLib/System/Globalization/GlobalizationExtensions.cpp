#include "GlobalizationExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Globalization::GlobalizationExtensionsNamespace {
StringComparer GlobalizationExtensions::GetStringComparer(CompareInfo compareInfo, CompareOptions options) {
  if (compareInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("compareInfo");
  }
}

} // namespace System::Private::CoreLib::System::Globalization::GlobalizationExtensionsNamespace
