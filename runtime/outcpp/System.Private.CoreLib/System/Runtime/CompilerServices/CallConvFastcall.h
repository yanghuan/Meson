#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallConvFastcallNamespace {
CLASS(CallConvFastcall) : public object {
  public: void ctor();
};
} // namespace CallConvFastcallNamespace
using CallConvFastcall = CallConvFastcallNamespace::CallConvFastcall;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
