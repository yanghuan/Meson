#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace ActionNamespace {
CLASS_FORWARD(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
CLASS_(Action) {
};
CLASS_(Action, T) {
};
CLASS_(Action, T1, T2) {
};
CLASS_(Action, T1, T2, T3) {
};
CLASS_(Action, T1, T2, T3, T4) {
};
CLASS_(Action, T1, T2, T3, T4, T5) {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6) {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7) {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8) {
};
} // namespace ActionNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void>
using Action = ActionNamespace::Action<T1, T2, T3, T4, T5, T6, T7, T8, T9>;
} // namespace System::Private::CoreLib::System
