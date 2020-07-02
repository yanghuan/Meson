#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Array, T1, T2)
namespace ArrayEnumeratorNamespace {
CLASS(ArrayEnumerator) {
  public: Object get_Current();
  private: void IncArray();
  public: Object Clone();
  public: Boolean MoveNext();
  public: void Reset();
  private: Array<> array;
  private: Int32 index;
  private: Int32 endIndex;
  private: Int32 startIndex;
  private: Array<Int32> _indices;
  private: Boolean _complete;
};
} // namespace ArrayEnumeratorNamespace
using ArrayEnumerator = ArrayEnumeratorNamespace::ArrayEnumerator;
} // namespace System::Private::CoreLib::System