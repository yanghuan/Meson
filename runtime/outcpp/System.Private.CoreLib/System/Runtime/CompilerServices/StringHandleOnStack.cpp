#include "StringHandleOnStack-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::StringHandleOnStackNamespace {
using namespace Internal::Runtime::CompilerServices;

StringHandleOnStack::StringHandleOnStack(String& s) {
  _ptr = Unsafe::AsPointer(s);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::StringHandleOnStackNamespace
