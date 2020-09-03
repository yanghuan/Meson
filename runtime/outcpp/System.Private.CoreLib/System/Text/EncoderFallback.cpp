#include "EncoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/EncoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderFallbackNamespace {
EncoderFallback EncoderFallback___::get_ReplacementFallback() {
  return EncoderReplacementFallback::in::s_default;
}

EncoderFallback EncoderFallback___::get_ExceptionFallback() {
  return EncoderExceptionFallback::in::s_default;
}

void EncoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::EncoderFallbackNamespace
