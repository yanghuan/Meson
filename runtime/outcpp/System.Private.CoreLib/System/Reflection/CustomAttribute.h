#pragma once

#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
enum class AttributeTargets : int32_t;
FORWARD_(Array)
FORWARD(AttributeUsageAttribute)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeMethodInfo)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(ConstArray)
FORWARDS(MetadataImport)
FORWARDS(MetadataToken)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeEventInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimeParameterInfo)
FORWARD(RuntimePropertyInfo)
namespace CustomAttributeNamespace {
class CustomAttribute {
  public: static Boolean IsDefined(RuntimeType type, RuntimeType caType, Boolean inherit);
  public: static Boolean IsDefined(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit);
  public: static Boolean IsDefined(RuntimeConstructorInfo ctor, RuntimeType caType);
  public: static Boolean IsDefined(RuntimePropertyInfo property, RuntimeType caType);
  public: static Boolean IsDefined(RuntimeEventInfo e, RuntimeType caType);
  public: static Boolean IsDefined(RuntimeFieldInfo field, RuntimeType caType);
  public: static Boolean IsDefined(RuntimeParameterInfo parameter, RuntimeType caType);
  public: static Boolean IsDefined(RuntimeAssembly assembly, RuntimeType caType);
  public: static Boolean IsDefined(RuntimeModule module, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeType type, RuntimeType caType, Boolean inherit);
  public: static Array<Object> GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit);
  public: static Array<Object> GetCustomAttributes(RuntimeConstructorInfo ctor, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimePropertyInfo property, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeEventInfo e, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeAssembly assembly, RuntimeType caType);
  public: static Array<Object> GetCustomAttributes(RuntimeModule module, RuntimeType caType);
  private: static Boolean IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType);
  private: static Boolean IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Int32 attributeCtorToken, Boolean mustBeInheritable);
  private: static Array<Object> GetCustomAttributes(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, Int32 pcaCount, RuntimeType attributeFilterType);
  private: static void AddCustomAttributes(RuntimeType::in::ListBuilder<Object>& attributes, RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object> derivedAttributes);
  private: static Boolean FilterCustomAttributeRecord(MetadataToken caCtorToken, MetadataImport& scope, RuntimeModule decoratedModule, MetadataToken decoratedToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes, RuntimeType& attributeType, IRuntimeMethodInfo& ctorWithParameters, Boolean& isVarArg);
  private: static Boolean AttributeUsageCheck(RuntimeType attributeType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes);
  public: static AttributeUsageAttribute GetAttributeUsage(RuntimeType decoratedAttribute);
  private: static void _ParseAttributeUsageAttribute(IntPtr pCa, Int32 cCa, Int32& targets, Boolean& inherited, Boolean& allowMultiple);
  private: static void ParseAttributeUsageAttribute(ConstArray ca, AttributeTargets& targets, Boolean& inherited, Boolean& allowMultiple);
  private: static Object _CreateCaObject(RuntimeModule pModule, RuntimeType type, IRuntimeMethodInfo pCtor, Byte** ppBlob, Byte* pEndBlob, Int32* pcNamedArgs);
  private: static Object CreateCaObject(RuntimeModule module, RuntimeType type, IRuntimeMethodInfo ctor, IntPtr& blob, IntPtr blobEnd, Int32& namedArgs);
  private: static void _GetPropertyOrFieldData(RuntimeModule pModule, Byte** ppBlobStart, Byte* pBlobEnd, String& name, Boolean& bIsProperty, RuntimeType& type, Object& value);
  private: static void GetPropertyOrFieldData(RuntimeModule module, IntPtr& blobStart, IntPtr blobEnd, String& name, Boolean& isProperty, RuntimeType& type, Object& value);
  private: static Array<Object> CreateAttributeArrayHelper(RuntimeType elementType, Int32 elementCount);
  public: static void cctor();
  private: static RuntimeType Type_RuntimeType;
  private: static RuntimeType Type_Type;
};
} // namespace CustomAttributeNamespace
using CustomAttribute = CustomAttributeNamespace::CustomAttribute;
} // namespace System::Private::CoreLib::System::Reflection
