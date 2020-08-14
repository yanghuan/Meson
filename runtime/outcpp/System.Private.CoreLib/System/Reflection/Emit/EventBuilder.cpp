#include "EventBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::EventBuilderNamespace {
using namespace System::Runtime::CompilerServices;

void EventBuilder___::ctor(ModuleBuilder mod, String name, EventAttributes attr, TypeBuilder type, EventToken evToken) {
  m_name = name;
  m_module = mod;
  m_attributes = attr;
  m_evToken = evToken;
  m_type = type;
}

EventToken EventBuilder___::GetEventToken() {
  return m_evToken;
}

void EventBuilder___::SetMethodSemantics(MethodBuilder mdBuilder, MethodSemanticsAttributes semantics) {
  if (mdBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("mdBuilder");
  }
  m_type->ThrowIfCreated();
  ModuleBuilder module = m_module;
  TypeBuilder::in::DefineMethodSemantics(QCallModule(module), m_evToken.get_Token(), semantics, mdBuilder->GetToken().get_Token());
}

void EventBuilder___::SetAddOnMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::AddOn);
}

void EventBuilder___::SetRemoveOnMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::RemoveOn);
}

void EventBuilder___::SetRaiseMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::Fire);
}

void EventBuilder___::AddOtherMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::Other);
}

void EventBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  m_type->ThrowIfCreated();
  TypeBuilder::in::DefineCustomAttribute(m_module, m_evToken.get_Token(), m_module->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void EventBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  m_type->ThrowIfCreated();
  customBuilder->CreateCustomAttribute(m_module, m_evToken.get_Token());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::EventBuilderNamespace
