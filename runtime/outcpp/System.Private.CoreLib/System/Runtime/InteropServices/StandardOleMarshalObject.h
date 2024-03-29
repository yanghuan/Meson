#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
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
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  private: CLASS(MarshalInterfaceDelegate) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: Int32 Invoke(IntPtr _this, IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  public: void ctor();
  private: IntPtr GetStdMarshaler(Guid& riid, Int32 dwDestContext, Int32 mshlflags);
  private: Int32 GetUnmarshalClassOfIMarshal(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Guid& pCid);
  private: Int32 GetMarshalSizeMaxOfIMarshal(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Int32& pSize);
  private: Int32 MarshalInterfaceOfIMarshal(IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags);
  private: Int32 UnmarshalInterfaceOfIMarshal(IntPtr pStm, Guid& riid, IntPtr& ppv);
  private: Int32 ReleaseMarshalDataOfIMarshal(IntPtr pStm);
  private: Int32 DisconnectObjectOfIMarshal(Int32 dwReserved);
  public: static void cctor();
  private: static Guid CLSID_StdMarshal;
};
} // namespace StandardOleMarshalObjectNamespace
using StandardOleMarshalObject = StandardOleMarshalObjectNamespace::StandardOleMarshalObject;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
