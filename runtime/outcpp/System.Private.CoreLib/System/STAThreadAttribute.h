#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace STAThreadAttributeNamespace {
CLASS(STAThreadAttribute) {
  public: void Ctor();
};
} // namespace STAThreadAttributeNamespace
using STAThreadAttribute = STAThreadAttributeNamespace::STAThreadAttribute;
} // namespace System::Private::CoreLib::System
