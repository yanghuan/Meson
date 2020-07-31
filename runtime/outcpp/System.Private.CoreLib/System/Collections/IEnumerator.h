#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IEnumeratorNamespace {
CLASS(IEnumerator) : public Object::in {
  public: Object get_Current();
  public: Boolean MoveNext();
  public: void Reset();
};
} // namespace IEnumeratorNamespace
using IEnumerator = IEnumeratorNamespace::IEnumerator;
} // namespace System::Private::CoreLib::System::Collections
