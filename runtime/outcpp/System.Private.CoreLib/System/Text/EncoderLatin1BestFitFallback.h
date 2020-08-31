#pragma once

#include <System.Private.CoreLib/System/Text/EncoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderLatin1BestFitFallbackNamespace {
CLASS(EncoderLatin1BestFitFallback) : public EncoderFallback::in {
  public: Int32 get_MaxCharCount();
  private: void ctor();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  private: static void cctor();
  public: static EncoderLatin1BestFitFallback SingletonInstance;
};
} // namespace EncoderLatin1BestFitFallbackNamespace
using EncoderLatin1BestFitFallback = EncoderLatin1BestFitFallbackNamespace::EncoderLatin1BestFitFallback;
} // namespace System::Private::CoreLib::System::Text
