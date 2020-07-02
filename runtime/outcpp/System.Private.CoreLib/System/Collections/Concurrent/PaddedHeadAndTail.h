#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace PaddedHeadAndTailNamespace {
struct PaddedHeadAndTail {
  public: Int32 Head;
  public: Int32 Tail;
};
} // namespace PaddedHeadAndTailNamespace
using PaddedHeadAndTail = PaddedHeadAndTailNamespace::PaddedHeadAndTail;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
