#include "Marshal-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/__ComObject-dep.h>
#include <System.Private.CoreLib/System/AccessViolationException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>
#include <System.Private.CoreLib/System/NullReferenceException-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RtFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IBindCtx.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IMoniker.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ProgIdAttribute-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices::ComTypes;
using namespace System::Text;

void Marshal::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void Marshal::__c___::ctor() {
}

Byte Marshal::__c___::_ReadByte_b__4_0(IntPtr nativeHome, Int32 offset) {
  return ReadByte(nativeHome, offset);
}

Int16 Marshal::__c___::_ReadInt16_b__5_0(IntPtr nativeHome, Int32 offset) {
  return ReadInt16(nativeHome, offset);
}

Int32 Marshal::__c___::_ReadInt32_b__6_0(IntPtr nativeHome, Int32 offset) {
  return ReadInt32(nativeHome, offset);
}

Int64 Marshal::__c___::_ReadInt64_b__7_0(IntPtr nativeHome, Int32 offset) {
  return ReadInt64(nativeHome, offset);
}

void Marshal::__c___::_WriteByte_b__9_0(IntPtr nativeHome, Int32 offset, Byte value) {
  WriteByte(nativeHome, offset, value);
}

void Marshal::__c___::_WriteInt16_b__10_0(IntPtr nativeHome, Int32 offset, Int16 value) {
  WriteInt16(nativeHome, offset, value);
}

void Marshal::__c___::_WriteInt32_b__11_0(IntPtr nativeHome, Int32 offset, Int32 value) {
  WriteInt32(nativeHome, offset, value);
}

void Marshal::__c___::_WriteInt64_b__12_0(IntPtr nativeHome, Int32 offset, Int64 value) {
  WriteInt64(nativeHome, offset, value);
}

IntPtr Marshal::OffsetOf(Type t, String fieldName) {
  if ((Object)t == nullptr) {
    rt::throw_exception<ArgumentNullException>("t");
  }
  FieldInfo field = t->GetField(fieldName, BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  if ((Object)field == nullptr) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_OffsetOfFieldNotFound(), t->get_FullName()), "fieldName");
  }
  RtFieldInfo rtFieldInfo = rt::as<RtFieldInfo>(field);
  if ((Object)rtFieldInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeFieldInfo(), "fieldName");
  }
  return OffsetOfHelper(rtFieldInfo);
}

Byte Marshal::ReadByte(Object ptr, Int32 ofs) {
  Func<IntPtr, Int32, Byte> as = __c::in::__9__4_0;
  return ReadValueSlow(ptr, ofs, as != nullptr ? as : (__c::in::__9__4_0 = {__c::in::__9, &__c::in::_ReadByte_b__4_0}));
}

Int16 Marshal::ReadInt16(Object ptr, Int32 ofs) {
  Func<IntPtr, Int32, Int16> as = __c::in::__9__5_0;
  return ReadValueSlow(ptr, ofs, as != nullptr ? as : (__c::in::__9__5_0 = {__c::in::__9, &__c::in::_ReadInt16_b__5_0}));
}

Int32 Marshal::ReadInt32(Object ptr, Int32 ofs) {
  Func<IntPtr, Int32, Int32> as = __c::in::__9__6_0;
  return ReadValueSlow(ptr, ofs, as != nullptr ? as : (__c::in::__9__6_0 = {__c::in::__9, &__c::in::_ReadInt32_b__6_0}));
}

Int64 Marshal::ReadInt64(Object ptr, Int32 ofs) {
  Func<IntPtr, Int32, Int64> as = __c::in::__9__7_0;
  return ReadValueSlow(ptr, ofs, as != nullptr ? as : (__c::in::__9__7_0 = {__c::in::__9, &__c::in::_ReadInt64_b__7_0}));
}

void Marshal::WriteByte(Object ptr, Int32 ofs, Byte val) {
  Action<IntPtr, Int32, Byte> as = __c::in::__9__9_0;
  WriteValueSlow(ptr, ofs, val, as != nullptr ? as : (__c::in::__9__9_0 = {__c::in::__9, &__c::in::_WriteByte_b__9_0}));
}

