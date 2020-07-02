#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Resources {
namespace PRIExceptionInfoNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(PRIExceptionInfo) {
  public: String PackageSimpleName;
  public: String ResWFile;
};
} // namespace PRIExceptionInfoNamespace
using PRIExceptionInfo = PRIExceptionInfoNamespace::PRIExceptionInfo;
} // namespace System::Private::CoreLib::Internal::Resources
