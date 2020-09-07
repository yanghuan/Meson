#include "FormattableString-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>

namespace System::Private::CoreLib::System::FormattableStringNamespace {
using namespace System::Globalization;

String FormattableString___::ToStringOfIFormattable(String ignored, IFormatProvider formatProvider) {
  return ToString(formatProvider);
}

String FormattableString___::Invariant(FormattableString formattable) {
  if (formattable == nullptr) {
    rt::throw_exception<ArgumentNullException>("formattable");
  }
  return formattable->ToString(CultureInfo::in::get_InvariantCulture());
}

String FormattableString___::CurrentCulture(FormattableString formattable) {
  if (formattable == nullptr) {
    rt::throw_exception<ArgumentNullException>("formattable");
  }
  return formattable->ToString(CultureInfo::in::get_CurrentCulture());
}

String FormattableString___::ToString() {
  return ToString(CultureInfo::in::get_CurrentCulture());
}

void FormattableString___::ctor() {
}

} // namespace System::Private::CoreLib::System::FormattableStringNamespace
