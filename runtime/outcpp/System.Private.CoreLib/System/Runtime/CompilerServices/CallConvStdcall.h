#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallConvStdcallNamespace {
CLASS(CallConvStdcall) : public object {
  public: void ctor();
};
} // namespace CallConvStdcallNamespace
using CallConvStdcall = CallConvStdcallNamespace::CallConvStdcall;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
