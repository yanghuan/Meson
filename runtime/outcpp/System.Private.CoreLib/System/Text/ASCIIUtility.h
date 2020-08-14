#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace ASCIIUtilityNamespace {
class ASCIIUtility {
  private: static Boolean AllBytesInUInt64AreAscii(UInt64 value);
  private: static Boolean AllCharsInUInt32AreAscii(UInt32 value);
  private: static Boolean AllCharsInUInt64AreAscii(UInt64 value);
  private: static Boolean FirstCharInUInt32IsAscii(UInt32 value);
  public: static unsigned int GetIndexOfFirstNonAsciiByte(Byte* pBuffer, unsigned int bufferLength);
  private: static unsigned int GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, unsigned int bufferLength);
  private: static unsigned int GetIndexOfFirstNonAsciiByte_Sse2(Byte* pBuffer, unsigned int bufferLength);
  public: static unsigned int GetIndexOfFirstNonAsciiChar(Char* pBuffer, unsigned int bufferLength);
  private: static unsigned int GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, unsigned int bufferLength);
  private: static unsigned int GetIndexOfFirstNonAsciiChar_Sse2(Char* pBuffer, unsigned int bufferLength);
  private: static void NarrowFourUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt64 value);
  private: static void NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt32 value);
  public: static unsigned int NarrowUtf16ToAscii(Char* pUtf16Buffer, Byte* pAsciiBuffer, unsigned int elementCount);
  private: static unsigned int NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, unsigned int elementCount);
  public: static unsigned int WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, unsigned int elementCount);
  private: static unsigned int WidenAsciiToUtf16_Sse2(Byte* pAsciiBuffer, Char* pUtf16Buffer, unsigned int elementCount);
  public: static void WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value);
  public: static Boolean AllBytesInUInt32AreAscii(UInt32 value);
  public: static UInt32 CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value);
};
} // namespace ASCIIUtilityNamespace
using ASCIIUtility = ASCIIUtilityNamespace::ASCIIUtility;
} // namespace System::Private::CoreLib::System::Text
