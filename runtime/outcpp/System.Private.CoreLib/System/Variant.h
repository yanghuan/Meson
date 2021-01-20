#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Int16)
FORWARD(Object)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace VariantNamespace {
struct Variant : public valueType<Variant> {
  public: Int32 get_CVType();
  public: void SetFieldsObject(Object val);
  public: explicit Variant(Int32 flags, Object or一, Int64 data);
  public: explicit Variant(Boolean val);
  public: explicit Variant(SByte val);
  public: explicit Variant(Byte val);
  public: explicit Variant(Int16 val);
  public: explicit Variant(UInt16 val);
  public: explicit Variant(Char val);
  public: explicit Variant(Int32 val);
  public: explicit Variant(UInt32 val);
  public: explicit Variant(Int64 val);
  public: explicit Variant(UInt64 val);
  public: explicit Variant(Single val);
  public: explicit Variant(Double val);
  public: explicit Variant(DateTime val);
  public: explicit Variant(Decimal val);
  public: explicit Variant(Object obj);
  public: Object ToObject();
  private: Object BoxEnum();
  public: static void MarshalHelperConvertObjectToVariant(Object o, Variant& v);
  public: static Object MarshalHelperConvertVariantToObject(Variant& v);
  public: static void MarshalHelperCastVariant(Object pValue, Int32 vt, Variant& v);
  public: static void cctor();
  public: explicit Variant() {}
  private: Object _objref;
  private: Int64 _data;
  private: Int32 _flags;
  public: static constexpr Int32 CV_EMPTY = 0;
  public: static constexpr Int32 CV_VOID = 1;
  public: static constexpr Int32 CV_BOOLEAN = 2;
  public: static constexpr Int32 CV_CHAR = 3;
  public: static constexpr Int32 CV_I1 = 4;
  public: static constexpr Int32 CV_U1 = 5;
  public: static constexpr Int32 CV_I2 = 6;
  public: static constexpr Int32 CV_U2 = 7;
  public: static constexpr Int32 CV_I4 = 8;
  public: static constexpr Int32 CV_U4 = 9;
  public: static constexpr Int32 CV_I8 = 10;
  public: static constexpr Int32 CV_U8 = 11;
  public: static constexpr Int32 CV_R4 = 12;
  public: static constexpr Int32 CV_R8 = 13;
  public: static constexpr Int32 CV_STRING = 14;
  public: static constexpr Int32 CV_PTR = 15;
  public: static constexpr Int32 CV_DATETIME = 16;
  public: static constexpr Int32 CV_TIMESPAN = 17;
  public: static constexpr Int32 CV_OBJECT = 18;
  public: static constexpr Int32 CV_DECIMAL = 19;
  public: static constexpr Int32 CV_ENUM = 21;
  public: static constexpr Int32 CV_MISSING = 22;
  public: static constexpr Int32 CV_NULL = 23;
  public: static constexpr Int32 CV_LAST = 24;
  public: static constexpr Int32 TypeCodeBitMask = 65535;
  public: static constexpr Int32 VTBitMask = -16777216;
  public: static constexpr Int32 VTBitShift = 24;
  public: static constexpr Int32 ArrayBitMask = 65536;
  public: static constexpr Int32 EnumI1 = 1048576;
  public: static constexpr Int32 EnumU1 = 2097152;
  public: static constexpr Int32 EnumI2 = 3145728;
  public: static constexpr Int32 EnumU2 = 4194304;
  public: static constexpr Int32 EnumI4 = 5242880;
  public: static constexpr Int32 EnumU4 = 6291456;
  public: static constexpr Int32 EnumI8 = 7340032;
  public: static constexpr Int32 EnumU8 = 8388608;
  public: static constexpr Int32 EnumMask = 15728640;
  public: static Array<Type> ClassTypes;
  public: static Variant Empty;
  public: static Variant Missing;
  public: static Variant DBNull;
};
} // namespace VariantNamespace
using Variant = VariantNamespace::Variant;
} // namespace System::Private::CoreLib::System
