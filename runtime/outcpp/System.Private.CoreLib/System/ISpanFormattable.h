#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
namespace ISpanFormattableNamespace {
CLASS(ISpanFormattable) : public object {
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ISpanFormattableNamespace
using ISpanFormattable = ISpanFormattableNamespace::ISpanFormattable;
} // namespace System::Private::CoreLib::System
