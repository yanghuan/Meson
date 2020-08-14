#include "EncoderReplacementFallback-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallbackBuffer-dep.h>

namespace System::Private::CoreLib::System::Text::EncoderReplacementFallbackNamespace {
String EncoderReplacementFallback___::get_DefaultString() {
  return _strDefault;
}

Int32 EncoderReplacementFallback___::get_MaxCharCount() {
  return _strDefault->get_Length();
}

void EncoderReplacementFallback___::ctor() {
}

void EncoderReplacementFallback___::ctor(String replacement) {
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
        continue;
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

EncoderFallbackBuffer EncoderReplacementFallback___::CreateFallbackBuffer() {
  return rt::newobj<EncoderReplacementFallbackBuffer>((EncoderReplacementFallback)this);
}

Boolean EncoderReplacementFallback___::Equals(Object value) {
  EncoderReplacementFallback encoderReplacementFallback = rt::as<EncoderReplacementFallback>(value);
  if (encoderReplacementFallback != nullptr) {
    return _strDefault == encoderReplacementFallback->_strDefault;
  }
  return false;
}

Int32 EncoderReplacementFallback___::GetHashCode() {
  return _strDefault->GetHashCode();
}

} // namespace System::Private::CoreLib::System::Text::EncoderReplacementFallbackNamespace
