#include "DateMarshaler-dep.h"

namespace System::Private::CoreLib::System::StubHelpers::DateMarshalerNamespace {
Double DateMarshaler::ConvertToNative(DateTime managedDate) {
  return managedDate.ToOADate();
}

Int64 DateMarshaler::ConvertToManaged(Double nativeDate) {
  return DateTime::DoubleDateToTicks(nativeDate);
}

} // namespace System::Private::CoreLib::System::StubHelpers::DateMarshalerNamespace
