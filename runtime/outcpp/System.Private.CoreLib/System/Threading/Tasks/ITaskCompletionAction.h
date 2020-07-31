#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ITaskCompletionActionNamespace {
CLASS(ITaskCompletionAction) : public Object::in {
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: void Invoke(Task<> completingTask);
};
} // namespace ITaskCompletionActionNamespace
using ITaskCompletionAction = ITaskCompletionActionNamespace::ITaskCompletionAction;
} // namespace System::Private::CoreLib::System::Threading::Tasks
