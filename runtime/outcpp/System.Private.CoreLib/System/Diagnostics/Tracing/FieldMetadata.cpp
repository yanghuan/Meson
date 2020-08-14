#include "FieldMetadata-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::FieldMetadataNamespace {
using namespace System::Text;

void FieldMetadata___::ctor(String name, TraceLoggingDataType type, EventFieldTags tags, Boolean variableCount) {
}

void FieldMetadata___::ctor(String name, TraceLoggingDataType dataType, EventFieldTags tags, Byte countFlags, UInt16 fixedCount, Array<Byte> custom) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name", "This usually means that the object passed to Write is of a type that does not support being used as the top-level object in an event, e.g. a primitive or built-in type.");
  }
  Statics::CheckName(name);
}

void FieldMetadata___::IncrementStructFieldCount() {
  inType |= 128;
  outType++;
}

void FieldMetadata___::Encode(Int32& pos, Array<Byte> metadata) {
  if (metadata != nullptr) {
    Encoding::in::get_UTF8()->GetBytes(name, 0, name->get_Length(), metadata, pos);
  }
  pos += nameSize;
  if (metadata != nullptr) {
    metadata[pos] = inType;
  }
  pos++;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::FieldMetadataNamespace
