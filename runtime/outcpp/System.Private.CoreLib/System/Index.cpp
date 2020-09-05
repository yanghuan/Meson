#include "Index-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Index-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IndexNamespace {
Index Index::get_Start() {
  return Index(0);
}

Index Index::get_End() {
  return Index(-1);
}

Int32 Index::get_Value() {
  if (_value < 0) {
    return ~_value;
  }
  return _value;
}

Boolean Index::get_IsFromEnd() {
  return _value < 0;
}

Index::Index(Int32 value, Boolean fromEnd) {
  if (value < 0) {
    ThrowHelper::ThrowValueArgumentOutOfRange_NeedNonNegNumException();
  }
  if (fromEnd) {
    _value = ~value;
  } else {
    _value = value;
  }
}

Index::Index(Int32 value) {
  _value = value;
}

Index Index::FromStart(Int32 value) {
  if (value < 0) {
    ThrowHelper::ThrowValueArgumentOutOfRange_NeedNonNegNumException();
  }
  return Index(value);
}

Index Index::FromEnd(Int32 value) {
  if (value < 0) {
    ThrowHelper::ThrowValueArgumentOutOfRange_NeedNonNegNumException();
  }
  return Index(~value);
}

Int32 Index::GetOffset(Int32 length) {
  Int32 num = _value;
  if (get_IsFromEnd()) {
    num += length + 1;
  }
  return num;
}

Boolean Index::Equals(Object value) {
  if (rt::is<Index>(value)) {
    return _value == ((Index)value)._value;
  }
  return false;
}

Boolean Index::Equals(Index other) {
  return _value == other._value;
}

Int32 Index::GetHashCode() {
  return _value;
}

Index Index::op_Implicit(Int32 value) {
  return FromStart(value);
}

String Index::ToString() {
  if (get_IsFromEnd()) {
    return ToStringFromEnd();
  }
  return ((UInt32)get_Value()).ToString();
}

String Index::ToStringFromEnd() {
  Char as[11] = {};
  Span<Char> span = as;
  Int32 charsWritten;
  Boolean flag = ((UInt32)get_Value()).TryFormat(span.Slice(1), charsWritten);
  span[0] = 94;
  return rt::newstr<String>(span.Slice(0, charsWritten + 1));
}

} // namespace System::Private::CoreLib::System::IndexNamespace
