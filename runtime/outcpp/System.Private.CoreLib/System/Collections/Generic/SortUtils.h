#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace SortUtilsNamespace {
class SortUtils {
  public: template <class TKey, class TValue>
  static Int32 MoveNansToFront(Span<TKey> keys, Span<TValue> values);
};
} // namespace SortUtilsNamespace
using SortUtils = SortUtilsNamespace::SortUtils;
} // namespace System::Private::CoreLib::System::Collections::Generic
