#include "HebrewNumberParsingContext-dep.h"

#include <System.Private.CoreLib/System/Globalization/HebrewNumber-dep.h>

namespace System::Private::CoreLib::System::Globalization::HebrewNumberParsingContextNamespace {
HebrewNumberParsingContext::HebrewNumberParsingContext(Int32 result) {
  state = HebrewNumber::HS::Start;
  this->result = result;
}

} // namespace System::Private::CoreLib::System::Globalization::HebrewNumberParsingContextNamespace
