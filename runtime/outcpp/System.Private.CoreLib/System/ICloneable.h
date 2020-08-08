#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace ICloneableNamespace {
CLASS(ICloneable) : public Object::in {
  public: Object Clone();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICloneableNamespace
using ICloneable = ICloneableNamespace::ICloneable;
} // namespace System::Private::CoreLib::System
