#pragma once

#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace SessionMaskNamespace {
struct SessionMask : public valueType<SessionMask> {
  public: static SessionMask get_All();
  public: explicit SessionMask(UInt32 mask = 0u);
  public: UInt64 ToEventKeywords();
  public: static SessionMask FromEventKeywords(UInt64 m);
  public: static UInt32 op_Explicit(SessionMask m);
  public: explicit SessionMask() {}
  private: UInt32 m_mask;
};
} // namespace SessionMaskNamespace
using SessionMask = SessionMaskNamespace::SessionMask;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
