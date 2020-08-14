#include "DisableMediaInsertionPrompt-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/IO/DisableMediaInsertionPrompt-dep.h>

namespace System::Private::CoreLib::System::IO::DisableMediaInsertionPromptNamespace {
DisableMediaInsertionPrompt DisableMediaInsertionPrompt::Create() {
  DisableMediaInsertionPrompt result = DisableMediaInsertionPrompt();
  result._disableSuccess = Interop::Kernel32::SetThreadErrorMode(1u, result._oldMode);
  return result;
}

void DisableMediaInsertionPrompt::Dispose() {
  if (_disableSuccess) {
  }
}

} // namespace System::Private::CoreLib::System::IO::DisableMediaInsertionPromptNamespace
