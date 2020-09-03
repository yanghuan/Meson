#include "InternalEncoderBestFitFallback-dep.h"

#include <System.Private.CoreLib/System/Text/InternalEncoderBestFitFallback-dep.h>
#include <System.Private.CoreLib/System/Text/InternalEncoderBestFitFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::InternalEncoderBestFitFallbackNamespace {
Int32 InternalEncoderBestFitFallback___::get_MaxCharCount() {
  return 1;
}

void InternalEncoderBestFitFallback___::ctor(Encoding encoding) {
  _encoding = encoding;
}

EncoderFallbackBuffer InternalEncoderBestFitFallback___::CreateFallbackBuffer() {
  return rt::newobj<InternalEncoderBestFitFallbackBuffer>((InternalEncoderBestFitFallback)this);
}

Boolean InternalEncoderBestFitFallback___::Equals(Object value) {
  InternalEncoderBestFitFallback internalEncoderBestFitFallback = rt::as<InternalEncoderBestFitFallback>(value);
  if (internalEncoderBestFitFallback != nullptr) {
    return _encoding->get_CodePage() == internalEncoderBestFitFallback->_encoding->get_CodePage();
  }
  return false;
}

Int32 InternalEncoderBestFitFallback___::GetHashCode() {
  return _encoding->get_CodePage();
}

} // namespace System::Private::CoreLib::System::Text::InternalEncoderBestFitFallbackNamespace
