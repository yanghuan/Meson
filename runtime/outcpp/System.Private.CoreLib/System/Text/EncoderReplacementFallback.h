#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderReplacementFallbackNamespace {
CLASS(EncoderReplacementFallback) {
  public: String get_DefaultString();
  public: Int32 get_MaxCharCount();
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: String _strDefault;
};
} // namespace EncoderReplacementFallbackNamespace
using EncoderReplacementFallback = EncoderReplacementFallbackNamespace::EncoderReplacementFallback;
} // namespace System::Private::CoreLib::System::Text
