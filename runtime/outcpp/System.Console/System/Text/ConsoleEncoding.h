#pragma once

#include <System.Private.CoreLib/System/Text/Encoding.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System::Text {
namespace ConsoleEncodingNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(ConsoleEncoding) : public Encoding::in {
  public: Int32 get_CodePage();
  public: Boolean get_IsSingleByte();
  public: String get_EncodingName();
  public: String get_WebName();
  public: void ctor(Encoding encoding);
  public: Array<Byte> GetPreamble();
  public: Int32 GetByteCount(Array<Char> chars);
  public: Int32 GetByteCount(Char* chars, Int32 count);
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String s);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount);
  public: Array<Byte> GetBytes(Array<Char> chars);
  public: Array<Byte> GetBytes(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Array<Byte> GetBytes(String s);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetCharCount(Byte* bytes, Int32 count);
  public: Int32 GetCharCount(Array<Byte> bytes);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount);
  public: Array<Char> GetChars(Array<Byte> bytes);
  public: Array<Char> GetChars(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Decoder GetDecoder();
  public: Encoder GetEncoder();
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: String GetString(Array<Byte> bytes);
  public: String GetString(Array<Byte> bytes, Int32 index, Int32 count);
  private: Encoding _encoding;
};
} // namespace ConsoleEncodingNamespace
using ConsoleEncoding = ConsoleEncodingNamespace::ConsoleEncoding;
} // namespace System::Console::System::Text
