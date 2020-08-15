#include "EncoderFallbackException-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderFallbackExceptionNamespace {
Char EncoderFallbackException___::get_CharUnknown() {
  return _charUnknown;
}

Char EncoderFallbackException___::get_CharUnknownHigh() {
  return _charUnknownHigh;
}

Char EncoderFallbackException___::get_CharUnknownLow() {
  return _charUnknownLow;
}

Int32 EncoderFallbackException___::get_Index() {
  return _index;
}

void EncoderFallbackException___::ctor() {
  Exception::in::set_HResult = -2147024809;
}

void EncoderFallbackException___::ctor(String message) {
  Exception::in::set_HResult = -2147024809;
}

void EncoderFallbackException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2147024809;
}

void EncoderFallbackException___::ctor(String message, Char charUnknown, Int32 index) {
  _charUnknown = charUnknown;
  _index = index;
}

void EncoderFallbackException___::ctor(String message, Char charUnknownHigh, Char charUnknownLow, Int32 index) {
  if (!Char::IsHighSurrogate(charUnknownHigh)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownHigh", SR::Format(SR::get_ArgumentOutOfRange_Range(), 55296, 56319));
  }
  if (!Char::IsLowSurrogate(charUnknownLow)) {
    rt::throw_exception<ArgumentOutOfRangeException>("CharUnknownLow", SR::Format(SR::get_ArgumentOutOfRange_Range(), 56320, 57343));
  }
  _charUnknownHigh = charUnknownHigh;
  _charUnknownLow = charUnknownLow;
  _index = index;
}

void EncoderFallbackException___::ctor(SerializationInfo serializationInfo, StreamingContext streamingContext) {
}

Boolean EncoderFallbackException___::IsUnknownSurrogate() {
  return _charUnknownHigh != 0;
}

} // namespace System::Private::CoreLib::System::Text::EncoderFallbackExceptionNamespace
