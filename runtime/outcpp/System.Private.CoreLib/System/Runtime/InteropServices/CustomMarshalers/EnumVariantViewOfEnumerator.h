#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IEnumVARIANT)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumVariantViewOfEnumeratorNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices::ComTypes;
CLASS(EnumVariantViewOfEnumerator) {
  public: IEnumVARIANT Clone();
  public: Int32 Next(Int32 celt, Array<Object> rgVar, IntPtr pceltFetched);
  public: Int32 Reset();
  public: Int32 Skip(Int32 celt);
  public: Object GetUnderlyingObject();
};
} // namespace EnumVariantViewOfEnumeratorNamespace
using EnumVariantViewOfEnumerator = EnumVariantViewOfEnumeratorNamespace::EnumVariantViewOfEnumerator;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
