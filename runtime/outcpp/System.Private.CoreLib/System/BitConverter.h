#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Double)
FORWARDS(Half)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
namespace BitConverterNamespace {
using namespace System::Buffers;
class BitConverter {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _ToString_b__39_0(Span<Char> dst, ValueTuple<Array<Byte>, Int32, Int32> state);
    public: static __c __9;
    public: static SpanAction<Char, ValueTuple<Array<Byte>, Int32, Int32>> __9__39_0;
  };
  public: static Array<Byte> GetBytes(Boolean value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Boolean value);
  public: static Array<Byte> GetBytes(Char value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Char value);
  public: static Array<Byte> GetBytes(Int16 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Int16 value);
  public: static Array<Byte> GetBytes(Int32 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Int32 value);
  public: static Array<Byte> GetBytes(Int64 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Int64 value);
  public: static Array<Byte> GetBytes(UInt16 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, UInt16 value);
  public: static Array<Byte> GetBytes(UInt32 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, UInt32 value);
  public: static Array<Byte> GetBytes(UInt64 value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, UInt64 value);
  public: static Array<Byte> GetBytes(Single value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Single value);
  public: static Array<Byte> GetBytes(Double value);
  public: static Boolean TryWriteBytes(Span<Byte> destination, Double value);
  public: static Char ToChar(Array<Byte> value, Int32 startIndex);
  public: static Char ToChar(ReadOnlySpan<Byte> value);
  public: static Int16 ToInt16(Array<Byte> value, Int32 startIndex);
  public: static Int16 ToInt16(ReadOnlySpan<Byte> value);
  public: static Int32 ToInt32(Array<Byte> value, Int32 startIndex);
  public: static Int32 ToInt32(ReadOnlySpan<Byte> value);
  public: static Int64 ToInt64(Array<Byte> value, Int32 startIndex);
  public: static Int64 ToInt64(ReadOnlySpan<Byte> value);
  public: static UInt16 ToUInt16(Array<Byte> value, Int32 startIndex);
  public: static UInt16 ToUInt16(ReadOnlySpan<Byte> value);
  public: static UInt32 ToUInt32(Array<Byte> value, Int32 startIndex);
  public: static UInt32 ToUInt32(ReadOnlySpan<Byte> value);
  public: static UInt64 ToUInt64(Array<Byte> value, Int32 startIndex);
  public: static UInt64 ToUInt64(ReadOnlySpan<Byte> value);
  public: static Single ToSingle(Array<Byte> value, Int32 startIndex);
  public: static Single ToSingle(ReadOnlySpan<Byte> value);
  public: static Double ToDouble(Array<Byte> value, Int32 startIndex);
  public: static Double ToDouble(ReadOnlySpan<Byte> value);
  public: static String ToString(Array<Byte> value, Int32 startIndex, Int32 length);
  public: static String ToString(Array<Byte> value);
  public: static String ToString(Array<Byte> value, Int32 startIndex);
  public: static Boolean ToBoolean(Array<Byte> value, Int32 startIndex);
  public: static Boolean ToBoolean(ReadOnlySpan<Byte> value);
  public: static Int64 DoubleToInt64Bits(Double value);
  public: static Double Int64BitsToDouble(Int64 value);
  public: static Int32 SingleToInt32Bits(Single value);
  public: static Single Int32BitsToSingle(Int32 value);
  public: static Int16 HalfToInt16Bits(Half value);
  public: static Half Int16BitsToHalf(Int16 value);
  public: static void cctor();
  public: static Boolean IsLittleEndian;
};
} // namespace BitConverterNamespace
using BitConverter = BitConverterNamespace::BitConverter;
} // namespace System::Private::CoreLib::System
