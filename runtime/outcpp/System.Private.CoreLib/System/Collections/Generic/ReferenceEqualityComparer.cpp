#include "ReferenceEqualityComparer-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/ReferenceEqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>

namespace System::Private::CoreLib::System::Collections::Generic::ReferenceEqualityComparerNamespace {
using namespace System::Runtime::CompilerServices;

void ReferenceEqualityComparer___::ctor() {
}

Boolean ReferenceEqualityComparer___::Equals(Object x, Object y) {
  return x == y;
}

Int32 ReferenceEqualityComparer___::GetHashCode(Object obj) {
  return RuntimeHelpers::GetHashCode(obj);
}

void ReferenceEqualityComparer___::cctor() {
  Instance = rt::newobj<ReferenceEqualityComparer>();
}

} // namespace System::Private::CoreLib::System::Collections::Generic::ReferenceEqualityComparerNamespace
