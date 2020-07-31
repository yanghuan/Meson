#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
namespace ISpanFormattableNamespace {
CLASS(ISpanFormattable) : public Object::in {
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
};
} // namespace ISpanFormattableNamespace
using ISpanFormattable = ISpanFormattableNamespace::ISpanFormattable;
} // namespace System::Private::CoreLib::System
