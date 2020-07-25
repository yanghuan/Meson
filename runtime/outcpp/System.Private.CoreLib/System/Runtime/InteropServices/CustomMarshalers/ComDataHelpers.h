#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers {
namespace ComDataHelpersNamespace {
class ComDataHelpers {
  public: template <class T, class TView>
  static TView GetOrCreateManagedViewFromComData(Object comObject, Func<T, TView> createCallback);
};
} // namespace ComDataHelpersNamespace
using ComDataHelpers = ComDataHelpersNamespace::ComDataHelpers;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers
