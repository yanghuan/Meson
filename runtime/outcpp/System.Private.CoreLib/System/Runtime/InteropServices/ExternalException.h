#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ExternalExceptionNamespace {
CLASS(ExternalException) {
  public: Int32 get_ErrorCode();
  public: String ToString();
};
} // namespace ExternalExceptionNamespace
using ExternalException = ExternalExceptionNamespace::ExternalException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
