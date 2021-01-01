#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
namespace StreamHelpersNamespace {
class StreamHelpers {
  public: static void ValidateCopyToArgs(Stream source, Stream destination, Int32 bufferSize);
  public: static void ValidateCopyToArgs(Stream source, Delegate callback, Int32 bufferSize);
};
} // namespace StreamHelpersNamespace
using StreamHelpers = StreamHelpersNamespace::StreamHelpers;
} // namespace System::Private::CoreLib::System::IO
