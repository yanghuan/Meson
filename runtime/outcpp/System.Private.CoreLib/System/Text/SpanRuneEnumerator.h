#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/Text/Rune.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace SpanRuneEnumeratorNamespace {
struct SpanRuneEnumerator {
  public: Rune get_Current();
  public: SpanRuneEnumerator GetEnumerator();
  public: Boolean MoveNext();
  private: ReadOnlySpan<Char> _remaining;
  private: Rune _current;
};
} // namespace SpanRuneEnumeratorNamespace
using SpanRuneEnumerator = SpanRuneEnumeratorNamespace::SpanRuneEnumerator;
} // namespace System::Private::CoreLib::System::Text
