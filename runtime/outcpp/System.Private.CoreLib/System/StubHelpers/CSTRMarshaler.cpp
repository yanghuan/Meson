#include "CSTRMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::CSTRMarshalerNamespace {
using namespace System::Runtime::InteropServices;

IntPtr CSTRMarshaler::ConvertToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer) {
  if (strManaged == nullptr) {
    return IntPtr::Zero;
  }
  Byte* ptr = (Byte*)(void*)pNativeBuffer;
  Int32 num;
  if (ptr != nullptr || Marshal::SystemMaxDBCSCharSize == 1) {
    num = (strManaged->get_Length() + 1) * Marshal::SystemMaxDBCSCharSize + 1;
    Boolean flag = false;
    if (ptr == nullptr) {
      ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(num);
      flag = true;
    }
    try{
    } catch (Exception) {
    }
  } else if (strManaged->get_Length() == 0) {
    num = 0;
    ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(2);
  } else {
  }

  ptr[num] = 0;
  ptr[num + 1] = 0;
  return (IntPtr)(void*)ptr;
}

String CSTRMarshaler::ConvertToManaged(IntPtr cstr) {
  if (IntPtr::Zero == cstr) {
    return nullptr;
  }
  return rt::newobj<String>((SByte*)(void*)cstr);
}

void CSTRMarshaler::ClearNative(IntPtr pNative) {
  Interop::Ole32::CoTaskMemFree(pNative);
}

void CSTRMarshaler::ConvertFixedToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer, Int32 length) {
  if (strManaged == nullptr) {
    if (length > 0) {
      *(SByte*)(void*)pNativeBuffer = 0;
    }
    return;
  }
  Int32 num = strManaged->get_Length();
  if (num >= length) {
    num = length - 1;
  }
  Byte* ptr = (Byte*)(void*)pNativeBuffer;
  Boolean flag = flags >> 8 != 0;
}

String CSTRMarshaler::ConvertFixedToManaged(IntPtr cstr, Int32 length) {
  Int32 num = length + 2;
  if (num < length) {
    rt::throw_exception<OutOfMemoryException>();
  }
  Span<SByte> span = Span<SByte>((void*)cstr, length);
  Int32 num2 = num;
  Byte default[(Int32)(UInt32)num2] = {};
  Span<SByte> span2 = Span<SByte>(default, num2);
  Span<SByte> destination = span2;
  span.CopyTo(destination);
  destination[length - 1] = 0;
  destination[length] = 0;
  destination[length + 1] = 0;
  {
    SByte* ptr = destination;
    return rt::newobj<String>(ptr, 0, String::in::strlen((Byte*)ptr));
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::CSTRMarshalerNamespace
