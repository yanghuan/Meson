#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
enum class StringComparison;
FORWARD(Utf8String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
enum class CompareOptions;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
FORWARDS(Utf8Span)
namespace Utf8StringComparerNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(Utf8StringComparer) {
  private: CLASS(CultureAwareComparer) {
    public: Int32 Compare(Utf8String x, Utf8String y);
    public: Int32 Compare(Utf8Span x, Utf8Span y);
    public: Boolean Equals(Utf8String x, Utf8String y);
    public: Boolean Equals(Utf8Span x, Utf8Span y);
    public: Int32 GetHashCode(Utf8String obj);
    public: Int32 GetHashCode(Utf8Span obj);
    public: static CultureAwareComparer Invariant;
    public: static CultureAwareComparer InvariantIgnoreCase;
    private: CompareInfo _compareInfo;
    private: CompareOptions _options;
  };
  private: CLASS(OrdinalComparer) {
    public: Int32 Compare(Utf8String x, Utf8String y);
    public: Int32 Compare(Utf8Span x, Utf8Span y);
    public: Boolean Equals(Utf8String x, Utf8String y);
    public: Boolean Equals(Utf8Span x, Utf8Span y);
    public: Int32 GetHashCode(Utf8String obj);
    public: Int32 GetHashCode(Utf8Span obj);
    public: static OrdinalComparer Instance;
  };
  private: CLASS(OrdinalIgnoreCaseComparer) {
    public: Int32 Compare(Utf8String x, Utf8String y);
    public: Int32 Compare(Utf8Span x, Utf8Span y);
    public: Boolean Equals(Utf8String x, Utf8String y);
    public: Boolean Equals(Utf8Span x, Utf8Span y);
    public: Int32 GetHashCode(Utf8String obj);
    public: Int32 GetHashCode(Utf8Span obj);
    public: static OrdinalIgnoreCaseComparer Instance;
  };
  public: static Utf8StringComparer get_CurrentCulture();
  public: static Utf8StringComparer get_CurrentCultureIgnoreCase();
  public: static Utf8StringComparer get_InvariantCulture();
  public: static Utf8StringComparer get_InvariantCultureIgnoreCase();
  public: static Utf8StringComparer get_Ordinal();
  public: static Utf8StringComparer get_OrdinalIgnoreCase();
  public: static Utf8StringComparer FromComparison(StringComparison comparisonType);
  public: Int32 Compare(Utf8String x, Utf8String y);
  public: Int32 Compare(Utf8Span x, Utf8Span y);
  public: Boolean Equals(Utf8String x, Utf8String y);
  public: Boolean Equals(Utf8Span x, Utf8Span y);
  public: Int32 GetHashCode(Utf8String obj);
  public: Int32 GetHashCode(Utf8Span obj);
};
} // namespace Utf8StringComparerNamespace
using Utf8StringComparer = Utf8StringComparerNamespace::Utf8StringComparer;
} // namespace System::Private::CoreLib::System::Text
