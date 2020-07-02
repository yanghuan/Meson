#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace IEnumStringNamespace {
CLASS(IEnumString) {
  public: Int32 Next(Int32 celt, Array<String> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumString& ppenum);
};
} // namespace IEnumStringNamespace
using IEnumString = IEnumStringNamespace::IEnumString;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
