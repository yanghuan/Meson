#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Concurrent {
namespace PaddedHeadAndTailNamespace {
struct PaddedHeadAndTail : public valueType<PaddedHeadAndTail> {
  public: Int32 Head;
  public: Int32 Tail;
};
} // namespace PaddedHeadAndTailNamespace
using PaddedHeadAndTail = PaddedHeadAndTailNamespace::PaddedHeadAndTail;
} // namespace System::Private::CoreLib::System::Collections::Concurrent
