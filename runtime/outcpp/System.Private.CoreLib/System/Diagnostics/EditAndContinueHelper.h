#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace EditAndContinueHelperNamespace {
CLASS(EditAndContinueHelper) {
  private: Object _objectReference;
};
} // namespace EditAndContinueHelperNamespace
using EditAndContinueHelper = EditAndContinueHelperNamespace::EditAndContinueHelper;
} // namespace System::Private::CoreLib::System::Diagnostics
