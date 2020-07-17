#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
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
  protected: void Ctor();
};
} // namespace FormattableStringNamespace
using FormattableString = FormattableStringNamespace::FormattableString;
} // namespace System::Private::CoreLib::System
