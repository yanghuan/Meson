#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
FORWARD(MethodInfo)
FORWARD(PropertyInfo)
FORWARD(EventInfo)
FORWARD(TypeInfo)
FORWARDS(InterfaceMapping)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Runtime::System::Reflection {
namespace RuntimeReflectionExtensionsNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Reflection;
class RuntimeReflectionExtensions {
  public: static IEnumerable<FieldInfo> GetRuntimeFields(Type type);
  public: static IEnumerable<MethodInfo> GetRuntimeMethods(Type type);
  public: static IEnumerable<PropertyInfo> GetRuntimeProperties(Type type);
  public: static IEnumerable<EventInfo> GetRuntimeEvents(Type type);
  public: static FieldInfo GetRuntimeField(Type type, String name);
  public: static MethodInfo GetRuntimeMethod(Type type, String name, Array<Type> parameters);
  public: static PropertyInfo GetRuntimeProperty(Type type, String name);
  public: static EventInfo GetRuntimeEvent(Type type, String name);
  public: static MethodInfo GetRuntimeBaseDefinition(MethodInfo method);
  public: static InterfaceMapping GetRuntimeInterfaceMap(TypeInfo typeInfo, Type interfaceType);
  public: static MethodInfo GetMethodInfo(Delegate del);
};
} // namespace RuntimeReflectionExtensionsNamespace
using RuntimeReflectionExtensions = RuntimeReflectionExtensionsNamespace::RuntimeReflectionExtensions;
} // namespace System::Runtime::System::Reflection
