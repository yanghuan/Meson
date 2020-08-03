#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace BINDPTRNamespace {
struct BINDPTR : public valueType<BINDPTR> {
  public: IntPtr lpfuncdesc;
  public: IntPtr lpvardesc;
  public: IntPtr lptcomp;
};
} // namespace BINDPTRNamespace
using BINDPTR = BINDPTRNamespace::BINDPTR;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
