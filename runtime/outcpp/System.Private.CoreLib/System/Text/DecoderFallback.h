#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
namespace DecoderFallbackNamespace {
CLASS(DecoderFallback) : public object {
  public: static DecoderFallback get_ReplacementFallback();
  public: static DecoderFallback get_ExceptionFallback();
  public: Int32 get_MaxCharCount();
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: void ctor();
};
} // namespace DecoderFallbackNamespace
using DecoderFallback = DecoderFallbackNamespace::DecoderFallback;
} // namespace System::Private::CoreLib::System::Text
