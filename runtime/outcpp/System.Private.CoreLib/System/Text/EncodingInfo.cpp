#include "EncodingInfo-dep.h"

#include <System.Private.CoreLib/System/Text/EncodingInfo-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingInfoNamespace {
void EncodingInfo___::ctor(Int32 codePage, String name, String displayName) {
  CodePage = codePage;
  Name = name;
  DisplayName = displayName;
}

Encoding EncodingInfo___::GetEncoding() {
  return Encoding::in::GetEncoding(CodePage);
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
