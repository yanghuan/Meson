#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace COMExceptionNamespace {
CLASS(COMException) {
  public: String ToString();
};
} // namespace COMExceptionNamespace
using COMException = COMExceptionNamespace::COMException;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
