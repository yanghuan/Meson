#include "InternalDecoderBestFitFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::InternalDecoderBestFitFallbackBufferNamespace {
using namespace System::Threading;

Object InternalDecoderBestFitFallbackBuffer___::get_InternalSyncObject() {
  if (s_InternalSyncObject == nullptr) {
    Object value = rt::newobj<Object>();
    Interlocked::CompareExchange<Object>(s_InternalSyncObject, value, (Object)nullptr);
  }
  return s_InternalSyncObject;
}

Int32 InternalDecoderBestFitFallbackBuffer___::get_Remaining() {
  if (_iCount <= 0) {
    return 0;
  }
  return _iCount;
}

void InternalDecoderBestFitFallbackBuffer___::ctor(InternalDecoderBestFitFallback fallback) {
  _iCount = -1;
  DecoderFallbackBuffer::ctor();
  _oFallback = fallback;
  if (_oFallback->_arrayBestFit != nullptr) {
    return;
  }
  {
    rt::lock(get_InternalSyncObject());
    InternalDecoderBestFitFallback oFallback = _oFallback;
    if (oFallback->_arrayBestFit == nullptr) {
      oFallback->_arrayBestFit = fallback->_encoding->GetBestFitBytesToUnicodeData();
    }
  }
}

Boolean InternalDecoderBestFitFallbackBuffer___::Fallback(Array<Byte> bytesUnknown, Int32 index) {
  _cBestFit = TryBestFit(bytesUnknown);
  if (_cBestFit == 0) {
    _cBestFit = _oFallback->_cReplacement;
  }
  _iCount = (_iSize = 1);
  return true;
}

Char InternalDecoderBestFitFallbackBuffer___::GetNextChar() {
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

Boolean InternalDecoderBestFitFallbackBuffer___::MovePrevious() {
  if (_iCount >= 0) {
    _iCount++;
  }
  if (_iCount >= 0) {
    return _iCount <= _iSize;
  }
  return false;
}

void InternalDecoderBestFitFallbackBuffer___::Reset() {
  _iCount = -1;
  byteStart = nullptr;
}

Int32 InternalDecoderBestFitFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  return 1;
}

Char InternalDecoderBestFitFallbackBuffer___::TryBestFit(Array<Byte> bytesCheck) {
  Int32 num = 0;
  Int32 num2 = _oFallback->_arrayBestFit->get_Length();
  if (num2 == 0) {
    return 0;
  }
  if (bytesCheck->get_Length() == 0 || bytesCheck->get_Length() > 2) {
    return 0;
  }
  Char c = (Char)((bytesCheck->get_Length() != 1) ? ((Int32)(Char)((bytesCheck[0] << 8) + bytesCheck[1])) : ((Int32)bytesCheck[0]));
  if (c < _oFallback->_arrayBestFit[0] || c > _oFallback->_arrayBestFit[num2 - 2]) {
    return 0;
  }
  Int32 num3;
  while ((num3 = num2 - num) > 6) {
    Int32 num4 = (num3 / 2 + num) & 65534;
    Char c2 = _oFallback->_arrayBestFit[num4];
    if (c2 == c) {
      return _oFallback->_arrayBestFit[num4 + 1];
    }
    if (c2 < c) {
      num = num4;
    } else {
      num2 = num4;
    }
  }
  for (Int32 num4 = num; num4 < num2; num4 += 2) {
    if (_oFallback->_arrayBestFit[num4] == c) {
      return _oFallback->_arrayBestFit[num4 + 1];
    }
  }
  return 0;
}

} // namespace System::Private::CoreLib::System::Text::InternalDecoderBestFitFallbackBufferNamespace
