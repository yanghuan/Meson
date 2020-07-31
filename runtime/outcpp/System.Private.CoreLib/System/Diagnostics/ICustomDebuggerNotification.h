#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace ICustomDebuggerNotificationNamespace {
CLASS(ICustomDebuggerNotification) : public Object::in {
};
} // namespace ICustomDebuggerNotificationNamespace
using ICustomDebuggerNotification = ICustomDebuggerNotificationNamespace::ICustomDebuggerNotification;
} // namespace System::Private::CoreLib::System::Diagnostics
