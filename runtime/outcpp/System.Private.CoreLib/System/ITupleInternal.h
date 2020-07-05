#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
namespace ITupleInternalNamespace {
using namespace Collections;
using namespace Text;
CLASS(ITupleInternal) {
  public: String ToString(StringBuilder sb);
  public: Int32 GetHashCode(IEqualityComparer comparer);
};
} // namespace ITupleInternalNamespace
using ITupleInternal = ITupleInternalNamespace::ITupleInternal;
} // namespace System::Private::CoreLib::System
