#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Guid)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace IClassFactoryNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IClassFactory) : public Object::in {
  public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject);
  public: void LockServer(Boolean fLock);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IClassFactoryNamespace
using IClassFactory = IClassFactoryNamespace::IClassFactory;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
