#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IEnumerableNamespace {
using namespace System::Collections;
using IEnumerator = Collections::IEnumerator;
CLASS(IEnumerable) : public object {
  public: IEnumerator GetEnumerator();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEnumerableNamespace
using IEnumerable = IEnumerableNamespace::IEnumerable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
