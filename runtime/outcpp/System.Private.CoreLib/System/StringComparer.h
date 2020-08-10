#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
FORWARD(IEqualityComparer, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions;
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class StringComparison;
FORWARDS(Boolean)
FORWARD(CultureAwareComparer)
FORWARDS(Int32)
FORWARD(OrdinalCaseSensitiveComparer)
FORWARD(OrdinalIgnoreCaseComparer)
FORWARD(String)
namespace StringComparerNamespace {
using namespace Collections;
using namespace Collections::Generic;
using namespace Globalization;
template <class T>
using IComparer = Collections::Generic::IComparer<T>;
using IComparer1 = Collections::IComparer;
template <class T>
using IEqualityComparer = Collections::Generic::IEqualityComparer<T>;
using IEqualityComparer1 = Collections::IEqualityComparer;
CLASS(StringComparer) : public Object::in {
  public: using interface = rt::TypeList<IComparer1, IEqualityComparer1, IComparer<String>, IEqualityComparer<String>>;
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
  protected: void ctor();
  private: static void ctor_static();
  private: static CultureAwareComparer s_invariantCulture;
  private: static CultureAwareComparer s_invariantCultureIgnoreCase;
  private: static OrdinalCaseSensitiveComparer s_ordinal;
  private: static OrdinalIgnoreCaseComparer s_ordinalIgnoreCase;
};
} // namespace StringComparerNamespace
using StringComparer = StringComparerNamespace::StringComparer;
} // namespace System::Private::CoreLib::System
