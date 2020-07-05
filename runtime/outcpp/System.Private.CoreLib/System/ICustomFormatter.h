#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(IFormatProvider)
FORWARD(Object)
FORWARD(String)
namespace ICustomFormatterNamespace {
CLASS(ICustomFormatter) {
  public: String Format(String format, Object arg, IFormatProvider formatProvider);
};
} // namespace ICustomFormatterNamespace
using ICustomFormatter = ICustomFormatterNamespace::ICustomFormatter;
} // namespace System::Private::CoreLib::System
