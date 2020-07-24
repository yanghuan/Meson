#include "StringRuneEnumerator-dep.h"

#include <System.Private.CoreLib/System/Text/StringRuneEnumerator-dep.h>

namespace System::Private::CoreLib::System::Text::StringRuneEnumeratorNamespace {
Rune StringRuneEnumerator::get_Current() {
  return Rune();
};

Object StringRuneEnumerator::get_CurrentOfIEnumerator() {
  return nullptr;
};

StringRuneEnumerator::StringRuneEnumerator(String value) {
};

StringRuneEnumerator StringRuneEnumerator::GetEnumerator() {
  return StringRuneEnumerator();
};

Boolean StringRuneEnumerator::MoveNext() {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Text::StringRuneEnumeratorNamespace
