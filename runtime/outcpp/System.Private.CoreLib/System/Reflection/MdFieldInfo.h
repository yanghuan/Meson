#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(RuntimeFieldHandle)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
FORWARDS(TypedReference)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class FieldAttributes;
FORWARD(RuntimeModule)
enum class BindingFlags;
FORWARD(Binder)
namespace MdFieldInfoNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(MdFieldInfo) {
  public: String get_Name();
  public: Int32 get_MetadataToken();
  public: RuntimeFieldHandle get_FieldHandle();
  public: FieldAttributes get_Attributes();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Type get_FieldType();
  public: Boolean CacheEquals(Object o);
  public: RuntimeModule GetRuntimeModule();
  public: Object GetValueDirect(TypedReference obj);
  public: void SetValueDirect(TypedReference obj, Object value);
  public: Object GetValue(Object obj);
  public: Object GetRawConstantValue();
  private: Object GetValue(Boolean raw);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture);
  public: Array<Type> GetRequiredCustomModifiers();
  public: Array<Type> GetOptionalCustomModifiers();
  private: Int32 m_tkField;
  private: String m_name;
  private: RuntimeType m_fieldType;
  private: FieldAttributes m_fieldAttributes;
};
} // namespace MdFieldInfoNamespace
using MdFieldInfo = MdFieldInfoNamespace::MdFieldInfo;
} // namespace System::Private::CoreLib::System::Reflection
