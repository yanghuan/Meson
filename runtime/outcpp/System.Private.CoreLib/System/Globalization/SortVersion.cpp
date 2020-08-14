#include "SortVersion-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Globalization/SortVersion-dep.h>

namespace System::Private::CoreLib::System::Globalization::SortVersionNamespace {
Int32 SortVersion___::get_FullVersion() {
  return m_NlsVersion;
}

Guid SortVersion___::get_SortId() {
  return m_SortId;
}

void SortVersion___::ctor(Int32 fullVersion, Guid sortId) {
  m_SortId = sortId;
  m_NlsVersion = fullVersion;
}

void SortVersion___::ctor(Int32 nlsVersion, Int32 effectiveId, Guid customVersion) {
  m_NlsVersion = nlsVersion;
  if (customVersion == Guid::Empty) {
    Byte h = (Byte)(effectiveId >> 24);
  }
  m_SortId = customVersion;
}

Boolean SortVersion___::Equals(Object obj) {
  SortVersion sortVersion = rt::as<SortVersion>(obj);
  if ((Object)sortVersion != nullptr) {
    return Equals(sortVersion);
  }
  return false;
}

Boolean SortVersion___::Equals(SortVersion other) {
  if (other == nullptr) {
    return false;
  }
  if (m_NlsVersion == other->m_NlsVersion) {
    return m_SortId == other->m_SortId;
  }
  return false;
}

Int32 SortVersion___::GetHashCode() {
}

Boolean SortVersion___::op_Equality(SortVersion left, SortVersion right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  return right->Equals(left);
}

Boolean SortVersion___::op_Inequality(SortVersion left, SortVersion right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Globalization::SortVersionNamespace
