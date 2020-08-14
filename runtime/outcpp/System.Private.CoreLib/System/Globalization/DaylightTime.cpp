#include "DaylightTime-dep.h"

namespace System::Private::CoreLib::System::Globalization::DaylightTimeNamespace {
DateTime DaylightTime___::get_Start() {
  return _start;
}

DateTime DaylightTime___::get_End() {
  return _end;
}

TimeSpan DaylightTime___::get_Delta() {
  return _delta;
}

void DaylightTime___::ctor(DateTime start, DateTime end, TimeSpan delta) {
  _start = start;
  _end = end;
  _delta = delta;
}

} // namespace System::Private::CoreLib::System::Globalization::DaylightTimeNamespace
