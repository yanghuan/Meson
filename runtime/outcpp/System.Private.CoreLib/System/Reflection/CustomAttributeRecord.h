#pragma once

#include <System.Private.CoreLib/System/Reflection/ConstArray.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
namespace CustomAttributeRecordNamespace {
struct CustomAttributeRecord : public valueType<CustomAttributeRecord> {
  public: ConstArray blob;
  public: MetadataToken tkCtor;
};
} // namespace CustomAttributeRecordNamespace
using CustomAttributeRecord = CustomAttributeRecordNamespace::CustomAttributeRecord;
} // namespace System::Private::CoreLib::System::Reflection
