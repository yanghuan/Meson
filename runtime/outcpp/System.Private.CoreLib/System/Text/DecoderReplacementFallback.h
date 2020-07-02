#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
namespace DecoderReplacementFallbackNamespace {
CLASS(DecoderReplacementFallback) {
  public: String get_DefaultString();
  public: Int32 get_MaxCharCount();
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: String _strDefault;
};
} // namespace DecoderReplacementFallbackNamespace
using DecoderReplacementFallback = DecoderReplacementFallbackNamespace::DecoderReplacementFallback;
} // namespace System::Private::CoreLib::System::Text
