#include "IInternalStringEqualityComparer-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IInternalStringEqualityComparer.h>

namespace System::Private::CoreLib::System::Collections::Generic::IInternalStringEqualityComparerNamespace {
IEqualityComparer<String> IInternalStringEqualityComparer___::GetUnderlyingEqualityComparer(IEqualityComparer<String> outerComparer) {
  if (outerComparer == nullptr) {
    return EqualityComparer<String>::in::get_Default();
  }
  IInternalStringEqualityComparer internalStringEqualityComparer = rt::as<IInternalStringEqualityComparer>(outerComparer);
  if (internalStringEqualityComparer != nullptr) {
    return internalStringEqualityComparer->GetUnderlyingEqualityComparer();
  }
  return outerComparer;
}

} // namespace System::Private::CoreLib::System::Collections::Generic::IInternalStringEqualityComparerNamespace