void Marshal::WriteInt16(Object ptr, Int32 ofs, Int16 val) {
  Action<IntPtr, Int32, Int16> as = __c::in::__9__10_0;
  WriteValueSlow(ptr, ofs, val, as != nullptr ? as : (__c::in::__9__10_0 = {__c::in::__9, &__c::in::_WriteInt16_b__10_0}));
}

void Marshal::WriteInt32(Object ptr, Int32 ofs, Int32 val) {
  Action<IntPtr, Int32, Int32> as = __c::in::__9__11_0;
  WriteValueSlow(ptr, ofs, val, as != nullptr ? as : (__c::in::__9__11_0 = {__c::in::__9, &__c::in::_WriteInt32_b__11_0}));
}

void Marshal::WriteInt64(Object ptr, Int32 ofs, Int64 val) {
  Action<IntPtr, Int32, Int64> as = __c::in::__9__12_0;
  WriteValueSlow(ptr, ofs, val, as != nullptr ? as : (__c::in::__9__12_0 = {__c::in::__9, &__c::in::_WriteInt64_b__12_0}));
}

void Marshal::PrelinkCore(MethodInfo m) {
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(m);
  if ((Object)runtimeMethodInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "m");
  }
  InternalPrelink(((IRuntimeMethodInfo)runtimeMethodInfo)->get_Value());
  GC::KeepAlive(runtimeMethodInfo);
}

Object Marshal::PtrToStructureHelper(IntPtr ptr, Type structureType) {
  RuntimeType runtimeType = (RuntimeType)structureType;
  Object obj = runtimeType->CreateInstanceDefaultCtor(false, false, false, true);
  PtrToStructureHelper(ptr, obj, true);
  return obj;
}

IntPtr Marshal::GetHINSTANCE(Module m) {
  if ((Object)m == nullptr) {
    rt::throw_exception<ArgumentNullException>("m");
  }
  RuntimeModule module = rt::as<RuntimeModule>(m);
  if ((Object)module != nullptr) {
    return GetHINSTANCE(QCallModule(module));
  }
  return (IntPtr)(Int32)(-1);
}

IntPtr Marshal::AllocHGlobal(IntPtr cb) {
  UIntPtr uBytes = UIntPtr((UInt64)cb.ToInt64());
  IntPtr intPtr = Interop::Kernel32::LocalAlloc(0u, uBytes);
  if (intPtr == IntPtr::Zero) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

void Marshal::FreeHGlobal(IntPtr hglobal) {
  if (!IsNullOrWin32Atom(hglobal) && IntPtr::Zero != Interop::Kernel32::LocalFree(hglobal)) {
    ThrowExceptionForHR(GetHRForLastWin32Error());
  }
}

IntPtr Marshal::ReAllocHGlobal(IntPtr pv, IntPtr cb) {
  IntPtr intPtr = Interop::Kernel32::LocalReAlloc(pv, cb, 2u);
  if (intPtr == IntPtr::Zero) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

String Marshal::GetTypeInfoName(ITypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeInfo");
  }
  String strName;
  String strDocString;
  Int32 dwHelpContext;
  String strHelpFile;
  typeInfo->GetDocumentation(-1, strName, strDocString, dwHelpContext, strHelpFile);
  return strName;
}

Type Marshal::GetTypeFromCLSID(Guid clsid) {
  return RuntimeType::in::GetTypeFromCLSIDImpl(clsid, nullptr, false);
}

IntPtr Marshal::GetIUnknownForObject(Object o) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>("o");
  }
  return GetIUnknownForObjectNative(o, false);
}

IntPtr Marshal::GetIDispatchForObject(Object o) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>("o");
  }
  return GetIDispatchForObjectNative(o, false);
}

IntPtr Marshal::GetComInterfaceForObject(Object o, Type T) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>("o");
  }
  if ((Object)T == nullptr) {
    rt::throw_exception<ArgumentNullException>("T");
  }
  return GetComInterfaceForObjectNative(o, T, false, true);
}

