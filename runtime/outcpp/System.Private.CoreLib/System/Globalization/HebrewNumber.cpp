#include "HebrewNumber-dep.h"

namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace {
void HebrewNumber::Append(StringBuilder outputBuffer, Int32 Number) {
};

HebrewNumberParsingState HebrewNumber::ParseByChar(Char ch, HebrewNumberParsingContext& context) {
  return HebrewNumberParsingState::ContinueParsing;
};

Boolean HebrewNumber::IsDigit(Char ch) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace
