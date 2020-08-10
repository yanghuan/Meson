#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers::Text {
namespace Utf8ConstantsNamespace {
class Utf8Constants {
  private: static void ctor_static();
  public: static TimeSpan NullUtcOffset;
};
} // namespace Utf8ConstantsNamespace
using Utf8Constants = Utf8ConstantsNamespace::Utf8Constants;
} // namespace System::Private::CoreLib::System::Buffers::Text
