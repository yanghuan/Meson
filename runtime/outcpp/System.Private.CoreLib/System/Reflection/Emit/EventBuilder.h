#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EventToken.h>

namespace System::Private::CoreLib::System::Reflection {
enum class MethodSemanticsAttributes;
FORWARD(ConstructorInfo)
enum class EventAttributes;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(MethodBuilder)
FORWARD(CustomAttributeBuilder)
FORWARD(ModuleBuilder)
FORWARD(TypeBuilder)
namespace EventBuilderNamespace {
CLASS(EventBuilder) {
  public: EventToken GetEventToken();
  private: void SetMethodSemantics(MethodBuilder mdBuilder, MethodSemanticsAttributes semantics);
  public: void SetAddOnMethod(MethodBuilder mdBuilder);
  public: void SetRemoveOnMethod(MethodBuilder mdBuilder);
  public: void SetRaiseMethod(MethodBuilder mdBuilder);
  public: void AddOtherMethod(MethodBuilder mdBuilder);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  private: String m_name;
  private: EventToken m_evToken;
  private: ModuleBuilder m_module;
  private: EventAttributes m_attributes;
  private: TypeBuilder m_type;
};
} // namespace EventBuilderNamespace
using EventBuilder = EventBuilderNamespace::EventBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
