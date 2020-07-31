#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(EncoderFallbackBuffer)
namespace EncoderReplacementFallbackNamespace {
CLASS(EncoderReplacementFallback) : public EncoderFallback::in {
  public: String get_DefaultString();
  public: Int32 get_MaxCharCount();
  public: void Ctor();
  public: void Ctor(String replacement);
  public: EncoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: String _strDefault;
};
} // namespace EncoderReplacementFallbackNamespace
using EncoderReplacementFallback = EncoderReplacementFallbackNamespace::EncoderReplacementFallback;
} // namespace System::Private::CoreLib::System::Text
