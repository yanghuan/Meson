#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System::Text {
namespace OSEncodingNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(OSEncoding) {
  public: String get_EncodingName();
  public: String get_WebName();
  public: void Ctor(Int32 codePage);
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count);
  public: Int32 GetByteCount(String s);
  public: Int32 GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Encoder GetEncoder();
  public: Decoder GetDecoder();
  public: static Int32 WideCharToMultiByte(Int32 codePage, Char* pChars, Int32 count, Byte* pBytes, Int32 byteCount);
  public: static Int32 MultiByteToWideChar(Int32 codePage, Byte* pBytes, Int32 byteCount, Char* pChars, Int32 count);
  private: Int32 _codePage;
  private: String _encodingName;
};
} // namespace OSEncodingNamespace
using OSEncoding = OSEncodingNamespace::OSEncoding;
} // namespace System::Console::System::Text
