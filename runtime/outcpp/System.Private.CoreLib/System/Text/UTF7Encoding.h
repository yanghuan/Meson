#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackBuffer.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS.h>
#include <System.Private.CoreLib/System/Text/EncoderNLS.h>
#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(SByte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
namespace UTF7EncodingNamespace {
CLASS(UTF7Encoding) : public Encoding::in {
  private: CLASS(Decoder) : public DecoderNLS::in {
    public: Boolean get_HasState();
    public: void ctor(UTF7Encoding encoding);
    public: void Reset();
    public: Int32 bits;
    public: Int32 bitCount;
    public: Boolean firstByte;
  };
  private: CLASS(Encoder) : public EncoderNLS::in {
    public: Boolean get_HasState();
    public: void ctor(UTF7Encoding encoding);
    public: void Reset();
    public: Int32 bits;
    public: Int32 bitCount;
  };
  private: CLASS(DecoderUTF7Fallback) : public DecoderFallback::in {
    public: Int32 get_MaxCharCount();
    public: DecoderFallbackBuffer CreateFallbackBuffer();
    public: Boolean Equals(Object value);
    public: Int32 GetHashCode();
    public: void ctor();
  };
  private: CLASS(DecoderUTF7FallbackBuffer) : public DecoderFallbackBuffer::in {
    public: Int32 get_Remaining();
    public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
    public: Char GetNextChar();
    public: Boolean MovePrevious();
    public: void Reset();
    public: Int32 InternalFallback(Array<Byte> bytes, Byte* pBytes);
    public: void ctor();
    private: Char cFallback;
    private: Int32 iCount;
    private: Int32 iSize;
  };
  public: void ctor();
  public: void ctor(Boolean allowOptionals);
  private: void MakeTables();
  public: void SetDefaultFallbacks();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
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
  public: Int32 GetByteCount(Char* chars, Int32 count, EncoderNLS baseEncoder);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS baseEncoder);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, DecoderNLS baseDecoder);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS baseDecoder);
  public: Text::Decoder GetDecoder();
  public: Text::Encoder GetEncoder();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: static void cctor();
  public: static UTF7Encoding s_default;
  private: Array<Byte> _base64Bytes;
  private: Array<SByte> _base64Values;
  private: Array<Boolean> _directEncode;
  private: Boolean _allowOptionals;
};
} // namespace UTF7EncodingNamespace
using UTF7Encoding = UTF7EncodingNamespace::UTF7Encoding;
} // namespace System::Private::CoreLib::System::Text
