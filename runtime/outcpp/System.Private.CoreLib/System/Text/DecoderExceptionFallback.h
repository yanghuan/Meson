#pragma once

#include <System.Private.CoreLib/System/Text/DecoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
namespace DecoderExceptionFallbackNamespace {
CLASS(DecoderExceptionFallback) : public DecoderFallback::in {
  public: Int32 get_MaxCharCount();
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: void ctor();
  private: static void cctor();
  public: static DecoderExceptionFallback s_default;
};
} // namespace DecoderExceptionFallbackNamespace
using DecoderExceptionFallback = DecoderExceptionFallbackNamespace::DecoderExceptionFallback;
} // namespace System::Private::CoreLib::System::Text
