#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ErrorWrapperNamespace {
CLASS(ErrorWrapper) : public object {
  public: Int32 get_ErrorCode() { return ErrorCode; }
  public: void ctor(Int32 errorCode);
  public: void ctor(Object errorCode);
  public: void ctor(Exception e);
  private: Int32 ErrorCode;
};
} // namespace ErrorWrapperNamespace
using ErrorWrapper = ErrorWrapperNamespace::ErrorWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
