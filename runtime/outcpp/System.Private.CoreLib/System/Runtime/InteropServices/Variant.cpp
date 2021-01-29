#include "Variant-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ErrorWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/IDispatch.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Variant-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::VariantNamespace {
VarEnum Variant::get_VariantType() {
  return (VarEnum)_typeUnion._vt;
}

void Variant::set_VariantType(VarEnum value) {
  _typeUnion._vt = (UInt16)value;
}

Boolean Variant::get_IsEmpty() {
  return _typeUnion._vt == 0;
}

Boolean Variant::get_IsByRef() {
  return (_typeUnion._vt & 16384) != 0;
}

SByte Variant::get_AsI1() {
  return _typeUnion._unionTypes._i1;
}

Int16 Variant::get_AsI2() {
  return _typeUnion._unionTypes._i2;
}

Int32 Variant::get_AsI4() {
  return _typeUnion._unionTypes._i4;
}

Int64 Variant::get_AsI8() {
  return _typeUnion._unionTypes._i8;
}

Byte Variant::get_AsUi1() {
  return _typeUnion._unionTypes._ui1;
}

UInt16 Variant::get_AsUi2() {
  return _typeUnion._unionTypes._ui2;
}

UInt32 Variant::get_AsUi4() {
  return _typeUnion._unionTypes._ui4;
}

UInt64 Variant::get_AsUi8() {
  return _typeUnion._unionTypes._ui8;
}

Int32 Variant::get_AsInt() {
  return _typeUnion._unionTypes._int;
}

UInt32 Variant::get_AsUint() {
  return _typeUnion._unionTypes._uint;
}

Boolean Variant::get_AsBool() {
  return _typeUnion._unionTypes._bool != 0;
}

Int32 Variant::get_AsError() {
  return _typeUnion._unionTypes._error;
}

Single Variant::get_AsR4() {
  return _typeUnion._unionTypes._r4;
}

Double Variant::get_AsR8() {
  return _typeUnion._unionTypes._r8;
}

Decimal Variant::get_AsDecimal() {
  Variant variant = *this;
  variant._typeUnion._vt = 0;
  return variant._decimal;
}

Decimal Variant::get_AsCy() {
  return Decimal::FromOACurrency(_typeUnion._unionTypes._cy);
}

DateTime Variant::get_AsDate() {
  return DateTime::FromOADate(_typeUnion._unionTypes._date);
}

String Variant::get_AsBstr() {
  return Marshal::PtrToStringBSTR(_typeUnion._unionTypes._bstr);
}

Object Variant::get_AsUnknown() {
  if (_typeUnion._unionTypes._unknown == IntPtr::Zero) {
    return nullptr;
  }
  return Marshal::GetObjectForIUnknown(_typeUnion._unionTypes._unknown);
}

Object Variant::get_AsDispatch() {
  if (_typeUnion._unionTypes._dispatch == IntPtr::Zero) {
    return nullptr;
  }
  return Marshal::GetObjectForIUnknown(_typeUnion._unionTypes._dispatch);
}

IntPtr Variant::get_AsByRefVariant() {
  return _typeUnion._unionTypes._pvarVal;
}

