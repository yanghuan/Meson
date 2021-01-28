#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
FORWARD(Encoding)
namespace InternalDecoderBestFitFallbackNamespace {
CLASS(InternalDecoderBestFitFallback) : public DecoderFallback::in {
  public: Int32 get_MaxCharCount();
  public: void ctor(Encoding encoding);
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: Encoding _encoding;
  public: Array<Char> _arrayBestFit;
  public: Char _cReplacement;
};
} // namespace InternalDecoderBestFitFallbackNamespace
using InternalDecoderBestFitFallback = InternalDecoderBestFitFallbackNamespace::InternalDecoderBestFitFallback;
} // namespace System::Private::CoreLib::System::Text
