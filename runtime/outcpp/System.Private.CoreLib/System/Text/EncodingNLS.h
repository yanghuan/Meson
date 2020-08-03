#pragma once

#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
namespace EncodingNLSNamespace {
CLASS(EncodingNLS) : public Encoding::in {
  protected: void Ctor(Int32 codePage);
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
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
};
} // namespace EncodingNLSNamespace
using EncodingNLS = EncodingNLSNamespace::EncodingNLS;
} // namespace System::Private::CoreLib::System::Text
