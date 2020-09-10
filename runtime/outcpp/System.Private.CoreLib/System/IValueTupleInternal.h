#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ITuple)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
namespace IValueTupleInternalNamespace {
using namespace System::Collections;
using namespace System::Runtime::CompilerServices;
CLASS(IValueTupleInternal) : public object {
  public: using interface = rt::TypeList<ITuple>;
  public: Int32 get_Length();
  public: Object get_Item(Int32 index);
  public: Int32 GetHashCode(IEqualityComparer comparer);
  public: String ToStringEnd();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IValueTupleInternalNamespace
using IValueTupleInternal = IValueTupleInternalNamespace::IValueTupleInternal;
} // namespace System::Private::CoreLib::System
