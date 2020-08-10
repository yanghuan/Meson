#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
enum class Base64FormattingOptions;
enum class TypeCode;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IConvertible)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace ConvertNamespace {
class Convert {
  private: static ReadOnlySpan<SByte> get_DecodingMap();
  private: static Boolean TryDecodeFromUtf16(ReadOnlySpan<Char> utf16, Span<Byte> bytes, Int32& consumed, Int32& written);
  private: static Int32 Decode(Char& encodedChars, SByte& decodingMap);
  private: static void WriteThreeLowOrderBytes(Byte& destination, Int32 value);
  public: static TypeCode GetTypeCode(Object value);
  public: static Boolean IsDBNull(Object value);
  public: static Object ChangeType(Object value, TypeCode typeCode);
  public: static Object ChangeType(Object value, TypeCode typeCode, IFormatProvider provider);
  public: static Object DefaultToType(IConvertible value, Type targetType, IFormatProvider provider);
  public: static Object ChangeType(Object value, Type conversionType);
  public: static Object ChangeType(Object value, Type conversionType, IFormatProvider provider);
  private: static void ThrowCharOverflowException();
  private: static void ThrowByteOverflowException();
  private: static void ThrowSByteOverflowException();
  private: static void ThrowInt16OverflowException();
  private: static void ThrowUInt16OverflowException();
  private: static void ThrowInt32OverflowException();
  private: static void ThrowUInt32OverflowException();
  private: static void ThrowInt64OverflowException();
  private: static void ThrowUInt64OverflowException();
  public: static Boolean ToBoolean(Object value);
  public: static Boolean ToBoolean(Object value, IFormatProvider provider);
  public: static Boolean ToBoolean(Boolean value);
  public: static Boolean ToBoolean(SByte value);
  public: static Boolean ToBoolean(Char value);
  public: static Boolean ToBoolean(Byte value);
  public: static Boolean ToBoolean(Int16 value);
  public: static Boolean ToBoolean(UInt16 value);
  public: static Boolean ToBoolean(Int32 value);
  public: static Boolean ToBoolean(UInt32 value);
  public: static Boolean ToBoolean(Int64 value);
  public: static Boolean ToBoolean(UInt64 value);
  public: static Boolean ToBoolean(String value);
  public: static Boolean ToBoolean(String value, IFormatProvider provider);
  public: static Boolean ToBoolean(Single value);
  public: static Boolean ToBoolean(Double value);
  public: static Boolean ToBoolean(Decimal value);
  public: static Boolean ToBoolean(DateTime value);
  public: static Char ToChar(Object value);
  public: static Char ToChar(Object value, IFormatProvider provider);
  public: static Char ToChar(Boolean value);
  public: static Char ToChar(Char value);
  public: static Char ToChar(SByte value);
  public: static Char ToChar(Byte value);
  public: static Char ToChar(Int16 value);
  public: static Char ToChar(UInt16 value);
  public: static Char ToChar(Int32 value);
  public: static Char ToChar(UInt32 value);
  public: static Char ToChar(Int64 value);
  public: static Char ToChar(UInt64 value);
  public: static Char ToChar(String value);
  public: static Char ToChar(String value, IFormatProvider provider);
  public: static Char ToChar(Single value);
  public: static Char ToChar(Double value);
  public: static Char ToChar(Decimal value);
  public: static Char ToChar(DateTime value);
  public: static SByte ToSByte(Object value);
  public: static SByte ToSByte(Object value, IFormatProvider provider);
  public: static SByte ToSByte(Boolean value);
  public: static SByte ToSByte(SByte value);
  public: static SByte ToSByte(Char value);
  public: static SByte ToSByte(Byte value);
  public: static SByte ToSByte(Int16 value);
  public: static SByte ToSByte(UInt16 value);
  public: static SByte ToSByte(Int32 value);
  public: static SByte ToSByte(UInt32 value);
  public: static SByte ToSByte(Int64 value);
  public: static SByte ToSByte(UInt64 value);
  public: static SByte ToSByte(Single value);
  public: static SByte ToSByte(Double value);
  public: static SByte ToSByte(Decimal value);
  public: static SByte ToSByte(String value);
  public: static SByte ToSByte(String value, IFormatProvider provider);
  public: static SByte ToSByte(DateTime value);
  public: static Byte ToByte(Object value);
  public: static Byte ToByte(Object value, IFormatProvider provider);
  public: static Byte ToByte(Boolean value);
  public: static Byte ToByte(Byte value);
  public: static Byte ToByte(Char value);
  public: static Byte ToByte(SByte value);
  public: static Byte ToByte(Int16 value);
  public: static Byte ToByte(UInt16 value);
  public: static Byte ToByte(Int32 value);
  public: static Byte ToByte(UInt32 value);
  public: static Byte ToByte(Int64 value);
  public: static Byte ToByte(UInt64 value);
  public: static Byte ToByte(Single value);
  public: static Byte ToByte(Double value);
  public: static Byte ToByte(Decimal value);
  public: static Byte ToByte(String value);
  public: static Byte ToByte(String value, IFormatProvider provider);
  public: static Byte ToByte(DateTime value);
  public: static Int16 ToInt16(Object value);
  public: static Int16 ToInt16(Object value, IFormatProvider provider);
  public: static Int16 ToInt16(Boolean value);
  public: static Int16 ToInt16(Char value);
  public: static Int16 ToInt16(SByte value);
  public: static Int16 ToInt16(Byte value);
  public: static Int16 ToInt16(UInt16 value);
  public: static Int16 ToInt16(Int32 value);
  public: static Int16 ToInt16(UInt32 value);
  public: static Int16 ToInt16(Int16 value);
  public: static Int16 ToInt16(Int64 value);
  public: static Int16 ToInt16(UInt64 value);
  public: static Int16 ToInt16(Single value);
  public: static Int16 ToInt16(Double value);
  public: static Int16 ToInt16(Decimal value);
  public: static Int16 ToInt16(String value);
  public: static Int16 ToInt16(String value, IFormatProvider provider);
  public: static Int16 ToInt16(DateTime value);
  public: static UInt16 ToUInt16(Object value);
  public: static UInt16 ToUInt16(Object value, IFormatProvider provider);
  public: static UInt16 ToUInt16(Boolean value);
  public: static UInt16 ToUInt16(Char value);
  public: static UInt16 ToUInt16(SByte value);
  public: static UInt16 ToUInt16(Byte value);
  public: static UInt16 ToUInt16(Int16 value);
  public: static UInt16 ToUInt16(Int32 value);
  public: static UInt16 ToUInt16(UInt16 value);
  public: static UInt16 ToUInt16(UInt32 value);
  public: static UInt16 ToUInt16(Int64 value);
  public: static UInt16 ToUInt16(UInt64 value);
  public: static UInt16 ToUInt16(Single value);
  public: static UInt16 ToUInt16(Double value);
  public: static UInt16 ToUInt16(Decimal value);
  public: static UInt16 ToUInt16(String value);
  public: static UInt16 ToUInt16(String value, IFormatProvider provider);
  public: static UInt16 ToUInt16(DateTime value);
  public: static Int32 ToInt32(Object value);
  public: static Int32 ToInt32(Object value, IFormatProvider provider);
  public: static Int32 ToInt32(Boolean value);
  public: static Int32 ToInt32(Char value);
  public: static Int32 ToInt32(SByte value);
  public: static Int32 ToInt32(Byte value);
  public: static Int32 ToInt32(Int16 value);
  public: static Int32 ToInt32(UInt16 value);
  public: static Int32 ToInt32(UInt32 value);
  public: static Int32 ToInt32(Int32 value);
  public: static Int32 ToInt32(Int64 value);
  public: static Int32 ToInt32(UInt64 value);
  public: static Int32 ToInt32(Single value);
  public: static Int32 ToInt32(Double value);
  public: static Int32 ToInt32(Decimal value);
  public: static Int32 ToInt32(String value);
  public: static Int32 ToInt32(String value, IFormatProvider provider);
  public: static Int32 ToInt32(DateTime value);
  public: static UInt32 ToUInt32(Object value);
  public: static UInt32 ToUInt32(Object value, IFormatProvider provider);
  public: static UInt32 ToUInt32(Boolean value);
  public: static UInt32 ToUInt32(Char value);
  public: static UInt32 ToUInt32(SByte value);
  public: static UInt32 ToUInt32(Byte value);
  public: static UInt32 ToUInt32(Int16 value);
  public: static UInt32 ToUInt32(UInt16 value);
  public: static UInt32 ToUInt32(Int32 value);
  public: static UInt32 ToUInt32(UInt32 value);
  public: static UInt32 ToUInt32(Int64 value);
  public: static UInt32 ToUInt32(UInt64 value);
  public: static UInt32 ToUInt32(Single value);
  public: static UInt32 ToUInt32(Double value);
  public: static UInt32 ToUInt32(Decimal value);
  public: static UInt32 ToUInt32(String value);
  public: static UInt32 ToUInt32(String value, IFormatProvider provider);
  public: static UInt32 ToUInt32(DateTime value);
  public: static Int64 ToInt64(Object value);
  public: static Int64 ToInt64(Object value, IFormatProvider provider);
  public: static Int64 ToInt64(Boolean value);
  public: static Int64 ToInt64(Char value);
  public: static Int64 ToInt64(SByte value);
  public: static Int64 ToInt64(Byte value);
  public: static Int64 ToInt64(Int16 value);
  public: static Int64 ToInt64(UInt16 value);
  public: static Int64 ToInt64(Int32 value);
  public: static Int64 ToInt64(UInt32 value);
  public: static Int64 ToInt64(UInt64 value);
  public: static Int64 ToInt64(Int64 value);
  public: static Int64 ToInt64(Single value);
  public: static Int64 ToInt64(Double value);
  public: static Int64 ToInt64(Decimal value);
  public: static Int64 ToInt64(String value);
  public: static Int64 ToInt64(String value, IFormatProvider provider);
  public: static Int64 ToInt64(DateTime value);
  public: static UInt64 ToUInt64(Object value);
  public: static UInt64 ToUInt64(Object value, IFormatProvider provider);
  public: static UInt64 ToUInt64(Boolean value);
  public: static UInt64 ToUInt64(Char value);
  public: static UInt64 ToUInt64(SByte value);
  public: static UInt64 ToUInt64(Byte value);
  public: static UInt64 ToUInt64(Int16 value);
  public: static UInt64 ToUInt64(UInt16 value);
  public: static UInt64 ToUInt64(Int32 value);
  public: static UInt64 ToUInt64(UInt32 value);
  public: static UInt64 ToUInt64(Int64 value);
  public: static UInt64 ToUInt64(UInt64 value);
  public: static UInt64 ToUInt64(Single value);
  public: static UInt64 ToUInt64(Double value);
  public: static UInt64 ToUInt64(Decimal value);
  public: static UInt64 ToUInt64(String value);
  public: static UInt64 ToUInt64(String value, IFormatProvider provider);
  public: static UInt64 ToUInt64(DateTime value);
  public: static Single ToSingle(Object value);
  public: static Single ToSingle(Object value, IFormatProvider provider);
  public: static Single ToSingle(SByte value);
  public: static Single ToSingle(Byte value);
  public: static Single ToSingle(Char value);
  public: static Single ToSingle(Int16 value);
  public: static Single ToSingle(UInt16 value);
  public: static Single ToSingle(Int32 value);
  public: static Single ToSingle(UInt32 value);
  public: static Single ToSingle(Int64 value);
  public: static Single ToSingle(UInt64 value);
  public: static Single ToSingle(Single value);
  public: static Single ToSingle(Double value);
  public: static Single ToSingle(Decimal value);
  public: static Single ToSingle(String value);
  public: static Single ToSingle(String value, IFormatProvider provider);
  public: static Single ToSingle(Boolean value);
  public: static Single ToSingle(DateTime value);
  public: static Double ToDouble(Object value);
  public: static Double ToDouble(Object value, IFormatProvider provider);
  public: static Double ToDouble(SByte value);
  public: static Double ToDouble(Byte value);
  public: static Double ToDouble(Int16 value);
  public: static Double ToDouble(Char value);
  public: static Double ToDouble(UInt16 value);
  public: static Double ToDouble(Int32 value);
  public: static Double ToDouble(UInt32 value);
  public: static Double ToDouble(Int64 value);
  public: static Double ToDouble(UInt64 value);
  public: static Double ToDouble(Single value);
  public: static Double ToDouble(Double value);
  public: static Double ToDouble(Decimal value);
  public: static Double ToDouble(String value);
  public: static Double ToDouble(String value, IFormatProvider provider);
  public: static Double ToDouble(Boolean value);
  public: static Double ToDouble(DateTime value);
  public: static Decimal ToDecimal(Object value);
  public: static Decimal ToDecimal(Object value, IFormatProvider provider);
  public: static Decimal ToDecimal(SByte value);
  public: static Decimal ToDecimal(Byte value);
  public: static Decimal ToDecimal(Char value);
  public: static Decimal ToDecimal(Int16 value);
  public: static Decimal ToDecimal(UInt16 value);
  public: static Decimal ToDecimal(Int32 value);
  public: static Decimal ToDecimal(UInt32 value);
  public: static Decimal ToDecimal(Int64 value);
  public: static Decimal ToDecimal(UInt64 value);
  public: static Decimal ToDecimal(Single value);
  public: static Decimal ToDecimal(Double value);
  public: static Decimal ToDecimal(String value);
  public: static Decimal ToDecimal(String value, IFormatProvider provider);
  public: static Decimal ToDecimal(Decimal value);
  public: static Decimal ToDecimal(Boolean value);
  public: static Decimal ToDecimal(DateTime value);
  public: static DateTime ToDateTime(DateTime value);
  public: static DateTime ToDateTime(Object value);
  public: static DateTime ToDateTime(Object value, IFormatProvider provider);
  public: static DateTime ToDateTime(String value);
  public: static DateTime ToDateTime(String value, IFormatProvider provider);
  public: static DateTime ToDateTime(SByte value);
  public: static DateTime ToDateTime(Byte value);
  public: static DateTime ToDateTime(Int16 value);
  public: static DateTime ToDateTime(UInt16 value);
  public: static DateTime ToDateTime(Int32 value);
  public: static DateTime ToDateTime(UInt32 value);
  public: static DateTime ToDateTime(Int64 value);
  public: static DateTime ToDateTime(UInt64 value);
  public: static DateTime ToDateTime(Boolean value);
  public: static DateTime ToDateTime(Char value);
  public: static DateTime ToDateTime(Single value);
  public: static DateTime ToDateTime(Double value);
  public: static DateTime ToDateTime(Decimal value);
  public: static String ToString(Object value);
  public: static String ToString(Object value, IFormatProvider provider);
  public: static String ToString(Boolean value);
  public: static String ToString(Boolean value, IFormatProvider provider);
  public: static String ToString(Char value);
  public: static String ToString(Char value, IFormatProvider provider);
  public: static String ToString(SByte value);
  public: static String ToString(SByte value, IFormatProvider provider);
  public: static String ToString(Byte value);
  public: static String ToString(Byte value, IFormatProvider provider);
  public: static String ToString(Int16 value);
  public: static String ToString(Int16 value, IFormatProvider provider);
  public: static String ToString(UInt16 value);
  public: static String ToString(UInt16 value, IFormatProvider provider);
  public: static String ToString(Int32 value);
  public: static String ToString(Int32 value, IFormatProvider provider);
  public: static String ToString(UInt32 value);
  public: static String ToString(UInt32 value, IFormatProvider provider);
  public: static String ToString(Int64 value);
  public: static String ToString(Int64 value, IFormatProvider provider);
  public: static String ToString(UInt64 value);
  public: static String ToString(UInt64 value, IFormatProvider provider);
  public: static String ToString(Single value);
  public: static String ToString(Single value, IFormatProvider provider);
  public: static String ToString(Double value);
  public: static String ToString(Double value, IFormatProvider provider);
  public: static String ToString(Decimal value);
  public: static String ToString(Decimal value, IFormatProvider provider);
  public: static String ToString(DateTime value);
  public: static String ToString(DateTime value, IFormatProvider provider);
  public: static String ToString(String value);
  public: static String ToString(String value, IFormatProvider provider);
  public: static Byte ToByte(String value, Int32 fromBase);
  public: static SByte ToSByte(String value, Int32 fromBase);
  public: static Int16 ToInt16(String value, Int32 fromBase);
  public: static UInt16 ToUInt16(String value, Int32 fromBase);
  public: static Int32 ToInt32(String value, Int32 fromBase);
  public: static UInt32 ToUInt32(String value, Int32 fromBase);
  public: static Int64 ToInt64(String value, Int32 fromBase);
  public: static UInt64 ToUInt64(String value, Int32 fromBase);
  public: static String ToString(Byte value, Int32 toBase);
  public: static String ToString(Int16 value, Int32 toBase);
  public: static String ToString(Int32 value, Int32 toBase);
  public: static String ToString(Int64 value, Int32 toBase);
  public: static String ToBase64String(Array<Byte> inArray);
  public: static String ToBase64String(Array<Byte> inArray, Base64FormattingOptions options);
  public: static String ToBase64String(Array<Byte> inArray, Int32 offset, Int32 length);
  public: static String ToBase64String(Array<Byte> inArray, Int32 offset, Int32 length, Base64FormattingOptions options);
  public: static String ToBase64String(ReadOnlySpan<Byte> bytes, Base64FormattingOptions options);
  public: static Int32 ToBase64CharArray(Array<Byte> inArray, Int32 offsetIn, Int32 length, Array<Char> outArray, Int32 offsetOut);
  public: static Int32 ToBase64CharArray(Array<Byte> inArray, Int32 offsetIn, Int32 length, Array<Char> outArray, Int32 offsetOut, Base64FormattingOptions options);
  public: static Boolean TryToBase64Chars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Int32& charsWritten, Base64FormattingOptions options);
  private: static Int32 ConvertToBase64Array(Char* outChars, Byte* inData, Int32 offset, Int32 length, Boolean insertLineBreaks);
  private: static Int32 ToBase64_CalculateAndValidateOutputLength(Int32 inputLength, Boolean insertLineBreaks);
  public: static Array<Byte> FromBase64String(String s);
  public: static Boolean TryFromBase64String(String s, Span<Byte> bytes, Int32& bytesWritten);
  public: static Boolean TryFromBase64Chars(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& bytesWritten);
  private: static void CopyToTempBufferWithoutWhiteSpace(ReadOnlySpan<Char> chars, Span<Char> tempBuffer, Int32& consumed, Int32& charsWritten);
  private: static Boolean IsSpace(Char c);
  public: static Array<Byte> FromBase64CharArray(Array<Char> inArray, Int32 offset, Int32 length);
  private: static Array<Byte> FromBase64CharPtr(Char* inputPtr, Int32 inputLength);
  private: static Int32 FromBase64_ComputeResultLength(Char* inputPtr, Int32 inputLength);
  private: static void ctor_static();
  public: static Array<Type> ConvertTypes;
  private: static Type EnumType;
  public: static Array<Char> base64Table;
  public: static Object DBNull;
};
} // namespace ConvertNamespace
using Convert = ConvertNamespace::Convert;
} // namespace System::Private::CoreLib::System
