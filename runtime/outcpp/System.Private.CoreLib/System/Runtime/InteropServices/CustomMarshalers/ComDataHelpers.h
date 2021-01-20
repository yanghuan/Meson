#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
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
