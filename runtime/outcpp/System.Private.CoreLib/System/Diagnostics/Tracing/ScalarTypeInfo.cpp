#include "ScalarTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarTypeInfoNamespace {
void ScalarTypeInfo___::ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat) {
  this->formatFunc = &formatFunc;
  this->nativeFormat = nativeFormat;
}

void ScalarTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddScalar(name, formatFunc(format, nativeFormat));
}

void ScalarTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddScalar(value);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Boolean() {
  return rt::newobj<ScalarTypeInfo>(typeof<Boolean>(), Statics::Format8, TraceLoggingDataType::Boolean8);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Byte() {
  return rt::newobj<ScalarTypeInfo>(typeof<Byte>(), Statics::Format8, TraceLoggingDataType::UInt8);
}

TraceLoggingTypeInfo ScalarTypeInfo___::SByte() {
  return rt::newobj<ScalarTypeInfo>(typeof<SByte>(), Statics::Format8, TraceLoggingDataType::Int8);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Char() {
  return rt::newobj<ScalarTypeInfo>(typeof<Char>(), Statics::Format16, TraceLoggingDataType::Char16);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int16() {
  return rt::newobj<ScalarTypeInfo>(typeof<Int16>(), Statics::Format16, TraceLoggingDataType::Int16);
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt16() {
  return rt::newobj<ScalarTypeInfo>(typeof<UInt16>(), Statics::Format16, TraceLoggingDataType::UInt16);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int32() {
  return rt::newobj<ScalarTypeInfo>(typeof<Int32>(), Statics::Format32, TraceLoggingDataType::Int32);
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt32() {
  return rt::newobj<ScalarTypeInfo>(typeof<UInt32>(), Statics::Format32, TraceLoggingDataType::UInt32);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Int64() {
  return rt::newobj<ScalarTypeInfo>(typeof<Int64>(), Statics::Format64, TraceLoggingDataType::Int64);
}

TraceLoggingTypeInfo ScalarTypeInfo___::UInt64() {
  return rt::newobj<ScalarTypeInfo>(typeof<UInt64>(), Statics::Format64, TraceLoggingDataType::UInt64);
}

TraceLoggingTypeInfo ScalarTypeInfo___::IntPtr() {
  return rt::newobj<ScalarTypeInfo>(typeof<IntPtr>(), Statics::FormatPtr, Statics::IntPtrType);
}

TraceLoggingTypeInfo ScalarTypeInfo___::UIntPtr() {
  return rt::newobj<ScalarTypeInfo>(typeof<UIntPtr>(), Statics::FormatPtr, Statics::UIntPtrType);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Single() {
  return rt::newobj<ScalarTypeInfo>(typeof<Single>(), Statics::Format32, TraceLoggingDataType::Float);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Double() {
  return rt::newobj<ScalarTypeInfo>(typeof<Double>(), Statics::Format64, TraceLoggingDataType::Double);
}

TraceLoggingTypeInfo ScalarTypeInfo___::Guid() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarTypeInfoNamespace
