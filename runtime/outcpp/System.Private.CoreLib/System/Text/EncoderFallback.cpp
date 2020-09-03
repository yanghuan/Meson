#include "EncoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/EncoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderFallbackNamespace {
using namespace System::Threading;

EncoderFallback EncoderFallback___::get_ReplacementFallback() {
  if (s_replacementFallback == nullptr) {
    Interlocked::CompareExchange(s_replacementFallback, rt::newobj<EncoderReplacementFallback>(), (EncoderFallback)nullptr);
  }
  return s_replacementFallback;
}

EncoderFallback EncoderFallback___::get_ExceptionFallback() {
  if (s_exceptionFallback == nullptr) {
    Interlocked::CompareExchange(s_exceptionFallback, rt::newobj<EncoderExceptionFallback>(), (EncoderFallback)nullptr);
  }
  return s_exceptionFallback;
}

void EncoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::EncoderFallbackNamespace
