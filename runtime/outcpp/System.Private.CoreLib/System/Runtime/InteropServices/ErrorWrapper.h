#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ErrorWrapperNamespace {
CLASS(ErrorWrapper) {
  public: Int32 get_ErrorCode() { return ErrorCode; }
  private: Int32 ErrorCode;
};
} // namespace ErrorWrapperNamespace
using ErrorWrapper = ErrorWrapperNamespace::ErrorWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
