#pragma once

#include "GlobalizationMode.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace {
inline Boolean GlobalizationMode::get_Invariant() {
  return Invariant;
}

inline Boolean GlobalizationMode::get_UseNls() {
  return UseNls;
}

} // namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace
