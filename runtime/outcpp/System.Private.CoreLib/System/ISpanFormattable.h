#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Span, T)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARD(IFormatProvider)
FORWARDS(Boolean)
namespace ISpanFormattableNamespace {
CLASS(ISpanFormattable) {
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
};
} // namespace ISpanFormattableNamespace
using ISpanFormattable = ISpanFormattableNamespace::ISpanFormattable;
} // namespace System::Private::CoreLib::System
