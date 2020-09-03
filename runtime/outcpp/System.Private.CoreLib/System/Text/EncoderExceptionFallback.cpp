#include "EncoderExceptionFallback-dep.h"

#include <System.Private.CoreLib/System/Text/EncoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderExceptionFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderExceptionFallbackNamespace {
Int32 EncoderExceptionFallback___::get_MaxCharCount() {
  return 0;
}

void EncoderExceptionFallback___::ctor() {
}

EncoderFallbackBuffer EncoderExceptionFallback___::CreateFallbackBuffer() {
  return rt::newobj<EncoderExceptionFallbackBuffer>();
}

Boolean EncoderExceptionFallback___::Equals(Object value) {
  return rt::is<EncoderExceptionFallback>(value);
}

Int32 EncoderExceptionFallback___::GetHashCode() {
  return 654;
}

void EncoderExceptionFallback___::cctor() {
  s_default = rt::newobj<EncoderExceptionFallback>();
}

} // namespace System::Private::CoreLib::System::Text::EncoderExceptionFallbackNamespace
