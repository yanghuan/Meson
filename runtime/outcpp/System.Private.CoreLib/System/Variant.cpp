#include "Variant-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IConvertible.h>
#include <System.Private.CoreLib/System/IFormatProvider.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/BStrWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CurrencyWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DispatchWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ErrorWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/UnknownWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/VarEnum.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/Variant-dep.h>

namespace System::Private::CoreLib::System::VariantNamespace {
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

Int32 Variant::get_CVType() {
  return _flags & 65535;
}

Variant::Variant(Int32 flags, Object or_, Int64 data) {
  _flags = flags;
  _objref = or;
  _data = data;
}

Variant::Variant(Boolean val) {
  _objref = nullptr;
  _flags = 2;
  _data = (val ? 1 : 0);
}

Variant::Variant(SByte val) {
  _objref = nullptr;
  _flags = 4;
  _data = val;
}

Variant::Variant(Byte val) {
  _objref = nullptr;
  _flags = 5;
  _data = val;
}

Variant::Variant(Int16 val) {
  _objref = nullptr;
  _flags = 6;
  _data = val;
}

Variant::Variant(UInt16 val) {
  _objref = nullptr;
  _flags = 7;
  _data = val;
}

Variant::Variant(Char val) {
  _objref = nullptr;
  _flags = 3;
  _data = val;
}

Variant::Variant(Int32 val) {
  _objref = nullptr;
  _flags = 8;
  _data = val;
}

Variant::Variant(UInt32 val) {
  _objref = nullptr;
  _flags = 9;
  _data = val;
}

Variant::Variant(Int64 val) {
  _objref = nullptr;
  _flags = 10;
  _data = val;
}

Variant::Variant(UInt64 val) {
  _objref = nullptr;
  _flags = 11;
  _data = (Int64)val;
}

Variant::Variant(Single val) {
  _objref = nullptr;
  _flags = 12;
  _data = (UInt32)BitConverter::SingleToInt32Bits(val);
}

Variant::Variant(Double val) {
  _objref = nullptr;
  _flags = 13;
  _data = BitConverter::DoubleToInt64Bits(val);
}

Variant::Variant(DateTime val) {
  _objref = nullptr;
  _flags = 16;
  _data = val.get_Ticks();
}

Variant::Variant(Decimal val) {
  _objref = val;
  _flags = 19;
  _data = 0;
}

Variant::Variant(Object obj) {
  _data = 0;
  VarEnum varEnum = VarEnum::VT_EMPTY;
  if (rt::is<DateTime>(obj)) {
    _objref = nullptr;
    _flags = 16;
    _data = ((DateTime)obj).get_Ticks();
    return;
  }
  if (rt::is<String>(obj)) {
    _flags = 14;
    _objref = obj;
    return;
  }
  if (obj == nullptr) {
    *this = Empty;
    return;
  }
  if (obj == DBNull::in::Value) {
    *this = DBNull;
    return;
  }
  if (obj == Type::in::Missing) {
    *this = Missing;
    return;
  }
  if (rt::is<Array<>>(obj)) {
    _flags = 65554;
    _objref = obj;
    return;
  }
  _flags = 0;
  _objref = nullptr;
  if (rt::is<UnknownWrapper>(obj)) {
    varEnum = VarEnum::VT_UNKNOWN;
    obj = ((UnknownWrapper)obj)->get_WrappedObject();
  } else if (rt::is<DispatchWrapper>(obj)) {
    varEnum = VarEnum::VT_DISPATCH;
    obj = ((DispatchWrapper)obj)->get_WrappedObject();
  } else if (rt::is<ErrorWrapper>(obj)) {
    varEnum = VarEnum::VT_ERROR;
    obj = ((ErrorWrapper)obj)->get_ErrorCode();
  } else if (rt::is<CurrencyWrapper>(obj)) {
    varEnum = VarEnum::VT_CY;
    obj = ((CurrencyWrapper)obj)->get_WrappedObject();
  } else if (rt::is<BStrWrapper>(obj)) {
    varEnum = VarEnum::VT_BSTR;
    obj = ((BStrWrapper)obj)->get_WrappedObject();
  }




  if (obj != nullptr) {
    SetFieldsObject(obj);
  }
  if (varEnum != 0) {
    _flags |= (Int32)varEnum << 24;
  }
}

Object Variant::ToObject() {
  switch (get_CVType().get()) {
    case 0:
      return nullptr;
    case 2:
      return (Int32)_data != 0;
    case 4:
      return (SByte)_data;
    case 5:
      return (Byte)_data;
    case 3:
      return (Char)_data;
    case 6:
      return (Int16)_data;
    case 7:
      return (UInt16)_data;
    case 8:
      return (Int32)_data;
    case 9:
      return (UInt32)_data;
    case 10:
      return _data;
    case 11:
      return (UInt64)_data;
    case 12:
      return BitConverter::Int32BitsToSingle((Int32)_data);
    case 13:
      return BitConverter::Int64BitsToDouble(_data);
    case 16:
      return DateTime(_data);
    case 17:
      return TimeSpan(_data);
    case 21:
      return BoxEnum();
    case 22:
      return Type::in::Missing;
    case 23:
      return DBNull::in::Value;
    default:
      return _objref;
  }
}

void Variant::MarshalHelperConvertObjectToVariant(Object o, Variant& v) {
  if (o == nullptr) {
    v = Empty;
    return;
  }
  IConvertible convertible = rt::as<IConvertible>(o);
  if (convertible != nullptr) {
    IFormatProvider invariantCulture = CultureInfo::in::get_InvariantCulture();
    Variant variant;
    switch (convertible->GetTypeCode()) {
      case TypeCode::Empty:
        variant = Empty;
        break;
      case TypeCode::Object:
        variant = Variant(o);
        break;
      case TypeCode::DBNull:
        variant = DBNull;
        break;
      case TypeCode::Boolean:
        variant = Variant(convertible->ToBoolean(invariantCulture));
        break;
      case TypeCode::Char:
        variant = Variant(convertible->ToChar(invariantCulture));
        break;
      case TypeCode::SByte:
        variant = Variant(convertible->ToSByte(invariantCulture));
        break;
      case TypeCode::Byte:
        variant = Variant(convertible->ToByte(invariantCulture));
        break;
      case TypeCode::Int16:
        variant = Variant(convertible->ToInt16(invariantCulture));
        break;
      case TypeCode::UInt16:
        variant = Variant(convertible->ToUInt16(invariantCulture));
        break;
      case TypeCode::Int32:
        variant = Variant(convertible->ToInt32(invariantCulture));
        break;
      case TypeCode::UInt32:
        variant = Variant(convertible->ToUInt32(invariantCulture));
        break;
      case TypeCode::Int64:
        variant = Variant(convertible->ToInt64(invariantCulture));
        break;
      case TypeCode::UInt64:
        variant = Variant(convertible->ToUInt64(invariantCulture));
        break;
      case TypeCode::Single:
        variant = Variant(convertible->ToSingle(invariantCulture));
        break;
      case TypeCode::Double:
        variant = Variant(convertible->ToDouble(invariantCulture));
        break;
      case TypeCode::Decimal:
        variant = Variant(convertible->ToDecimal(invariantCulture));
        break;
      case TypeCode::DateTime:
        variant = Variant(convertible->ToDateTime(invariantCulture));
        break;
      case TypeCode::String:
        variant = Variant(convertible->ToString(invariantCulture));
        break;
      default:
        rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_UnknownTypeCode(), convertible->GetTypeCode()));
    }
    v = variant;
  } else {
    v = Variant(o);
  }
}

