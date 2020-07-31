#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS.h>
#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
FORWARD(EncoderNLS)
namespace UnicodeEncodingNamespace {
CLASS(UnicodeEncoding) : public Encoding::in {
  private: CLASS(Decoder) : public DecoderNLS::in {
    public: Boolean get_HasState();
    public: void Ctor(UnicodeEncoding encoding);
    public: void Reset();
    public: Int32 lastByte;
    public: Char lastChar;
  };
  public: ReadOnlySpan<Byte> get_Preamble();
  public: void Ctor();
  public: void Ctor(Boolean bigEndian, Boolean byteOrderMark);
  public: void Ctor(Boolean bigEndian, Boolean byteOrderMark, Boolean throwOnInvalidBytes);
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
  public: Text::Decoder GetDecoder();
  public: Array<Byte> GetPreamble();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: static void SCtor();
  public: static UnicodeEncoding s_bigEndianDefault;
  public: static UnicodeEncoding s_littleEndianDefault;
  private: Boolean isThrowException;
  private: Boolean bigEndian;
  private: Boolean byteOrderMark;
  public: static constexpr Int32 CharSize = 2;
};
} // namespace UnicodeEncodingNamespace
using UnicodeEncoding = UnicodeEncodingNamespace::UnicodeEncoding;
} // namespace System::Private::CoreLib::System::Text
