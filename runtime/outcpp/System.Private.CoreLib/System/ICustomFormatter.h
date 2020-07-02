#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Object)
FORWARD(IFormatProvider)
namespace ICustomFormatterNamespace {
CLASS(ICustomFormatter) {
  public: String Format(String format, Object arg, IFormatProvider formatProvider);
};
} // namespace ICustomFormatterNamespace
using ICustomFormatter = ICustomFormatterNamespace::ICustomFormatter;
} // namespace System::Private::CoreLib::System
