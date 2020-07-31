#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
namespace EventHandlerNamespace {
CLASS_FORWARD(EventHandler, T1, T2)
CLASS_(EventHandler) : public MulticastDelegate::in {
};
CLASS_(EventHandler, TEventArgs) : public MulticastDelegate::in {
};
} // namespace EventHandlerNamespace
template <class T1 = void, class T2 = void>
using EventHandler = EventHandlerNamespace::EventHandler<T1, T2>;
} // namespace System::Private::CoreLib::System
