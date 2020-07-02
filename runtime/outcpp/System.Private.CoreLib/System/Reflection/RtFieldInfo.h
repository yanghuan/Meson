#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeFieldHandleInternal)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
FORWARDS(TypedReference)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class INVOCATION_FLAGS : uint32_t;
enum class FieldAttributes;
FORWARD(RuntimeModule)
enum class BindingFlags;
FORWARD(Binder)
namespace RtFieldInfoNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(RtFieldInfo) {
  public: INVOCATION_FLAGS get_InvocationFlags();
  private: RuntimeFieldHandleInternal get_ValueOfIRuntimeFieldInfo();
  public: String get_Name();
  public: Int32 get_MetadataToken();
  public: RuntimeFieldHandle get_FieldHandle();
  public: FieldAttributes get_Attributes();
  public: Type get_FieldType();
  private: INVOCATION_FLAGS InitializeInvocationFlags();
  public: void CheckConsistency(Object target);
  public: Boolean CacheEquals(Object o);
  public: RuntimeModule GetRuntimeModule();
  public: Object GetValue(Object obj);
  public: Object GetRawConstantValue();
  public: Object GetValueDirect(TypedReference obj);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture);
  public: void SetValueDirect(TypedReference obj, Object value);
  public: IntPtr GetFieldHandle();
  private: RuntimeType InitializeFieldType();
  public: Array<Type> GetRequiredCustomModifiers();
  public: Array<Type> GetOptionalCustomModifiers();
  private: IntPtr m_fieldHandle;
  private: FieldAttributes m_fieldAttributes;
  private: String m_name;
  private: RuntimeType m_fieldType;
  private: INVOCATION_FLAGS m_invocationFlags;
};
} // namespace RtFieldInfoNamespace
using RtFieldInfo = RtFieldInfoNamespace::RtFieldInfo;
} // namespace System::Private::CoreLib::System::Reflection