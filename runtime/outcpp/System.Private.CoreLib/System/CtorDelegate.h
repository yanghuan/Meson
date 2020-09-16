#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(Object)
namespace CtorDelegateNamespace {
CLASS(CtorDelegate) : public MulticastDelegate::in {
  public: void ctor(Object object, IntPtr method);
  public: void Invoke(Object instance);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
};
} // namespace CtorDelegateNamespace
using CtorDelegate = CtorDelegateNamespace::CtorDelegate;
} // namespace System::Private::CoreLib::System
