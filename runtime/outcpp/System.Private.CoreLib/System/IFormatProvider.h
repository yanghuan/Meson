#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
namespace IFormatProviderNamespace {
CLASS(IFormatProvider) : public Object::in {
  public: Object GetFormat(Type formatType);
};
} // namespace IFormatProviderNamespace
using IFormatProvider = IFormatProviderNamespace::IFormatProvider;
} // namespace System::Private::CoreLib::System
