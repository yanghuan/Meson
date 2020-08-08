#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IConnectionPoint)
FORWARD(IEnumConnectionPoints)
namespace IConnectionPointContainerNamespace {
CLASS(IConnectionPointContainer) : public Object::in {
  public: void EnumConnectionPoints(IEnumConnectionPoints& ppEnum);
  public: void FindConnectionPoint(Guid& riid, IConnectionPoint& ppCP);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IConnectionPointContainerNamespace
using IConnectionPointContainer = IConnectionPointContainerNamespace::IConnectionPointContainer;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
