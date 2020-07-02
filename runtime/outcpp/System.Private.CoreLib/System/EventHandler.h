#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace EventHandlerNamespace {
CLASS_FORWARD(EventHandler, T1, T2)
CLASS_(EventHandler) {
};
CLASS_(EventHandler, TEventArgs) {
};
} // namespace EventHandlerNamespace
template <class T1 = void, class T2 = void>
using EventHandler = EventHandlerNamespace::EventHandler<T1, T2>;
} // namespace System::Private::CoreLib::System
