#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IMoniker)
namespace IEnumMonikerNamespace {
CLASS(IEnumMoniker) {
  public: Int32 Next(Int32 celt, Array<IMoniker> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumMoniker& ppenum);
};
} // namespace IEnumMonikerNamespace
using IEnumMoniker = IEnumMonikerNamespace::IEnumMoniker;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
