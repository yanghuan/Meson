#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
namespace ActionNamespace {
CLASS_FORWARD(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
CLASS_(Action) : public MulticastDelegate::in {
};
CLASS_(Action, T) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) : public MulticastDelegate::in {
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) : public MulticastDelegate::in {
};
} // namespace ActionNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void, class T10 = void, class T11 = void, class T12 = void, class T13 = void, class T14 = void, class T15 = void, class T16 = void, class T17 = void>
using Action = ActionNamespace::Action<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17>;
} // namespace System::Private::CoreLib::System
