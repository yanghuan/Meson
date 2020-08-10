#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SuppressIldasmAttributeNamespace {
CLASS(SuppressIldasmAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SuppressIldasmAttributeNamespace
using SuppressIldasmAttribute = SuppressIldasmAttributeNamespace::SuppressIldasmAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
