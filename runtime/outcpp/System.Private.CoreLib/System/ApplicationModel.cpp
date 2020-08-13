#include "ApplicationModel-dep.h"

namespace System::Private::CoreLib::System::ApplicationModelNamespace {
void ApplicationModel::ctor_static() {
  IsUap = (IsAppXProcess() != Interop::BOOL::FALSE);
}

} // namespace System::Private::CoreLib::System::ApplicationModelNamespace
