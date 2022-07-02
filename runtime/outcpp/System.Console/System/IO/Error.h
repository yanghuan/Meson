#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Console::System::IO {
namespace ErrorNamespace {
using namespace ::System::Private::CoreLib::System;
class Error {
  public: static Exception GetFileNotOpen();
  public: static Exception GetReadNotSupported();
  public: static Exception GetSeekNotSupported();
  public: static Exception GetWriteNotSupported();
};
} // namespace ErrorNamespace
using Error = ErrorNamespace::Error;
} // namespace System::Console::System::IO
