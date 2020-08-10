#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringFreezingAttributeNamespace {
CLASS(StringFreezingAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace StringFreezingAttributeNamespace
using StringFreezingAttribute = StringFreezingAttributeNamespace::StringFreezingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
