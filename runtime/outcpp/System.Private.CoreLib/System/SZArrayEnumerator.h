#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
namespace SZArrayEnumeratorNamespace {
CLASS(SZArrayEnumerator) {
  public: Object get_Current();
  public: Object Clone();
  public: Boolean MoveNext();
  public: void Reset();
  private: Array<> _array;
  private: Int32 _index;
  private: Int32 _endIndex;
};
} // namespace SZArrayEnumeratorNamespace
using SZArrayEnumerator = SZArrayEnumeratorNamespace::SZArrayEnumerator;
} // namespace System::Private::CoreLib::System
