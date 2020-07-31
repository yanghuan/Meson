#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace ErrorNamespace {
class Error : public Object::in {
  public: static Exception GetStreamIsClosed();
  public: static Exception GetEndOfFile();
  public: static Exception GetFileNotOpen();
  public: static Exception GetReadNotSupported();
  public: static Exception GetSeekNotSupported();
  public: static Exception GetWriteNotSupported();
};
} // namespace ErrorNamespace
using Error = ErrorNamespace::Error;
} // namespace System::Private::CoreLib::System::IO
