#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128, T1, T2)
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
namespace System::Private::CoreLib::System::Text::Unicode {
namespace Utf16UtilityNamespace {
using namespace System::Runtime::Intrinsics;
class Utf16Utility {
  public: static Boolean AllCharsInUInt32AreAscii(UInt32 value);
  public: static Boolean AllCharsInUInt64AreAscii(UInt64 value);
  public: static UInt32 ConvertAllAsciiCharsInUInt32ToLowercase(UInt32 value);
  public: static UInt32 ConvertAllAsciiCharsInUInt32ToUppercase(UInt32 value);
  public: static Boolean UInt32ContainsAnyLowercaseAsciiChar(UInt32 value);
  public: static Boolean UInt32ContainsAnyUppercaseAsciiChar(UInt32 value);
  public: static Boolean UInt32OrdinalIgnoreCaseAscii(UInt32 valueA, UInt32 valueB);
  public: static Boolean UInt64OrdinalIgnoreCaseAscii(UInt64 valueA, UInt64 valueB);
  public: static Char* GetPointerToFirstInvalidChar(Char* pInputBuffer, Int32 inputLength, Int64& utf8CodeUnitCountAdjustment, Int32& scalarCountAdjustment);
  private: static UInt32 GetNonAsciiBytes(Vector128<Byte> value, Vector128<Byte> bitMask128);
};
} // namespace Utf16UtilityNamespace
using Utf16Utility = Utf16UtilityNamespace::Utf16Utility;
} // namespace System::Private::CoreLib::System::Text::Unicode
