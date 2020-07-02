#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARD(Type)
namespace VariantNamespace {
struct Variant {
  public: Int32 get_CVType();
  public: void SetFieldsObject(Object val);
  public: Object ToObject();
  private: Object BoxEnum();
  public: static void MarshalHelperConvertObjectToVariant(Object o, Variant& v);
  public: static Object MarshalHelperConvertVariantToObject(Variant& v);
  public: static void MarshalHelperCastVariant(Object pValue, Int32 vt, Variant& v);
  private: Object _objref;
  private: Int64 _data;
  private: Int32 _flags;
  public: static Int32 CV_EMPTY;
  public: static Int32 CV_VOID;
  public: static Int32 CV_BOOLEAN;
  public: static Int32 CV_CHAR;
  public: static Int32 CV_I1;
  public: static Int32 CV_U1;
  public: static Int32 CV_I2;
  public: static Int32 CV_U2;
  public: static Int32 CV_I4;
  public: static Int32 CV_U4;
  public: static Int32 CV_I8;
  public: static Int32 CV_U8;
  public: static Int32 CV_R4;
  public: static Int32 CV_R8;
  public: static Int32 CV_STRING;
  public: static Int32 CV_PTR;
  public: static Int32 CV_DATETIME;
  public: static Int32 CV_TIMESPAN;
  public: static Int32 CV_OBJECT;
  public: static Int32 CV_DECIMAL;
  public: static Int32 CV_ENUM;
  public: static Int32 CV_MISSING;
  public: static Int32 CV_NULL;
  public: static Int32 CV_LAST;
  public: static Int32 TypeCodeBitMask;
  public: static Int32 VTBitMask;
  public: static Int32 VTBitShift;
  public: static Int32 ArrayBitMask;
  public: static Int32 EnumI1;
  public: static Int32 EnumU1;
  public: static Int32 EnumI2;
  public: static Int32 EnumU2;
  public: static Int32 EnumI4;
  public: static Int32 EnumU4;
  public: static Int32 EnumI8;
  public: static Int32 EnumU8;
  public: static Int32 EnumMask;
  public: static Array<Type> ClassTypes;
  public: static Variant Empty;
  public: static Variant Missing;
  public: static Variant DBNull;
};
} // namespace VariantNamespace
using Variant = VariantNamespace::Variant;
} // namespace System::Private::CoreLib::System
