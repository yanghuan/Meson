#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
namespace AccessViolationExceptionNamespace {
CLASS(AccessViolationException) {
  private: IntPtr _ip;
  private: IntPtr _target;
  private: Int32 _accessType;
};
} // namespace AccessViolationExceptionNamespace
using AccessViolationException = AccessViolationExceptionNamespace::AccessViolationException;
} // namespace System::Private::CoreLib::System
