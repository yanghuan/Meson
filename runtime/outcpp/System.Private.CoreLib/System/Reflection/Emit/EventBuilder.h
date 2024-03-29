#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EventToken.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class EventAttributes : int32_t;
enum class MethodSemanticsAttributes : int32_t;
FORWARD(ConstructorInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(MethodBuilder)
FORWARD(ModuleBuilder)
FORWARD(TypeBuilder)
namespace EventBuilderNamespace {
CLASS(EventBuilder) : public object {
  public: void ctor(ModuleBuilder mod, String name, EventAttributes attr, TypeBuilder type, EventToken evToken);
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
