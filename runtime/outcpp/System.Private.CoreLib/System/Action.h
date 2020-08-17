#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
namespace ActionNamespace {
CLASS_FORWARD(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
CLASS_(Action) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke();
  public: IAsyncResult BeginInvoke(AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T obj);
  public: IAsyncResult BeginInvoke(T obj, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
CLASS_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, T16 arg16);
  public: IAsyncResult BeginInvoke(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10, T11 arg11, T12 arg12, T13 arg13, T14 arg14, T15 arg15, T16 arg16, AsyncCallback callback, Object object);
  public: void EndInvoke(IAsyncResult result);
};
} // namespace ActionNamespace
template <class T1 = void, class T2 = void, class T3 = void, class T4 = void, class T5 = void, class T6 = void, class T7 = void, class T8 = void, class T9 = void, class T10 = void, class T11 = void, class T12 = void, class T13 = void, class T14 = void, class T15 = void, class T16 = void, class T17 = void>
using Action = ActionNamespace::Action<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17>;
} // namespace System::Private::CoreLib::System
