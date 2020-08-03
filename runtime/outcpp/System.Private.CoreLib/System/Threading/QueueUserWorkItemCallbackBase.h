#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
namespace QueueUserWorkItemCallbackBaseNamespace {
CLASS(QueueUserWorkItemCallbackBase) : public Object::in {
  public: void Execute();
  protected: void Ctor();
};
} // namespace QueueUserWorkItemCallbackBaseNamespace
using QueueUserWorkItemCallbackBase = QueueUserWorkItemCallbackBaseNamespace::QueueUserWorkItemCallbackBase;
} // namespace System::Private::CoreLib::System::Threading
