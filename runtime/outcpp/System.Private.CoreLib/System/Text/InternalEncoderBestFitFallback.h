#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Char)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
FORWARD(Encoding)
namespace InternalEncoderBestFitFallbackNamespace {
CLASS(InternalEncoderBestFitFallback) {
  public: Int32 get_MaxCharCount();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: Encoding _encoding;
  public: Array<Char> _arrayBestFit;
};
} // namespace InternalEncoderBestFitFallbackNamespace
using InternalEncoderBestFitFallback = InternalEncoderBestFitFallbackNamespace::InternalEncoderBestFitFallback;
} // namespace System::Private::CoreLib::System::Text
