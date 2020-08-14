#include "CompatibleComparer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/IComparable.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Collections::CompatibleComparerNamespace {
IHashCodeProvider CompatibleComparer___::get_HashCodeProvider() {
  return _hcp;
}

IComparer CompatibleComparer___::get_Comparer() {
  return _comparer;
}

void CompatibleComparer___::ctor(IHashCodeProvider hashCodeProvider, IComparer comparer) {
  _hcp = hashCodeProvider;
  _comparer = comparer;
}

Boolean CompatibleComparer___::Equals(Object a, Object b) {
  return Compare(a, b) == 0;
}

Int32 CompatibleComparer___::Compare(Object a, Object b) {
  if (a == b) {
    return 0;
  }
  if (a == nullptr) {
    return -1;
  }
  if (b == nullptr) {
    return 1;
  }
  if (_comparer != nullptr) {
    return _comparer->Compare(a, b);
  }
  IComparable comparable = rt::as<IComparable>(a);
  if (comparable != nullptr) {
    return comparable->CompareTo(b);
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_ImplementIComparable());
}

Int32 CompatibleComparer___::GetHashCode(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  if (_hcp == nullptr) {
    return obj->GetHashCode();
  }
  return _hcp->GetHashCode(obj);
}

} // namespace System::Private::CoreLib::System::Collections::CompatibleComparerNamespace
