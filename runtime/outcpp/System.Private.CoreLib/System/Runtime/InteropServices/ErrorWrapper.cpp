#include "ErrorWrapper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ErrorWrapperNamespace {
void ErrorWrapper___::ctor(Int32 errorCode) {
  ErrorCode = errorCode;
}

void ErrorWrapper___::ctor(Object errorCode) {
  if (!rt::is<Int32>(errorCode)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeInt32(), "errorCode");
  }
  ErrorCode = (Int32)errorCode;
}

void ErrorWrapper___::ctor(Exception e) {
  ErrorCode = Marshal::GetHRForException(e);
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ErrorWrapperNamespace
