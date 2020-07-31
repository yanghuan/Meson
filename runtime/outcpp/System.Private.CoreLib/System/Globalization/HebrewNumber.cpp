#include "HebrewNumber-dep.h"

namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace {
HebrewNumber::HebrewValue::HebrewValue(HebrewToken token, Int16 value) {
}

void HebrewNumber::Append(StringBuilder outputBuffer, Int32 Number) {
}

HebrewNumberParsingState HebrewNumber::ParseByChar(Char ch, HebrewNumberParsingContext& context) {
  return HebrewNumberParsingState::ContinueParsing;
}

Boolean HebrewNumber::IsDigit(Char ch) {
  return Boolean();
}

void HebrewNumber::SCtor() {
}

} // namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace
