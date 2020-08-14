#include "ObjectHandleOnStack-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ObjectHandleOnStackNamespace {
ObjectHandleOnStack::ObjectHandleOnStack(void* pObject) {
  _ptr = pObject;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ObjectHandleOnStackNamespace
