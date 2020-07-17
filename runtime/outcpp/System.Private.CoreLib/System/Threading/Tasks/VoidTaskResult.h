#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
namespace VoidTaskResultNamespace {
struct VoidTaskResult {
  public: void Ctor();
};
} // namespace VoidTaskResultNamespace
using VoidTaskResult = VoidTaskResultNamespace::VoidTaskResult;
} // namespace System::Private::CoreLib::System::Threading::Tasks
