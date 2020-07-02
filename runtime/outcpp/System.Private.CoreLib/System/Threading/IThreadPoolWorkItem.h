#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
namespace IThreadPoolWorkItemNamespace {
CLASS(IThreadPoolWorkItem) {
  public: void Execute();
};
} // namespace IThreadPoolWorkItemNamespace
using IThreadPoolWorkItem = IThreadPoolWorkItemNamespace::IThreadPoolWorkItem;
} // namespace System::Private::CoreLib::System::Threading
