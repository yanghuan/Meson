#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallConvCdeclNamespace {
CLASS(CallConvCdecl) : public object {
  public: void ctor();
};
} // namespace CallConvCdeclNamespace
using CallConvCdecl = CallConvCdeclNamespace::CallConvCdecl;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
