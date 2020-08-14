#include "SessionMask-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/SessionMask-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::SessionMaskNamespace {
SessionMask SessionMask::get_All() {
  return SessionMask(15u);
}

SessionMask::SessionMask(UInt32 mask) {
  m_mask = (mask & 15);
}

UInt64 SessionMask::ToEventKeywords() {
  return (UInt64)m_mask << 44;
}

SessionMask SessionMask::FromEventKeywords(UInt64 m) {
  return SessionMask((UInt32)(m >> 44));
}

UInt32 SessionMask::op_Explicit(SessionMask m) {
  return m.m_mask;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::SessionMaskNamespace