IntPtr Marshal::GetComInterfaceForObject(Object o, Type T, CustomQueryInterfaceMode mode) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>("o");
  }
  if ((Object)T == nullptr) {
    rt::throw_exception<ArgumentNullException>("T");
  }
  Boolean fEnableCustomizedQueryInterface = ((mode == CustomQueryInterfaceMode::Allow) ? true : false);
  return GetComInterfaceForObjectNative(o, T, false, fEnableCustomizedQueryInterface);
}

Object Marshal::GetObjectForIUnknown(IntPtr pUnk) {
  if (pUnk == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pUnk");
  }
  return GetObjectForIUnknownNative(pUnk);
}

Object Marshal::GetUniqueObjectForIUnknown(IntPtr unknown) {
  if (unknown == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("unknown");
  }
  return GetUniqueObjectForIUnknownNative(unknown);
}

IntPtr Marshal::AllocCoTaskMem(Int32 cb) {
  IntPtr intPtr = Interop::Ole32::CoTaskMemAlloc(UIntPtr((UInt32)cb));
  if (intPtr == IntPtr::Zero) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

void Marshal::FreeCoTaskMem(IntPtr ptr) {
  if (!IsNullOrWin32Atom(ptr)) {
    Interop::Ole32::CoTaskMemFree(ptr);
  }
}

IntPtr Marshal::ReAllocCoTaskMem(IntPtr pv, Int32 cb) {
  IntPtr intPtr = Interop::Ole32::CoTaskMemRealloc(pv, UIntPtr((UInt32)cb));
  if (intPtr == IntPtr::Zero && cb != 0) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

IntPtr Marshal::AllocBSTR(Int32 length) {
  IntPtr intPtr = Interop::OleAut32::SysAllocStringLen(nullptr, length);
  if (intPtr == IntPtr::Zero) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

void Marshal::FreeBSTR(IntPtr ptr) {
  if (!IsNullOrWin32Atom(ptr)) {
    Interop::OleAut32::SysFreeString(ptr);
  }
}

IntPtr Marshal::StringToBSTR(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  IntPtr intPtr = Interop::OleAut32::SysAllocStringLen(s, s->get_Length());
  if (intPtr == IntPtr::Zero) {
    rt::throw_exception<OutOfMemoryException>();
  }
  return intPtr;
}

String Marshal::PtrToStringBSTR(IntPtr ptr) {
  if (ptr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("ptr");
  }
  return PtrToStringUni(ptr, (Int32)(SysStringByteLen(ptr) / 2u));
}

Int32 Marshal::ReleaseComObject(Object o) {
  if (o == nullptr) {
    rt::throw_exception<NullReferenceException>();
  }
  __ComObject _ComObject = rt::as<__ComObject>(o);
  if (_ComObject == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ObjNotComObject(), "o");
  }
  return _ComObject->ReleaseSelf();
}

Int32 Marshal::FinalReleaseComObject(Object o) {
  if (o == nullptr) {
    rt::throw_exception<ArgumentNullException>("o");
  }
  __ComObject _ComObject = rt::as<__ComObject>(o);
  if (_ComObject == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ObjNotComObject(), "o");
  }
  _ComObject->FinalReleaseSelf();
  return 0;
}

Object Marshal::GetComObjectData(Object obj, Object key) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  __ComObject _ComObject = rt::as<__ComObject>(obj);
  if (_ComObject == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ObjNotComObject(), "obj");
  }
  return _ComObject->GetData(key);
}

Boolean Marshal::SetComObjectData(Object obj, Object key, Object data) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  __ComObject _ComObject = rt::as<__ComObject>(obj);
  if (_ComObject == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ObjNotComObject(), "obj");
  }
  return _ComObject->SetData(key, data);
}

Object Marshal::CreateWrapperOfType(Object o, Type t) {
  if ((Object)t == nullptr) {
    rt::throw_exception<ArgumentNullException>("t");
  }
  if (!t->get_IsCOMObject()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TypeNotComObject(), "t");
  }
  if (t->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "t");
  }
  if (o == nullptr) {
    return nullptr;
  }
  if (!o->GetType()->get_IsCOMObject()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ObjNotComObject(), "o");
  }
  if (o->GetType() == t) {
    return o;
  }
  Object obj = GetComObjectData(o, t);
  if (obj == nullptr) {
    obj = InternalCreateWrapperOfType(o, t);
    if (!SetComObjectData(o, t, obj)) {
      obj = GetComObjectData(o, t);
    }
  }
  return obj;
}

