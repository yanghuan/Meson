#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IComparerNamespace {
CLASS(IComparer) {
  public: Int32 Compare(Object x, Object y);
};
} // namespace IComparerNamespace
using IComparer = IComparerNamespace::IComparer;
} // namespace System::Private::CoreLib::System::Collections
