#include "DecoderExceptionFallbackBuffer-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallbackException-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Text::DecoderExceptionFallbackBufferNamespace {
using namespace System::Globalization;

Int32 DecoderExceptionFallbackBuffer___::get_Remaining() {
  return 0;
}

Boolean DecoderExceptionFallbackBuffer___::Fallback(Array<Byte> bytesUnknown, Int32 index) {
  Throw(bytesUnknown, index);
  return true;
}

Char DecoderExceptionFallbackBuffer___::GetNextChar() {
  return 0;
}

Boolean DecoderExceptionFallbackBuffer___::MovePrevious() {
  return false;
}

void DecoderExceptionFallbackBuffer___::Throw(Array<Byte> bytesUnknown, Int32 index) {
  if (bytesUnknown == nullptr) {
    bytesUnknown = Array<>::in::Empty<Byte>();
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(bytesUnknown->get_Length() * 4);
  for (Int32 i = 0; i < bytesUnknown->get_Length() && i < 20; i++) {
    stringBuilder->Append(91);
    stringBuilder->Append(bytesUnknown[i].ToString("X2", CultureInfo::in::get_InvariantCulture()));
    stringBuilder->Append(93);
  }
  if (bytesUnknown->get_Length() > 20) {
    stringBuilder->Append(" ...");
  }
  rt::throw_exception<DecoderFallbackException>(SR::Format(SR::get_Argument_InvalidCodePageBytesIndex(), stringBuilder, index), bytesUnknown, index);
}

void DecoderExceptionFallbackBuffer___::ctor() {
}

} // namespace System::Private::CoreLib::System::Text::DecoderExceptionFallbackBufferNamespace
