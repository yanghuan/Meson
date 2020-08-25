#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace EditAndContinueHelperNamespace {
CLASS(EditAndContinueHelper) : public object {
  private: Object _objectReference;
};
} // namespace EditAndContinueHelperNamespace
using EditAndContinueHelper = EditAndContinueHelperNamespace::EditAndContinueHelper;
} // namespace System::Private::CoreLib::System::Diagnostics
