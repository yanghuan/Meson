#pragma once

#include <System.Private.CoreLib/System/Text/EncodingNLS.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm : int32_t;
FORWARD(DecoderNLS)
FORWARD(EncoderNLS)
namespace Latin1EncodingNamespace {
CLASS(Latin1Encoding) : public EncodingNLS::in {
  public: Boolean get_IsSingleByte();
  public: void ctor();
  public: Int32 GetByteCount(Char* chars, Int32 charCount, EncoderNLS encoder);
  public: Int32 GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount, EncoderNLS encoder);
  public: Int32 GetCharCount(Byte* bytes, Int32 count, DecoderNLS decoder);
  public: Int32 GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount, DecoderNLS decoder);
  public: Int32 GetMaxByteCount(Int32 charCount);
  public: Int32 GetMaxCharCount(Int32 byteCount);
  public: Boolean IsAlwaysNormalized(NormalizationForm form);
  public: Array<Char> GetBestFitUnicodeToBytesData();
  private: static void cctor();
  public: static Latin1Encoding s_default;
  private: static Array<Char> arrayCharBestFit;
};
} // namespace Latin1EncodingNamespace
using Latin1Encoding = Latin1EncodingNamespace::Latin1Encoding;
} // namespace System::Private::CoreLib::System::Text
