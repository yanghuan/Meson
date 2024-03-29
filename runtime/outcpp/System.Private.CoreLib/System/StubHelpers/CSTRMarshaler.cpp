#include "CSTRMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/AnsiCharMarshaler-dep.h>
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
    try {
      num = Marshal::StringToAnsiString(strManaged, ptr, num, (flags & 255) != 0, flags >> 8 != 0);
    } catch (Exception) {
      Marshal::FreeCoTaskMem((IntPtr)ptr);
      throw;
    }
  } else if (strManaged->get_Length() == 0) {
    num = 0;
    ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(2);
  } else {
    Array<Byte> array = AnsiCharMarshaler::DoAnsiConversion(strManaged, (flags & 255) != 0, flags >> 8 != 0, num);
    ptr = (Byte*)(void*)Marshal::AllocCoTaskMem(num + 2);
    {
      Byte* src = rt::fixed(&array[0]);
      Buffer::Memcpy(ptr, src, num);
    }
  }

  *(ptr + num) = 0;
  *(ptr + num + 1) = 0;
  return (IntPtr)ptr;
}

String CSTRMarshaler::ConvertToManaged(IntPtr cstr) {
  if (IntPtr::Zero == cstr) {
    return nullptr;
  }
  return rt::newstr<String>((SByte*)(void*)cstr);
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
  Boolean flag2 = (flags & 255) != 0;
  UInt32 num2 = 0u;
  Int32 num3;
  {
    Char* ptr2 = rt::fixed(strManaged);
    Char* lpWideCharStr = ptr2;
    num3 = Interop::Kernel32::WideCharToMultiByte(0u, (!flag2) ? 1024u : 0u, lpWideCharStr, num, ptr, length, IntPtr::Zero, flag ? IntPtr(&num2) : IntPtr::Zero);
  }
  if (num2 != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Interop_Marshal_Unmappable_Char());
  }
  if (num3 == length) {
    num3--;
  }
  *(ptr + num3) = 0;
}

String CSTRMarshaler::ConvertFixedToManaged(IntPtr cstr, Int32 length) {
  Int32 num = length + 2;
  if (num < length) {
    rt::throw_exception<OutOfMemoryException>();
  }
  Span<SByte> span = Span<SByte>((void*)cstr, length);
  SByte as[num] = {};
  Span<SByte> destination = as;
  span.CopyTo(destination);
  destination[length - 1] = 0;
  destination[length] = 0;
  destination[length + 1] = 0;
  {
    SByte* ptr = rt::fixed(destination);
    return rt::newstr<String>(ptr, 0, String::in::strlen((Byte*)ptr));
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::CSTRMarshalerNamespace
