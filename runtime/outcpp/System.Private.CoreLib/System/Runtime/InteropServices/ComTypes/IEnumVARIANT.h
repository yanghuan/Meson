#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IEnumVARIANTNamespace {
CLASS(IEnumVARIANT) {
  public: Int32 Next(Int32 celt, Array<Object> rgVar, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: Int32 Reset();
  public: IEnumVARIANT Clone();
};
} // namespace IEnumVARIANTNamespace
using IEnumVARIANT = IEnumVARIANTNamespace::IEnumVARIANT;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
