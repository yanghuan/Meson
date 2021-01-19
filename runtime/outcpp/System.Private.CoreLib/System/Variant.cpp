#include "Variant-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IConvertible.h>
#include <System.Private.CoreLib/System/IFormatProvider.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/BStrWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CurrencyWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DispatchWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ErrorWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/UnknownWrapper-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/VarEnum.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/Variant-dep.h>

namespace System::Private::CoreLib::System::VariantNamespace {
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

Int32 Variant::get_CVType() {
  return _flags & 65535;
}

Variant::Variant(Int32 flags, Object or一, Int64 data) {
  _flags = flags;
  _objref = or一;
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
}

void Variant::MarshalHelperConvertObjectToVariant(Object o, Variant& v) {
  if (o == nullptr) {
    v = Empty;
    return;
  }
  IConvertible convertible = rt::as<IConvertible>(o);
  if (convertible != nullptr) {
    IFormatProvider invariantCulture = CultureInfo::in::get_InvariantCulture();
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
}

void Variant::cctor() {
  ClassTypes = rt::newarr<Array<Type>>(23);
  Missing = Variant(22, Type::in::Missing, 0);
  DBNull = Variant(23, DBNull::in::Value, 0);
}

} // namespace System::Private::CoreLib::System::VariantNamespace
