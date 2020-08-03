#pragma once

#include <System.Private.CoreLib/System/Text/EncoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderExceptionFallbackNamespace {
CLASS(EncoderExceptionFallback) : public EncoderFallback::in {
  public: Int32 get_MaxCharCount();
  public: void Ctor();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
};
} // namespace EncoderExceptionFallbackNamespace
using EncoderExceptionFallback = EncoderExceptionFallbackNamespace::EncoderExceptionFallback;
} // namespace System::Private::CoreLib::System::Text
