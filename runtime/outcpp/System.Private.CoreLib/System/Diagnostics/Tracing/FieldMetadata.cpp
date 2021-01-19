#include "FieldMetadata-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FieldMetadata-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::FieldMetadataNamespace {
using namespace System::Text;

void FieldMetadata___::ctor(String name, TraceLoggingDataType type, EventFieldTags tags, Boolean variableCount) {
}

void FieldMetadata___::ctor(String name, TraceLoggingDataType dataType, EventFieldTags tags, Byte countFlags, UInt16 fixedCount, Array<Byte> custom) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name", "This usually means that the object passed to Write is of a type that does not support being used as the top-level object in an event, e.g. a primitive or built-in type.");
  }
  Statics::CheckName(name);
  Int32 num = (Int32)(dataType & (TraceLoggingDataType)31);
  this->name = name;
  nameSize = Encoding::in::get_UTF8()->GetByteCount(this->name) + 1;
  inType = (Byte)(num | countFlags);
  outType = (Byte)((UInt32)((Int32)dataType >> 8) & 127u);
  this->tags = tags;
  this->fixedCount = fixedCount;
  this->custom = custom;
  if (countFlags != 0) {
    switch (num.get()) {
      case 0:
        rt::throw_exception<NotSupportedException>(SR::get_EventSource_NotSupportedArrayOfNil());
      case 14:
        rt::throw_exception<NotSupportedException>(SR::get_EventSource_NotSupportedArrayOfBinary());
      case 1:
      case 2:
        rt::throw_exception<NotSupportedException>(SR::get_EventSource_NotSupportedArrayOfNullTerminatedString());
    }
  }
  if ((this->tags & (EventFieldTags)268435455) != 0) {
    outType |= 128;
  }
  if (outType != 0) {
    inType |= 128;
  }
}

void FieldMetadata___::IncrementStructFieldCount() {
  inType |= 128;
  outType++;
  if ((outType & 127) == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_EventSource_TooManyFields());
  }
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
  if ((inType & 128u) != 0) {
    if (metadata != nullptr) {
      metadata[pos] = outType;
    }
    pos++;
    if ((outType & 128u) != 0) {
      Statics::EncodeTags((Int32)tags, pos, metadata);
    }
  }
  if ((inType & 32) == 0) {
    return;
  }
  if (metadata != nullptr) {
    metadata[pos] = (Byte)fixedCount;
    metadata[pos + 1] = (Byte)(fixedCount >> 8);
  }
  pos += 2;
  if (96 == (inType & 96) && fixedCount != 0) {
    if (metadata != nullptr) {
      Buffer::BlockCopy(custom, 0, metadata, pos, fixedCount);
    }
    pos += fixedCount;
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::FieldMetadataNamespace
