#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IEnumerableNamespace {
using namespace Collections;
CLASS(IEnumerable) : public Object::in {
  public: IEnumerator GetEnumerator();
};
} // namespace IEnumerableNamespace
using IEnumerable = IEnumerableNamespace::IEnumerable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
