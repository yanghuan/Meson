#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(TypeInfo)
namespace ReflectionContextNamespace {
CLASS(ReflectionContext) {
  protected: void Ctor();
  public: Assembly MapAssembly(Assembly assembly);
  public: TypeInfo MapType(TypeInfo type);
  public: TypeInfo GetTypeForObject(Object value);
};
} // namespace ReflectionContextNamespace
using ReflectionContext = ReflectionContextNamespace::ReflectionContext;
} // namespace System::Private::CoreLib::System::Reflection
