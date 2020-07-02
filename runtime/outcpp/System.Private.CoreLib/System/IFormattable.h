#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(IFormatProvider)
namespace IFormattableNamespace {
CLASS(IFormattable) {
  public: String ToString(String format, IFormatProvider formatProvider);
};
} // namespace IFormattableNamespace
using IFormattable = IFormattableNamespace::IFormattable;
} // namespace System::Private::CoreLib::System