Int32 Marshal::QueryInterface(IntPtr pUnk, Guid& iid, IntPtr& ppv) {
  if (pUnk == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pUnk");
  }
  {
    Guid* ptr = &iid;
    {
      IntPtr* ptr2 = &ppv;
    }
  }
}

Int32 Marshal::AddRef(IntPtr pUnk) {
  if (pUnk == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pUnk");
  }
}

Int32 Marshal::Release(IntPtr pUnk) {
  if (pUnk == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pUnk");
  }
}

Object Marshal::BindToMoniker(String monikerName) {
  IBindCtx ppbc;
  CreateBindCtx(0u, ppbc);
  UInt32 pchEaten;
  IMoniker ppmk;
  MkParseDisplayName(ppbc, monikerName, pchEaten, ppmk);
  Object ppvResult;
  BindMoniker(ppmk, 0u, IID_IUnknown, ppvResult);
  return ppvResult;
}

IntPtr Marshal::AllocHGlobal(Int32 cb) {
  return AllocHGlobal((IntPtr)cb);
}

String Marshal::PtrToStringAnsi(IntPtr ptr) {
  if (IsNullOrWin32Atom(ptr)) {
    return nullptr;
  }
  return rt::newstr<String>((SByte*)(void*)ptr);
}

String Marshal::PtrToStringAnsi(IntPtr ptr, Int32 len) {
  if (ptr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("ptr");
  }
  if (len < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("len", len, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return rt::newstr<String>((SByte*)(void*)ptr, 0, len);
}

String Marshal::PtrToStringUni(IntPtr ptr) {
  if (IsNullOrWin32Atom(ptr)) {
    return nullptr;
  }
  return rt::newstr<String>((Char*)(void*)ptr);
}

String Marshal::PtrToStringUni(IntPtr ptr, Int32 len) {
  if (ptr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("ptr");
  }
  if (len < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("len", len, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return rt::newstr<String>((Char*)(void*)ptr, 0, len);
}

String Marshal::PtrToStringUTF8(IntPtr ptr) {
  if (IsNullOrWin32Atom(ptr)) {
    return nullptr;
  }
  Int32 byteLength = String::in::strlen((Byte*)(void*)ptr);
  return String::in::CreateStringFromEncoding((Byte*)(void*)ptr, byteLength, Encoding::in::get_UTF8());
}

String Marshal::PtrToStringUTF8(IntPtr ptr, Int32 byteLen) {
  if (ptr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("ptr");
  }
  if (byteLen < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("byteLen", byteLen, SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return String::in::CreateStringFromEncoding((Byte*)(void*)ptr, byteLen, Encoding::in::get_UTF8());
}

Int32 Marshal::SizeOf(Object structure) {
  if (structure == nullptr) {
    rt::throw_exception<ArgumentNullException>("structure");
  }
  return SizeOfHelper(structure->GetType(), true);
}

Int32 Marshal::SizeOf(Type t) {
  if ((Object)t == nullptr) {
    rt::throw_exception<ArgumentNullException>("t");
  }
  if (!t->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "t");
  }
  if (t->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "t");
  }
  return SizeOfHelper(t, true);
}

IntPtr Marshal::UnsafeAddrOfPinnedArrayElement(Array<> arr, Int32 index) {
  if (arr == nullptr) {
    rt::throw_exception<ArgumentNullException>("arr");
  }
  void* ptr = Unsafe::AsPointer(RuntimeHelpers::GetRawArrayData(arr));
  return (IntPtr)((Byte*)ptr + (UInt64)(UIntPtr)(void*)((Int64)(UInt32)index * (Int64)RuntimeHelpers::GetElementSize(arr)));
}

void Marshal::Copy(Array<Int32> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Char> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Int16> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Int64> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Single> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Double> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<Byte> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(Array<IntPtr> source, Int32 startIndex, IntPtr destination, Int32 length) {
  CopyToNative(source, startIndex, destination, length);
}

void Marshal::Copy(IntPtr source, Array<Int32> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Char> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Int16> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Int64> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Single> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Double> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<Byte> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

void Marshal::Copy(IntPtr source, Array<IntPtr> destination, Int32 startIndex, Int32 length) {
  CopyToManaged(source, destination, startIndex, length);
}

Byte Marshal::ReadByte(IntPtr ptr, Int32 ofs) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    return *ptr2;
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

Byte Marshal::ReadByte(IntPtr ptr) {
  return ReadByte(ptr, 0);
}

Int16 Marshal::ReadInt16(IntPtr ptr, Int32 ofs) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 1) == 0) {
      return *(Int16*)ptr2;
    }
    return Unsafe::ReadUnaligned<Int16>(ptr2);
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

Int16 Marshal::ReadInt16(IntPtr ptr) {
  return ReadInt16(ptr, 0);
}

Int32 Marshal::ReadInt32(IntPtr ptr, Int32 ofs) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 3) == 0) {
      return *(Int32*)ptr2;
    }
    return Unsafe::ReadUnaligned<Int32>(ptr2);
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

Int32 Marshal::ReadInt32(IntPtr ptr) {
  return ReadInt32(ptr, 0);
}

IntPtr Marshal::ReadIntPtr(Object ptr, Int32 ofs) {
  return (IntPtr)ReadInt64(ptr, ofs);
}

IntPtr Marshal::ReadIntPtr(IntPtr ptr, Int32 ofs) {
  return (IntPtr)ReadInt64(ptr, ofs);
}

IntPtr Marshal::ReadIntPtr(IntPtr ptr) {
  return ReadIntPtr(ptr, 0);
}

Int64 Marshal::ReadInt64(IntPtr ptr, Int32 ofs) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 7) == 0) {
      return *(Int64*)ptr2;
    }
    return Unsafe::ReadUnaligned<Int64>(ptr2);
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

