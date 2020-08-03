#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
namespace SZArrayEnumeratorNamespace {
CLASS(SZArrayEnumerator) : public Object::in {
  public: Object get_Current();
  public: void Ctor(Array<> array);
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
