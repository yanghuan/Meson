#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IStrongBoxNamespace {
CLASS(IStrongBox) : public Object::in {
  public: Object get_Value();
  public: void set_Value(Object value);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IStrongBoxNamespace
using IStrongBox = IStrongBoxNamespace::IStrongBox;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
