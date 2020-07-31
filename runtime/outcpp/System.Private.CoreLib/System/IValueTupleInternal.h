#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
namespace IValueTupleInternalNamespace {
using namespace Collections;
CLASS(IValueTupleInternal) : public Object::in {
  public: Int32 GetHashCode(IEqualityComparer comparer);
  public: String ToStringEnd();
};
} // namespace IValueTupleInternalNamespace
using IValueTupleInternal = IValueTupleInternalNamespace::IValueTupleInternal;
} // namespace System::Private::CoreLib::System
