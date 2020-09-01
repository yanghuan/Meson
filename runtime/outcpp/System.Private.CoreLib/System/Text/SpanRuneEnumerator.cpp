#include "SpanRuneEnumerator-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Text/SpanRuneEnumerator-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::SpanRuneEnumeratorNamespace {
Rune SpanRuneEnumerator::get_Current() {
  return _current;
}

SpanRuneEnumerator::SpanRuneEnumerator(ReadOnlySpan<Char> buffer) {
  _remaining = buffer;
  _current = rt::default__;
}

SpanRuneEnumerator SpanRuneEnumerator::GetEnumerator() {
  return *this;
}

Boolean SpanRuneEnumerator::MoveNext() {
  if (_remaining.get_IsEmpty()) {
    _current = rt::default__;
    return false;
  }
  Int32 num = Rune::ReadFirstRuneFromUtf16Buffer(_remaining);
  if (num < 0) {
    num = Rune::get_ReplacementChar().get_Value();
  }
  _current = Rune::UnsafeCreate((UInt32)num);
  _remaining = _remaining.Slice(_current.get_Utf16SequenceLength());
  return true;
}

} // namespace System::Private::CoreLib::System::Text::SpanRuneEnumeratorNamespace
