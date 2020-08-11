#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEnumeratorNamespace {
using IEnumerator_ = Collections::IEnumerator;
CLASS(IEnumerator, T) : public Object::in {
  public: using interface = rt::TypeList<IDisposable, IEnumerator_>;
  public: T get_Current();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEnumeratorNamespace
template <class T>
using IEnumerator = IEnumeratorNamespace::IEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
