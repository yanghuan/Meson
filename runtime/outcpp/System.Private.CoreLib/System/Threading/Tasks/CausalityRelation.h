#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class CausalityRelation {
  AssignDelegate = 0,
  Join = 1,
  Choice = 2,
  Cancel = 3,
  Error = 4,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
