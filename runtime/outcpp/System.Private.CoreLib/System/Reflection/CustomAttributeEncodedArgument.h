#pragma once

#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeType.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(ConstArray)
FORWARDS(CustomAttributeCtorParameter)
FORWARDS(CustomAttributeNamedParameter)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeModule)
namespace CustomAttributeEncodedArgumentNamespace {
struct CustomAttributeEncodedArgument : public valueType<CustomAttributeEncodedArgument> {
  public: CustomAttributeType get_CustomAttributeType();
  public: Int64 get_PrimitiveValue();
  public: Array<CustomAttributeEncodedArgument> get_ArrayValue();
  public: String get_StringValue();
  private: static void ParseAttributeArguments(IntPtr pCa, Int32 cCa, Array<CustomAttributeCtorParameter>& CustomAttributeCtorParameters, Array<CustomAttributeNamedParameter>& CustomAttributeTypedArgument, RuntimeAssembly assembly);
  public: static void ParseAttributeArguments(ConstArray attributeBlob, Array<CustomAttributeCtorParameter>& customAttributeCtorParameters, Array<CustomAttributeNamedParameter>& customAttributeNamedParameters, RuntimeModule customAttributeModule);
  private: Int64 m_primitiveValue;
  private: Array<CustomAttributeEncodedArgument> m_arrayValue;
  private: String m_stringValue;
  private: CustomAttributeType m_type;
};
} // namespace CustomAttributeEncodedArgumentNamespace
using CustomAttributeEncodedArgument = CustomAttributeEncodedArgumentNamespace::CustomAttributeEncodedArgument;
} // namespace System::Private::CoreLib::System::Reflection
