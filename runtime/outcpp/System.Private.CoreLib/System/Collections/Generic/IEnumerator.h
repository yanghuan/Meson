#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEnumeratorNamespace {
CLASS(IEnumerator, T) {
};
} // namespace IEnumeratorNamespace
template <class T>
using IEnumerator = IEnumeratorNamespace::IEnumerator<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
