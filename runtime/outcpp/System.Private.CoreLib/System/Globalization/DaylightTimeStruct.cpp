#include "DaylightTimeStruct-dep.h"

namespace System::Private::CoreLib::System::Globalization::DaylightTimeStructNamespace {
DaylightTimeStruct::DaylightTimeStruct(DateTime start, DateTime end, TimeSpan delta) {
  Start = start;
  End = end;
  Delta = delta;
}

} // namespace System::Private::CoreLib::System::Globalization::DaylightTimeStructNamespace
