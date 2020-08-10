#pragma once

#include "Marvin.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::MarvinNamespace {
inline UInt64 Marvin::get_DefaultSeed() {
  return DefaultSeed;
}

} // namespace System::Private::CoreLib::System::MarvinNamespace
