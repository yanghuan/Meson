#include "AsAnyMarshaler-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ArrayWithOffset-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/VarEnum.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/AsAnyMarshaler-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/MngdNativeArrayMarshaler-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/StubHelpers-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::StubHelpers::AsAnyMarshalerNamespace {
using namespace System::Runtime::InteropServices;

Boolean AsAnyMarshaler::IsIn(Int32 dwFlags) {
}

Boolean AsAnyMarshaler::IsOut(Int32 dwFlags) {
}

Boolean AsAnyMarshaler::IsAnsi(Int32 dwFlags) {
}

Boolean AsAnyMarshaler::IsThrowOn(Int32 dwFlags) {
}

Boolean AsAnyMarshaler::IsBestFit(Int32 dwFlags) {
}

AsAnyMarshaler::AsAnyMarshaler(IntPtr pvArrayMarshaler) {
  this->pvArrayMarshaler = pvArrayMarshaler;
  backPropAction = BackPropAction::None;
  layoutType = nullptr;
  cleanupWorkList = nullptr;
}

IntPtr AsAnyMarshaler::ConvertArrayToNative(Object pManagedHome, Int32 dwFlags) {
  Type elementType = pManagedHome->GetType()->GetElementType();
  VarEnum varEnum = VarEnum::VT_EMPTY;
}

IntPtr AsAnyMarshaler::ConvertStringToNative(String pManagedHome, Int32 dwFlags) {
  IntPtr intPtr;
  if (IsAnsi(dwFlags)) {
  } else {
    Int32 num = (pManagedHome->get_Length() + 1) * 2;
    intPtr = Marshal::AllocCoTaskMem(num);
    String::in::InternalCopy(pManagedHome, intPtr, num);
  }
  return intPtr;
}

IntPtr AsAnyMarshaler::ConvertStringBuilderToNative(StringBuilder pManagedHome, Int32 dwFlags) {
  IntPtr intPtr;
  if (IsAnsi(dwFlags)) {
    StubHelpers::CheckStringLength(pManagedHome->get_Capacity());
    Int32 num = pManagedHome->get_Capacity() * Marshal::SystemMaxDBCSCharSize + 4;
    intPtr = Marshal::AllocCoTaskMem(num);
    Byte* ptr = (Byte*)(void*)intPtr;
    *(ptr + num - 3) = 0;
    *(ptr + num - 2) = 0;
    *(ptr + num - 1) = 0;
    if (IsIn(dwFlags)) {
      Int32 num2 = Marshal::StringToAnsiString(pManagedHome->ToString(), ptr, num, IsBestFit(dwFlags), IsThrowOn(dwFlags));
    }
    if (IsOut(dwFlags)) {
      backPropAction = BackPropAction::StringBuilderAnsi;
    }
  } else {
    Int32 num3 = pManagedHome->get_Capacity() * 2 + 4;
    intPtr = Marshal::AllocCoTaskMem(num3);
    Byte* ptr2 = (Byte*)(void*)intPtr;
    *(ptr2 + num3 - 1) = 0;
    *(ptr2 + num3 - 2) = 0;
    if (IsIn(dwFlags)) {
      Int32 num4 = pManagedHome->get_Length() * 2;
      pManagedHome->InternalCopy(intPtr, num4);
      ptr2[num4] = 0;
      (ptr2 + num4)[1] = 0;
    }
    if (IsOut(dwFlags)) {
      backPropAction = BackPropAction::StringBuilderUnicode;
    }
  }
  return intPtr;
}

IntPtr AsAnyMarshaler::ConvertLayoutToNative(Object pManagedHome, Int32 dwFlags) {
  Int32 cb = Marshal::SizeOfHelper(pManagedHome->GetType(), false);
  IntPtr intPtr = Marshal::AllocCoTaskMem(cb);
  if (IsIn(dwFlags)) {
    StubHelpers::FmtClassUpdateNativeInternal(pManagedHome, (Byte*)(void*)intPtr, cleanupWorkList);
  }
  if (IsOut(dwFlags)) {
    backPropAction = BackPropAction::Layout;
  }
  layoutType = pManagedHome->GetType();
  return intPtr;
}

IntPtr AsAnyMarshaler::ConvertToNative(Object pManagedHome, Int32 dwFlags) {
  if (pManagedHome == nullptr) {
    return IntPtr::Zero;
  }
  if (rt::is<ArrayWithOffset>(pManagedHome)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MarshalAsAnyRestriction());
  }
  if (pManagedHome->GetType()->get_IsArray()) {
    return ConvertArrayToNative(pManagedHome, dwFlags);
  }
  String text = rt::as<String>(pManagedHome);
  if (text != nullptr) {
    return ConvertStringToNative(text, dwFlags);
  }
  StringBuilder stringBuilder = rt::as<StringBuilder>(pManagedHome);
  if (stringBuilder != nullptr) {
    return ConvertStringBuilderToNative(stringBuilder, dwFlags);
  }
  if (pManagedHome->GetType()->get_IsLayoutSequential() || pManagedHome->GetType()->get_IsExplicitLayout()) {
    return ConvertLayoutToNative(pManagedHome, dwFlags);
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_NDirectBadObject());
}

void AsAnyMarshaler::ConvertToManaged(Object pManagedHome, IntPtr pNativeHome) {
  switch (backPropAction) {
    case BackPropAction::Array:
      MngdNativeArrayMarshaler::ConvertContentsToManaged(pvArrayMarshaler, pManagedHome, IntPtr(&pNativeHome));
      break;
    case BackPropAction::Layout:
      StubHelpers::FmtClassUpdateCLRInternal(pManagedHome, (Byte*)(void*)pNativeHome);
      break;
    case BackPropAction::StringBuilderAnsi:
      {
        Int32 newLength2 = (!(pNativeHome == IntPtr::Zero)) ? String::in::strlen((Byte*)(void*)pNativeHome) : 0;
        ((StringBuilder)pManagedHome)->ReplaceBufferAnsiInternal((SByte*)(void*)pNativeHome, newLength2);
        break;
      }case BackPropAction::StringBuilderUnicode:
      {
        Int32 newLength = (!(pNativeHome == IntPtr::Zero)) ? String::in::wcslen((Char*)(void*)pNativeHome) : 0;
        ((StringBuilder)pManagedHome)->ReplaceBufferInternal((Char*)(void*)pNativeHome, newLength);
        break;
      }}
}

void AsAnyMarshaler::ClearNative(IntPtr pNativeHome) {
  if (pNativeHome != IntPtr::Zero) {
    if (layoutType != nullptr) {
      Marshal::DestroyStructure(pNativeHome, layoutType);
    }
    Interop::Ole32::CoTaskMemFree(pNativeHome);
  }
  StubHelpers::DestroyCleanupList(cleanupWorkList);
}

} // namespace System::Private::CoreLib::System::StubHelpers::AsAnyMarshalerNamespace
