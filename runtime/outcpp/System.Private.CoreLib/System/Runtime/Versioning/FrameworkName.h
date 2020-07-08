#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace FrameworkNameNamespace {
CLASS(FrameworkName) {
  public: String get_Identifier();
  public: Version get_Version();
  public: String get_Profile();
  public: String get_FullName();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(FrameworkName other);
  public: Int32 GetHashCode();
  public: String ToString();
  private: String _identifier;
  private: Version _version;
  private: String _profile;
  private: String _fullName;
};
} // namespace FrameworkNameNamespace
using FrameworkName = FrameworkNameNamespace::FrameworkName;
} // namespace System::Private::CoreLib::System::Runtime::Versioning