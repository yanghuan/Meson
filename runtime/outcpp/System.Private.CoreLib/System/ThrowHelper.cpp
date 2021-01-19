#include "ThrowHelper-dep.h"

#include <System.Private.CoreLib/System/AggregateException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArrayTypeMismatchException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/RankException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ThrowHelperNamespace {
using namespace System::Runtime::Serialization;

void ThrowHelper::ThrowArrayTypeMismatchException() {
  rt::throw_exception<ArrayTypeMismatchException>();
}

void ThrowHelper::ThrowInvalidTypeWithPointersNotSupported(Type targetType) {
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidTypeWithPointersNotSupported(), targetType));
}

void ThrowHelper::ThrowIndexOutOfRangeException() {
  rt::throw_exception<IndexOutOfRangeException>();
}

void ThrowHelper::ThrowArgumentOutOfRangeException() {
  rt::throw_exception<ArgumentOutOfRangeException>();
}

void ThrowHelper::ThrowArgumentException_DestinationTooShort() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_DestinationTooShort(), "destination");
}

void ThrowHelper::ThrowArgumentException_OverlapAlignmentMismatch() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_OverlapAlignmentMismatch());
}

void ThrowHelper::ThrowArgumentException_CannotExtractScalar(ExceptionArgument argument) {
  rt::throw_exception(GetArgumentException(ExceptionResource::Argument_CannotExtractScalar, argument));
}

void ThrowHelper::ThrowArgumentOutOfRange_IndexException() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_Index));
}

void ThrowHelper::ThrowArgumentException_BadComparer(Object comparer) {
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_BogusIComparer(), comparer));
}

void ThrowHelper::ThrowIndexArgumentOutOfRange_NeedNonNegNumException() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum));
}

void ThrowHelper::ThrowValueArgumentOutOfRange_NeedNonNegNumException() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::value, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum));
}

void ThrowHelper::ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::length, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum));
}

void ThrowHelper::ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index));
}

void ThrowHelper::ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_Count));
}

void ThrowHelper::ThrowArgumentOutOfRange_Year() {
  rt::throw_exception(GetArgumentOutOfRangeException(ExceptionArgument::year, ExceptionResource::ArgumentOutOfRange_Year));
}

void ThrowHelper::ThrowArgumentOutOfRange_BadYearMonthDay() {
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadYearMonthDay());
}

void ThrowHelper::ThrowArgumentOutOfRange_BadHourMinuteSecond() {
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
}

void ThrowHelper::ThrowArgumentOutOfRange_TimeSpanTooLong() {
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_Overflow_TimeSpanTooLong());
}

ArgumentException ThrowHelper::GetAddingDuplicateWithKeyArgumentException(Object key) {
  return rt::newobj<ArgumentException>(SR::Format(SR::get_Argument_AddingDuplicateWithKey(), key));
}

void ThrowHelper::ThrowArgumentException(ExceptionResource resource) {
  rt::throw_exception(GetArgumentException(resource));
}

void ThrowHelper::ThrowArgumentException(ExceptionResource resource, ExceptionArgument argument) {
  rt::throw_exception(GetArgumentException(resource, argument));
}

ArgumentNullException ThrowHelper::GetArgumentNullException(ExceptionArgument argument) {
  return rt::newobj<ArgumentNullException>(GetArgumentName(argument));
}

void ThrowHelper::ThrowArgumentNullException(ExceptionArgument argument) {
  rt::throw_exception(GetArgumentNullException(argument));
}

void ThrowHelper::ThrowArgumentNullException(ExceptionArgument argument, ExceptionResource resource) {
  rt::throw_exception<ArgumentNullException>(GetArgumentName(argument), GetResourceString(resource));
}

void ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument argument) {
  rt::throw_exception<ArgumentOutOfRangeException>(GetArgumentName(argument));
}

void ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument argument, ExceptionResource resource) {
  rt::throw_exception(GetArgumentOutOfRangeException(argument, resource));
}

void ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument argument, Int32 paramNumber, ExceptionResource resource) {
  rt::throw_exception(GetArgumentOutOfRangeException(argument, paramNumber, resource));
}

void ThrowHelper::ThrowInvalidOperationException() {
  rt::throw_exception<InvalidOperationException>();
}

void ThrowHelper::ThrowInvalidOperationException(ExceptionResource resource) {
  rt::throw_exception(GetInvalidOperationException(resource));
}

void ThrowHelper::ThrowInvalidOperationException(ExceptionResource resource, Exception e) {
  rt::throw_exception<InvalidOperationException>(GetResourceString(resource), e);
}

void ThrowHelper::ThrowSerializationException(ExceptionResource resource) {
  rt::throw_exception<SerializationException>(GetResourceString(resource));
}

void ThrowHelper::ThrowRankException(ExceptionResource resource) {
  rt::throw_exception<RankException>(GetResourceString(resource));
}

void ThrowHelper::ThrowNotSupportedException(ExceptionResource resource) {
  rt::throw_exception<NotSupportedException>(GetResourceString(resource));
}

