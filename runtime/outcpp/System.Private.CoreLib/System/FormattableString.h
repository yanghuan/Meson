#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(IFormatProvider)
namespace FormattableStringNamespace {
CLASS(FormattableString) {
  public: String get_Format();
  public: Int32 get_ArgumentCount();
  public: Array<Object> GetArguments();
  public: Object GetArgument(Int32 index);
  public: String ToString(IFormatProvider formatProvider);
  public: static String Invariant(FormattableString formattable);
  public: static String CurrentCulture(FormattableString formattable);
  public: String ToString();
};
} // namespace FormattableStringNamespace
using FormattableString = FormattableStringNamespace::FormattableString;
} // namespace System::Private::CoreLib::System