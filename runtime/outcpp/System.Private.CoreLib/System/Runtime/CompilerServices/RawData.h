#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RawDataNamespace {
CLASS(RawData) {
  public: Byte Data;
};
} // namespace RawDataNamespace
using RawData = RawDataNamespace::RawData;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
