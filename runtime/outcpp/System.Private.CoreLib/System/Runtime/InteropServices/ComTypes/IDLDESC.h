#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class IDLFLAG : int16_t;
namespace IDLDESCNamespace {
struct IDLDESC : public valueType<IDLDESC> {
  public: IntPtr dwReserved;
  public: IDLFLAG wIDLFlags;
};
} // namespace IDLDESCNamespace
using IDLDESC = IDLDESCNamespace::IDLDESC;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
