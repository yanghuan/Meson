#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Attribute)
FORWARDS(Boolean)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(MemberInfo)
FORWARD(Module)
FORWARD(ParameterInfo)
namespace CustomAttributeExtensionsNamespace {
using namespace Collections::Generic;
class CustomAttributeExtensions : public Object::in {
  public: static Attribute GetCustomAttribute(Assembly element, Type attributeType);
  public: static Attribute GetCustomAttribute(Module element, Type attributeType);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType);
  public: template <class T>
  static T GetCustomAttribute(Assembly element);
  public: template <class T>
  static T GetCustomAttribute(Module element);
  public: template <class T>
  static T GetCustomAttribute(MemberInfo element);
  public: template <class T>
  static T GetCustomAttribute(ParameterInfo element);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType, Boolean inherit);
  public: template <class T>
  static T GetCustomAttribute(MemberInfo element, Boolean inherit);
  public: template <class T>
  static T GetCustomAttribute(ParameterInfo element, Boolean inherit);
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
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(Assembly element);
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(Module element);
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(MemberInfo element);
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(ParameterInfo element);
  public: static IEnumerable<Attribute> GetCustomAttributes(MemberInfo element, Type attributeType, Boolean inherit);
  public: static IEnumerable<Attribute> GetCustomAttributes(ParameterInfo element, Type attributeType, Boolean inherit);
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(MemberInfo element, Boolean inherit);
  public: template <class T>
  static IEnumerable<T> GetCustomAttributes(ParameterInfo element, Boolean inherit);
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
