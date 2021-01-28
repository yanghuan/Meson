#include "BitConverter-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::BitConverterNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::X86;

void BitConverter::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void BitConverter::__c___::ctor() {
}

void BitConverter::__c___::_ToString_b__39_0(Span<Char> dst, ValueTuple<Array<Byte>, Int32, Int32> state) {
  ReadOnlySpan<Byte> readOnlySpan = ReadOnlySpan<Byte>(state.Item1, state.Item2, state.Item3);
  Int32 num = 0;
  Int32 num2 = 0;
  Byte b = readOnlySpan[num++];
  dst[num2++] = HexConverter::ToCharUpper(b >> 4);
  dst[num2++] = HexConverter::ToCharUpper(b);
  while (num < readOnlySpan.get_Length()) {
    b = readOnlySpan[num++];
    dst[num2++] = u'-';
    dst[num2++] = HexConverter::ToCharUpper(b >> 4);
    dst[num2++] = HexConverter::ToCharUpper(b);
  }
}

Array<Byte> BitConverter::GetBytes(Boolean value) {
  return rt::newarr<Array<Byte>>(1);
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Boolean value) {
  if (destination.get_Length() < 1) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), (Byte)(value ? 1 : 0));
  return true;
}

Array<Byte> BitConverter::GetBytes(Char value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(2);
  Unsafe::As<Byte, Char>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Char value) {
  if (destination.get_Length() < 2) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(Int16 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(2);
  Unsafe::As<Byte, Int16>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Int16 value) {
  if (destination.get_Length() < 2) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(Int32 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(4);
  Unsafe::As<Byte, Int32>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Int32 value) {
  if (destination.get_Length() < 4) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(Int64 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(8);
  Unsafe::As<Byte, Int64>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Int64 value) {
  if (destination.get_Length() < 8) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(UInt16 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(2);
  Unsafe::As<Byte, UInt16>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, UInt16 value) {
  if (destination.get_Length() < 2) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(UInt32 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(4);
  Unsafe::As<Byte, UInt32>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, UInt32 value) {
  if (destination.get_Length() < 4) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(UInt64 value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(8);
  Unsafe::As<Byte, UInt64>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, UInt64 value) {
  if (destination.get_Length() < 8) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(Single value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(4);
  Unsafe::As<Byte, Single>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Single value) {
  if (destination.get_Length() < 4) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Array<Byte> BitConverter::GetBytes(Double value) {
  Array<Byte> array = rt::newarr<Array<Byte>>(8);
  Unsafe::As<Byte, Double>(array[0]) = value;
  return array;
}

Boolean BitConverter::TryWriteBytes(Span<Byte> destination, Double value) {
  if (destination.get_Length() < 8) {
    return false;
  }
  Unsafe::WriteUnaligned(MemoryMarshal::GetReference(destination), value);
  return true;
}

Char BitConverter::ToChar(Array<Byte> value, Int32 startIndex) {
  return (Char)ToInt16(value, startIndex);
}

Char BitConverter::ToChar(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Char>(MemoryMarshal::GetReference(value));
}

Int16 BitConverter::ToInt16(Array<Byte> value, Int32 startIndex) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  if ((UInt32)startIndex >= (UInt32)value->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  if (startIndex > value->get_Length() - 2) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_ArrayPlusOffTooSmall, ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int16>(value[startIndex]);
}

Int16 BitConverter::ToInt16(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int16>(MemoryMarshal::GetReference(value));
}

Int32 BitConverter::ToInt32(Array<Byte> value, Int32 startIndex) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  if ((UInt32)startIndex >= (UInt32)value->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  if (startIndex > value->get_Length() - 4) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_ArrayPlusOffTooSmall, ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int32>(value[startIndex]);
}

Int32 BitConverter::ToInt32(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 4) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int32>(MemoryMarshal::GetReference(value));
}

Int64 BitConverter::ToInt64(Array<Byte> value, Int32 startIndex) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  if ((UInt32)startIndex >= (UInt32)value->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  if (startIndex > value->get_Length() - 8) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_ArrayPlusOffTooSmall, ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int64>(value[startIndex]);
}

Int64 BitConverter::ToInt64(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 8) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Int64>(MemoryMarshal::GetReference(value));
}

UInt16 BitConverter::ToUInt16(Array<Byte> value, Int32 startIndex) {
  return (UInt16)ToInt16(value, startIndex);
}

UInt16 BitConverter::ToUInt16(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<UInt16>(MemoryMarshal::GetReference(value));
}

UInt32 BitConverter::ToUInt32(Array<Byte> value, Int32 startIndex) {
  return (UInt32)ToInt32(value, startIndex);
}

UInt32 BitConverter::ToUInt32(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 4) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<UInt32>(MemoryMarshal::GetReference(value));
}

UInt64 BitConverter::ToUInt64(Array<Byte> value, Int32 startIndex) {
  return (UInt64)ToInt64(value, startIndex);
}

UInt64 BitConverter::ToUInt64(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 8) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<UInt64>(MemoryMarshal::GetReference(value));
}

Single BitConverter::ToSingle(Array<Byte> value, Int32 startIndex) {
  return Int32BitsToSingle(ToInt32(value, startIndex));
}

Single BitConverter::ToSingle(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 4) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Single>(MemoryMarshal::GetReference(value));
}

Double BitConverter::ToDouble(Array<Byte> value, Int32 startIndex) {
  return Int64BitsToDouble(ToInt64(value, startIndex));
}

Double BitConverter::ToDouble(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 8) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Double>(MemoryMarshal::GetReference(value));
}

String BitConverter::ToString(Array<Byte> value, Int32 startIndex, Int32 length) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  if (startIndex < 0 || (startIndex >= value->get_Length() && startIndex > 0)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (startIndex > value->get_Length() - length) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_ArrayPlusOffTooSmall, ExceptionArgument::value);
  }
  if (length == 0) {
    return String::in::Empty;
  }
  if (length > 715827882) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::Format(SR::get_ArgumentOutOfRange_LengthTooLarge(), 715827882));
  }
  SpanAction<Char, ValueTuple<Array<Byte>, Int32, Int32>> as = __c::in::__9__39_0;
  return String::in::Create(length * 3 - 1, {value, startIndex, length}, as != nullptr ? as : (__c::in::__9__39_0 = {__c::in::__9, &__c::in::_ToString_b__39_0}));
}

