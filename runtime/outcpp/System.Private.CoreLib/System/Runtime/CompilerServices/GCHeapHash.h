#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace GCHeapHashNamespace {
CLASS(GCHeapHash) {
  private: Array<> _data;
  private: Int32 _count;
  private: Int32 _deletedCount;
};
} // namespace GCHeapHashNamespace
using GCHeapHash = GCHeapHashNamespace::GCHeapHash;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices