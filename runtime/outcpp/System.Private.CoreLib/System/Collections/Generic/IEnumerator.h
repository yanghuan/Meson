#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEnumeratorNamespace {
CLASS(IEnumerator, T) : public Object::in {
  public: T get_Current();
};
} // namespace IEnumeratorNamespace
template <class T>
using IEnumerator = IEnumeratorNamespace::IEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
