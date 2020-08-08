#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CustomQueryInterfaceResult;
namespace ICustomQueryInterfaceNamespace {
CLASS(ICustomQueryInterface) : public Object::in {
  public: CustomQueryInterfaceResult GetInterface(Guid& iid, IntPtr& ppv);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomQueryInterfaceNamespace
using ICustomQueryInterface = ICustomQueryInterfaceNamespace::ICustomQueryInterface;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
