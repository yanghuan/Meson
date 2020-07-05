#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Index.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
namespace RangeNamespace {
struct Range {
  public: Index get_Start() { return Start; }
  public: Index get_End() { return End; }
  public: static Range get_All();
  public: Boolean Equals(Object value);
  public: Boolean Equals(Range other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Range StartAt(Index start);
  public: static Range EndAt(Index end);
  public: ValueTuple<> GetOffsetAndLength(Int32 length);
  private: Index Start;
  private: Index End;
};
} // namespace RangeNamespace
using Range = RangeNamespace::Range;
} // namespace System::Private::CoreLib::System
