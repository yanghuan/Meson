#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Byte)
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderNLS)
FORWARD(DecoderNLS)
FORWARD(Encoder)
FORWARD(Decoder)
namespace UnicodeEncodingNamespace {
CLASS(UnicodeEncoding) {
  private: CLASS(Decoder) {
    public: Boolean get_HasState();
    public: void Reset();
    public: Int32 lastByte;
    public: Char lastChar;
  };
  public: ReadOnlySpan<Byte> get_Preamble();
  public: void SetDefaultFallbacks();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String s);
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: String GetString(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetByteCount(Char* chars, Int32 count, EncoderNLS encoder);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder);
  public: Encoder GetEncoder();
  public: ::System::Private::CoreLib::System::Text::Decoder GetDecoder();
  public: Array<Byte> GetPreamble();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: static UnicodeEncoding s_bigEndianDefault;
  public: static UnicodeEncoding s_littleEndianDefault;
  private: Boolean isThrowException;
  private: Boolean bigEndian;
  private: Boolean byteOrderMark;
  public: static Int32 CharSize;
};
} // namespace UnicodeEncodingNamespace
using UnicodeEncoding = UnicodeEncodingNamespace::UnicodeEncoding;
} // namespace System::Private::CoreLib::System::Text
