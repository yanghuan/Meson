#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IConnectionPoint)
namespace IEnumConnectionPointsNamespace {
CLASS(IEnumConnectionPoints) : public Object::in {
  public: Int32 Next(Int32 celt, Array<IConnectionPoint> rgelt, IntPtr pceltFetched);
  public: Int32 Skip(Int32 celt);
  public: void Reset();
  public: void Clone(IEnumConnectionPoints& ppenum);
};
} // namespace IEnumConnectionPointsNamespace
using IEnumConnectionPoints = IEnumConnectionPointsNamespace::IEnumConnectionPoints;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