Int64 Marshal::ReadInt64(IntPtr ptr) {
  return ReadInt64(ptr, 0);
}

void Marshal::WriteByte(IntPtr ptr, Int32 ofs, Byte val) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    *ptr2 = val;
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

void Marshal::WriteByte(IntPtr ptr, Byte val) {
  WriteByte(ptr, 0, val);
}

void Marshal::WriteInt16(IntPtr ptr, Int32 ofs, Int16 val) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 1) == 0) {
      *(Int16*)ptr2 = val;
    } else {
      Unsafe::WriteUnaligned(ptr2, val);
    }
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

void Marshal::WriteInt16(IntPtr ptr, Int16 val) {
  WriteInt16(ptr, 0, val);
}

void Marshal::WriteInt16(IntPtr ptr, Int32 ofs, Char val) {
  WriteInt16(ptr, ofs, (Int16)val);
}

void Marshal::WriteInt16(Object ptr, Int32 ofs, Char val) {
  WriteInt16(ptr, ofs, (Int16)val);
}

void Marshal::WriteInt16(IntPtr ptr, Char val) {
  WriteInt16(ptr, 0, (Int16)val);
}

void Marshal::WriteInt32(IntPtr ptr, Int32 ofs, Int32 val) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 3) == 0) {
      *(Int32*)ptr2 = val;
    } else {
      Unsafe::WriteUnaligned(ptr2, val);
    }
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

void Marshal::WriteInt32(IntPtr ptr, Int32 val) {
  WriteInt32(ptr, 0, val);
}

void Marshal::WriteIntPtr(IntPtr ptr, Int32 ofs, IntPtr val) {
  WriteInt64(ptr, ofs, (Int64)val);
}

void Marshal::WriteIntPtr(Object ptr, Int32 ofs, IntPtr val) {
  WriteInt64(ptr, ofs, (Int64)val);
}

void Marshal::WriteIntPtr(IntPtr ptr, IntPtr val) {
  WriteIntPtr(ptr, 0, val);
}

