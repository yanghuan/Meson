#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IEnumVARIANT)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ICustomAdapter)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace EnumVariantViewOfEnumeratorNamespace {
using namespace System::Collections;
using namespace System::Runtime::InteropServices::ComTypes;
using IEnumerator = Collections::IEnumerator;
CLASS(EnumVariantViewOfEnumerator) : public object {
  public: using interface = rt::TypeList<IEnumVARIANT, ICustomAdapter>;
  public: IEnumerator get_Enumerator() { return Enumerator; }
  public: void ctor(IEnumerator enumerator);
  public: IEnumVARIANT Clone();
  public: Int32 Next(Int32 celt, Array<Object> rgVar, IntPtr pceltFetched);
  public: Int32 Reset();
  public: Int32 Skip(Int32 celt);
  public: Object GetUnderlyingObject();
  private: IEnumerator Enumerator;
};
} // namespace EnumVariantViewOfEnumeratorNamespace
using EnumVariantViewOfEnumerator = EnumVariantViewOfEnumeratorNamespace::EnumVariantViewOfEnumerator;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
