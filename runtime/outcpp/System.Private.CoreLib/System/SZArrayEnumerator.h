#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(ICloneable)
namespace SZArrayEnumeratorNamespace {
using namespace System::Collections;
CLASS(SZArrayEnumerator) : public object {
  public: using interface = rt::TypeList<IEnumerator, ICloneable>;
  public: Object get_Current();
  public: void ctor(Array<> array);
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
