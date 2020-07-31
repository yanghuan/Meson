#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int16)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace VersionNamespace {
using namespace Text;
CLASS(Version) : public Object::in {
  public: Int32 get_Major();
  public: Int32 get_Minor();
  public: Int32 get_Build();
  public: Int32 get_Revision();
  public: Int16 get_MajorRevision();
  public: Int16 get_MinorRevision();
  private: Int32 get_DefaultFormatFieldCount();
  public: void Ctor(Int32 major, Int32 minor, Int32 build, Int32 revision);
  public: void Ctor(Int32 major, Int32 minor, Int32 build);
  public: void Ctor(Int32 major, Int32 minor);
  public: void Ctor(String version);
  public: void Ctor();
  private: void Ctor(Version version);
  public: Object Clone();
  public: Int32 CompareTo(Object version);
  public: Int32 CompareTo(Version value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Version obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(Int32 fieldCount);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten);
  public: Boolean TryFormat(Span<Char> destination, Int32 fieldCount, Int32& charsWritten);
  private: StringBuilder ToCachedStringBuilder(Int32 fieldCount);
  public: static Version Parse(String input);
  public: static Version Parse(ReadOnlySpan<Char> input);
  public: static Boolean TryParse(String input, Version& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, Version& result);
  private: static Version ParseVersion(ReadOnlySpan<Char> input, Boolean throwOnFailure);
  private: static Boolean TryParseComponent(ReadOnlySpan<Char> component, String componentName, Boolean throwOnFailure, Int32& parsedComponent);
  public: static Boolean op_Equality(Version v1, Version v2);
  public: static Boolean op_Inequality(Version v1, Version v2);
  public: static Boolean op_LessThan(Version v1, Version v2);
  public: static Boolean op_LessThanOrEqual(Version v1, Version v2);
  public: static Boolean op_GreaterThan(Version v1, Version v2);
  public: static Boolean op_GreaterThanOrEqual(Version v1, Version v2);
  private: Int32 _Major;
  private: Int32 _Minor;
  private: Int32 _Build;
  private: Int32 _Revision;
};
} // namespace VersionNamespace
using Version = VersionNamespace::Version;
} // namespace System::Private::CoreLib::System
