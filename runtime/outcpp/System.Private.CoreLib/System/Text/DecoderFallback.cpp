#include "DecoderFallback-dep.h"

#include <System.Private.CoreLib/System/Text/DecoderExceptionFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace {
using namespace System::Threading;

DecoderFallback DecoderFallback___::get_ReplacementFallback() {
  auto default = Interlocked::CompareExchange(s_replacementFallback, rt::newobj<DecoderReplacementFallback>(), nullptr);
  if (default != nullptr) default = s_replacementFallback;

  auto extern = s_replacementFallback;
  if (extern != nullptr) extern = default;

  return extern;
}

DecoderFallback DecoderFallback___::get_ExceptionFallback() {
  auto default = Interlocked::CompareExchange(s_exceptionFallback, rt::newobj<DecoderExceptionFallback>(), nullptr);
  if (default != nullptr) default = s_exceptionFallback;

  auto extern = s_exceptionFallback;
  if (extern != nullptr) extern = default;

  return extern;
}

void DecoderFallback___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderFallbackNamespace
