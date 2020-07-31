#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARD(IConnectionPointContainer)
FORWARD(IEnumConnections)
namespace IConnectionPointNamespace {
CLASS(IConnectionPoint) : public Object::in {
  public: void GetConnectionInterface(Guid& pIID);
  public: void GetConnectionPointContainer(IConnectionPointContainer& ppCPC);
  public: void Advise(Object pUnkSink, Int32& pdwCookie);
  public: void Unadvise(Int32 dwCookie);
  public: void EnumConnections(IEnumConnections& ppEnum);
};
} // namespace IConnectionPointNamespace
using IConnectionPoint = IConnectionPointNamespace::IConnectionPoint;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
