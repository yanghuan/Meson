#include "EncodingProvider-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Text/EncodingProvider-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingProviderNamespace {
void EncodingProvider___::ctor() {
}

Encoding EncodingProvider___::GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding encoding = GetEncoding(name);
  if (encoding != nullptr) {
    encoding = (Encoding)encoding->Clone();
    encoding->set_EncoderFallback = encoderFallback;
    encoding->set_DecoderFallback = decoderFallback;
  }
  return encoding;
}

Encoding EncodingProvider___::GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding encoding = GetEncoding(codepage);
  if (encoding != nullptr) {
    encoding = (Encoding)encoding->Clone();
    encoding->set_EncoderFallback = encoderFallback;
    encoding->set_DecoderFallback = decoderFallback;
  }
  return encoding;
}

void EncodingProvider___::AddProvider(EncodingProvider provider) {
  if (provider == nullptr) {
    rt::throw_exception<ArgumentNullException>("provider");
  }
}

Encoding EncodingProvider___::GetEncodingFromProvider(Int32 codepage) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
}

Encoding EncodingProvider___::GetEncodingFromProvider(String encodingName) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
}

Encoding EncodingProvider___::GetEncodingFromProvider(Int32 codepage, EncoderFallback enc, DecoderFallback dec) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
}

Encoding EncodingProvider___::GetEncodingFromProvider(String encodingName, EncoderFallback enc, DecoderFallback dec) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
}

void EncodingProvider___::cctor() {
  s_InternalSyncObject = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Text::EncodingProviderNamespace