void Variant::CopyFromIndirect(Object value) {
  VarEnum varEnum = get_VariantType() & (VarEnum)(-16385);
  if (value == nullptr) {
    if (varEnum == VarEnum::VT_DISPATCH || varEnum == VarEnum::VT_UNKNOWN || varEnum == VarEnum::VT_BSTR) {
      *(IntPtr*)(void*)_typeUnion._unionTypes._byref = IntPtr::Zero;
    }
    return;
  }
  if ((varEnum & VarEnum::VT_ARRAY) != 0) {
    Variant variant;
    Marshal::GetNativeVariantForObject(value, (IntPtr)(&variant));
    *(IntPtr*)(void*)_typeUnion._unionTypes._byref = variant._typeUnion._unionTypes._byref;
    return;
  }
  switch (varEnum) {
    case VarEnum::VT_I1:
      *(SByte*)(void*)_typeUnion._unionTypes._byref = (SByte)value;
      break;
    case VarEnum::VT_UI1:
      *(Byte*)(void*)_typeUnion._unionTypes._byref = (Byte)value;
      break;
    case VarEnum::VT_I2:
      *(Int16*)(void*)_typeUnion._unionTypes._byref = (Int16)value;
      break;
    case VarEnum::VT_UI2:
      *(UInt16*)(void*)_typeUnion._unionTypes._byref = (UInt16)value;
      break;
    case VarEnum::VT_BOOL:
      *(Int16*)(void*)_typeUnion._unionTypes._byref = (Int16)(((Boolean)value) ? (-1) : 0);
      break;
    case VarEnum::VT_I4:
    case VarEnum::VT_INT:
      *(Int32*)(void*)_typeUnion._unionTypes._byref = (Int32)value;
      break;
    case VarEnum::VT_UI4:
    case VarEnum::VT_UINT:
      *(UInt32*)(void*)_typeUnion._unionTypes._byref = (UInt32)value;
      break;
    case VarEnum::VT_ERROR:
      *(Int32*)(void*)_typeUnion._unionTypes._byref = ((ErrorWrapper)value)->get_ErrorCode();
      break;
    case VarEnum::VT_I8:
      *(Int64*)(void*)_typeUnion._unionTypes._byref = (Int64)value;
      break;
    case VarEnum::VT_UI8:
      *(UInt64*)(void*)_typeUnion._unionTypes._byref = (UInt64)value;
      break;
    case VarEnum::VT_R4:
      *(Single*)(void*)_typeUnion._unionTypes._byref = (Single)value;
      break;
    case VarEnum::VT_R8:
      *(Double*)(void*)_typeUnion._unionTypes._byref = (Double)value;
      break;
    case VarEnum::VT_DATE:
      *(Double*)(void*)_typeUnion._unionTypes._byref = ((DateTime)value).ToOADate();
      break;
    case VarEnum::VT_UNKNOWN:
      *(IntPtr*)(void*)_typeUnion._unionTypes._byref = Marshal::GetIUnknownForObject(value);
      break;
    case VarEnum::VT_DISPATCH:
      *(IntPtr*)(void*)_typeUnion._unionTypes._byref = Marshal::GetComInterfaceForObject<Object, IDispatch>(value);
      break;
    case VarEnum::VT_BSTR:
      *(IntPtr*)(void*)_typeUnion._unionTypes._byref = Marshal::StringToBSTR((String)value);
      break;
    case VarEnum::VT_CY:
      *(Int64*)(void*)_typeUnion._unionTypes._byref = Decimal::ToOACurrency((Decimal)value);
      break;
    case VarEnum::VT_DECIMAL:
      *(Decimal*)(void*)_typeUnion._unionTypes._byref = (Decimal)value;
      break;
    case VarEnum::VT_VARIANT:
      Marshal::GetNativeVariantForObject(value, _typeUnion._unionTypes._byref);
      break;
    default:
      rt::throw_exception<ArgumentException>();
  }
}

Object Variant::ToObject() {
  if (get_IsEmpty()) {
    return nullptr;
  }
  switch (get_VariantType()) {
    case VarEnum::VT_NULL:
      return DBNull::in::Value;
    case VarEnum::VT_I1:
      return get_AsI1();
    case VarEnum::VT_I2:
      return get_AsI2();
    case VarEnum::VT_I4:
      return get_AsI4();
    case VarEnum::VT_I8:
      return get_AsI8();
    case VarEnum::VT_UI1:
      return get_AsUi1();
    case VarEnum::VT_UI2:
      return get_AsUi2();
    case VarEnum::VT_UI4:
      return get_AsUi4();
    case VarEnum::VT_UI8:
      return get_AsUi8();
    case VarEnum::VT_INT:
      return get_AsInt();
    case VarEnum::VT_UINT:
      return get_AsUint();
    case VarEnum::VT_BOOL:
      return get_AsBool();
    case VarEnum::VT_ERROR:
      return get_AsError();
    case VarEnum::VT_R4:
      return get_AsR4();
    case VarEnum::VT_R8:
      return get_AsR8();
    case VarEnum::VT_DECIMAL:
      return get_AsDecimal();
    case VarEnum::VT_CY:
      return get_AsCy();
    case VarEnum::VT_DATE:
      return get_AsDate();
    case VarEnum::VT_BSTR:
      return get_AsBstr();
    case VarEnum::VT_UNKNOWN:
      return get_AsUnknown();
    case VarEnum::VT_DISPATCH:
      return get_AsDispatch();
    default:
      {
        Variant* ptr = rt::fixed(&*this);
        void* value = ptr;
        return Marshal::GetObjectForNativeVariant((IntPtr)value);
      }
  }
}

void Variant::Clear() {
  VarEnum variantType = get_VariantType();
  if ((variantType & VarEnum::VT_BYREF) != 0) {
    set_VariantType(VarEnum::VT_EMPTY);
  } else if ((variantType & VarEnum::VT_ARRAY) != 0 || variantType == VarEnum::VT_BSTR || variantType == VarEnum::VT_UNKNOWN || variantType == VarEnum::VT_DISPATCH || variantType == VarEnum::VT_VARIANT || variantType == VarEnum::VT_RECORD) {
    {
      Variant* ptr = rt::fixed(&*this);
      void* value = ptr;
      Interop::OleAut32::VariantClear((IntPtr)value);
    }
  } else {
    set_VariantType(VarEnum::VT_EMPTY);
  }

}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::VariantNamespace
