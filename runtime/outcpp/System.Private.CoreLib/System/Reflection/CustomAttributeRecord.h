#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken.h>

namespace System::Private::CoreLib::System::Reflection {
namespace CustomAttributeRecordNamespace {
struct CustomAttributeRecord {
  public: ConstArray blob;
  public: MetadataToken tkCtor;
};
} // namespace CustomAttributeRecordNamespace
using CustomAttributeRecord = CustomAttributeRecordNamespace::CustomAttributeRecord;
} // namespace System::Private::CoreLib::System::Reflection
