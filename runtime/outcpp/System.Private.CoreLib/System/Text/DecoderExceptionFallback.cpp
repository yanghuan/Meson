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

} // namespace System::Private::CoreLib::System::Text::DecoderExceptionFallbackNamespace
