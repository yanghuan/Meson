#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
namespace ITaskCompletionActionNamespace {
CLASS(ITaskCompletionAction) : public object {
  public: Boolean get_InvokeMayRunArbitraryCode();
  public: void Invoke(Task<> completingTask);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITaskCompletionActionNamespace
using ITaskCompletionAction = ITaskCompletionActionNamespace::ITaskCompletionAction;
} // namespace System::Private::CoreLib::System::Threading::Tasks
