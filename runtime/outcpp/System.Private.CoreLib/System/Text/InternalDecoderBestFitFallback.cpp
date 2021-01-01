#include "InternalDecoderBestFitFallback-dep.h"

#include <System.Private.CoreLib/System/Text/InternalDecoderBestFitFallback-dep.h>
#include <System.Private.CoreLib/System/Text/InternalDecoderBestFitFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::InternalDecoderBestFitFallbackNamespace {
Int32 InternalDecoderBestFitFallback___::get_MaxCharCount() {
  return 1;
}

void InternalDecoderBestFitFallback___::ctor(Encoding encoding) {
  _cReplacement = '?';
  DecoderFallback::in::ctor();
  _encoding = encoding;
}

DecoderFallbackBuffer InternalDecoderBestFitFallback___::CreateFallbackBuffer() {
  return rt::newobj<InternalDecoderBestFitFallbackBuffer>((InternalDecoderBestFitFallback)this);
}

Boolean InternalDecoderBestFitFallback___::Equals(Object value) {
  InternalDecoderBestFitFallback internalDecoderBestFitFallback = rt::as<InternalDecoderBestFitFallback>(value);
  if (internalDecoderBestFitFallback != nullptr) {
    return _encoding->get_CodePage() == internalDecoderBestFitFallback->_encoding->get_CodePage();
  }
  return false;
}

Int32 InternalDecoderBestFitFallback___::GetHashCode() {
  return _encoding->get_CodePage();
}

} // namespace System::Private::CoreLib::System::Text::InternalDecoderBestFitFallbackNamespace
