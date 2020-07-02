#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt64)
FORWARDS(Boolean)
FORWARDS(UInt32)
FORWARDS(Byte)
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace ASCIIUtilityNamespace {
class ASCIIUtility {
  private: static Boolean AllBytesInUInt64AreAscii(UInt64 value);
  private: static Boolean AllCharsInUInt32AreAscii(UInt32 value);
  private: static Boolean AllCharsInUInt64AreAscii(UInt64 value);
  private: static Boolean FirstCharInUInt32IsAscii(UInt32 value);
  public: static UInt64 GetIndexOfFirstNonAsciiByte(Byte* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonAsciiByte_Sse2(Byte* pBuffer, UInt64 bufferLength);
  public: static UInt64 GetIndexOfFirstNonAsciiChar(Char* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonAsciiChar_Sse2(Char* pBuffer, UInt64 bufferLength);
  private: static void NarrowFourUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt64 value);
  private: static void NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt32 value);
  public: static UInt64 NarrowUtf16ToAscii(Char* pUtf16Buffer, Byte* pAsciiBuffer, UInt64 elementCount);
  private: static UInt64 NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, UInt64 elementCount);
  public: static UInt64 WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UInt64 elementCount);
  private: static UInt64 WidenAsciiToUtf16_Sse2(Byte* pAsciiBuffer, Char* pUtf16Buffer, UInt64 elementCount);
  private: static void WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value);
  public: static Boolean AllBytesInUInt32AreAscii(UInt32 value);
  public: static UInt32 CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value);
};
} // namespace ASCIIUtilityNamespace
using ASCIIUtility = ASCIIUtilityNamespace::ASCIIUtility;
} // namespace System::Private::CoreLib::System::Text
