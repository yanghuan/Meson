#include "EncoderReplacementFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderReplacementFallbackBufferNamespace {
Int32 EncoderReplacementFallbackBuffer___::get_Remaining() {
  if (_fallbackCount >= 0) {
    return _fallbackCount;
  }
  return 0;
}

void EncoderReplacementFallbackBuffer___::ctor(EncoderReplacementFallback fallback) {
  _fallbackCount = -1;
  _fallbackIndex = -1;
  EncoderFallbackBuffer::ctor();
  _strDefault = fallback->get_DefaultString() + fallback->get_DefaultString();
}

Boolean EncoderReplacementFallbackBuffer___::Fallback(Char charUnknown, Int32 index) {
  if (_fallbackCount >= 1) {
    if (Char::IsHighSurrogate(charUnknown) && _fallbackCount >= 0 && Char::IsLowSurrogate(_strDefault[_fallbackIndex + 1])) {
      EncoderFallbackBuffer::in::ThrowLastCharRecursive(Char::ConvertToUtf32(charUnknown, _strDefault[_fallbackIndex + 1]));
    }
    EncoderFallbackBuffer::in::ThrowLastCharRecursive(charUnknown);
  }
  _fallbackCount = _strDefault->get_Length() / 2;
  _fallbackIndex = -1;
  return _fallbackCount != 0;
}

Boolean EncoderReplacementFallbackBuffer___::Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index) {
  if (!Char::IsHighSurrogate(charUnknownHigh)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownHigh", SR::Format(SR::get_ArgumentOutOfRange_Range(), 55296, 56319));
  }
  if (!Char::IsLowSurrogate(charUnknownLow)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownLow", SR::Format(SR::get_ArgumentOutOfRange_Range(), 56320, 57343));
  }
  if (_fallbackCount >= 1) {
    EncoderFallbackBuffer::in::ThrowLastCharRecursive(Char::ConvertToUtf32(charUnknownHigh, charUnknownLow));
  }
  _fallbackCount = _strDefault->get_Length();
  _fallbackIndex = -1;
  return _fallbackCount != 0;
}

Char EncoderReplacementFallbackBuffer___::GetNextChar() {
  _fallbackCount--;
  _fallbackIndex++;
  if (_fallbackCount < 0) {
    return 0;
  }
  if (_fallbackCount == Int32::MaxValue) {
    _fallbackCount = -1;
    return 0;
  }
  return _strDefault[_fallbackIndex];
}

Boolean EncoderReplacementFallbackBuffer___::MovePrevious() {
  if (_fallbackCount >= -1 && _fallbackIndex >= 0) {
    _fallbackIndex--;
    _fallbackCount++;
    return true;
  }
  return false;
}

void EncoderReplacementFallbackBuffer___::Reset() {
  _fallbackCount = -1;
  _fallbackIndex = 0;
  charStart = nullptr;
  bFallingBack = false;
}

} // namespace System::Private::CoreLib::System::Text::EncoderReplacementFallbackBufferNamespace
