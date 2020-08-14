#include "LockCookie-dep.h"

#include <System.Threading/System/Threading/LockCookie-dep.h>

namespace System::Threading::System::Threading::LockCookieNamespace {
Int32 LockCookie::GetHashCode() {
  return (Int32)(_flags + _readerLevel + _writerLevel + _threadID);
}

Boolean LockCookie::Equals(Object obj) {
  if (rt::is<LockCookie>(obj)) {
    return Equals((LockCookie)obj);
  }
  return false;
}

Boolean LockCookie::Equals(LockCookie obj) {
  if (_flags == obj._flags && _readerLevel == obj._readerLevel && _writerLevel == obj._writerLevel) {
    return _threadID == obj._threadID;
  }
  return false;
}

Boolean LockCookie::op_Equality(LockCookie a, LockCookie b) {
  return a.Equals(b);
}

Boolean LockCookie::op_Inequality(LockCookie a, LockCookie b) {
  return !(a == b);
}

} // namespace System::Threading::System::Threading::LockCookieNamespace
