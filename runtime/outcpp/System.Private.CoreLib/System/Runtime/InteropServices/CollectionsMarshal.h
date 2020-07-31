#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CollectionsMarshalNamespace {
using namespace Collections::Generic;
class CollectionsMarshal {
  public: template <class T>
  static Span<T> AsSpan(List<T> list);
};
} // namespace CollectionsMarshalNamespace
using CollectionsMarshal = CollectionsMarshalNamespace::CollectionsMarshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
