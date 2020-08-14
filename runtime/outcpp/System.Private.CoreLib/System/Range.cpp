#include "Range-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/HashCode-dep.h>
#include <System.Private.CoreLib/System/Range-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::RangeNamespace {
Range Range::get_All() {
}

Range::Range(Index start, Index end) {
  Start = start;
  End = end;
}

Boolean Range::Equals(Object value) {
  if (rt::is<Range>(value)) {
    Range range = (Range)value;
    if (range.get_Start().Equals(Start)) {
      return range.get_End().Equals(End);
    }
  }
  return false;
}

Boolean Range::Equals(Range other) {
  if (other.get_Start().Equals(Start)) {
    return other.get_End().Equals(End);
  }
  return false;
}

Int32 Range::GetHashCode() {
  return HashCode::Combine(Start.GetHashCode(), End.GetHashCode());
}

String Range::ToString() {
  Char default[24] = {};
  Span<Char> span = default;
  Int32 num = 0;
  if (Start.get_IsFromEnd()) {
    span[0] = 94;
    num = 1;
  }
  Int32 charsWritten;
  Boolean flag = ((UInt32)Start.get_Value()).TryFormat(span.Slice(num), charsWritten);
  num += charsWritten;
  span[num++] = 46;
  span[num++] = 46;
  if (End.get_IsFromEnd()) {
    span[num++] = 94;
  }
  flag = ((UInt32)End.get_Value()).TryFormat(span.Slice(num), charsWritten);
}

Range Range::StartAt(Index start) {
}

Range Range::EndAt(Index end) {
}

ValueTuple<> Range::GetOffsetAndLength(Int32 length) {
  Index start = Start;
  Int32 num = (!start.get_IsFromEnd()) ? start.get_Value() : (length - start.get_Value());
  Index end = End;
  Int32 num2 = (!end.get_IsFromEnd()) ? end.get_Value() : (length - end.get_Value());
  if ((UInt32)num2 > (UInt32)length || (UInt32)num > (UInt32)num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length);
  }
}

} // namespace System::Private::CoreLib::System::RangeNamespace