Object Variant::MarshalHelperConvertVariantToObject(Variant& v) {
  return v.ToObject();
}

void Variant::MarshalHelperCastVariant(Object pValue, Int32 vt, Variant& v) {
  IConvertible convertible = rt::as<IConvertible>(pValue);
  Variant variant;
  if (convertible == nullptr) {
    switch (vt.get()) {
      case 9:
        v = Variant(rt::newobj<DispatchWrapper>(pValue));
        return;
      case 12:
        v = Variant(pValue);
        return;
      case 13:
        v = Variant(rt::newobj<UnknownWrapper>(pValue));
        return;
      case 36:
        v = Variant(pValue);
        return;
      case 8:
        if (pValue == nullptr) {
          variant = Variant(nullptr);
          v = variant;
          return;
        }
        break;
    }
    rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_CannotCoerceByRefVariant());
  }
  IFormatProvider invariantCulture = CultureInfo::in::get_InvariantCulture();
  switch (vt.get()) {
    case 0:
      variant = Empty;
      break;
    case 1:
      variant = DBNull;
      break;
    case 2:
      variant = Variant(convertible->ToInt16(invariantCulture));
      break;
    case 3:
      variant = Variant(convertible->ToInt32(invariantCulture));
      break;
    case 4:
      variant = Variant(convertible->ToSingle(invariantCulture));
      break;
    case 5:
      variant = Variant(convertible->ToDouble(invariantCulture));
      break;
    case 6:
      variant = Variant(rt::newobj<CurrencyWrapper>(convertible->ToDecimal(invariantCulture)));
      break;
    case 7:
      variant = Variant(convertible->ToDateTime(invariantCulture));
      break;
    case 8:
      variant = Variant(convertible->ToString(invariantCulture));
      break;
    case 9:
      variant = Variant(rt::newobj<DispatchWrapper>(convertible));
      break;
    case 10:
      variant = Variant(rt::newobj<ErrorWrapper>(convertible->ToInt32(invariantCulture)));
      break;
    case 11:
      variant = Variant(convertible->ToBoolean(invariantCulture));
      break;
    case 12:
      variant = Variant(convertible);
      break;
    case 13:
      variant = Variant(rt::newobj<UnknownWrapper>(convertible));
      break;
    case 14:
      variant = Variant(convertible->ToDecimal(invariantCulture));
      break;
    case 16:
      variant = Variant(convertible->ToSByte(invariantCulture));
      break;
    case 17:
      variant = Variant(convertible->ToByte(invariantCulture));
      break;
    case 18:
      variant = Variant(convertible->ToUInt16(invariantCulture));
      break;
    case 19:
      variant = Variant(convertible->ToUInt32(invariantCulture));
      break;
    case 20:
      variant = Variant(convertible->ToInt64(invariantCulture));
      break;
    case 21:
      variant = Variant(convertible->ToUInt64(invariantCulture));
      break;
    case 22:
      variant = Variant(convertible->ToInt32(invariantCulture));
      break;
    case 23:
      variant = Variant(convertible->ToUInt32(invariantCulture));
      break;
    default:
      rt::throw_exception<InvalidCastException>(SR::get_InvalidCast_CannotCoerceByRefVariant());
  }
  v = variant;
}

void Variant::cctor() {
  ClassTypes = rt::newarr<Array<Type>>(23);
  Empty = rt::default__;
  Missing = Variant(22, Type::in::Missing, 0);
  DBNull = Variant(23, DBNull::in::Value, 0);
}

} // namespace System::Private::CoreLib::System::VariantNamespace
