#include "EncoderExceptionFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackException-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderExceptionFallbackBufferNamespace {
Int32 EncoderExceptionFallbackBuffer___::get_Remaining() {
  return 0;
}

void EncoderExceptionFallbackBuffer___::ctor() {
}

Boolean EncoderExceptionFallbackBuffer___::Fallback(Char charUnknown, Int32 index) {
  rt::throw_exception<EncoderFallbackException>(SR::Format(SR::get_Argument_InvalidCodePageConversionIndex(), (Int32)charUnknown, index), charUnknown, index);
}

Boolean EncoderExceptionFallbackBuffer___::Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index) {
  if (!Char::IsHighSurrogate(charUnknownHigh)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownHigh", SR::Format(SR::get_ArgumentOutOfRange_Range(), 55296, 56319));
  }
  if (!Char::IsLowSurrogate(charUnknownLow)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownLow", SR::Format(SR::get_ArgumentOutOfRange_Range(), 56320, 57343));
  }
  Int32 num = Char::ConvertToUtf32(charUnknownHigh, charUnknownLow);
  rt::throw_exception<EncoderFallbackException>(SR::Format(SR::get_Argument_InvalidCodePageConversionIndex(), num, index), charUnknownHigh, charUnknownLow, index);
}

Char EncoderExceptionFallbackBuffer___::GetNextChar() {
  return '\0';
}

Boolean EncoderExceptionFallbackBuffer___::MovePrevious() {
  return false;
}

} // namespace System::Private::CoreLib::System::Text::EncoderExceptionFallbackBufferNamespace
