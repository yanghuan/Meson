#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
namespace IValueTaskSourceNamespace {
CLASS_FORWARD(IValueTaskSource, T1, T2)
CLASS_(IValueTaskSource) : public Object::in {
};
CLASS_(IValueTaskSource, TResult) : public Object::in {
};
} // namespace IValueTaskSourceNamespace
template <class T1 = void, class T2 = void>
using IValueTaskSource = IValueTaskSourceNamespace::IValueTaskSource<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
