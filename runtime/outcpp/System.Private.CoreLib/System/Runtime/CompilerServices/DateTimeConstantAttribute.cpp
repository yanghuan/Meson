#include "DateTimeConstantAttribute-dep.h"

#include <System.Private.CoreLib/System/DateTime-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::DateTimeConstantAttributeNamespace {
Object DateTimeConstantAttribute___::get_Value() {
  return _date;
}

void DateTimeConstantAttribute___::ctor(Int64 ticks) {
  _date = DateTime(ticks);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::DateTimeConstantAttributeNamespace
