#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEqualityComparer, T)
namespace IInternalStringEqualityComparerNamespace {
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(IInternalStringEqualityComparer) : public object {
  public: using interface = rt::TypeList<IEqualityComparer<String>>;
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: IEqualityComparer<String> GetUnderlyingEqualityComparer();
  public: static IEqualityComparer<String> GetUnderlyingEqualityComparer(IEqualityComparer<String> outerComparer);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IInternalStringEqualityComparerNamespace
using IInternalStringEqualityComparer = IInternalStringEqualityComparerNamespace::IInternalStringEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections::Generic
