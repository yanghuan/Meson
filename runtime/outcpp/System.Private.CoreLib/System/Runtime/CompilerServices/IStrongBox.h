#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IStrongBoxNamespace {
CLASS(IStrongBox) : public Object::in {
  public: Object get_Value();
  public: void set_Value(Object value);
};
} // namespace IStrongBoxNamespace
using IStrongBox = IStrongBoxNamespace::IStrongBox;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
