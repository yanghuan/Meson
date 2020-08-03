#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
namespace IEnumerableNamespace {
using Generic::IEnumerator;
CLASS(IEnumerable, T) : public Object::in {
  public: IEnumerator<T> GetEnumerator();
};
} // namespace IEnumerableNamespace
template <class T>
using IEnumerable = IEnumerableNamespace::IEnumerable<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
