#include "DateTimeRawInfo-dep.h"

#include <System.Private.CoreLib/System/DateTimeParse-dep.h>

namespace System::Private::CoreLib::System::DateTimeRawInfoNamespace {
void DateTimeRawInfo::Init(Int32* numberBuffer) {
  month = -1;
  year = -1;
  dayOfWeek = -1;
  era = -1;
  timeMark = DateTimeParse::TM::NotSet;
  fraction = -1;
  num = numberBuffer;
}

void DateTimeRawInfo::AddNumber(Int32 value) {
  num[numCount++] = value;
}

Int32 DateTimeRawInfo::GetNumber(Int32 index) {
  return num[index];
}

} // namespace System::Private::CoreLib::System::DateTimeRawInfoNamespace
