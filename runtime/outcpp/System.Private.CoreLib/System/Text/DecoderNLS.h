#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/Decoder.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
namespace DecoderNLSNamespace {
CLASS(DecoderNLS) : public Decoder::in {
  public: Boolean get_MustFlush();
  public: Boolean get_HasState();
  public: Boolean get_HasLeftoverData();
  public: void Ctor(Encoding encoding);
  public: void Reset();
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count);
  public: Int32 GetCharCount(Array<Byte> bytes, Int32 index, Int32 count, Boolean flush);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, Boolean flush);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex);
  public: Int32 GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Boolean flush);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush);
  public: void Convert(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: void Convert(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, Boolean flush, Int32& bytesUsed, Int32& charsUsed, Boolean& completed);
  public: void ClearMustFlush();
  public: ReadOnlySpan<Byte> GetLeftoverData();
  public: void SetLeftoverData(ReadOnlySpan<Byte> bytes);
  public: void ClearLeftoverData();
  public: Int32 DrainLeftoverDataForGetCharCount(ReadOnlySpan<Byte> bytes, Int32& bytesConsumed);
  public: Int32 DrainLeftoverDataForGetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars, Int32& bytesConsumed);
  private: static Int32 ConcatInto(ReadOnlySpan<Byte> srcLeft, ReadOnlySpan<Byte> srcRight, Span<Byte> dest);
  private: Encoding _encoding;
  private: Boolean _mustFlush;
  public: Boolean _throwOnOverflow;
  public: Int32 _bytesUsed;
  private: Int32 _leftoverBytes;
  private: Int32 _leftoverByteCount;
};
} // namespace DecoderNLSNamespace
using DecoderNLS = DecoderNLSNamespace::DecoderNLS;
} // namespace System::Private::CoreLib::System::Text
