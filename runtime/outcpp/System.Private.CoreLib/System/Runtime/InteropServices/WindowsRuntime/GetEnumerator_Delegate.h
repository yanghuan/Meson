#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace GetEnumerator_DelegateNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IEnumerator;
CLASS(GetEnumerator_Delegate, T) {
  public: IEnumerator<T> Invoke();
  public: IAsyncResult BeginInvoke(AsyncCallback callback, Object object);
  public: IEnumerator<T> EndInvoke(IAsyncResult result);
};
} // namespace GetEnumerator_DelegateNamespace
template <class T>
using GetEnumerator_Delegate = GetEnumerator_DelegateNamespace::GetEnumerator_Delegate<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
