#pragma once

#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Attribute)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(DllImportAttribute)
FORWARD(FieldOffsetAttribute)
FORWARD(MarshalAsAttribute)
FORWARD(StructLayoutAttribute)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimeParameterInfo)
namespace PseudoCustomAttributeNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
class PseudoCustomAttribute {
  private: static Dictionary<RuntimeType, RuntimeType> CreatePseudoCustomAttributeDictionary();
  public: static void GetCustomAttributes(RuntimeType type, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas);
  public: static Boolean IsDefined(RuntimeType type, RuntimeType caType);
  public: static void GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas);
  public: static Boolean IsDefined(RuntimeMethodInfo method, RuntimeType caType);
  public: static void GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas);
  public: static Boolean IsDefined(RuntimeParameterInfo parameter, RuntimeType caType);
  public: static void GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas);
  public: static Boolean IsDefined(RuntimeFieldInfo field, RuntimeType caType);
  private: static DllImportAttribute GetDllImportCustomAttribute(RuntimeMethodInfo method);
  private: static MarshalAsAttribute GetMarshalAsCustomAttribute(RuntimeParameterInfo parameter);
  private: static MarshalAsAttribute GetMarshalAsCustomAttribute(RuntimeFieldInfo field);
  private: static MarshalAsAttribute GetMarshalAsCustomAttribute(Int32 token, RuntimeModule scope);
  private: static FieldOffsetAttribute GetFieldOffsetCustomAttribute(RuntimeFieldInfo field);
  public: static StructLayoutAttribute GetStructLayoutCustomAttribute(RuntimeType type);
  public: static void cctor();
  private: static Dictionary<RuntimeType, RuntimeType> s_pca;
};
} // namespace PseudoCustomAttributeNamespace
using PseudoCustomAttribute = PseudoCustomAttributeNamespace::PseudoCustomAttribute;
} // namespace System::Private::CoreLib::System::Reflection
