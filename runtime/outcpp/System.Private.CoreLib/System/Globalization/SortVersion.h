#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace SortVersionNamespace {
CLASS(SortVersion) {
  public: Int32 get_FullVersion();
  public: Guid get_SortId();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SortVersion other);
  public: Int32 GetHashCode();
  private: Int32 m_NlsVersion;
  private: Guid m_SortId;
};
} // namespace SortVersionNamespace
using SortVersion = SortVersionNamespace::SortVersion;
} // namespace System::Private::CoreLib::System::Globalization
