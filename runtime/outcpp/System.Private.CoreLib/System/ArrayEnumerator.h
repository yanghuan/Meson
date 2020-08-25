#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(ICloneable)
namespace ArrayEnumeratorNamespace {
using namespace System::Collections;
CLASS(ArrayEnumerator) : public object {
  public: using interface = rt::TypeList<IEnumerator, ICloneable>;
  public: Object get_Current();
  public: void ctor(Array<> array, Int32 index, Int32 count);
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
