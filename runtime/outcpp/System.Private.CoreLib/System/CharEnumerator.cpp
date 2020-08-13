#include "CharEnumerator-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::CharEnumeratorNamespace {
Object CharEnumerator___::get_CurrentOfIEnumerator() {
  return get_Current();
}

Char CharEnumerator___::get_Current() {
  if (_index == -1) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_index >= _str->get_Length()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  return _currentElement;
}

void CharEnumerator___::ctor(String str) {
  _str = str;
  _index = -1;
}

Object CharEnumerator___::Clone() {
  return MemberwiseClone();
}

Boolean CharEnumerator___::MoveNext() {
  if (_index < _str->get_Length() - 1) {
    _index++;
    _currentElement = _str[_index];
    return true;
  }
  _index = _str->get_Length();
  return false;
}

void CharEnumerator___::Dispose() {
  if (_str != nullptr) {
    _index = _str->get_Length();
  }
  _str = nullptr;
}

void CharEnumerator___::Reset() {
  _currentElement = 0;
  _index = -1;
}

} // namespace System::Private::CoreLib::System::CharEnumeratorNamespace
