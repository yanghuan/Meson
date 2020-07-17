#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EmptyCAHolderNamespace {
CLASS(EmptyCAHolder) {
  public: void Ctor();
};
} // namespace EmptyCAHolderNamespace
using EmptyCAHolder = EmptyCAHolderNamespace::EmptyCAHolder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
