#include "EncodingInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Text/EncodingInfo-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingInfoNamespace {
void EncodingInfo___::ctor(EncodingProvider provider, Int32 codePage, String name, String displayName) {
  if (name == nullptr || displayName == nullptr || provider == nullptr) {
    rt::throw_exception<ArgumentNullException>((name == nullptr) ? "name" : ((displayName == nullptr) ? "displayName" : "provider"));
  }
  Provider = provider;
}

void EncodingInfo___::ctor(Int32 codePage, String name, String displayName) {
  CodePage = codePage;
  Name = name;
  DisplayName = displayName;
}

Encoding EncodingInfo___::GetEncoding() {
  EncodingProvider provider = Provider;
  Encoding as = ((provider != nullptr) ? provider->GetEncoding(CodePage) : nullptr);
  return as != nullptr ? as : Encoding::in::GetEncoding(CodePage);
}

Boolean EncodingInfo___::Equals(Object value) {
  EncodingInfo encodingInfo = rt::as<EncodingInfo>(value);
  if (encodingInfo != nullptr) {
    return CodePage == encodingInfo->get_CodePage();
  }
  return false;
}

Int32 EncodingInfo___::GetHashCode() {
  return CodePage;
}

} // namespace System::Private::CoreLib::System::Text::EncodingInfoNamespace
