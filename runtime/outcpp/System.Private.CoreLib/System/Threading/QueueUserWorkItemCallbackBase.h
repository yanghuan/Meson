#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
namespace QueueUserWorkItemCallbackBaseNamespace {
CLASS(QueueUserWorkItemCallbackBase) {
  public: void Execute();
};
} // namespace QueueUserWorkItemCallbackBaseNamespace
using QueueUserWorkItemCallbackBase = QueueUserWorkItemCallbackBaseNamespace::QueueUserWorkItemCallbackBase;
} // namespace System::Private::CoreLib::System::Threading