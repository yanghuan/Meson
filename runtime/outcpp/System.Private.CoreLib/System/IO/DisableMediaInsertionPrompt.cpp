#include "DisableMediaInsertionPrompt-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/IO/DisableMediaInsertionPrompt-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::DisableMediaInsertionPromptNamespace {
DisableMediaInsertionPrompt DisableMediaInsertionPrompt::Create() {
  DisableMediaInsertionPrompt result = rt::default__;
  result._disableSuccess = Interop::Kernel32::SetThreadErrorMode(1u, result._oldMode);
  return result;
}

void DisableMediaInsertionPrompt::Dispose() {
  if (_disableSuccess) {
    UInt32 lpOldMode;
    Interop::Kernel32::SetThreadErrorMode(_oldMode, lpOldMode);
  }
}

} // namespace System::Private::CoreLib::System::IO::DisableMediaInsertionPromptNamespace
