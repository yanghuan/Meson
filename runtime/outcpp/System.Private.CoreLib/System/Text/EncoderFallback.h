#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderFallbackNamespace {
CLASS(EncoderFallback) {
  public: static EncoderFallback get_ReplacementFallback();
  public: static EncoderFallback get_ExceptionFallback();
  public: Int32 get_MaxCharCount();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  protected: void Ctor();
  private: static EncoderFallback s_replacementFallback;
  private: static EncoderFallback s_exceptionFallback;
};
} // namespace EncoderFallbackNamespace
using EncoderFallback = EncoderFallbackNamespace::EncoderFallback;
} // namespace System::Private::CoreLib::System::Text
