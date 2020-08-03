#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/Text/Rune.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace SpanRuneEnumeratorNamespace {
struct SpanRuneEnumerator : public valueType<SpanRuneEnumerator> {
  public: Rune get_Current();
  public: explicit SpanRuneEnumerator(ReadOnlySpan<Char> buffer);
  public: SpanRuneEnumerator GetEnumerator();
  public: Boolean MoveNext();
  public: explicit SpanRuneEnumerator() {}
  private: ReadOnlySpan<Char> _remaining;
  private: Rune _current;
};
} // namespace SpanRuneEnumeratorNamespace
using SpanRuneEnumerator = SpanRuneEnumeratorNamespace::SpanRuneEnumerator;
} // namespace System::Private::CoreLib::System::Text
