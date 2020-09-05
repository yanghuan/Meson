#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(TypeInfo)
namespace ReflectionContextNamespace {
CLASS(ReflectionContext) : public object {
  public: void ctor();
  public: Assembly MapAssembly(Assembly assembly);
  public: TypeInfo MapType(TypeInfo type);
  public: TypeInfo GetTypeForObject(Object value);
};
} // namespace ReflectionContextNamespace
using ReflectionContext = ReflectionContextNamespace::ReflectionContext;
} // namespace System::Private::CoreLib::System::Reflection
