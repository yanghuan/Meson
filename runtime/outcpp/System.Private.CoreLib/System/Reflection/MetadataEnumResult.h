#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace MetadataEnumResultNamespace {
struct MetadataEnumResult : public valueType<MetadataEnumResult> {
  public: Int32 get_Length();
  public: Int32 get_Item(Int32 index);
  private: Array<Int32> largeResult;
  private: Int32 length;
  private: Int32 smallResult[16];
};
} // namespace MetadataEnumResultNamespace
using MetadataEnumResult = MetadataEnumResultNamespace::MetadataEnumResult;
} // namespace System::Private::CoreLib::System::Reflection
