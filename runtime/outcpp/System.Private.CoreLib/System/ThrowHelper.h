#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(KeyNotFoundException)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
enum class ExceptionArgument : int32_t;
enum class ExceptionResource : int32_t;
FORWARD(ArgumentException)
FORWARD(ArgumentNullException)
FORWARD(ArgumentOutOfRangeException)
FORWARD_(Array)
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(InvalidOperationException)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
namespace ThrowHelperNamespace {
using namespace System::Collections::Generic;
class ThrowHelper {
  public: static void ThrowArrayTypeMismatchException();
  public: static void ThrowInvalidTypeWithPointersNotSupported(Type targetType);
  public: static void ThrowIndexOutOfRangeException();
  public: static void ThrowArgumentOutOfRangeException();
  public: static void ThrowArgumentException_DestinationTooShort();
  public: static void ThrowArgumentException_OverlapAlignmentMismatch();
  public: static void ThrowArgumentException_CannotExtractScalar(ExceptionArgument argument);
  public: static void ThrowArgumentOutOfRange_IndexException();
  public: static void ThrowArgumentException_BadComparer(Object comparer);
  public: static void ThrowIndexArgumentOutOfRange_NeedNonNegNumException();
  public: static void ThrowValueArgumentOutOfRange_NeedNonNegNumException();
  public: static void ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum();
  public: static void ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index();
  public: static void ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count();
  public: static void ThrowArgumentOutOfRange_Year();
  public: static void ThrowArgumentOutOfRange_BadYearMonthDay();
  public: static void ThrowArgumentOutOfRange_BadHourMinuteSecond();
  public: static void ThrowArgumentOutOfRange_TimeSpanTooLong();
  public: template <class T>
  static void ThrowWrongKeyTypeArgumentException(T key, Type targetType);
  public: template <class T>
  static void ThrowWrongValueTypeArgumentException(T value, Type targetType);
  private: static ArgumentException GetAddingDuplicateWithKeyArgumentException(Object key);
  public: template <class T>
  static void ThrowAddingDuplicateWithKeyArgumentException(T key);
  public: template <class T>
  static void ThrowKeyNotFoundException(T key);
  public: static void ThrowArgumentException(ExceptionResource resource);
  public: static void ThrowArgumentException(ExceptionResource resource, ExceptionArgument argument);
  private: static ArgumentNullException GetArgumentNullException(ExceptionArgument argument);
  public: static void ThrowArgumentNullException(ExceptionArgument argument);
  public: static void ThrowArgumentNullException(ExceptionArgument argument, ExceptionResource resource);
  public: static void ThrowArgumentOutOfRangeException(ExceptionArgument argument);
  public: static void ThrowArgumentOutOfRangeException(ExceptionArgument argument, ExceptionResource resource);
  public: static void ThrowArgumentOutOfRangeException(ExceptionArgument argument, Int32 paramNumber, ExceptionResource resource);
  public: static void ThrowInvalidOperationException();
  public: static void ThrowInvalidOperationException(ExceptionResource resource);
  public: static void ThrowInvalidOperationException(ExceptionResource resource, Exception e);
  public: static void ThrowSerializationException(ExceptionResource resource);
  public: static void ThrowRankException(ExceptionResource resource);
  public: static void ThrowNotSupportedException(ExceptionResource resource);
  public: static void ThrowObjectDisposedException(ExceptionResource resource);
  public: static void ThrowNotSupportedException();
  public: static void ThrowAggregateException(List<Exception> exceptions);
  public: static void ThrowArgumentException_Argument_InvalidArrayType();
  public: static void ThrowInvalidOperationException_InvalidOperation_EnumNotStarted();
  public: static void ThrowInvalidOperationException_InvalidOperation_EnumEnded();
  public: static void ThrowInvalidOperationException_EnumCurrent(Int32 index);
  public: static void ThrowInvalidOperationException_InvalidOperation_EnumFailedVersion();
  public: static void ThrowInvalidOperationException_InvalidOperation_EnumOpCantHappen();
  public: static void ThrowInvalidOperationException_InvalidOperation_NoValue();
  public: static void ThrowInvalidOperationException_ConcurrentOperationsNotSupported();
  public: static void ThrowInvalidOperationException_HandleIsNotInitialized();
  public: static void ThrowInvalidOperationException_HandleIsNotPinned();
  public: static void ThrowArraySegmentCtorValidationFailedExceptions(Array<> array, Int32 offset, Int32 count);
  public: static void ThrowFormatException_BadFormatSpecifier();
  public: static void ThrowArgumentOutOfRangeException_PrecisionTooLarge();
  public: static void ThrowArgumentOutOfRangeException_SymbolDoesNotFit();
  private: static Exception GetArraySegmentCtorValidationFailedException(Array<> array, Int32 offset, Int32 count);
  private: static ArgumentException GetArgumentException(ExceptionResource resource);
  private: static InvalidOperationException GetInvalidOperationException(ExceptionResource resource);
  private: static ArgumentException GetWrongKeyTypeArgumentException(Object key, Type targetType);
  private: static ArgumentException GetWrongValueTypeArgumentException(Object value, Type targetType);
  private: static KeyNotFoundException GetKeyNotFoundException(Object key);
  private: static ArgumentOutOfRangeException GetArgumentOutOfRangeException(ExceptionArgument argument, ExceptionResource resource);
  private: static ArgumentException GetArgumentException(ExceptionResource resource, ExceptionArgument argument);
  private: static ArgumentOutOfRangeException GetArgumentOutOfRangeException(ExceptionArgument argument, Int32 paramNumber, ExceptionResource resource);
  private: static InvalidOperationException GetInvalidOperationException_EnumCurrent(Int32 index);
  public: template <class T>
  static void IfNullAndNullsAreIllegalThenThrow(Object value, ExceptionArgument argName);
  public: template <class T>
  static void ThrowForUnsupportedVectorBaseType();
  private: static String GetArgumentName(ExceptionArgument argument);
  private: static String GetResourceString(ExceptionResource resource);
};
} // namespace ThrowHelperNamespace
using ThrowHelper = ThrowHelperNamespace::ThrowHelper;
} // namespace System::Private::CoreLib::System
