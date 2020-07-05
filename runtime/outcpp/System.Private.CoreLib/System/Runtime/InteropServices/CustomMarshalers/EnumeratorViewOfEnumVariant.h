#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IEnumVARIANT)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumeratorViewOfEnumVariantNamespace {
using namespace ComTypes;
CLASS(EnumeratorViewOfEnumVariant) {
  public: Object get_Current();
  public: Boolean MoveNext();
  public: void Reset();
  public: Object GetUnderlyingObject();
  private: IEnumVARIANT _enumVariantObject;
  private: Boolean _fetchedLastObject;
  private: Array<Object> _nextArray;
  private: Object _current;
};
} // namespace EnumeratorViewOfEnumVariantNamespace
using EnumeratorViewOfEnumVariant = EnumeratorViewOfEnumVariantNamespace::EnumeratorViewOfEnumVariant;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
