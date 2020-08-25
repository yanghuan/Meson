#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace FuncNamespace {
CLASS_FORWARD(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
CLASS_(Func, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke();
  public: IAsyncResult BeginInvoke(AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T arg);
  public: IAsyncResult BeginInvoke(T arg, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
CLASS_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, TResult) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: TResult Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, T16 arg16);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, T16 arg16, AsyncCallback callback, Object object);
  public: TResult EndInvoke(IAsyncResult result);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace FuncNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void, class T10 = void, class T11 = void, class T12 = void, class T13 = void, class T14 = void, class T15 = void, class T16 = void, class T17 = void, class T18 = void>
using Func = FuncNamespace::Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18>;
} // namespace System::Private::CoreLib::System
