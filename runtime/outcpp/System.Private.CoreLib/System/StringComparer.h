#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
enum class CompareOptions;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class StringComparison;
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(Int32)
FORWARD(String)
FORWARD(CultureAwareComparer)
FORWARD(OrdinalCaseSensitiveComparer)
FORWARD(OrdinalIgnoreCaseComparer)
namespace StringComparerNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(StringComparer) {
  public: static StringComparer get_InvariantCulture();
  public: static StringComparer get_InvariantCultureIgnoreCase();
  public: static StringComparer get_CurrentCulture();
  public: static StringComparer get_CurrentCultureIgnoreCase();
  public: static StringComparer get_Ordinal();
  public: static StringComparer get_OrdinalIgnoreCase();
  public: static StringComparer FromComparison(StringComparison comparisonType);
  public: static StringComparer Create(CultureInfo culture, Boolean ignoreCase);
  public: static StringComparer Create(CultureInfo culture, CompareOptions options);
  public: Int32 Compare(Object x, Object y);
  public: Boolean Equals(Object x, Object y);
  public: Int32 GetHashCode(Object obj);
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  private: static CultureAwareComparer s_invariantCulture;
  private: static CultureAwareComparer s_invariantCultureIgnoreCase;
  private: static OrdinalCaseSensitiveComparer s_ordinal;
  private: static OrdinalIgnoreCaseComparer s_ordinalIgnoreCase;
};
} // namespace StringComparerNamespace
using StringComparer = StringComparerNamespace::StringComparer;
} // namespace System::Private::CoreLib::System
