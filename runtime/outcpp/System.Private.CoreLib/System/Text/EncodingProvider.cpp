#include "EncodingProvider-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Text/EncodingProvider-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingProviderNamespace {
void EncodingProvider___::ctor() {
}

Encoding EncodingProvider___::GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding encoding = GetEncoding(name);
  if (encoding != nullptr) {
    encoding = (Encoding)encoding->Clone();
    encoding->set_EncoderFallback(encoderFallback);
    encoding->set_DecoderFallback(decoderFallback);
  }
  return encoding;
}

Encoding EncodingProvider___::GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback) {
  Encoding encoding = GetEncoding(codepage);
  if (encoding != nullptr) {
    encoding = (Encoding)encoding->Clone();
    encoding->set_EncoderFallback(encoderFallback);
    encoding->set_DecoderFallback(decoderFallback);
  }
  return encoding;
}

IEnumerable<EncodingInfo> EncodingProvider___::GetEncodings() {
  return Array<>::in::Empty<EncodingInfo>();
}

void EncodingProvider___::AddProvider(EncodingProvider provider) {
  if (provider == nullptr) {
    rt::throw_exception<ArgumentNullException>("provider");
  }
  {
    rt::lock(s_InternalSyncObject);
    if (s_providers == nullptr) {
      s_providers = rt::newarr<Array<EncodingProvider>>(1);
    } else if (Array<>::in::IndexOf(s_providers, provider) < 0) {
      Array<EncodingProvider> array = rt::newarr<Array<EncodingProvider>>(s_providers->get_Length() + 1);
      Array<>::in::Copy(s_providers, array, s_providers->get_Length());
    }

  }
}

Encoding EncodingProvider___::GetEncodingFromProvider(Int32 codepage) {
  Array<EncodingProvider> array = s_providers;
  if (array == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array2 = array;
  for (EncodingProvider& encodingProvider : rt::each(array2)) {
    Encoding encoding = encodingProvider->GetEncoding(codepage);
    if (encoding != nullptr) {
      return encoding;
    }
  }
  return nullptr;
}

Dictionary<Int32, EncodingInfo> EncodingProvider___::GetEncodingListFromProviders() {
  Array<EncodingProvider> array = s_providers;
  if (array == nullptr) {
    return nullptr;
  }
  Dictionary<Int32, EncodingInfo> dictionary = rt::newobj<Dictionary<Int32, EncodingInfo>>();
  Array<EncodingProvider> array2 = array;
  for (EncodingProvider& encodingProvider : rt::each(array2)) {
    IEnumerable<EncodingInfo> encodings = encodingProvider->GetEncodings();
    if (encodings == nullptr) {
      continue;
    }
    for (EncodingInfo& item : rt::each(encodings)) {
      dictionary->TryAdd(item->get_CodePage(), item);
    }
  }
  return dictionary;
}

Encoding EncodingProvider___::GetEncodingFromProvider(String encodingName) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
  for (EncodingProvider& encodingProvider : rt::each(array2)) {
    Encoding encoding = encodingProvider->GetEncoding(encodingName);
    if (encoding != nullptr) {
      return encoding;
    }
  }
  return nullptr;
}

Encoding EncodingProvider___::GetEncodingFromProvider(Int32 codepage, EncoderFallback enc, DecoderFallback dec) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
  for (EncodingProvider& encodingProvider : rt::each(array2)) {
    Encoding encoding = encodingProvider->GetEncoding(codepage, enc, dec);
    if (encoding != nullptr) {
      return encoding;
    }
  }
  return nullptr;
}

Encoding EncodingProvider___::GetEncodingFromProvider(String encodingName, EncoderFallback enc, DecoderFallback dec) {
  if (s_providers == nullptr) {
    return nullptr;
  }
  Array<EncodingProvider> array = s_providers;
  Array<EncodingProvider> array2 = array;
  for (EncodingProvider& encodingProvider : rt::each(array2)) {
    Encoding encoding = encodingProvider->GetEncoding(encodingName, enc, dec);
    if (encoding != nullptr) {
      return encoding;
    }
  }
  return nullptr;
}

void EncodingProvider___::cctor() {
  s_InternalSyncObject = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Text::EncodingProviderNamespace
