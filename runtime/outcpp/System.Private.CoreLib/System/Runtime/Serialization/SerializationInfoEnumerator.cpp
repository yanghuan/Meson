#include "SerializationInfoEnumerator-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoEnumeratorNamespace {
Object SerializationInfoEnumerator___::get_CurrentOfIEnumerator() {
  return get_Current();
}

SerializationEntry SerializationInfoEnumerator___::get_Current() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return SerializationEntry(_members[_currItem], _data[_currItem], _types[_currItem]);
}

String SerializationInfoEnumerator___::get_Name() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return _members[_currItem];
}

Object SerializationInfoEnumerator___::get_Value() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return _data[_currItem];
}

Type SerializationInfoEnumerator___::get_ObjectType() {
  if (!_current) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
  }
  return _types[_currItem];
}

void SerializationInfoEnumerator___::ctor(Array<String> members, Array<Object> info, Array<Type> types, Int32 numItems) {
  _members = members;
  _data = info;
  _types = types;
  _numItems = numItems - 1;
  _currItem = -1;
  _current = false;
}

Boolean SerializationInfoEnumerator___::MoveNext() {
  if (_currItem < _numItems) {
    _currItem++;
    _current = true;
  } else {
    _current = false;
  }
  return _current;
}

void SerializationInfoEnumerator___::Reset() {
  _currItem = -1;
  _current = false;
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationInfoEnumeratorNamespace
