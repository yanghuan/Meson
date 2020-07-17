#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(ConstructorInfo)
FORWARD(FieldInfo)
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(BinaryWriter)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
namespace CustomAttributeBuilderNamespace {
using namespace IO;
CLASS(CustomAttributeBuilder) {
  public: void Ctor(ConstructorInfo con, Array<Object> constructorArgs);
  public: void Ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<PropertyInfo> namedProperties, Array<Object> propertyValues);
  public: void Ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<FieldInfo> namedFields, Array<Object> fieldValues);
  public: void Ctor(ConstructorInfo con, Array<Object> constructorArgs, Array<PropertyInfo> namedProperties, Array<Object> propertyValues, Array<FieldInfo> namedFields, Array<Object> fieldValues);
  private: Boolean ValidateType(Type t);
  private: static void VerifyTypeAndPassedObjectType(Type type, Type passedType, String paramName);
  private: static void EmitType(BinaryWriter writer, Type type);
  private: static void EmitString(BinaryWriter writer, String str);
  private: static void EmitValue(BinaryWriter writer, Type type, Object value);
  public: void CreateCustomAttribute(ModuleBuilder mod, Int32 tkOwner);
  public: void CreateCustomAttribute(ModuleBuilder mod, Int32 tkOwner, Int32 tkAttrib, Boolean toDisk);
  public: ConstructorInfo m_con;
  private: Array<Object> m_constructorArgs;
  private: Array<Byte> m_blob;
};
} // namespace CustomAttributeBuilderNamespace
using CustomAttributeBuilder = CustomAttributeBuilderNamespace::CustomAttributeBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
