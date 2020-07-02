#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace FuncNamespace {
CLASS_FORWARD(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
CLASS_(Func, TResult) {
};
CLASS_(Func, T, TResult) {
};
CLASS_(Func, T1, T2, TResult) {
};
CLASS_(Func, T1, T2, T3, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, TResult) {
};
} // namespace FuncNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void, class T10 = void>
using Func = FuncNamespace::Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>;
} // namespace System::Private::CoreLib::System
