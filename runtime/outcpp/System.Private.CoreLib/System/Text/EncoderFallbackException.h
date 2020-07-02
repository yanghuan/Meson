#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace EncoderFallbackExceptionNamespace {
CLASS(EncoderFallbackException) {
  public: Char get_CharUnknown();
  public: Char get_CharUnknownHigh();
  public: Char get_CharUnknownLow();
  public: Int32 get_Index();
  public: Boolean IsUnknownSurrogate();
  private: Char _charUnknown;
  private: Char _charUnknownHigh;
  private: Char _charUnknownLow;
  private: Int32 _index;
};
} // namespace EncoderFallbackExceptionNamespace
using EncoderFallbackException = EncoderFallbackExceptionNamespace::EncoderFallbackException;
} // namespace System::Private::CoreLib::System::Text
