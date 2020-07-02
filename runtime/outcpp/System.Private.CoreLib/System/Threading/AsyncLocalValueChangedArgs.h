#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
namespace AsyncLocalValueChangedArgsNamespace {
template <class T>
struct AsyncLocalValueChangedArgs {
};
} // namespace AsyncLocalValueChangedArgsNamespace
template <class T>
using AsyncLocalValueChangedArgs = AsyncLocalValueChangedArgsNamespace::AsyncLocalValueChangedArgs<T>;
} // namespace System::Private::CoreLib::System::Threading