void Marshal::WriteInt64(IntPtr ptr, Int32 ofs, Int64 val) {
  try {
    Byte* ptr2 = (Byte*)(void*)ptr + ofs;
    if (((Int32)ptr2 & 7) == 0) {
      *(Int64*)ptr2 = val;
    } else {
      Unsafe::WriteUnaligned(ptr2, val);
    }
  } catch (NullReferenceException) {
    rt::throw_exception<AccessViolationException>();
  }
}

void Marshal::WriteInt64(IntPtr ptr, Int64 val) {
  WriteInt64(ptr, 0, val);
}

void Marshal::Prelink(MethodInfo m) {
  if ((Object)m == nullptr) {
    rt::throw_exception<ArgumentNullException>("m");
  }
  PrelinkCore(m);
}

void Marshal::PrelinkAll(Type c) {
  if ((Object)c == nullptr) {
    rt::throw_exception<ArgumentNullException>("c");
  }
  Array<MethodInfo> methods = c->GetMethods();
  for (Int32 i = 0; i < methods->get_Length(); i++) {
    Prelink(methods[i]);
  }
}

Object Marshal::PtrToStructure(IntPtr ptr, Type structureType) {
  if (ptr == IntPtr::Zero) {
    return nullptr;
  }
  if ((Object)structureType == nullptr) {
    rt::throw_exception<ArgumentNullException>("structureType");
  }
  if (structureType->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "structureType");
  }
  if (!structureType->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "structureType");
  }
  return PtrToStructureHelper(ptr, structureType);
}

void Marshal::PtrToStructure(IntPtr ptr, Object structure) {
  PtrToStructureHelper(ptr, structure, false);
}

Exception Marshal::GetExceptionForHR(Int32 errorCode) {
  return GetExceptionForHR(errorCode, IntPtr::Zero);
}

Exception Marshal::GetExceptionForHR(Int32 errorCode, IntPtr errorInfo) {
  if (errorCode >= 0) {
    return nullptr;
  }
  return GetExceptionForHRInternal(errorCode, errorInfo);
}

void Marshal::ThrowExceptionForHR(Int32 errorCode) {
  if (errorCode < 0) {
    rt::throw_exception(GetExceptionForHR(errorCode, IntPtr::Zero));
  }
}

void Marshal::ThrowExceptionForHR(Int32 errorCode, IntPtr errorInfo) {
  if (errorCode < 0) {
    rt::throw_exception(GetExceptionForHR(errorCode, errorInfo));
  }
}

IntPtr Marshal::SecureStringToBSTR(SecureString s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return s->MarshalToBSTR();
}

IntPtr Marshal::SecureStringToCoTaskMemAnsi(SecureString s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return s->MarshalToString(false, false);
}

IntPtr Marshal::SecureStringToCoTaskMemUnicode(SecureString s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return s->MarshalToString(false, true);
}

IntPtr Marshal::SecureStringToGlobalAllocAnsi(SecureString s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return s->MarshalToString(true, false);
}

IntPtr Marshal::SecureStringToGlobalAllocUnicode(SecureString s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  return s->MarshalToString(true, true);
}

IntPtr Marshal::StringToHGlobalAnsi(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  Int64 num = (Int64)(s->get_Length() + 1) * (Int64)SystemMaxDBCSCharSize;
  Int32 num2 = (Int32)num;
  if (num2 != num) {
    rt::throw_exception<ArgumentOutOfRangeException>("s");
  }
  IntPtr intPtr = AllocHGlobal((IntPtr)num2);
  StringToAnsiString(s, (Byte*)(void*)intPtr, num2);
  return intPtr;
}

IntPtr Marshal::StringToHGlobalUni(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  Int32 num = (s->get_Length() + 1) * 2;
  if (num < s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("s");
  }
  IntPtr intPtr = AllocHGlobal((IntPtr)num);
  {
    Char* ptr = s;
    Char* smem = ptr;
    String::in::wstrcpy((Char*)(void*)intPtr, smem, s->get_Length() + 1);
  }
  return intPtr;
}

IntPtr Marshal::StringToCoTaskMemUni(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  Int32 num = (s->get_Length() + 1) * 2;
  if (num < s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("s");
  }
  IntPtr intPtr = AllocCoTaskMem(num);
  {
    Char* ptr = s;
    Char* smem = ptr;
    String::in::wstrcpy((Char*)(void*)intPtr, smem, s->get_Length() + 1);
  }
  return intPtr;
}

IntPtr Marshal::StringToCoTaskMemUTF8(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  Int32 maxByteCount = Encoding::in::get_UTF8()->GetMaxByteCount(s->get_Length());
  IntPtr intPtr = AllocCoTaskMem(maxByteCount + 1);
  Byte* ptr = (Byte*)(void*)intPtr;
  Int32 bytes;
  {
    Char* ptr2 = s;
    Char* chars = ptr2;
    bytes = Encoding::in::get_UTF8()->GetBytes(chars, s->get_Length(), ptr, maxByteCount);
  }
  *(ptr + bytes) = 0;
  return intPtr;
}

IntPtr Marshal::StringToCoTaskMemAnsi(String s) {
  if (s == nullptr) {
    return IntPtr::Zero;
  }
  Int64 num = (Int64)(s->get_Length() + 1) * (Int64)SystemMaxDBCSCharSize;
  Int32 num2 = (Int32)num;
  if (num2 != num) {
    rt::throw_exception<ArgumentOutOfRangeException>("s");
  }
  IntPtr intPtr = AllocCoTaskMem(num2);
  StringToAnsiString(s, (Byte*)(void*)intPtr, num2);
  return intPtr;
}

Guid Marshal::GenerateGuidForType(Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (!type->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  return type->get_GUID();
}

String Marshal::GenerateProgIdForType(Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (type->get_IsImport()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TypeMustNotBeComImport(), "type");
  }
  if (type->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "type");
  }
  ProgIdAttribute customAttribute = CustomAttributeExtensions::GetCustomAttribute<ProgIdAttribute>(type);
  if (customAttribute != nullptr) {
    String as = customAttribute->get_Value();
    return as != nullptr ? as : String::in::Empty;
  }
  return type->get_FullName();
}

Delegate Marshal::GetDelegateForFunctionPointer(IntPtr ptr, Type t) {
  if (ptr == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("ptr");
  }
  if ((Object)t == nullptr) {
    rt::throw_exception<ArgumentNullException>("t");
  }
  if (!t->IsRuntimeImplemented()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "t");
  }
  if (t->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NeedNonGenericType(), "t");
  }
  Type baseType = t->get_BaseType();
  if (baseType != typeof<Delegate>() && baseType != typeof<MulticastDelegate>()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "t");
  }
  return GetDelegateForFunctionPointerInternal(ptr, t);
}

IntPtr Marshal::GetFunctionPointerForDelegate(Delegate d) {
  if ((Object)d == nullptr) {
    rt::throw_exception<ArgumentNullException>("d");
  }
  return GetFunctionPointerForDelegateInternal(d);
}

Int32 Marshal::GetHRForLastWin32Error() {
  Int32 lastWin32Error = GetLastWin32Error();
  if ((lastWin32Error & 2147483648u) == 2147483648u) {
    return lastWin32Error;
  }
  return (lastWin32Error & 65535) | -2147024896;
}

void Marshal::ZeroFreeBSTR(IntPtr s) {
  if (!(s == IntPtr::Zero)) {
    Buffer::ZeroMemory((Byte*)(void*)s, (UIntPtr)SysStringByteLen(s));
    FreeBSTR(s);
  }
}

void Marshal::ZeroFreeCoTaskMemAnsi(IntPtr s) {
  ZeroFreeCoTaskMemUTF8(s);
}

void Marshal::ZeroFreeCoTaskMemUnicode(IntPtr s) {
  if (!(s == IntPtr::Zero)) {
    Buffer::ZeroMemory((Byte*)(void*)s, (UIntPtr)((UInt64)String::in::wcslen((Char*)(void*)s) * 2));
    FreeCoTaskMem(s);
  }
}

void Marshal::ZeroFreeCoTaskMemUTF8(IntPtr s) {
  if (!(s == IntPtr::Zero)) {
    Buffer::ZeroMemory((Byte*)(void*)s, (UIntPtr)String::in::strlen((Byte*)(void*)s));
    FreeCoTaskMem(s);
  }
}

