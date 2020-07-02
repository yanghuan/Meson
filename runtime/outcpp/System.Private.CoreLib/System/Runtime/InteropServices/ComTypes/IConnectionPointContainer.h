#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IEnumConnectionPoints)
FORWARD(IConnectionPoint)
namespace IConnectionPointContainerNamespace {
CLASS(IConnectionPointContainer) {
  public: void EnumConnectionPoints(IEnumConnectionPoints& ppEnum);
  public: void FindConnectionPoint(Guid& riid, IConnectionPoint& ppCP);
};
} // namespace IConnectionPointContainerNamespace
using IConnectionPointContainer = IConnectionPointContainerNamespace::IConnectionPointContainer;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
