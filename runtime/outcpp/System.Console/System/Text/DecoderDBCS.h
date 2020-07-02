#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System::Text {
namespace DecoderDBCSNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(DecoderDBCS) {
  private: Boolean IsLeadByte(Byte b);
  public: void Reset();
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush);
  private: Int32 ConvertWithLeftOverByte(Byte* bytes, Int32 count, Char* chars, Int32 charCount);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, Boolean flush);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush);
  public: void Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: void Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  private: Boolean IsLastByteALeadByte(Byte* bytes, Int32 count);
  private: Encoding _encoding;
  private: Array<Byte> _leadByteRanges;
  private: Int32 _rangesCount;
  private: Byte _leftOverLeadByte;
};
} // namespace DecoderDBCSNamespace
using DecoderDBCS = DecoderDBCSNamespace::DecoderDBCS;
} // namespace System::Console::System::Text
