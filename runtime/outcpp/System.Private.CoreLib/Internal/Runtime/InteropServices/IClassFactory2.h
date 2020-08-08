#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARD(IClassFactory)
FORWARDS(LICINFO)
namespace IClassFactory2Namespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IClassFactory2) : public Object::in {
  public: using interface = rt::TypeList<IClassFactory>;
  public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject);
  public: void LockServer(Boolean fLock);
  public: void GetLicInfo(LICINFO& pLicInfo);
  public: void RequestLicKey(Int32 dwReserved, String& pBstrKey);
  public: void CreateInstanceLic(Object pUnkOuter, Object pUnkReserved, Guid& riid, String bstrKey, Object& ppvObject);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IClassFactory2Namespace
using IClassFactory2 = IClassFactory2Namespace::IClassFactory2;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
