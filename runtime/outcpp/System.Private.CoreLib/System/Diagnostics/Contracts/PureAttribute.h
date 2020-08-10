#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace PureAttributeNamespace {
CLASS(PureAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace PureAttributeNamespace
using PureAttribute = PureAttributeNamespace::PureAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
