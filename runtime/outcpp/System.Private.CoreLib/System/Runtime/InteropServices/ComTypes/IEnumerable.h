#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IEnumerableNamespace {
using namespace Collections;
CLASS(IEnumerable) {
  public: IEnumerator GetEnumerator();
};
} // namespace IEnumerableNamespace
using IEnumerable = IEnumerableNamespace::IEnumerable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
