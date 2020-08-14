#include "StackCrawlMarkHandle-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::StackCrawlMarkHandleNamespace {
using namespace Internal::Runtime::CompilerServices;

StackCrawlMarkHandle::StackCrawlMarkHandle(StackCrawlMark& stackMark) {
  _ptr = Unsafe::AsPointer(stackMark);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::StackCrawlMarkHandleNamespace
