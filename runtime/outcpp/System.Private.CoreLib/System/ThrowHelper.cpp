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
  switch (argument) {
    case ExceptionArgument::obj:
      return "obj";
    case ExceptionArgument::dictionary:
      return "dictionary";
    case ExceptionArgument::array:
      return "array";
    case ExceptionArgument::info:
      return "info";
    case ExceptionArgument::key:
      return "key";
    case ExceptionArgument::text:
      return "text";
    case ExceptionArgument::values:
      return "values";
    case ExceptionArgument::value:
      return "value";
    case ExceptionArgument::startIndex:
      return "startIndex";
    case ExceptionArgument::task:
      return "task";
    case ExceptionArgument::bytes:
      return "bytes";
    case ExceptionArgument::byteIndex:
      return "byteIndex";
    case ExceptionArgument::byteCount:
      return "byteCount";
    case ExceptionArgument::ch:
      return "ch";
    case ExceptionArgument::chars:
      return "chars";
    case ExceptionArgument::charIndex:
      return "charIndex";
    case ExceptionArgument::charCount:
      return "charCount";
    case ExceptionArgument::s:
      return "s";
    case ExceptionArgument::input:
      return "input";
    case ExceptionArgument::ownedMemory:
      return "ownedMemory";
    case ExceptionArgument::list:
      return "list";
    case ExceptionArgument::index:
      return "index";
    case ExceptionArgument::capacity:
      return "capacity";
    case ExceptionArgument::collection:
      return "collection";
    case ExceptionArgument::item:
      return "item";
    case ExceptionArgument::converter:
      return "converter";
    case ExceptionArgument::match:
      return "match";
    case ExceptionArgument::count:
      return "count";
    case ExceptionArgument::action:
      return "action";
    case ExceptionArgument::comparison:
      return "comparison";
    case ExceptionArgument::exceptions:
      return "exceptions";
    case ExceptionArgument::exception:
      return "exception";
    case ExceptionArgument::pointer:
      return "pointer";
    case ExceptionArgument::start:
      return "start";
    case ExceptionArgument::format:
      return "format";
    case ExceptionArgument::culture:
      return "culture";
    case ExceptionArgument::comparer:
      return "comparer";
    case ExceptionArgument::comparable:
      return "comparable";
    case ExceptionArgument::source:
      return "source";
    case ExceptionArgument::state:
      return "state";
    case ExceptionArgument::length:
      return "length";
    case ExceptionArgument::comparisonType:
      return "comparisonType";
    case ExceptionArgument::manager:
      return "manager";
    case ExceptionArgument::sourceBytesToCopy:
      return "sourceBytesToCopy";
    case ExceptionArgument::callBack:
      return "callBack";
    case ExceptionArgument::creationOptions:
      return "creationOptions";
    case ExceptionArgument::function:
      return "function";
    case ExceptionArgument::scheduler:
      return "scheduler";
    case ExceptionArgument::continuationAction:
      return "continuationAction";
    case ExceptionArgument::continuationFunction:
      return "continuationFunction";
    case ExceptionArgument::tasks:
      return "tasks";
    case ExceptionArgument::asyncResult:
      return "asyncResult";
    case ExceptionArgument::beginMethod:
      return "beginMethod";
    case ExceptionArgument::endMethod:
      return "endMethod";
    case ExceptionArgument::endFunction:
      return "endFunction";
    case ExceptionArgument::cancellationToken:
      return "cancellationToken";
    case ExceptionArgument::continuationOptions:
      return "continuationOptions";
    case ExceptionArgument::delay:
      return "delay";
    case ExceptionArgument::millisecondsDelay:
      return "millisecondsDelay";
    case ExceptionArgument::millisecondsTimeout:
      return "millisecondsTimeout";
    case ExceptionArgument::stateMachine:
      return "stateMachine";
    case ExceptionArgument::timeout:
      return "timeout";
    case ExceptionArgument::type:
      return "type";
    case ExceptionArgument::sourceIndex:
      return "sourceIndex";
    case ExceptionArgument::sourceArray:
      return "sourceArray";
    case ExceptionArgument::destinationIndex:
      return "destinationIndex";
    case ExceptionArgument::destinationArray:
      return "destinationArray";
    case ExceptionArgument::pHandle:
      return "pHandle";
    case ExceptionArgument::other:
      return "other";
    case ExceptionArgument::newSize:
      return "newSize";
    case ExceptionArgument::lowerBounds:
      return "lowerBounds";
    case ExceptionArgument::lengths:
      return "lengths";
    case ExceptionArgument::len:
      return "len";
    case ExceptionArgument::keys:
      return "keys";
    case ExceptionArgument::indices:
      return "indices";
    case ExceptionArgument::index1:
      return "index1";
    case ExceptionArgument::index2:
      return "index2";
    case ExceptionArgument::index3:
      return "index3";
    case ExceptionArgument::length1:
      return "length1";
    case ExceptionArgument::length2:
      return "length2";
    case ExceptionArgument::length3:
      return "length3";
    case ExceptionArgument::endIndex:
      return "endIndex";
    case ExceptionArgument::elementType:
      return "elementType";
    case ExceptionArgument::arrayIndex:
      return "arrayIndex";
    case ExceptionArgument::year:
      return "year";
    case ExceptionArgument::codePoint:
      return "codePoint";
    case ExceptionArgument::str:
      return "str";
    case ExceptionArgument::options:
      return "options";
    case ExceptionArgument::prefix:
      return "prefix";
    case ExceptionArgument::suffix:
      return "suffix";
    default:
      return "";
  }
}

