#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IHashCodeProviderNamespace {
CLASS(IHashCodeProvider) {
  public: Int32 GetHashCode(Object obj);
};
} // namespace IHashCodeProviderNamespace
using IHashCodeProvider = IHashCodeProviderNamespace::IHashCodeProvider;
} // namespace System::Private::CoreLib::System::Collections
