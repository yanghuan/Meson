#include "ScalarArrayTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ScalarArrayTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarArrayTypeInfoNamespace {
void ScalarArrayTypeInfo___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void ScalarArrayTypeInfo___::__c___::ctor() {
}

TraceLoggingDataType ScalarArrayTypeInfo___::__c___::_Guid_b__20_0(EventFieldFormat f, TraceLoggingDataType t) {
  return Statics::MakeDataType(TraceLoggingDataType::Guid, f);
}

void ScalarArrayTypeInfo___::ctor(Type type, Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> formatFunc, TraceLoggingDataType nativeFormat, System::Int32 elementSize) {
  this->formatFunc = formatFunc;
  this->nativeFormat = nativeFormat;
  this->elementSize = elementSize;
}

void ScalarArrayTypeInfo___::WriteMetadata(TraceLoggingMetadataCollector collector, String name, EventFieldFormat format) {
  collector->AddArray(name, formatFunc(format, nativeFormat));
}

void ScalarArrayTypeInfo___::WriteData(TraceLoggingDataCollector collector, PropertyValue value) {
  collector->AddArray(value, elementSize);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Boolean() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Boolean>>(), &Statics::Format8, TraceLoggingDataType::Boolean8, 1);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Byte() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Byte>>(), &Statics::Format8, TraceLoggingDataType::UInt8, 1);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::SByte() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<SByte>>(), &Statics::Format8, TraceLoggingDataType::Int8, 1);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Char() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Char>>(), &Statics::Format16, TraceLoggingDataType::Char16, 2);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int16() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Int16>>(), &Statics::Format16, TraceLoggingDataType::Int16, 2);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt16() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<UInt16>>(), &Statics::Format16, TraceLoggingDataType::UInt16, 2);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int32() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Int32>>(), &Statics::Format32, TraceLoggingDataType::Int32, 4);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt32() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<UInt32>>(), &Statics::Format32, TraceLoggingDataType::UInt32, 4);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Int64() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Int64>>(), &Statics::Format64, TraceLoggingDataType::Int64, 8);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UInt64() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<UInt64>>(), &Statics::Format64, TraceLoggingDataType::UInt64, 8);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::IntPtr() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<IntPtr>>(), &Statics::FormatPtr, Statics::IntPtrType, IntPtr::get_Size());
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::UIntPtr() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<UIntPtr>>(), &Statics::FormatPtr, Statics::UIntPtrType, IntPtr::get_Size());
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Single() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Single>>(), &Statics::Format32, TraceLoggingDataType::Float, 4);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Double() {
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Array<Double>>(), &Statics::Format64, TraceLoggingDataType::Double, 8);
}

TraceLoggingTypeInfo ScalarArrayTypeInfo___::Guid() {
  Func<EventFieldFormat, TraceLoggingDataType, TraceLoggingDataType> as = __c::in::__9__20_0;
  return rt::newobj<ScalarArrayTypeInfo>(typeof<Guid>(), as != nullptr ? as : (__c::in::__9__20_0 = {__c::in::__9, &__c::in::_Guid_b__20_0}), TraceLoggingDataType::Guid, sizeof(Guid));
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ScalarArrayTypeInfoNamespace
