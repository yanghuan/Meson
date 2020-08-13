#include "ParsingInfo-dep.h"

#include <System.Private.CoreLib/System/DateTimeParse-dep.h>

namespace System::Private::CoreLib::System::ParsingInfoNamespace {
void ParsingInfo::Init() {
  dayOfWeek = -1;
  timeMark = DateTimeParse::TM::NotSet;
}

} // namespace System::Private::CoreLib::System::ParsingInfoNamespace
