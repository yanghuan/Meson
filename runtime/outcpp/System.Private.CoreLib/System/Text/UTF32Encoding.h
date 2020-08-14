#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS.h>
#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
FORWARD(EncoderNLS)
namespace UTF32EncodingNamespace {
CLASS(UTF32Encoding) : public Encoding::in {
  private: CLASS(UTF32Decoder) : public DecoderNLS::in {
    public: Boolean get_HasState();
    public: void ctor(UTF32Encoding encoding);
    public: void Reset();
    public: Int32 iChar;
    public: Int32 readByteCount;
  };
  public: ReadOnlySpan<Byte> get_Preamble();
  public: void ctor();
  public: void ctor(Boolean bigEndian, Boolean byteOrderMark);
  public: void ctor(Boolean bigEndian, Boolean byteOrderMark, Boolean throwOnInvalidCharacters);
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
  private: UInt32 GetSurrogate(Char cHigh, Char cLow);
  private: Char GetHighSurrogate(UInt32 iChar);
  private: Char GetLowSurrogate(UInt32 iChar);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Array<Byte> GetPreamble();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: static void cctor();
  public: static UTF32Encoding s_default;
  public: static UTF32Encoding s_bigEndianDefault;
  private: Boolean _emitUTF32ByteOrderMark;
  private: Boolean _isThrowException;
  private: Boolean _bigEndian;
};
} // namespace UTF32EncodingNamespace
using UTF32Encoding = UTF32EncodingNamespace::UTF32Encoding;
} // namespace System::Private::CoreLib::System::Text
