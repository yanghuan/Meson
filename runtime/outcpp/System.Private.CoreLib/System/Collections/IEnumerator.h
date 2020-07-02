#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IEnumeratorNamespace {
CLASS(IEnumerator) {
  public: Object get_Current();
  public: Boolean MoveNext();
  public: void Reset();
};
} // namespace IEnumeratorNamespace
using IEnumerator = IEnumeratorNamespace::IEnumerator;
} // namespace System::Private::CoreLib::System::Collections