String BitConverter::ToString(Array<Byte> value) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  return ToString(value, 0, value->get_Length());
}

String BitConverter::ToString(Array<Byte> value, Int32 startIndex) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  return ToString(value, startIndex, value->get_Length() - startIndex);
}

Boolean BitConverter::ToBoolean(Array<Byte> value, Int32 startIndex) {
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  if (startIndex < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  if (startIndex > value->get_Length() - 1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  return value[startIndex] != 0;
}

Boolean BitConverter::ToBoolean(ReadOnlySpan<Byte> value) {
  if (value.get_Length() < 1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  return Unsafe::ReadUnaligned<Byte>(MemoryMarshal::GetReference(value)) != 0;
}

Int64 BitConverter::DoubleToInt64Bits(Double value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Int64> value2 = Vector128<>::AsInt64(Vector128<>::CreateScalarUnsafe(value));
    return Sse2::in::X64::in::ConvertToInt64(value2);
  }
  return *(Int64*)(&value);
}

Double BitConverter::Int64BitsToDouble(Int64 value) {
  if (Sse2::in::X64::in::get_IsSupported()) {
    Vector128<Double> vector = Vector128<>::AsDouble(Vector128<>::CreateScalarUnsafe(value));
    return Vector128<>::ToScalar(vector);
  }
  return *(Double*)(&value);
}

Int32 BitConverter::SingleToInt32Bits(Single value) {
  if (Sse2::in::get_IsSupported()) {
    Vector128<Int32> value2 = Vector128<>::AsInt32(Vector128<>::CreateScalarUnsafe(value));
    return Sse2::in::ConvertToInt32(value2);
  }
  return *(Int32*)(&value);
}

Single BitConverter::Int32BitsToSingle(Int32 value) {
  if (Sse2::in::get_IsSupported()) {
    Vector128<Single> vector = Vector128<>::AsSingle(Vector128<>::CreateScalarUnsafe(value));
    return Vector128<>::ToScalar(vector);
  }
  return *(Single*)(&value);
}

void BitConverter::cctor() {
  IsLittleEndian = true;
}

} // namespace System::Private::CoreLib::System::BitConverterNamespace
