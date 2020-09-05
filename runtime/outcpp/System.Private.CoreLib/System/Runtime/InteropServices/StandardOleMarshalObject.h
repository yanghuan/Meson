#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Guid)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(IMarshal)
namespace StandardOleMarshalObjectNamespace {
CLASS(StandardOleMarshalObject) : public MarshalByRefObject::in {
  public: using interface = rt::TypeList<IMarshal>;
  private: CLASS(GetMarshalSizeMaxDelegate) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: Int32 Invoke(IntPtr _this, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Int32& pSize);
    public: IAsyncResult BeginInvoke(IntPtr _this, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Int32& pSize, AsyncCallback callback, Object object);
    public: Int32 EndInvoke(Guid& riid, Int32& pSize, IAsyncResult result);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  private: CLASS(MarshalInterfaceDelegate) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: Int32 Invoke(IntPtr _this, IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags);
    public: IAsyncResult BeginInvoke(IntPtr _this, IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, AsyncCallback callback, Object object);
    public: Int32 EndInvoke(Guid& riid, IAsyncResult result);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  public: void ctor();
  private: IntPtr GetStdMarshaler(Guid& riid, Int32 dwDestContext, Int32 mshlflags);
  public: static void cctor();
  private: static Guid CLSID_StdMarshal;
};
} // namespace StandardOleMarshalObjectNamespace
using StandardOleMarshalObject = StandardOleMarshalObjectNamespace::StandardOleMarshalObject;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
