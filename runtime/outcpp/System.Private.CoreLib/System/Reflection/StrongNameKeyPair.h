#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace StrongNameKeyPairNamespace {
CLASS(StrongNameKeyPair) {
  public: Array<Byte> get_PublicKey();
};
} // namespace StrongNameKeyPairNamespace
using StrongNameKeyPair = StrongNameKeyPairNamespace::StrongNameKeyPair;
} // namespace System::Private::CoreLib::System::Reflection
