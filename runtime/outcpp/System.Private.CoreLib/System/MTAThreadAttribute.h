#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace MTAThreadAttributeNamespace {
CLASS(MTAThreadAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace MTAThreadAttributeNamespace
using MTAThreadAttribute = MTAThreadAttributeNamespace::MTAThreadAttribute;
} // namespace System::Private::CoreLib::System
