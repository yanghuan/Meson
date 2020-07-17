#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace MetadataEnumResultNamespace {
struct MetadataEnumResult {
  public: Int32 get_Length();
  public: Int32 get_Item(Int32 index);
  public: void Ctor();
  private: Array<Int32> largeResult;
  private: Int32 length;
  private: rt::FixedBuffer<Int32, 16> smallResult;
};
} // namespace MetadataEnumResultNamespace
using MetadataEnumResult = MetadataEnumResultNamespace::MetadataEnumResult;
} // namespace System::Private::CoreLib::System::Reflection
