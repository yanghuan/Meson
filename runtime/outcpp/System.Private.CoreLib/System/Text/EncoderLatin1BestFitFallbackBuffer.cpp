#include "EncoderLatin1BestFitFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderLatin1BestFitFallbackBufferNamespace {
Int32 EncoderLatin1BestFitFallbackBuffer___::get_Remaining() {
  if (_iCount <= 0) {
    return 0;
  }
  return _iCount;
}

Boolean EncoderLatin1BestFitFallbackBuffer___::Fallback(Char charUnknown, Int32 index) {
  _iCount = (_iSize = 1);
  _cBestFit = TryBestFit(charUnknown);
  if (_cBestFit == u'\0') {
    _cBestFit = u'?';
  }
  return true;
}

Boolean EncoderLatin1BestFitFallbackBuffer___::Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index) {
  if (!Char::IsHighSurrogate(charUnknownHigh)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownHigh", SR::Format(SR::get_ArgumentOutOfRange_Range(), 55296, 56319));
  }
  if (!Char::IsLowSurrogate(charUnknownLow)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownLow", SR::Format(SR::get_ArgumentOutOfRange_Range(), 56320, 57343));
  }
  _cBestFit = u'?';
  _iCount = (_iSize = 2);
  return true;
}

Char EncoderLatin1BestFitFallbackBuffer___::GetNextChar() {
  _iCount--;
  if (_iCount < 0) {
    return u'\0';
  }
  if (_iCount == Int32::MaxValue) {
    _iCount = -1;
    return u'\0';
  }
  return _cBestFit;
}

Boolean EncoderLatin1BestFitFallbackBuffer___::MovePrevious() {
  if (_iCount >= 0) {
    _iCount++;
  }
  if (_iCount >= 0) {
    return _iCount <= _iSize;
  }
  return false;
}

void EncoderLatin1BestFitFallbackBuffer___::Reset() {
  _iCount = -1;
  charStart = nullptr;
  bFallingBack = false;
}

Char EncoderLatin1BestFitFallbackBuffer___::TryBestFit(Char cUnknown) {
  Int32 num = 0;
  Int32 num2 = s_arrayCharBestFit->get_Length();
  Int32 num3;
  while ((num3 = num2 - num) > 6) {
    Int32 num4 = (num3 / 2 + num) & 65534;
    Char c = s_arrayCharBestFit[num4];
    if (c == cUnknown) {
      return s_arrayCharBestFit[num4 + 1];
    }
    if (c < cUnknown) {
      num = num4;
    } else {
      num2 = num4;
    }
  }
  for (Int32 num4 = num; num4 < num2; num4 += 2) {
    if (s_arrayCharBestFit[num4] == cUnknown) {
      return s_arrayCharBestFit[num4 + 1];
    }
  }
  return u'\0';
}

void EncoderLatin1BestFitFallbackBuffer___::ctor() {
  _iCount = -1;
  EncoderFallbackBuffer::in::ctor();
}

void EncoderLatin1BestFitFallbackBuffer___::cctor() {
  s_arrayCharBestFit = rt::newarr<Array<Char>>(604);
}

} // namespace System::Private::CoreLib::System::Text::EncoderLatin1BestFitFallbackBufferNamespace
