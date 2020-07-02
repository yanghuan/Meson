#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IAsyncEnumeratorNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(IAsyncEnumerator, T) {
  public: T get_Current();
  public: ValueTask<Boolean> MoveNextAsync();
};
} // namespace IAsyncEnumeratorNamespace
template <class T>
using IAsyncEnumerator = IAsyncEnumeratorNamespace::IAsyncEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
