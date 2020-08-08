#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace MissingNamespace {
using namespace Runtime::Serialization;
CLASS(Missing) : public Object::in {
  using interface = rt::TypeList<ISerializable>;
  private: void Ctor();
  private: static void SCtor();
  public: static Missing Value;
};
} // namespace MissingNamespace
using Missing = MissingNamespace::Missing;
} // namespace System::Private::CoreLib::System::Reflection
