#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARD(IFormatProvider)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(SByte)
FORWARDS(Byte)
FORWARDS(Int16)
FORWARDS(UInt16)
FORWARDS(Int32)
FORWARDS(UInt32)
FORWARDS(Int64)
FORWARDS(UInt64)
FORWARDS(Single)
FORWARDS(Double)
FORWARDS(Decimal)
FORWARDS(DateTime)
FORWARD(String)
FORWARD(Type)
FORWARD(Object)
namespace IConvertibleNamespace {
CLASS(IConvertible) {
  public: TypeCode GetTypeCode();
  public: Boolean ToBoolean(IFormatProvider provider);
  public: Char ToChar(IFormatProvider provider);
  public: SByte ToSByte(IFormatProvider provider);
  public: Byte ToByte(IFormatProvider provider);
  public: Int16 ToInt16(IFormatProvider provider);
  public: UInt16 ToUInt16(IFormatProvider provider);
  public: Int32 ToInt32(IFormatProvider provider);
  public: UInt32 ToUInt32(IFormatProvider provider);
  public: Int64 ToInt64(IFormatProvider provider);
  public: UInt64 ToUInt64(IFormatProvider provider);
  public: Single ToSingle(IFormatProvider provider);
  public: Double ToDouble(IFormatProvider provider);
  public: Decimal ToDecimal(IFormatProvider provider);
  public: DateTime ToDateTime(IFormatProvider provider);
  public: String ToString(IFormatProvider provider);
  public: Object ToType(Type conversionType, IFormatProvider provider);
};
} // namespace IConvertibleNamespace
using IConvertible = IConvertibleNamespace::IConvertible;
} // namespace System::Private::CoreLib::System
