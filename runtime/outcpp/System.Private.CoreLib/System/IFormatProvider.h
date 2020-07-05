#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Type)
namespace IFormatProviderNamespace {
CLASS(IFormatProvider) {
  public: Object GetFormat(Type formatType);
};
} // namespace IFormatProviderNamespace
using IFormatProvider = IFormatProviderNamespace::IFormatProvider;
} // namespace System::Private::CoreLib::System
