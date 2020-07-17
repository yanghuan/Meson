#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
namespace PureAttributeNamespace {
CLASS(PureAttribute) {
  public: void Ctor();
};
} // namespace PureAttributeNamespace
using PureAttribute = PureAttributeNamespace::PureAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
