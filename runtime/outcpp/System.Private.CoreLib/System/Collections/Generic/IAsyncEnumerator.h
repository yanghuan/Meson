#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IAsyncEnumeratorNamespace {
using namespace Threading::Tasks;
CLASS(IAsyncEnumerator, T) : public Object::in {
  public: using interface = rt::TypeList<IAsyncDisposable>;
  public: T get_Current();
  public: ValueTask<Boolean> MoveNextAsync();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncEnumeratorNamespace
template <class T>
using IAsyncEnumerator = IAsyncEnumeratorNamespace::IAsyncEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
