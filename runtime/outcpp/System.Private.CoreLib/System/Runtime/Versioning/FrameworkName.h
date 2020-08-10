#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace FrameworkNameNamespace {
CLASS(FrameworkName) : public Object::in {
  public: using interface = rt::TypeList<IEquatable<FrameworkName>>;
  public: String get_Identifier();
  public: Version get_Version();
  public: String get_Profile();
  public: String get_FullName();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(FrameworkName other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: void ctor(String identifier, Version version);
  public: void ctor(String identifier, Version version, String profile);
  public: void ctor(String frameworkName);
  public: static Boolean op_Equality(FrameworkName left, FrameworkName right);
  public: static Boolean op_Inequality(FrameworkName left, FrameworkName right);
  private: String _identifier;
  private: Version _version;
  private: String _profile;
  private: String _fullName;
};
} // namespace FrameworkNameNamespace
using FrameworkName = FrameworkNameNamespace::FrameworkName;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
