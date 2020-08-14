#include "DecoderReplacementFallback-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderReplacementFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderReplacementFallbackNamespace {
String DecoderReplacementFallback___::get_DefaultString() {
  return _strDefault;
}

Int32 DecoderReplacementFallback___::get_MaxCharCount() {
  return _strDefault->get_Length();
}

void DecoderReplacementFallback___::ctor() {
}

void DecoderReplacementFallback___::ctor(String replacement) {
  if (replacement == nullptr) {
    rt::throw_exception<ArgumentNullException>("replacement");
  }
  Boolean flag = false;
  for (Int32 i = 0; i < replacement->get_Length(); i++) {
    if (Char::IsSurrogate(replacement, i)) {
      if (Char::IsHighSurrogate(replacement, i)) {
        if (flag) {
          break;
        }
        flag = true;
      }
      if (!flag) {
        flag = true;
        break;
      }
      flag = false;
    } else if (flag) {
      break;
    }

  }
  if (flag) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidCharSequenceNoIndex(), "replacement"));
  }
  _strDefault = replacement;
}

DecoderFallbackBuffer DecoderReplacementFallback___::CreateFallbackBuffer() {
  return rt::newobj<DecoderReplacementFallbackBuffer>((DecoderReplacementFallback)this);
}

Boolean DecoderReplacementFallback___::Equals(Object value) {
  DecoderReplacementFallback decoderReplacementFallback = rt::as<DecoderReplacementFallback>(value);
  if (decoderReplacementFallback != nullptr) {
    return _strDefault == decoderReplacementFallback->_strDefault;
  }
  return false;
}

Int32 DecoderReplacementFallback___::GetHashCode() {
  return _strDefault->GetHashCode();
}

} // namespace System::Private::CoreLib::System::Text::DecoderReplacementFallbackNamespace
