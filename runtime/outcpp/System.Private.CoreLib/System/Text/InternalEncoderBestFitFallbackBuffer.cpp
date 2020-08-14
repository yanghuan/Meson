#include "InternalEncoderBestFitFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::InternalEncoderBestFitFallbackBufferNamespace {
using namespace System::Threading;

Object InternalEncoderBestFitFallbackBuffer___::get_InternalSyncObject() {
  if (s_InternalSyncObject == nullptr) {
    Object value = rt::newobj<Object>();
    Interlocked::CompareExchange<Object>(s_InternalSyncObject, value, (Object)nullptr);
  }
  return s_InternalSyncObject;
}

Int32 InternalEncoderBestFitFallbackBuffer___::get_Remaining() {
  if (_iCount <= 0) {
    return 0;
  }
  return _iCount;
}

void InternalEncoderBestFitFallbackBuffer___::ctor(InternalEncoderBestFitFallback fallback) {
  _iCount = -1;
}

Boolean InternalEncoderBestFitFallbackBuffer___::Fallback(Char charUnknown, Int32 index) {
  _iCount = (_iSize = 1);
  _cBestFit = TryBestFit(charUnknown);
  if (_cBestFit == 0) {
    _cBestFit = 63;
  }
  return true;
}

Boolean InternalEncoderBestFitFallbackBuffer___::Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index) {
  if (!Char::IsHighSurrogate(charUnknownHigh)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownHigh", SR::Format(SR::get_ArgumentOutOfRange_Range(), 55296, 56319));
  }
  if (!Char::IsLowSurrogate(charUnknownLow)) {
    rt::throw_exception<ArgumentOutOfRangeException>("charUnknownLow", SR::Format(SR::get_ArgumentOutOfRange_Range(), 56320, 57343));
  }
  _cBestFit = 63;
  _iCount = (_iSize = 2);
  return true;
}

Char InternalEncoderBestFitFallbackBuffer___::GetNextChar() {
  _iCount--;
  if (_iCount < 0) {
    return 0;
  }
  if (_iCount == Int32::MaxValue) {
    _iCount = -1;
    return 0;
  }
  return _cBestFit;
}

Boolean InternalEncoderBestFitFallbackBuffer___::MovePrevious() {
  if (_iCount >= 0) {
    _iCount++;
  }
  if (_iCount >= 0) {
    return _iCount <= _iSize;
  }
  return false;
}

void InternalEncoderBestFitFallbackBuffer___::Reset() {
  _iCount = -1;
  charStart = nullptr;
  bFallingBack = false;
}

Char InternalEncoderBestFitFallbackBuffer___::TryBestFit(Char cUnknown) {
  Int32 num = 0;
  Int32 num2 = _oFallback->_arrayBestFit->get_Length();
  Int32 num3;
  while ((num3 = num2 - num) > 6) {
    Int32 num4 = (num3 / 2 + num) & 65534;
    Char c = _oFallback->_arrayBestFit[num4];
    if (c == cUnknown) {
      return _oFallback->_arrayBestFit[num4 + 1];
    }
    if (c < cUnknown) {
      num = num4;
    } else {
      num2 = num4;
    }
  }
  for (Int32 num4 = num; num4 < num2; num4 += 2) {
    if (_oFallback->_arrayBestFit[num4] == cUnknown) {
      return _oFallback->_arrayBestFit[num4 + 1];
    }
  }
  return 0;
}

} // namespace System::Private::CoreLib::System::Text::InternalEncoderBestFitFallbackBufferNamespace
