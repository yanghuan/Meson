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
namespace Latin1UtilityNamespace {
class Latin1Utility {
  public: static UInt64 GetIndexOfFirstNonLatin1Char(Char* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonLatin1Char_Default(Char* pBuffer, UInt64 bufferLength);
  private: static UInt64 GetIndexOfFirstNonLatin1Char_Sse2(Char* pBuffer, UInt64 bufferLength);
  public: static UInt64 NarrowUtf16ToLatin1(Char* pUtf16Buffer, Byte* pLatin1Buffer, UInt64 elementCount);
  private: static UInt64 NarrowUtf16ToLatin1_Sse2(Char* pUtf16Buffer, Byte* pLatin1Buffer, UInt64 elementCount);
  public: static void WidenLatin1ToUtf16(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount);
  private: static void WidenLatin1ToUtf16_Sse2(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount);
  private: static void WidenLatin1ToUtf16_Fallback(Byte* pLatin1Buffer, Char* pUtf16Buffer, UInt64 elementCount);
  private: static Boolean AllCharsInUInt32AreLatin1(UInt32 value);
  private: static Boolean AllCharsInUInt64AreLatin1(UInt64 value);
  private: static Boolean FirstCharInUInt32IsLatin1(UInt32 value);
  private: static void NarrowFourUtf16CharsToLatin1AndWriteToBuffer(Byte& outputBuffer, UInt64 value);
  private: static void NarrowTwoUtf16CharsToLatin1AndWriteToBuffer(Byte& outputBuffer, UInt32 value);
};
} // namespace Latin1UtilityNamespace
using Latin1Utility = Latin1UtilityNamespace::Latin1Utility;
} // namespace System::Private::CoreLib::System::Text
