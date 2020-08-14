#include "ArrayWithOffset-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ArrayWithOffset-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ArrayWithOffsetNamespace {
using namespace System::Runtime::CompilerServices;

ArrayWithOffset::ArrayWithOffset(Object array, Int32 offset) {
  Int32 num = 0;
  if (array != nullptr) {
    Array<> array2 = rt::as<Array<>>(array);
    if (array2 == nullptr || array2->get_Rank() != 1 || !Marshal::IsPinnable(array2)) {
      rt::throw_exception<ArgumentException>(SR::get_ArgumentException_NotIsomorphic());
    }
    UIntPtr num2 = (UIntPtr)((IntPtr)array2->get_LongLength() * RuntimeHelpers::GetElementSize(array2));
    if (num2 > 2147483632) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_StructArrayTooLarge());
    }
    num = (Int32)num2;
  }
  if ((UInt32)offset > (UInt32)num) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_ArrayWithOffset());
  }
  m_array = array;
  m_offset = offset;
  m_count = num - offset;
}

Object ArrayWithOffset::GetArray() {
  return m_array;
}

Int32 ArrayWithOffset::GetOffset() {
  return m_offset;
}

Int32 ArrayWithOffset::GetHashCode() {
  return m_count + m_offset;
}

Boolean ArrayWithOffset::Equals(Object obj) {
  if (rt::is<ArrayWithOffset>(obj)) {
    return Equals((ArrayWithOffset)obj);
  }
  return false;
}

Boolean ArrayWithOffset::Equals(ArrayWithOffset obj) {
  if (obj.m_array == m_array && obj.m_offset == m_offset) {
    return obj.m_count == m_count;
  }
  return false;
}

Boolean ArrayWithOffset::op_Equality(ArrayWithOffset a, ArrayWithOffset b) {
  return a.Equals(b);
}

Boolean ArrayWithOffset::op_Inequality(ArrayWithOffset a, ArrayWithOffset b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ArrayWithOffsetNamespace
