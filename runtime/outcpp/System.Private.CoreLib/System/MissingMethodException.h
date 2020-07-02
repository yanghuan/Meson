#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace MissingMethodExceptionNamespace {
CLASS(MissingMethodException) {
  public: String get_Message();
};
} // namespace MissingMethodExceptionNamespace
using MissingMethodException = MissingMethodExceptionNamespace::MissingMethodException;
} // namespace System::Private::CoreLib::System
