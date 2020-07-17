#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SuppressIldasmAttributeNamespace {
CLASS(SuppressIldasmAttribute) {
  public: void Ctor();
};
} // namespace SuppressIldasmAttributeNamespace
using SuppressIldasmAttribute = SuppressIldasmAttributeNamespace::SuppressIldasmAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
