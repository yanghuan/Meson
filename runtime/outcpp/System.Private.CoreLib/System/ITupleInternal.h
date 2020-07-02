#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
namespace ITupleInternalNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(ITupleInternal) {
  public: String ToString(StringBuilder sb);
  public: Int32 GetHashCode(IEqualityComparer comparer);
};
} // namespace ITupleInternalNamespace
using ITupleInternal = ITupleInternalNamespace::ITupleInternal;
} // namespace System::Private::CoreLib::System
