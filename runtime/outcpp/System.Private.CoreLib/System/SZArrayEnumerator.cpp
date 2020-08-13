#include "SZArrayEnumerator-dep.h"

#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::SZArrayEnumeratorNamespace {
Object SZArrayEnumerator___::get_Current() {
  if (_index < 0) {
    ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumNotStarted();
  }
  if (_index >= _endIndex) {
    ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumEnded();
  }
  return _array->GetValue(_index);
}

void SZArrayEnumerator___::ctor(Array<> array) {
  _array = array;
  _index = -1;
  _endIndex = array->get_Length();
}

Object SZArrayEnumerator___::Clone() {
  return MemberwiseClone();
}

Boolean SZArrayEnumerator___::MoveNext() {
  if (_index < _endIndex) {
    _index++;
    return _index < _endIndex;
  }
  return false;
}

void SZArrayEnumerator___::Reset() {
  _index = -1;
}

} // namespace System::Private::CoreLib::System::SZArrayEnumeratorNamespace
