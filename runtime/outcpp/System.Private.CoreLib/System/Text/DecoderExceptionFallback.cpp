#include "DecoderExceptionFallback-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderExceptionFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderExceptionFallbackNamespace {
Int32 DecoderExceptionFallback___::get_MaxCharCount() {
  return 0;
}

DecoderFallbackBuffer DecoderExceptionFallback___::CreateFallbackBuffer() {
  return rt::newobj<DecoderExceptionFallbackBuffer>();
}

Boolean DecoderExceptionFallback___::Equals(Object value) {
  return rt::is<DecoderExceptionFallback>(value);
}

Int32 DecoderExceptionFallback___::GetHashCode() {
  return 879;
}

void DecoderExceptionFallback___::ctor() {
}

void DecoderExceptionFallback___::cctor() {
  s_default = rt::newobj<DecoderExceptionFallback>();
}

} // namespace System::Private::CoreLib::System::Text::DecoderExceptionFallbackNamespace
