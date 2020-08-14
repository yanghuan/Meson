#include "Variant-dep.h"

#include <System.Private.CoreLib/System/DBNull-dep.h>
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
        Variant* ptr = &*this;
        void* value = ptr;
        return Marshal::GetObjectForNativeVariant((IntPtr)value);
      }
  }
}

void Variant::Clear() {
  VarEnum variantType = get_VariantType();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::VariantNamespace
