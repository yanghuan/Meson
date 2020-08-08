#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IFormatProvider)
FORWARD(String)
namespace IFormattableNamespace {
CLASS(IFormattable) : public Object::in {
  public: String ToString(String format, IFormatProvider formatProvider);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IFormattableNamespace
using IFormattable = IFormattableNamespace::IFormattable;
} // namespace System::Private::CoreLib::System
