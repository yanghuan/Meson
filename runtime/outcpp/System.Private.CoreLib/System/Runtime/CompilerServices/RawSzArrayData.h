#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RawSzArrayDataNamespace {
CLASS(RawSzArrayData) {
  public: IntPtr Count;
  public: Byte Data;
};
} // namespace RawSzArrayDataNamespace
using RawSzArrayData = RawSzArrayDataNamespace::RawSzArrayData;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
