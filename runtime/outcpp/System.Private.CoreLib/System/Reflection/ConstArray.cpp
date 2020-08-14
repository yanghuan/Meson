#include "ConstArray-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>

namespace System::Private::CoreLib::System::Reflection::ConstArrayNamespace {
IntPtr ConstArray::get_Signature() {
  return m_constArray;
}

Int32 ConstArray::get_Length() {
  return m_length;
}

Byte ConstArray::get_Item(Int32 index) {
  if (index < 0 || index >= m_length) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  return ((Byte*)m_constArray.ToPointer())[index];
}

} // namespace System::Private::CoreLib::System::Reflection::ConstArrayNamespace
