#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace Indexer_Get_DelegateNamespace {
CLASS(Indexer_Get_Delegate, T) {
  public: T Invoke(Int32 index);
  public: IAsyncResult BeginInvoke(Int32 index, AsyncCallback callback, Object object);
  public: T EndInvoke(IAsyncResult result);
};
} // namespace Indexer_Get_DelegateNamespace
template <class T>
using Indexer_Get_Delegate = Indexer_Get_DelegateNamespace::Indexer_Get_Delegate<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
