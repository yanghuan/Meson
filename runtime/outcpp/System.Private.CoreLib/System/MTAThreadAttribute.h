#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace MTAThreadAttributeNamespace {
CLASS(MTAThreadAttribute) {
  public: void Ctor();
};
} // namespace MTAThreadAttributeNamespace
using MTAThreadAttribute = MTAThreadAttributeNamespace::MTAThreadAttribute;
} // namespace System::Private::CoreLib::System
