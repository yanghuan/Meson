#include "StringRuneEnumerator-dep.h"

#include <System.Private.CoreLib/System/Text/StringRuneEnumerator-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::StringRuneEnumeratorNamespace {
Rune StringRuneEnumerator::get_Current() {
  return _current;
}

Object StringRuneEnumerator::get_CurrentOfIEnumerator() {
  return _current;
}

StringRuneEnumerator::StringRuneEnumerator(String value) {
  _string = value;
  _current = rt::default__;
  _nextIndex = 0;
}

StringRuneEnumerator StringRuneEnumerator::GetEnumerator() {
  return *this;
}

Boolean StringRuneEnumerator::MoveNext() {
  if ((UInt32)_nextIndex >= _string->get_Length()) {
    _current = rt::default__;
    return false;
  }
  if (!Rune::TryGetRuneAt(_string, _nextIndex, _current)) {
    _current = Rune::get_ReplacementChar();
  }
  _nextIndex += _current.get_Utf16SequenceLength();
  return true;
}

} // namespace System::Private::CoreLib::System::Text::StringRuneEnumeratorNamespace
