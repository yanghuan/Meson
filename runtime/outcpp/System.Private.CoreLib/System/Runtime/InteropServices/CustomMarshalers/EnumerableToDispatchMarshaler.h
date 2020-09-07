#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomMarshaler)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
FORWARD(EnumerableViewOfDispatch)
namespace EnumerableToDispatchMarshalerNamespace {
CLASS(EnumerableToDispatchMarshaler) : public object {
  public: using interface = rt::TypeList<ICustomMarshaler>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: EnumerableViewOfDispatch _MarshalNativeToManaged_b__7_0(Object obj);
    public: static __c __9;
    public: static Func<Object, EnumerableViewOfDispatch> __9__7_0;
  };
  public: static ICustomMarshaler GetInstance(String cookie);
  public: void ctor();
  public: void CleanUpManagedData(Object ManagedObj);
  public: void CleanUpNativeData(IntPtr pNativeData);
  public: Int32 GetNativeDataSize();
  public: IntPtr MarshalManagedToNative(Object ManagedObj);
  public: Object MarshalNativeToManaged(IntPtr pNativeData);
  public: static void cctor();
  private: static EnumerableToDispatchMarshaler s_enumerableToDispatchMarshaler;
};
} // namespace EnumerableToDispatchMarshalerNamespace
using EnumerableToDispatchMarshaler = EnumerableToDispatchMarshalerNamespace::EnumerableToDispatchMarshaler;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