String ThrowHelper::GetResourceString(ExceptionResource resource) {
  switch (resource) {
    case ExceptionResource::ArgumentOutOfRange_Index:
      return SR::get_ArgumentOutOfRange_Index();
    case ExceptionResource::ArgumentOutOfRange_IndexCount:
      return SR::get_ArgumentOutOfRange_IndexCount();
    case ExceptionResource::ArgumentOutOfRange_IndexCountBuffer:
      return SR::get_ArgumentOutOfRange_IndexCountBuffer();
    case ExceptionResource::ArgumentOutOfRange_Count:
      return SR::get_ArgumentOutOfRange_Count();
    case ExceptionResource::ArgumentOutOfRange_Year:
      return SR::get_ArgumentOutOfRange_Year();
    case ExceptionResource::Arg_ArrayPlusOffTooSmall:
      return SR::get_Arg_ArrayPlusOffTooSmall();
    case ExceptionResource::NotSupported_ReadOnlyCollection:
      return SR::get_NotSupported_ReadOnlyCollection();
    case ExceptionResource::Arg_RankMultiDimNotSupported:
      return SR::get_Arg_RankMultiDimNotSupported();
    case ExceptionResource::Arg_NonZeroLowerBound:
      return SR::get_Arg_NonZeroLowerBound();
    case ExceptionResource::ArgumentOutOfRange_GetCharCountOverflow:
      return SR::get_ArgumentOutOfRange_GetCharCountOverflow();
    case ExceptionResource::ArgumentOutOfRange_ListInsert:
      return SR::get_ArgumentOutOfRange_ListInsert();
    case ExceptionResource::ArgumentOutOfRange_NeedNonNegNum:
      return SR::get_ArgumentOutOfRange_NeedNonNegNum();
    case ExceptionResource::ArgumentOutOfRange_SmallCapacity:
      return SR::get_ArgumentOutOfRange_SmallCapacity();
    case ExceptionResource::Argument_InvalidOffLen:
      return SR::get_Argument_InvalidOffLen();
    case ExceptionResource::Argument_CannotExtractScalar:
      return SR::get_Argument_CannotExtractScalar();
    case ExceptionResource::ArgumentOutOfRange_BiggerThanCollection:
      return SR::get_ArgumentOutOfRange_BiggerThanCollection();
    case ExceptionResource::Serialization_MissingKeys:
      return SR::get_Serialization_MissingKeys();
    case ExceptionResource::Serialization_NullKey:
      return SR::get_Serialization_NullKey();
    case ExceptionResource::NotSupported_KeyCollectionSet:
      return SR::get_NotSupported_KeyCollectionSet();
    case ExceptionResource::NotSupported_ValueCollectionSet:
      return SR::get_NotSupported_ValueCollectionSet();
    case ExceptionResource::InvalidOperation_NullArray:
      return SR::get_InvalidOperation_NullArray();
    case ExceptionResource::TaskT_TransitionToFinal_AlreadyCompleted:
      return SR::get_TaskT_TransitionToFinal_AlreadyCompleted();
    case ExceptionResource::TaskCompletionSourceT_TrySetException_NullException:
      return SR::get_TaskCompletionSourceT_TrySetException_NullException();
    case ExceptionResource::TaskCompletionSourceT_TrySetException_NoExceptions:
      return SR::get_TaskCompletionSourceT_TrySetException_NoExceptions();
    case ExceptionResource::NotSupported_StringComparison:
      return SR::get_NotSupported_StringComparison();
    case ExceptionResource::ConcurrentCollection_SyncRoot_NotSupported:
      return SR::get_ConcurrentCollection_SyncRoot_NotSupported();
    case ExceptionResource::Task_MultiTaskContinuation_NullTask:
      return SR::get_Task_MultiTaskContinuation_NullTask();
    case ExceptionResource::InvalidOperation_WrongAsyncResultOrEndCalledMultiple:
      return SR::get_InvalidOperation_WrongAsyncResultOrEndCalledMultiple();
    case ExceptionResource::Task_MultiTaskContinuation_EmptyTaskList:
      return SR::get_Task_MultiTaskContinuation_EmptyTaskList();
    case ExceptionResource::Task_Start_TaskCompleted:
      return SR::get_Task_Start_TaskCompleted();
    case ExceptionResource::Task_Start_Promise:
      return SR::get_Task_Start_Promise();
    case ExceptionResource::Task_Start_ContinuationTask:
      return SR::get_Task_Start_ContinuationTask();
    case ExceptionResource::Task_Start_AlreadyStarted:
      return SR::get_Task_Start_AlreadyStarted();
    case ExceptionResource::Task_RunSynchronously_Continuation:
      return SR::get_Task_RunSynchronously_Continuation();
    case ExceptionResource::Task_RunSynchronously_Promise:
      return SR::get_Task_RunSynchronously_Promise();
    case ExceptionResource::Task_RunSynchronously_TaskCompleted:
      return SR::get_Task_RunSynchronously_TaskCompleted();
    case ExceptionResource::Task_RunSynchronously_AlreadyStarted:
      return SR::get_Task_RunSynchronously_AlreadyStarted();
    case ExceptionResource::AsyncMethodBuilder_InstanceNotInitialized:
      return SR::get_AsyncMethodBuilder_InstanceNotInitialized();
    case ExceptionResource::Task_ContinueWith_ESandLR:
      return SR::get_Task_ContinueWith_ESandLR();
    case ExceptionResource::Task_ContinueWith_NotOnAnything:
      return SR::get_Task_ContinueWith_NotOnAnything();
    case ExceptionResource::Task_Delay_InvalidDelay:
      return SR::get_Task_Delay_InvalidDelay();
    case ExceptionResource::Task_Delay_InvalidMillisecondsDelay:
      return SR::get_Task_Delay_InvalidMillisecondsDelay();
    case ExceptionResource::Task_Dispose_NotCompleted:
      return SR::get_Task_Dispose_NotCompleted();
    case ExceptionResource::Task_ThrowIfDisposed:
      return SR::get_Task_ThrowIfDisposed();
    case ExceptionResource::Task_WaitMulti_NullTask:
      return SR::get_Task_WaitMulti_NullTask();
    case ExceptionResource::ArgumentException_OtherNotArrayOfCorrectLength:
      return SR::get_ArgumentException_OtherNotArrayOfCorrectLength();
    case ExceptionResource::ArgumentNull_Array:
      return SR::get_ArgumentNull_Array();
    case ExceptionResource::ArgumentNull_SafeHandle:
      return SR::get_ArgumentNull_SafeHandle();
    case ExceptionResource::ArgumentOutOfRange_EndIndexStartIndex:
      return SR::get_ArgumentOutOfRange_EndIndexStartIndex();
    case ExceptionResource::ArgumentOutOfRange_Enum:
      return SR::get_ArgumentOutOfRange_Enum();
    case ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported:
      return SR::get_ArgumentOutOfRange_HugeArrayNotSupported();
    case ExceptionResource::Argument_AddingDuplicate:
      return SR::get_Argument_AddingDuplicate();
    case ExceptionResource::Argument_InvalidArgumentForComparison:
      return SR::get_Argument_InvalidArgumentForComparison();
    case ExceptionResource::Arg_LowerBoundsMustMatch:
      return SR::get_Arg_LowerBoundsMustMatch();
    case ExceptionResource::Arg_MustBeType:
      return SR::get_Arg_MustBeType();
    case ExceptionResource::Arg_Need1DArray:
      return SR::get_Arg_Need1DArray();
    case ExceptionResource::Arg_Need2DArray:
      return SR::get_Arg_Need2DArray();
    case ExceptionResource::Arg_Need3DArray:
      return SR::get_Arg_Need3DArray();
    case ExceptionResource::Arg_NeedAtLeast1Rank:
      return SR::get_Arg_NeedAtLeast1Rank();
    case ExceptionResource::Arg_RankIndices:
      return SR::get_Arg_RankIndices();
    case ExceptionResource::Arg_RanksAndBounds:
      return SR::get_Arg_RanksAndBounds();
    case ExceptionResource::InvalidOperation_IComparerFailed:
      return SR::get_InvalidOperation_IComparerFailed();
    case ExceptionResource::NotSupported_FixedSizeCollection:
      return SR::get_NotSupported_FixedSizeCollection();
    case ExceptionResource::Rank_MultiDimNotSupported:
      return SR::get_Rank_MultiDimNotSupported();
    case ExceptionResource::Arg_TypeNotSupported:
      return SR::get_Arg_TypeNotSupported();
    case ExceptionResource::Argument_SpansMustHaveSameLength:
      return SR::get_Argument_SpansMustHaveSameLength();
    case ExceptionResource::Argument_InvalidFlag:
      return SR::get_Argument_InvalidFlag();
    default:
      return "";
  }
}

} // namespace System::Private::CoreLib::System::ThrowHelperNamespace
