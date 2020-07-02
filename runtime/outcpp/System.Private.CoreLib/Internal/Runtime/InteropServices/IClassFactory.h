#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Guid)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace IClassFactoryNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IClassFactory) {
  public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject);
  public: void LockServer(Boolean fLock);
};
} // namespace IClassFactoryNamespace
using IClassFactory = IClassFactoryNamespace::IClassFactory;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
