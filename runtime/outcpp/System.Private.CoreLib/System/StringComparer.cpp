#include "StringComparer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/CultureAwareComparer-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IComparable.h>
#include <System.Private.CoreLib/System/OrdinalCaseSensitiveComparer-dep.h>
#include <System.Private.CoreLib/System/OrdinalIgnoreCaseComparer-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>

namespace System::Private::CoreLib::System::StringComparerNamespace {
using namespace System::Globalization;

StringComparer StringComparer___::get_InvariantCulture() {
  return s_invariantCulture;
}

StringComparer StringComparer___::get_InvariantCultureIgnoreCase() {
  return s_invariantCultureIgnoreCase;
}

StringComparer StringComparer___::get_CurrentCulture() {
  return rt::newobj<CultureAwareComparer>(CultureInfo::in::get_CurrentCulture(), CompareOptions::None);
}

StringComparer StringComparer___::get_CurrentCultureIgnoreCase() {
  return rt::newobj<CultureAwareComparer>(CultureInfo::in::get_CurrentCulture(), CompareOptions::IgnoreCase);
}

StringComparer StringComparer___::get_Ordinal() {
  return s_ordinal;
}

StringComparer StringComparer___::get_OrdinalIgnoreCase() {
  return s_ordinalIgnoreCase;
}

StringComparer StringComparer___::FromComparison(StringComparison comparisonType) {
}

StringComparer StringComparer___::Create(CultureInfo culture, Boolean ignoreCase) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  return rt::newobj<CultureAwareComparer>(culture, ignoreCase ? CompareOptions::IgnoreCase : CompareOptions::None);
}

StringComparer StringComparer___::Create(CultureInfo culture, CompareOptions options) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  return rt::newobj<CultureAwareComparer>(culture, options);
}

Int32 StringComparer___::Compare(Object x, Object y) {
  if (x == y) {
    return 0;
  }
  if (x == nullptr) {
    return -1;
  }
  if (y == nullptr) {
    return 1;
  }
  String text = rt::as<String>(x);
  if (text != nullptr) {
    String text2 = rt::as<String>(y);
    if (text2 != nullptr) {
      return Compare(text, text2);
    }
  }
  IComparable<> comparable = rt::as<IComparable<>>(x);
  if (comparable != nullptr) {
    return comparable->CompareTo(y);
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ImplementIComparable());
}

Boolean StringComparer___::Equals(Object x, Object y) {
  if (x == y) {
    return true;
  }
  if (x == nullptr || y == nullptr) {
    return false;
  }
  String text = rt::as<String>(x);
  if (text != nullptr) {
    String text2 = rt::as<String>(y);
    if (text2 != nullptr) {
      return Equals(text, text2);
    }
  }
  return x->Equals(y);
}

Int32 StringComparer___::GetHashCode(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  String text = rt::as<String>(obj);
  if (text != nullptr) {
    return GetHashCode(text);
  }
  return obj->GetHashCode();
}

void StringComparer___::ctor() {
}

void StringComparer___::cctor() {
  s_invariantCulture = rt::newobj<CultureAwareComparer>(CultureInfo::in::get_InvariantCulture(), CompareOptions::None);
  s_invariantCultureIgnoreCase = rt::newobj<CultureAwareComparer>(CultureInfo::in::get_InvariantCulture(), CompareOptions::IgnoreCase);
  s_ordinal = rt::newobj<OrdinalCaseSensitiveComparer>();
  s_ordinalIgnoreCase = rt::newobj<OrdinalIgnoreCaseComparer>();
}

} // namespace System::Private::CoreLib::System::StringComparerNamespace
