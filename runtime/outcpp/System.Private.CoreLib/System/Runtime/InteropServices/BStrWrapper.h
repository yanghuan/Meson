#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace BStrWrapperNamespace {
CLASS(BStrWrapper) {
  private: String WrappedObject;
};
} // namespace BStrWrapperNamespace
using BStrWrapper = BStrWrapperNamespace::BStrWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
