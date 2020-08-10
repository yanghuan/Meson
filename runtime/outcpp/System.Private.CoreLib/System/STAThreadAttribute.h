#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace STAThreadAttributeNamespace {
CLASS(STAThreadAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace STAThreadAttributeNamespace
using STAThreadAttribute = STAThreadAttributeNamespace::STAThreadAttribute;
} // namespace System::Private::CoreLib::System
