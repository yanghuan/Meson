#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IntrospectiveSortUtilitiesNamespace {
class IntrospectiveSortUtilities {
  public: static Int32 FloorLog2PlusOne(Int32 n);
  public: static void ThrowOrIgnoreBadComparer(Object comparer);
};
} // namespace IntrospectiveSortUtilitiesNamespace
using IntrospectiveSortUtilities = IntrospectiveSortUtilitiesNamespace::IntrospectiveSortUtilities;
} // namespace System::Private::CoreLib::System::Collections::Generic
