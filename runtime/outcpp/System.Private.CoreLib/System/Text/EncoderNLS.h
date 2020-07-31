#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/Encoder.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
namespace EncoderNLSNamespace {
CLASS(EncoderNLS) : public Encoder::in {
  public: Encoding get_Encoding();
  public: Boolean get_MustFlush();
  public: Boolean get_HasLeftoverData();
  public: Boolean get_HasState();
  public: void Ctor(Encoding encoding);
  public: void Reset();
  public: Int32 GetByteCount(Array<Char> chars, Int32 index, Int32 count, Boolean flush);
  public: Int32 GetByteCount(Char* chars, Int32 count, Boolean flush);
  public: Int32 GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Boolean flush);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush);
  public: void Convert(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: void Convert(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, Boolean flush, Int32& charsUsed, Int32& bytesUsed, Boolean& completed);
  public: void ClearMustFlush();
  public: Int32 DrainLeftoverDataForGetByteCount(ReadOnlySpan<Char> chars, Int32& charsConsumed);
  public: Boolean TryDrainLeftoverDataForGetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes, Int32& charsConsumed, Int32& bytesWritten);
  public: Char _charLeftOver;
  private: Encoding _encoding;
  private: Boolean _mustFlush;
  public: Boolean _throwOnOverflow;
  public: Int32 _charsUsed;
};
} // namespace EncoderNLSNamespace
using EncoderNLS = EncoderNLSNamespace::EncoderNLS;
} // namespace System::Private::CoreLib::System::Text
