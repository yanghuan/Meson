#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IHashCodeProviderNamespace {
CLASS(IHashCodeProvider) : public Object::in {
  public: Int32 GetHashCode(Object obj);
};
} // namespace IHashCodeProviderNamespace
using IHashCodeProvider = IHashCodeProviderNamespace::IHashCodeProvider;
} // namespace System::Private::CoreLib::System::Collections
