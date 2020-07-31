#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace ASCIIUtilityNamespace {
class ASCIIUtility : public Object::in {
  private: static Boolean AllBytesInUInt64AreAscii(UInt64 value);
  private: static Boolean AllCharsInUInt32AreAscii(UInt32 value);
  private: static Boolean AllCharsInUInt64AreAscii(UInt64 value);
  private: static Boolean FirstCharInUInt32IsAscii(UInt32 value);
  public: static UIntPtr GetIndexOfFirstNonAsciiByte(Byte* pBuffer, UIntPtr bufferLength);
  private: static UIntPtr GetIndexOfFirstNonAsciiByte_Default(Byte* pBuffer, UIntPtr bufferLength);
  private: static UIntPtr GetIndexOfFirstNonAsciiByte_Sse2(Byte* pBuffer, UIntPtr bufferLength);
  public: static UIntPtr GetIndexOfFirstNonAsciiChar(Char* pBuffer, UIntPtr bufferLength);
  private: static UIntPtr GetIndexOfFirstNonAsciiChar_Default(Char* pBuffer, UIntPtr bufferLength);
  private: static UIntPtr GetIndexOfFirstNonAsciiChar_Sse2(Char* pBuffer, UIntPtr bufferLength);
  private: static void NarrowFourUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt64 value);
  private: static void NarrowTwoUtf16CharsToAsciiAndWriteToBuffer(Byte& outputBuffer, UInt32 value);
  public: static UIntPtr NarrowUtf16ToAscii(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount);
  private: static UIntPtr NarrowUtf16ToAscii_Sse2(Char* pUtf16Buffer, Byte* pAsciiBuffer, UIntPtr elementCount);
  public: static UIntPtr WidenAsciiToUtf16(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount);
  private: static UIntPtr WidenAsciiToUtf16_Sse2(Byte* pAsciiBuffer, Char* pUtf16Buffer, UIntPtr elementCount);
  public: static void WidenFourAsciiBytesToUtf16AndWriteToBuffer(Char& outputBuffer, UInt32 value);
  public: static Boolean AllBytesInUInt32AreAscii(UInt32 value);
  public: static UInt32 CountNumberOfLeadingAsciiBytesFromUInt32WithSomeNonAsciiData(UInt32 value);
};
} // namespace ASCIIUtilityNamespace
using ASCIIUtility = ASCIIUtilityNamespace::ASCIIUtility;
} // namespace System::Private::CoreLib::System::Text
