#include "EnumeratorViewOfEnumVariant-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumeratorViewOfEnumVariantNamespace {
Object EnumeratorViewOfEnumVariant___::get_Current() {
  return _current;
}

void EnumeratorViewOfEnumVariant___::ctor(IEnumVARIANT enumVariantObject) {
  _nextArray = rt::newarr<Array<Object>>(1);
  Object::in::ctor();
  _enumVariantObject = enumVariantObject;
  _fetchedLastObject = false;
  _current = nullptr;
}

Boolean EnumeratorViewOfEnumVariant___::MoveNext() {
  if (_fetchedLastObject) {
    _current = nullptr;
    return false;
  }
  Int32 num = 0;
  if (_enumVariantObject->Next(1, _nextArray, (IntPtr)(&num)) == 1) {
    _fetchedLastObject = true;
    if (num == 0) {
      _current = nullptr;
      return false;
    }
  }
  _current = _nextArray[0];
  return true;
}

void EnumeratorViewOfEnumVariant___::Reset() {
  Int32 num = _enumVariantObject->Reset();
  if (num < 0) {
    Marshal::ThrowExceptionForHR(num);
  }
}

Object EnumeratorViewOfEnumVariant___::GetUnderlyingObject() {
  return _enumVariantObject;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumeratorViewOfEnumVariantNamespace
