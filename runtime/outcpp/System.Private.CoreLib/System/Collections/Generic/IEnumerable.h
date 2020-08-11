#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
namespace IEnumerableNamespace {
CLASS(IEnumerable, T) : public Object::in {
  public: using interface = rt::TypeList<Collections::IEnumerable>;
  public: IEnumerator<T> GetEnumerator();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEnumerableNamespace
template <class T>
using IEnumerable = IEnumerableNamespace::IEnumerable<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
