#include "ArrayEnumerator-dep.h"

#include <System.Private.CoreLib/System/ArrayEnumerator-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::ArrayEnumeratorNamespace {
Object ArrayEnumerator___::get_Current() {
  if (index < startIndex) {
    ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumNotStarted();
  }
  if (_complete) {
    ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumEnded();
  }
  return array->GetValue(_indices);
}

void ArrayEnumerator___::ctor(Array<> array, Int32 index, Int32 count) {
  this->array = array;
  this->index = index - 1;
  startIndex = index;
  endIndex = index + count;
  _indices = rt::newarr<Array<Int32>>(array->get_Rank());
  Int32 num = 1;
  for (Int32 i = 0; i < array->get_Rank(); i++) {
    _indices[i] = array->GetLowerBound(i);
    num *= array->GetLength(i);
  }
}

void ArrayEnumerator___::IncArray() {
  Int32 rank = array->get_Rank();
  _indices[rank - 1]++;
  for (Int32 num = rank - 1; num >= 0; num--) {
    if (_indices[num] > array->GetUpperBound(num)) {
      if (num == 0) {
        _complete = true;
        break;
      }
      for (Int32 i = num; i < rank; i++) {
        _indices[i] = array->GetLowerBound(i);
      }
      _indices[num - 1]++;
    }
  }
}

Object ArrayEnumerator___::Clone() {
  return MemberwiseClone();
}

Boolean ArrayEnumerator___::MoveNext() {
  if (_complete) {
    index = endIndex;
    return false;
  }
  index++;
  IncArray();
  return !_complete;
}

void ArrayEnumerator___::Reset() {
  index = startIndex - 1;
  Int32 num = 1;
  for (Int32 i = 0; i < array->get_Rank(); i++) {
    _indices[i] = array->GetLowerBound(i);
    num *= array->GetLength(i);
  }
  _complete = (num == 0);
}

} // namespace System::Private::CoreLib::System::ArrayEnumeratorNamespace
