#include "AsyncIteratorMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncIteratorMethodBuilder-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncIteratorMethodBuilderNamespace {
Object AsyncIteratorMethodBuilder::get_ObjectIdForDebugger() {
  return _methodBuilder.get_ObjectIdForDebugger();
}

AsyncIteratorMethodBuilder AsyncIteratorMethodBuilder::Create() {
  return AsyncIteratorMethodBuilder();
}

void AsyncIteratorMethodBuilder::Complete() {
  _methodBuilder.SetResult();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncIteratorMethodBuilderNamespace
