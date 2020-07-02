#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(Byte)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderNLS)
FORWARD(DecoderNLS)
enum class NormalizationForm;
namespace Latin1EncodingNamespace {
CLASS(Latin1Encoding) {
  public: Boolean get_IsSingleByte();
  public: Int32 GetByteCount(Char* chars, Int32 charCount, EncoderNLS encoder);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, DecoderNLS decoder);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS decoder);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Boolean IsAlwaysNormalized(NormalizationForm form);
  public: Array<Char> GetBestFitUnicodeToBytesData();
  public: static Latin1Encoding s_default;
  private: static Array<Char> arrayCharBestFit;
};
} // namespace Latin1EncodingNamespace
using Latin1Encoding = Latin1EncodingNamespace::Latin1Encoding;
} // namespace System::Private::CoreLib::System::Text
