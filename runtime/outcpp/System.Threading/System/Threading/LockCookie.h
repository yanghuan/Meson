#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System::Threading {
enum class LockCookieFlags : int32_t;
namespace LockCookieNamespace {
using namespace ::System::Private::CoreLib::System;
struct LockCookie : public valueType<LockCookie> {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(LockCookie obj);
  public: static Boolean op_Equality(LockCookie a, LockCookie b);
  public: static Boolean op_Inequality(LockCookie a, LockCookie b);
  public: LockCookieFlags _flags;
  public: UInt16 _readerLevel;
  public: UInt16 _writerLevel;
  public: Int32 _threadID;
};
} // namespace LockCookieNamespace
using LockCookie = LockCookieNamespace::LockCookie;
} // namespace System::Threading::System::Threading
