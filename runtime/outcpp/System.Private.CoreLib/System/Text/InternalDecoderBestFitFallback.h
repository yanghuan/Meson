#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
FORWARD(Encoding)
namespace InternalDecoderBestFitFallbackNamespace {
CLASS(InternalDecoderBestFitFallback) {
  public: Int32 get_MaxCharCount();
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
