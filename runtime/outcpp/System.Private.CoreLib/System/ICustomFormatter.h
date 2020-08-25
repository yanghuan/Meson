#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IFormatProvider)
FORWARD(String)
namespace ICustomFormatterNamespace {
CLASS(ICustomFormatter) : public object {
  public: String Format(String format, Object arg, IFormatProvider formatProvider);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICustomFormatterNamespace
using ICustomFormatter = ICustomFormatterNamespace::ICustomFormatter;
} // namespace System::Private::CoreLib::System
