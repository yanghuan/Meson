#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SEHExceptionNamespace {
CLASS(SEHException) {
  public: Boolean CanResume();
};
} // namespace SEHExceptionNamespace
using SEHException = SEHExceptionNamespace::SEHException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
