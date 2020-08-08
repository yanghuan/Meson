#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(CONNECTDATA)
namespace IEnumConnectionsNamespace {
CLASS(IEnumConnections) : public Object::in {
  public: Int32 Next(Int32 celt, Array<CONNECTDATA> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumConnections& ppenum);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEnumConnectionsNamespace
using IEnumConnections = IEnumConnectionsNamespace::IEnumConnections;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
