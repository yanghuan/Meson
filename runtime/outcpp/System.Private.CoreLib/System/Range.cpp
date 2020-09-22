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
  return Range(Index::get_Start(), Index::get_End());
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
  Char as[24] = {};
  Span<Char> span = as;
  Int32 num = 0;
  if (Start.get_IsFromEnd()) {
    span[0] = '^';
    num = 1;
  }
  Int32 charsWritten;
  Boolean flag = ((UInt32)Start.get_Value()).TryFormat(span.Slice(num), charsWritten);
  num += charsWritten;
  span[num++] = '.';
  span[num++] = '.';
  if (End.get_IsFromEnd()) {
    span[num++] = '^';
  }
  flag = ((UInt32)End.get_Value()).TryFormat(span.Slice(num), charsWritten);
  num += charsWritten;
  return rt::newstr<String>(span.Slice(0, num));
}

Range Range::StartAt(Index start) {
  return Range(start, Index::get_End());
}

Range Range::EndAt(Index end) {
  return Range(Index::get_Start(), end);
}

ValueTuple<Int32, Int32> Range::GetOffsetAndLength(Int32 length) {
  Index start = Start;
  Int32 num = (!start.get_IsFromEnd()) ? start.get_Value() : (length - start.get_Value());
  Index end = End;
  Int32 num2 = (!end.get_IsFromEnd()) ? end.get_Value() : (length - end.get_Value());
  if ((UInt32)num2 > (UInt32)length || (UInt32)num > (UInt32)num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length);
  }
  return {num, num2 - num};
}

} // namespace System::Private::CoreLib::System::RangeNamespace
