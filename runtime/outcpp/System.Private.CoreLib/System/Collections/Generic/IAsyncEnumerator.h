#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IAsyncEnumeratorNamespace {
using namespace System::Threading::Tasks;
CLASS(IAsyncEnumerator, T) : public object {
  public: using interface = rt::TypeList<IAsyncDisposable>;
  public: T get_Current();
  public: ValueTask<> DisposeAsync();
  public: ValueTask<Boolean> MoveNextAsync();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncEnumeratorNamespace
template <class T>
using IAsyncEnumerator = IAsyncEnumeratorNamespace::IAsyncEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
