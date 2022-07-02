#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallConvThiscallNamespace {
CLASS(CallConvThiscall) : public object {
  public: void ctor();
};
} // namespace CallConvThiscallNamespace
using CallConvThiscall = CallConvThiscallNamespace::CallConvThiscall;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
