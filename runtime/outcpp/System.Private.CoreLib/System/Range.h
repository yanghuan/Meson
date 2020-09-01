#pragma once

#include <System.Private.CoreLib/System/Index.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
namespace RangeNamespace {
struct Range : public valueType<Range> {
  public: using interface = rt::TypeList<IEquatable<Range>>;
  public: Index get_Start() { return Start; }
  public: Index get_End() { return End; }
  public: static Range get_All();
  public: explicit Range(Index start, Index end);
  public: Boolean Equals(Object value);
  public: Boolean Equals(Range other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Range StartAt(Index start);
  public: static Range EndAt(Index end);
  public: ValueTuple<Int32, Int32> GetOffsetAndLength(Int32 length);
  public: explicit Range() {}
  private: Index Start;
  private: Index End;
};
} // namespace RangeNamespace
using Range = RangeNamespace::Range;
} // namespace System::Private::CoreLib::System
