#include "DecoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace {
using namespace System::Threading;

DecoderFallback DecoderFallback___::get_ReplacementFallback() {
  auto& default = Interlocked::CompareExchange(s_replacementFallback, rt::newobj<DecoderReplacementFallback>(), nullptr);
  auto& extern = s_replacementFallback;
  return extern != nullptr ? extern : default != nullptr ? default : s_replacementFallback;
}

DecoderFallback DecoderFallback___::get_ExceptionFallback() {
  auto& default = Interlocked::CompareExchange(s_exceptionFallback, rt::newobj<DecoderExceptionFallback>(), nullptr);
  auto& extern = s_exceptionFallback;
  return extern != nullptr ? extern : default != nullptr ? default : s_exceptionFallback;
}

void DecoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace
