#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RawDataNamespace {
CLASS(RawData) : public object {
  public: Byte Data;
};
} // namespace RawDataNamespace
using RawData = RawDataNamespace::RawData;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
