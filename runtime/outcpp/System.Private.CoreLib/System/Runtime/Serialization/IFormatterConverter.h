#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Type)
enum class TypeCode;
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
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace IFormatterConverterNamespace {
CLASS(IFormatterConverter) {
  public: Object Convert(Object value, Type type);
  public: Object Convert(Object value, TypeCode typeCode);
  public: Boolean ToBoolean(Object value);
  public: Char ToChar(Object value);
  public: SByte ToSByte(Object value);
  public: Byte ToByte(Object value);
  public: Int16 ToInt16(Object value);
  public: UInt16 ToUInt16(Object value);
  public: Int32 ToInt32(Object value);
  public: UInt32 ToUInt32(Object value);
  public: Int64 ToInt64(Object value);
  public: UInt64 ToUInt64(Object value);
  public: Single ToSingle(Object value);
  public: Double ToDouble(Object value);
  public: Decimal ToDecimal(Object value);
  public: DateTime ToDateTime(Object value);
  public: String ToString(Object value);
};
} // namespace IFormatterConverterNamespace
using IFormatterConverter = IFormatterConverterNamespace::IFormatterConverter;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
