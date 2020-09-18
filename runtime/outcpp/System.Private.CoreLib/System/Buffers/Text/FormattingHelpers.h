#pragma once

#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Span, T)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARDS(StandardFormat)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Buffers::Text {
namespace FormattingHelpersNamespace {
class FormattingHelpers {
  public: static Int32 CountDigits(UInt64 value);
  public: static Int32 CountDigits(UInt32 value);
  public: static Int32 CountHexDigits(UInt64 value);
  public: static Int32 CountDecimalTrailingZeros(UInt32 value, UInt32& valueWithoutTrailingZeros);
  public: static Char GetSymbolOrDefault(StandardFormat& format, Char defaultSymbol);
  public: static void FillWithAsciiZeros(Span<Byte> buffer);
  public: static void WriteDigits(UInt64 value, Span<Byte> buffer);
  public: static void WriteDigitsWithGroupSeparator(UInt64 value, Span<Byte> buffer);
  public: static void WriteDigits(UInt32 value, Span<Byte> buffer);
  public: static void WriteFourDecimalDigits(UInt32 value, Span<Byte> buffer, Int32 startingIndex = 0);
  public: static void WriteTwoDecimalDigits(UInt32 value, Span<Byte> buffer, Int32 startingIndex = 0);
  public: static UInt64 DivMod(UInt64 numerator, UInt64 denominator, UInt64& modulo);
  public: static UInt32 DivMod(UInt32 numerator, UInt32 denominator, UInt32& modulo);
  public: static Boolean TryFormatThrowFormatException(Int32& bytesWritten);
};
} // namespace FormattingHelpersNamespace
using FormattingHelpers = FormattingHelpersNamespace::FormattingHelpers;
} // namespace System::Private::CoreLib::System::Buffers::Text
