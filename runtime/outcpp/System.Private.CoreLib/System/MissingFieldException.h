#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace MissingFieldExceptionNamespace {
CLASS(MissingFieldException) {
  public: String get_Message();
};
} // namespace MissingFieldExceptionNamespace
using MissingFieldException = MissingFieldExceptionNamespace::MissingFieldException;
} // namespace System::Private::CoreLib::System
