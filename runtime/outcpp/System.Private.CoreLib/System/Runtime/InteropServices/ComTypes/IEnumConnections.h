#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(CONNECTDATA)
namespace IEnumConnectionsNamespace {
CLASS(IEnumConnections) {
  public: Int32 Next(Int32 celt, Array<CONNECTDATA> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumConnections& ppenum);
};
} // namespace IEnumConnectionsNamespace
using IEnumConnections = IEnumConnectionsNamespace::IEnumConnections;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
