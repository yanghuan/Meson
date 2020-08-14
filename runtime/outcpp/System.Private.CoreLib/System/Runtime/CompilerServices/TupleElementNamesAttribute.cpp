#include "TupleElementNamesAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TupleElementNamesAttributeNamespace {
IList<String> TupleElementNamesAttribute___::get_TransformNames() {
  return _transformNames;
}

void TupleElementNamesAttribute___::ctor(Array<String> transformNames) {
  if (transformNames == nullptr) {
    rt::throw_exception<ArgumentNullException>("transformNames");
  }
  _transformNames = transformNames;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TupleElementNamesAttributeNamespace
