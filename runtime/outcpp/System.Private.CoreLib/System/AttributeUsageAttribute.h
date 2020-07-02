#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
enum class AttributeTargets;
namespace AttributeUsageAttributeNamespace {
CLASS(AttributeUsageAttribute) {
  public: AttributeTargets get_ValidOn();
  public: Boolean get_AllowMultiple();
  public: void set_AllowMultiple(Boolean value);
  public: Boolean get_Inherited();
  public: void set_Inherited(Boolean value);
  private: AttributeTargets _attributeTarget;
  private: Boolean _allowMultiple;
  private: Boolean _inherited;
  public: static AttributeUsageAttribute Default;
};
} // namespace AttributeUsageAttributeNamespace
using AttributeUsageAttribute = AttributeUsageAttributeNamespace::AttributeUsageAttribute;
} // namespace System::Private::CoreLib::System
