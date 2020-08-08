#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEnumeratorNamespace {
CLASS(IEnumerator, T) : public Object::in {
  using interface = rt::TypeList<IDisposable, Collections::IEnumerator>;
  public: T get_Current();
};
} // namespace IEnumeratorNamespace
template <class T>
using IEnumerator = IEnumeratorNamespace::IEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