void ThrowHelper::ThrowObjectDisposedException(ExceptionResource resource) {
  rt::throw_exception<ObjectDisposedException>(nullptr, GetResourceString(resource));
}

void ThrowHelper::ThrowNotSupportedException() {
  rt::throw_exception<NotSupportedException>();
}

void ThrowHelper::ThrowAggregateException(List<Exception> exceptions) {
  rt::throw_exception<AggregateException>(exceptions);
}

void ThrowHelper::ThrowArgumentException_Argument_InvalidArrayType() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidArrayType());
}

void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumNotStarted() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
}

void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumEnded() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
}

void ThrowHelper::ThrowInvalidOperationException_EnumCurrent(Int32 index) {
  rt::throw_exception(GetInvalidOperationException_EnumCurrent(index));
}

void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumFailedVersion());
}

void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumOpCantHappen() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumOpCantHappen());
}

void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_NoValue() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoValue());
}

void ThrowHelper::ThrowInvalidOperationException_ConcurrentOperationsNotSupported() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ConcurrentOperationsNotSupported());
}

void ThrowHelper::ThrowInvalidOperationException_HandleIsNotInitialized() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_HandleIsNotInitialized());
}

void ThrowHelper::ThrowInvalidOperationException_HandleIsNotPinned() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_HandleIsNotPinned());
}

void ThrowHelper::ThrowArraySegmentCtorValidationFailedExceptions(Array<> array, Int32 offset, Int32 count) {
  rt::throw_exception(GetArraySegmentCtorValidationFailedException(array, offset, count));
}

void ThrowHelper::ThrowFormatException_BadFormatSpecifier() {
  rt::throw_exception<FormatException>(SR::get_Argument_BadFormatSpecifier());
}

void ThrowHelper::ThrowArgumentOutOfRangeException_PrecisionTooLarge() {
  rt::throw_exception<ArgumentOutOfRangeException>("precision", SR::Format(SR::get_Argument_PrecisionTooLarge(), (Byte)(Int32)99));
}

void ThrowHelper::ThrowArgumentOutOfRangeException_SymbolDoesNotFit() {
  rt::throw_exception<ArgumentOutOfRangeException>("symbol", SR::get_Argument_BadFormatSpecifier());
}

Exception ThrowHelper::GetArraySegmentCtorValidationFailedException(Array<> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    return rt::newobj<ArgumentNullException>("array");
  }
  if (offset < 0) {
    return rt::newobj<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    return rt::newobj<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  return rt::newobj<ArgumentException>(SR::get_Argument_InvalidOffLen());
}

ArgumentException ThrowHelper::GetArgumentException(ExceptionResource resource) {
  return rt::newobj<ArgumentException>(GetResourceString(resource));
}

InvalidOperationException ThrowHelper::GetInvalidOperationException(ExceptionResource resource) {
  return rt::newobj<InvalidOperationException>(GetResourceString(resource));
}

ArgumentException ThrowHelper::GetWrongKeyTypeArgumentException(Object key, Type targetType) {
  return rt::newobj<ArgumentException>(SR::Format(SR::get_Arg_WrongType(), key, targetType), "key");
}

ArgumentException ThrowHelper::GetWrongValueTypeArgumentException(Object value, Type targetType) {
  return rt::newobj<ArgumentException>(SR::Format(SR::get_Arg_WrongType(), value, targetType), "value");
}

KeyNotFoundException ThrowHelper::GetKeyNotFoundException(Object key) {
  return rt::newobj<KeyNotFoundException>(SR::Format(SR::get_Arg_KeyNotFoundWithKey(), key));
}

ArgumentOutOfRangeException ThrowHelper::GetArgumentOutOfRangeException(ExceptionArgument argument, ExceptionResource resource) {
  return rt::newobj<ArgumentOutOfRangeException>(GetArgumentName(argument), GetResourceString(resource));
}

ArgumentException ThrowHelper::GetArgumentException(ExceptionResource resource, ExceptionArgument argument) {
  return rt::newobj<ArgumentException>(GetResourceString(resource), GetArgumentName(argument));
}

ArgumentOutOfRangeException ThrowHelper::GetArgumentOutOfRangeException(ExceptionArgument argument, Int32 paramNumber, ExceptionResource resource) {
  return rt::newobj<ArgumentOutOfRangeException>(GetArgumentName(argument) + "[" + paramNumber + "]", GetResourceString(resource));
}

InvalidOperationException ThrowHelper::GetInvalidOperationException_EnumCurrent(Int32 index) {
  return rt::newobj<InvalidOperationException>((index < 0) ? SR::get_InvalidOperation_EnumNotStarted() : SR::get_InvalidOperation_EnumEnded());
}

String ThrowHelper::GetArgumentName(ExceptionArgument argument) {
}

String ThrowHelper::GetResourceString(ExceptionResource resource) {
}

} // namespace System::Private::CoreLib::System::ThrowHelperNamespace
