#include "ApplicationModel-dep.h"

namespace System::Private::CoreLib::System::ApplicationModelNamespace {
void ApplicationModel::cctor() {
  IsUap = IsAppXProcess() != Interop::BOOL::FALSE;
}

} // namespace System::Private::CoreLib::System::ApplicationModelNamespace
