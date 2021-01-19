#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace IMarshalNamespace {
CLASS(IMarshal) : public object {
  public: Int32 GetUnmarshalClass(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Guid& pCid);
  public: Int32 GetMarshalSizeMax(Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags, Int32& pSize);
  public: Int32 MarshalInterface(IntPtr pStm, Guid& riid, IntPtr pv, Int32 dwDestContext, IntPtr pvDestContext, Int32 mshlflags);
  public: Int32 UnmarshalInterface(IntPtr pStm, Guid& riid, IntPtr& ppv);
  public: Int32 ReleaseMarshalData(IntPtr pStm);
  public: Int32 DisconnectObject(Int32 dwReserved);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IMarshalNamespace
using IMarshal = IMarshalNamespace::IMarshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
