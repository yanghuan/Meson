#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(Object)
namespace IFormatProviderNamespace {
CLASS(IFormatProvider) {
  public: Object GetFormat(Type formatType);
};
} // namespace IFormatProviderNamespace
using IFormatProvider = IFormatProviderNamespace::IFormatProvider;
} // namespace System::Private::CoreLib::System
