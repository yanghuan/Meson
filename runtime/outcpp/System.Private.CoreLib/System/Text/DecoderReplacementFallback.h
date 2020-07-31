#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallbackBuffer)
namespace DecoderReplacementFallbackNamespace {
CLASS(DecoderReplacementFallback) : public DecoderFallback::in {
  public: String get_DefaultString();
  public: Int32 get_MaxCharCount();
  public: void Ctor();
  public: void Ctor(String replacement);
  public: DecoderFallbackBuffer CreateFallbackBuffer();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: String _strDefault;
};
} // namespace DecoderReplacementFallbackNamespace
using DecoderReplacementFallback = DecoderReplacementFallbackNamespace::DecoderReplacementFallback;
} // namespace System::Private::CoreLib::System::Text
