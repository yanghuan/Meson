#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(Attribute)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(Module)
FORWARD(MemberInfo)
FORWARD(ParameterInfo)
namespace CustomAttributeExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
class CustomAttributeExtensions {
  public: static Attribute GetCustomAttribute(Assembly element, Type attributeType);
  public: static Attribute GetCustomAttribute(Module element, Type attributeType);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType, Boolean inherit);
  public: static IEnumerable<Attribute> GetCustomAttributes(Assembly element);
  public: static IEnumerable<Attribute> GetCustomAttributes(Module element);
  public: static IEnumerable<Attribute> GetCustomAttributes(MemberInfo element);
  public: static IEnumerable<Attribute> GetCustomAttributes(ParameterInfo element);
  public: static IEnumerable<Attribute> GetCustomAttributes(MemberInfo element, Boolean inherit);
  public: static IEnumerable<Attribute> GetCustomAttributes(ParameterInfo element, Boolean inherit);
  public: static IEnumerable<Attribute> GetCustomAttributes(Assembly element, Type attributeType);
  public: static IEnumerable<Attribute> GetCustomAttributes(Module element, Type attributeType);
  public: static IEnumerable<Attribute> GetCustomAttributes(MemberInfo element, Type attributeType);
  public: static IEnumerable<Attribute> GetCustomAttributes(ParameterInfo element, Type attributeType);
  public: static IEnumerable<Attribute> GetCustomAttributes(MemberInfo element, Type attributeType, Boolean inherit);
  public: static IEnumerable<Attribute> GetCustomAttributes(ParameterInfo element, Type attributeType, Boolean inherit);
  public: static Boolean IsDefined(Assembly element, Type attributeType);
  public: static Boolean IsDefined(Module element, Type attributeType);
  public: static Boolean IsDefined(MemberInfo element, Type attributeType);
  public: static Boolean IsDefined(ParameterInfo element, Type attributeType);
  public: static Boolean IsDefined(MemberInfo element, Type attributeType, Boolean inherit);
  public: static Boolean IsDefined(ParameterInfo element, Type attributeType, Boolean inherit);
};
} // namespace CustomAttributeExtensionsNamespace
using CustomAttributeExtensions = CustomAttributeExtensionsNamespace::CustomAttributeExtensions;
} // namespace System::Private::CoreLib::System::Reflection
