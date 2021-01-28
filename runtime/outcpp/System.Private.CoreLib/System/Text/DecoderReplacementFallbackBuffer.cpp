#include "DecoderReplacementFallbackBuffer-dep.h"

namespace System::Private::CoreLib::System::Text::DecoderReplacementFallbackBufferNamespace {
Int32 DecoderReplacementFallbackBuffer___::get_Remaining() {
  if (_fallbackCount >= 0) {
    return _fallbackCount;
  }
  return 0;
}

void DecoderReplacementFallbackBuffer___::ctor(DecoderReplacementFallback fallback) {
  _fallbackCount = -1;
  _fallbackIndex = -1;
  DecoderFallbackBuffer::in::ctor();
  _strDefault = fallback->get_DefaultString();
}

Boolean DecoderReplacementFallbackBuffer___::Fallback(Array<Byte> bytesUnknown, Int32 index) {
  if (_fallbackCount >= 1) {
    ThrowLastBytesRecursive(bytesUnknown);
  }
  if (_strDefault->get_Length() == 0) {
    return false;
  }
  _fallbackCount = _strDefault->get_Length();
  _fallbackIndex = -1;
  return true;
}

Char DecoderReplacementFallbackBuffer___::GetNextChar() {
  _fallbackCount--;
  _fallbackIndex++;
  if (_fallbackCount < 0) {
    return u'\0';
  }
  if (_fallbackCount == Int32::MaxValue()) {
    _fallbackCount = -1;
    return u'\0';
  }
  return _strDefault[_fallbackIndex];
}

Boolean DecoderReplacementFallbackBuffer___::MovePrevious() {
  if (_fallbackCount >= -1 && _fallbackIndex >= 0) {
    _fallbackIndex--;
    _fallbackCount++;
    return true;
  }
  return false;
}

void DecoderReplacementFallbackBuffer___::Reset() {
  _fallbackCount = -1;
  _fallbackIndex = -1;
  byteStart = nullptr;
}

Int32 DecoderReplacementFallbackBuffer___::InternalFallback(Array<Byte> bytes, Byte* pBytes) {
  return _strDefault->get_Length();
}

} // namespace System::Private::CoreLib::System::Text::DecoderReplacementFallbackBufferNamespace
