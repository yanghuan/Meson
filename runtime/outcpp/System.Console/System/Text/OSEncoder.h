#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Console::System::Text {
namespace OSEncoderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(OSEncoder) {
  public: void Ctor(Encoding encoding);
  public: void Reset();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush);
  private: Int32 ConvertWithLeftOverChar(Char* chars, Int32 count, Byte* bytes, Int32 byteCount);
  public: Int32 GetByteCount(Char* chars, Int32 count, Boolean flush);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush);
  public: void Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: void Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  private: Char _charLeftOver;
  private: Encoding _encoding;
};
} // namespace OSEncoderNamespace
using OSEncoder = OSEncoderNamespace::OSEncoder;
} // namespace System::Console::System::Text
