#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System::Threading {
namespace ContextCallbackNamespace {
CLASS_FORWARD(ContextCallback, T1, T2)
CLASS_(ContextCallback) : public MulticastDelegate::in {
};
CLASS_(ContextCallback, TState) : public MulticastDelegate::in {
};
} // namespace ContextCallbackNamespace
template <class T1 = void, class T2 = void>
using ContextCallback = ContextCallbackNamespace::ContextCallback<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading
