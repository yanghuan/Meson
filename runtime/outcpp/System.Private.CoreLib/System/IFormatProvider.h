#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
namespace IFormatProviderNamespace {
CLASS(IFormatProvider) : public object {
  public: Object GetFormat(Type formatType);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IFormatProviderNamespace
using IFormatProvider = IFormatProviderNamespace::IFormatProvider;
} // namespace System::Private::CoreLib::System
