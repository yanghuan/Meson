#pragma once

#include <rt/GCObject.h>

namespace System::Runtime::System {
namespace FuncNamespace {
CLASS_FORWARD(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult) {
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, TResult) {
};
} // namespace FuncNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void, class T10 = void, class T11 = void, class T12 = void, class T13 = void, class T14 = void, class T15 = void, class T16 = void, class T17 = void, class T18 = void>
using Func = FuncNamespace::Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18>;
} // namespace System::Runtime::System
