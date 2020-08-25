#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ICustomAdapterNamespace {
CLASS(ICustomAdapter) : public object {
  public: Object GetUnderlyingObject();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomAdapterNamespace
using ICustomAdapter = ICustomAdapterNamespace::ICustomAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
