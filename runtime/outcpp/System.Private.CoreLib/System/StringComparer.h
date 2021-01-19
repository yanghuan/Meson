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
enum class CompareOptions : int32_t;
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t;
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
namespace StringComparerNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using IComparer = Collections::IComparer;
using IEqualityComparer = Collections::IEqualityComparer;
template <class T>
using IComparer_ = Collections::Generic::IComparer<T>;
template <class T>
using IEqualityComparer_ = Collections::Generic::IEqualityComparer<T>;
CLASS(StringComparer) : public object {
  public: using interface = rt::TypeList<IComparer, IEqualityComparer, IComparer_<String>, IEqualityComparer_<String>>;
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
  public: void ctor();
};
} // namespace StringComparerNamespace
using StringComparer = StringComparerNamespace::StringComparer;
} // namespace System::Private::CoreLib::System