void Marshal::ZeroFreeGlobalAllocAnsi(IntPtr s) {
  if (!(s == IntPtr::Zero)) {
    Buffer::ZeroMemory((Byte*)(void*)s, (UIntPtr)String::in::strlen((Byte*)(void*)s));
    FreeHGlobal(s);
  }
}

void Marshal::ZeroFreeGlobalAllocUnicode(IntPtr s) {
  if (!(s == IntPtr::Zero)) {
    Buffer::ZeroMemory((Byte*)(void*)s, (UIntPtr)((UInt64)String::in::wcslen((Char*)(void*)s) * 2));
    FreeHGlobal(s);
  }
}

UInt32 Marshal::SysStringByteLen(IntPtr s) {
  return *(UInt32*)((Byte*)(void*)s - 4);
}

String Marshal::PtrToStringAuto(IntPtr ptr, Int32 len) {
  return PtrToStringUni(ptr, len);
}

String Marshal::PtrToStringAuto(IntPtr ptr) {
  return PtrToStringUni(ptr);
}

IntPtr Marshal::StringToHGlobalAuto(String s) {
  return StringToHGlobalUni(s);
}

IntPtr Marshal::StringToCoTaskMemAuto(String s) {
  return StringToCoTaskMemUni(s);
}

Int32 Marshal::GetSystemMaxDBCSCharSize() {
  Interop::Kernel32::CPINFO cPINFO;
  if (Interop::Kernel32::GetCPInfo(0u, &cPINFO) == Interop::BOOL::FALSE) {
    return 2;
  }
  return cPINFO.MaxCharSize;
}

Boolean Marshal::IsNullOrWin32Atom(IntPtr ptr) {
  Int64 num = (Int64)ptr;
  return (num & -65536) == 0;
}

Int32 Marshal::StringToAnsiString(String s, Byte* buffer, Int32 bufferLength, Boolean bestFit, Boolean throwOnUnmappableChar) {
  UInt32 dwFlags = ((!bestFit) ? 1024u : 0u);
  UInt32 num = 0u;
  Int32 num2;
  {
    Char* ptr = s;
    Char* lpWideCharStr = ptr;
    num2 = Interop::Kernel32::WideCharToMultiByte(0u, dwFlags, lpWideCharStr, s->get_Length(), buffer, bufferLength, IntPtr::Zero, throwOnUnmappableChar ? IntPtr(&num) : IntPtr::Zero);
  }
  if (num != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Interop_Marshal_Unmappable_Char());
  }
  *(buffer + num2) = 0;
  return num2;
}

Int32 Marshal::GetAnsiStringByteCount(ReadOnlySpan<Char> chars) {
  Int32 num;
  if (chars.get_Length() == 0) {
    num = 0;
  } else {
    {
      Char* lpWideCharStr = chars;
      num = Interop::Kernel32::WideCharToMultiByte(0u, 1024u, lpWideCharStr, chars.get_Length(), nullptr, 0, IntPtr::Zero, IntPtr::Zero);
      if (num <= 0) {
        rt::throw_exception<ArgumentException>();
      }
    }
  }
  return num + 1;
}

void Marshal::GetAnsiStringBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  Int32 num;
  if (chars.get_Length() == 0) {
    num = 0;
  } else {
    {
      Char* lpWideCharStr = chars;
      {
        Byte* lpMultiByteStr = bytes;
        num = Interop::Kernel32::WideCharToMultiByte(0u, 1024u, lpWideCharStr, chars.get_Length(), lpMultiByteStr, bytes.get_Length(), IntPtr::Zero, IntPtr::Zero);
        if (num <= 0) {
          rt::throw_exception<ArgumentException>();
        }
      }
    }
  }
  bytes[num] = 0;
}

void Marshal::cctor() {
  IID_IUnknown = Guid(0, 0, 0, 192, 0, 0, 0, 0, 0, 0, 70);
  SystemDefaultCharSize = 2;
  SystemMaxDBCSCharSize = GetSystemMaxDBCSCharSize();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalNamespace
