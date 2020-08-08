#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ITuple)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
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
using namespace Runtime::CompilerServices;
using namespace Text;
CLASS(ITupleInternal) : public Object::in {
  using interface = rt::TypeList<ITuple>;
  public: String ToString(StringBuilder sb);
  public: Int32 GetHashCode(IEqualityComparer comparer);
};
} // namespace ITupleInternalNamespace
using ITupleInternal = ITupleInternalNamespace::ITupleInternal;
} // namespace System::Private::CoreLib::System
