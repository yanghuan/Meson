#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
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
