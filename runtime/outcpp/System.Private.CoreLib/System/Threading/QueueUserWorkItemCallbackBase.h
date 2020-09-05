#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(IThreadPoolWorkItem)
namespace QueueUserWorkItemCallbackBaseNamespace {
CLASS(QueueUserWorkItemCallbackBase) : public object {
  public: using interface = rt::TypeList<IThreadPoolWorkItem>;
  public: void Execute();
  public: void ctor();
};
} // namespace QueueUserWorkItemCallbackBaseNamespace
using QueueUserWorkItemCallbackBase = QueueUserWorkItemCallbackBaseNamespace::QueueUserWorkItemCallbackBase;
} // namespace System::Private::CoreLib::System::Threading
