#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32 {
namespace UnsafeNativeMethodsNamespace {
using namespace ::System::Private::CoreLib::System;
class UnsafeNativeMethods {
  public: static Int32 RoGetActivationFactory(String activatableClassId, Guid& iid, Object& factory);
};
} // namespace UnsafeNativeMethodsNamespace
using UnsafeNativeMethods = UnsafeNativeMethodsNamespace::UnsafeNativeMethods;
} // namespace System::Private::CoreLib::Microsoft::Win32
