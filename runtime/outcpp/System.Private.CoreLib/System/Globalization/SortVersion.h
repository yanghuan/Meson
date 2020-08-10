#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IEquatable, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace SortVersionNamespace {
CLASS(SortVersion) : public Object::in {
  public: using interface = rt::TypeList<IEquatable<SortVersion>>;
  public: Int32 get_FullVersion();
  public: Guid get_SortId();
  public: void ctor(Int32 fullVersion, Guid sortId);
  public: void ctor(Int32 nlsVersion, Int32 effectiveId, Guid customVersion);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SortVersion other);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(SortVersion left, SortVersion right);
  public: static Boolean op_Inequality(SortVersion left, SortVersion right);
  private: Int32 m_NlsVersion;
  private: Guid m_SortId;
};
} // namespace SortVersionNamespace
using SortVersion = SortVersionNamespace::SortVersion;
} // namespace System::Private::CoreLib::System::Globalization
