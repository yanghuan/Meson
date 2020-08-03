#pragma once

#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
namespace TYPEDESCNamespace {
struct TYPEDESC : public valueType<TYPEDESC> {
  public: IntPtr lpValue;
  public: Int16 vt;
};
} // namespace TYPEDESCNamespace
using TYPEDESC = TYPEDESCNamespace::TYPEDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
