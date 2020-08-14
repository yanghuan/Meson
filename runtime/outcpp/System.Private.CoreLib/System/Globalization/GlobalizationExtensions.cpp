#include "GlobalizationExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/CultureAwareComparer-dep.h>

namespace System::Private::CoreLib::System::Globalization::GlobalizationExtensionsNamespace {
StringComparer GlobalizationExtensions::GetStringComparer(CompareInfo compareInfo, CompareOptions options) {
  if (compareInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("compareInfo");
  }
  switch (options) {
    case CompareOptions::Ordinal:
      return StringComparer::in::get_Ordinal();
    case CompareOptions::OrdinalIgnoreCase:
      return StringComparer::in::get_OrdinalIgnoreCase();
    default:
      return rt::newobj<CultureAwareComparer>(compareInfo, options);
  }
}

} // namespace System::Private::CoreLib::System::Globalization::GlobalizationExtensionsNamespace
