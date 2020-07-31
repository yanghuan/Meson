#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace EditAndContinueHelperNamespace {
CLASS(EditAndContinueHelper) : public Object::in {
  private: Object _objectReference;
};
} // namespace EditAndContinueHelperNamespace
using EditAndContinueHelper = EditAndContinueHelperNamespace::EditAndContinueHelper;
} // namespace System::Private::CoreLib::System::Diagnostics
