#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ErrorWrapperNamespace {
CLASS(ErrorWrapper) {
  private: Int32 ErrorCode;
};
} // namespace ErrorWrapperNamespace
using ErrorWrapper = ErrorWrapperNamespace::ErrorWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
