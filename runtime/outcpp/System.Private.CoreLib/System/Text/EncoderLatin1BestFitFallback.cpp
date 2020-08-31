#include "EncoderLatin1BestFitFallback-dep.h"

#include <System.Private.CoreLib/System/Text/EncoderLatin1BestFitFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderLatin1BestFitFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderLatin1BestFitFallbackNamespace {
Int32 EncoderLatin1BestFitFallback___::get_MaxCharCount() {
  return 1;
}

void EncoderLatin1BestFitFallback___::ctor() {
}

EncoderFallbackBuffer EncoderLatin1BestFitFallback___::CreateFallbackBuffer() {
  return rt::newobj<EncoderLatin1BestFitFallbackBuffer>();
}

void EncoderLatin1BestFitFallback___::cctor() {
  SingletonInstance = rt::newobj<EncoderLatin1BestFitFallback>();
}

} // namespace System::Private::CoreLib::System::Text::EncoderLatin1BestFitFallbackNamespace
