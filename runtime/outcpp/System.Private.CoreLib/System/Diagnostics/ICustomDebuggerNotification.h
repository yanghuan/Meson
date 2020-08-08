#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace ICustomDebuggerNotificationNamespace {
CLASS(ICustomDebuggerNotification) : public Object::in {
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomDebuggerNotificationNamespace
using ICustomDebuggerNotification = ICustomDebuggerNotificationNamespace::ICustomDebuggerNotification;
} // namespace System::Private::CoreLib::System::Diagnostics
