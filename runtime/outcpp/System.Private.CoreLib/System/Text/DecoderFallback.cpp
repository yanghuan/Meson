#include "DecoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace {
DecoderFallback DecoderFallback___::get_ReplacementFallback() {
  return DecoderReplacementFallback::in::s_default;
}

DecoderFallback DecoderFallback___::get_ExceptionFallback() {
  return DecoderExceptionFallback::in::s_default;
}

void DecoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace
