#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
namespace IEnumerableNamespace {
CLASS(IEnumerable) {
  public: IEnumerator GetEnumerator();
};
} // namespace IEnumerableNamespace
using IEnumerable = IEnumerableNamespace::IEnumerable;
} // namespace System::Private::CoreLib::System::Collections
