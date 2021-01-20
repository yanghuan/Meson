#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(EventInfo)
FORWARD(MemberInfo)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(AttributeUsageAttribute)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Type)
namespace AttributeNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;
CLASS(Attribute) : public object {
  public: Object get_TypeId();
  private: static Array<Attribute> InternalGetCustomAttributes(PropertyInfo element, Type type, Boolean inherit);
  private: static Boolean InternalIsDefined(PropertyInfo element, Type attributeType, Boolean inherit);
  private: static PropertyInfo GetParentDefinition(PropertyInfo property, Array<Type> propertyParameters);
  private: static Array<Attribute> InternalGetCustomAttributes(EventInfo element, Type type, Boolean inherit);
  private: static EventInfo GetParentDefinition(EventInfo ev);
  private: static Boolean InternalIsDefined(EventInfo element, Type attributeType, Boolean inherit);
  private: static ParameterInfo GetParentDefinition(ParameterInfo param);
  private: static Array<Attribute> InternalParamGetCustomAttributes(ParameterInfo param, Type type, Boolean inherit);
  private: static Boolean InternalParamIsDefined(ParameterInfo param, Type type, Boolean inherit);
  private: static void CopyToArrayList(List<Attribute> attributeList, Array<Attribute> attributes, Dictionary<Type, AttributeUsageAttribute> types);
  private: static Array<Type> GetIndexParameterTypes(PropertyInfo element);
  private: static void AddAttributesToList(List<Attribute> attributeList, Array<Attribute> attributes, Dictionary<Type, AttributeUsageAttribute> types);
  private: static AttributeUsageAttribute InternalGetAttributeUsage(Type type);
  private: static Array<Attribute> CreateAttributeArrayHelper(Type elementType, Int32 elementCount);
  public: static Array<Attribute> GetCustomAttributes(MemberInfo element, Type type);
  public: static Array<Attribute> GetCustomAttributes(MemberInfo element, Type type, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(MemberInfo element);
  public: static Array<Attribute> GetCustomAttributes(MemberInfo element, Boolean inherit);
  public: static Boolean IsDefined(MemberInfo element, Type attributeType);
  public: static Boolean IsDefined(MemberInfo element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType);
  public: static Attribute GetCustomAttribute(MemberInfo element, Type attributeType, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(ParameterInfo element);
  public: static Array<Attribute> GetCustomAttributes(ParameterInfo element, Type attributeType);
  public: static Array<Attribute> GetCustomAttributes(ParameterInfo element, Type attributeType, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(ParameterInfo element, Boolean inherit);
  public: static Boolean IsDefined(ParameterInfo element, Type attributeType);
  public: static Boolean IsDefined(ParameterInfo element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType);
  public: static Attribute GetCustomAttribute(ParameterInfo element, Type attributeType, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(Module element, Type attributeType);
  public: static Array<Attribute> GetCustomAttributes(Module element);
  public: static Array<Attribute> GetCustomAttributes(Module element, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(Module element, Type attributeType, Boolean inherit);
  public: static Boolean IsDefined(Module element, Type attributeType);
  public: static Boolean IsDefined(Module element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(Module element, Type attributeType);
  public: static Attribute GetCustomAttribute(Module element, Type attributeType, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(Assembly element, Type attributeType);
  public: static Array<Attribute> GetCustomAttributes(Assembly element, Type attributeType, Boolean inherit);
  public: static Array<Attribute> GetCustomAttributes(Assembly element);
  public: static Array<Attribute> GetCustomAttributes(Assembly element, Boolean inherit);
  public: static Boolean IsDefined(Assembly element, Type attributeType);
  public: static Boolean IsDefined(Assembly element, Type attributeType, Boolean inherit);
  public: static Attribute GetCustomAttribute(Assembly element, Type attributeType);
  public: static Attribute GetCustomAttribute(Assembly element, Type attributeType, Boolean inherit);
  public: void ctor();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  private: static Boolean AreFieldValuesEqual(Object thisValue, Object thatValue);
  public: Boolean Match(Object obj);
  public: Boolean IsDefaultAttribute();
};
} // namespace AttributeNamespace
using Attribute = AttributeNamespace::Attribute;
} // namespace System::Private::CoreLib::System
