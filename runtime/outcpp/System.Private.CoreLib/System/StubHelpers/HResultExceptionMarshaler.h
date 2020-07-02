#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace HResultExceptionMarshalerNamespace {
class HResultExceptionMarshaler {
  public: static Int32 ConvertToNative(Exception ex);
  public: static Exception ConvertToManaged(Int32 hr);
};
} // namespace HResultExceptionMarshalerNamespace
using HResultExceptionMarshaler = HResultExceptionMarshalerNamespace::HResultExceptionMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
