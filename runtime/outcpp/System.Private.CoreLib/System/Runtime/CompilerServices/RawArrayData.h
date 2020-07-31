#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RawArrayDataNamespace {
CLASS(RawArrayData) : public Object::in {
  public: UInt32 Length;
  public: UInt32 Padding;
  public: Byte Data;
};
} // namespace RawArrayDataNamespace
using RawArrayData = RawArrayDataNamespace::RawArrayData;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
