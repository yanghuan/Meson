#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ErrorWrapperNamespace {
CLASS(ErrorWrapper) : public Object::in {
  public: Int32 get_ErrorCode() { return ErrorCode; }
  public: void Ctor(Int32 errorCode);
  public: void Ctor(Object errorCode);
  public: void Ctor(Exception e);
  private: Int32 ErrorCode;
};
} // namespace ErrorWrapperNamespace
using ErrorWrapper = ErrorWrapperNamespace::ErrorWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
