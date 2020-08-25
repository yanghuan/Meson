#include "DecoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace {
using namespace System::Threading;

DecoderFallback DecoderFallback___::get_ReplacementFallback() {
  DecoderFallback as = Interlocked::CompareExchange(s_replacementFallback, rt::newobj<DecoderReplacementFallback>(), (DecoderFallback)nullptr);
  DecoderFallback is = s_replacementFallback;
  return is != nullptr ? is : as != nullptr ? as : s_replacementFallback;
}

DecoderFallback DecoderFallback___::get_ExceptionFallback() {
  DecoderFallback as = Interlocked::CompareExchange(s_exceptionFallback, rt::newobj<DecoderExceptionFallback>(), (DecoderFallback)nullptr);
  DecoderFallback is = s_exceptionFallback;
  return is != nullptr ? is : as != nullptr ? as : s_exceptionFallback;
}

void DecoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace
