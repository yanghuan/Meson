#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
namespace IThreadPoolWorkItemNamespace {
CLASS(IThreadPoolWorkItem) : public Object::in {
  public: void Execute();
};
} // namespace IThreadPoolWorkItemNamespace
using IThreadPoolWorkItem = IThreadPoolWorkItemNamespace::IThreadPoolWorkItem;
} // namespace System::Private::CoreLib::System::Threading
