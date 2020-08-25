#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace IFormatterConverterNamespace {
CLASS(IFormatterConverter) : public object {
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
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IFormatterConverterNamespace
using IFormatterConverter = IFormatterConverterNamespace::IFormatterConverter;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
