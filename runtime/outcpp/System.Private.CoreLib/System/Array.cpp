#include "Array-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/ArrayEnumerator-dep.h>
#include <System.Private.CoreLib/System/ArrayTypeMismatchException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Comparer-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/RankException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/MethodTable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RawArrayData-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/SZArrayEnumerator-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypedReference-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::ArrayNamespace {
using namespace ::System::Private::CoreLib::Internal::Runtime::CompilerServices;
using namespace Collections;
using namespace Reflection;
using namespace Runtime::CompilerServices;
Array___<>::SorterObjectArray::SorterObjectArray(Array<Object> keys, Array<Object> items, IComparer1 comparer) {
}

void Array___<>::SorterObjectArray::SwapIfGreater(Int32 a, Int32 b) {
}

void Array___<>::SorterObjectArray::Swap(Int32 i, Int32 j) {
}

void Array___<>::SorterObjectArray::Sort(Int32 left, Int32 length) {
}

void Array___<>::SorterObjectArray::IntrospectiveSort(Int32 left, Int32 length) {
}

void Array___<>::SorterObjectArray::IntroSort(Int32 lo, Int32 hi, Int32 depthLimit) {
}

Int32 Array___<>::SorterObjectArray::PickPivotAndPartition(Int32 lo, Int32 hi) {
  return Int32();
}

void Array___<>::SorterObjectArray::Heapsort(Int32 lo, Int32 hi) {
}

void Array___<>::SorterObjectArray::DownHeap(Int32 i, Int32 n, Int32 lo) {
}

void Array___<>::SorterObjectArray::InsertionSort(Int32 lo, Int32 hi) {
}

Array___<>::SorterGenericArray::SorterGenericArray(Array<> keys, Array<> items, IComparer1 comparer) {
}

void Array___<>::SorterGenericArray::SwapIfGreater(Int32 a, Int32 b) {
}

void Array___<>::SorterGenericArray::Swap(Int32 i, Int32 j) {
}

void Array___<>::SorterGenericArray::Sort(Int32 left, Int32 length) {
}

void Array___<>::SorterGenericArray::IntrospectiveSort(Int32 left, Int32 length) {
}

void Array___<>::SorterGenericArray::IntroSort(Int32 lo, Int32 hi, Int32 depthLimit) {
}

Int32 Array___<>::SorterGenericArray::PickPivotAndPartition(Int32 lo, Int32 hi) {
  return Int32();
}

void Array___<>::SorterGenericArray::Heapsort(Int32 lo, Int32 hi) {
}

void Array___<>::SorterGenericArray::DownHeap(Int32 i, Int32 n, Int32 lo) {
}

void Array___<>::SorterGenericArray::InsertionSort(Int32 lo, Int32 hi) {
}

Array<> Array___<>::CreateInstance(Type elementType, Int32 length) {
  if ((Object)elementType == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (length < 0) {
    ThrowHelper::ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum();
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(elementType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_MustBeType, ExceptionArgument::elementType);
  }
  return InternalCreate((void*)runtimeType->get_TypeHandle().get_Value(), 1, &length, nullptr);
}

Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2) {
  if ((Object)elementType == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (length1 < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length1, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (length2 < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length2, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(elementType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_MustBeType, ExceptionArgument::elementType);
  }
  Int32 default[2] = {};
  Int32* ptr = default;
  *ptr = length1;
  ptr[1] = length2;
  return InternalCreate((void*)runtimeType->get_TypeHandle().get_Value(), 2, ptr, nullptr);
}

Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2, Int32 length3) {
  if ((Object)elementType == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (length1 < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length1, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (length2 < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length2, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (length3 < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length3, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(elementType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_MustBeType, ExceptionArgument::elementType);
  }
  Int32 default[3] = {};
  Int32* ptr = default;
  *ptr = length1;
  ptr[1] = length2;
  ptr[2] = length3;
  return InternalCreate((void*)runtimeType->get_TypeHandle().get_Value(), 3, ptr, nullptr);
}

Array<> Array___<>::CreateInstance(Type elementType, Array<Int32> lengths) {
  if ((Object)elementType == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (lengths == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lengths);
  }
  if (lengths->get_Length() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_NeedAtLeast1Rank);
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(elementType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_MustBeType, ExceptionArgument::elementType);
  }
  for (Int32 i = 0; i < lengths->get_Length(); i++) {
    if (lengths[i] < 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::lengths, i, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
    }
  }
  {
    Int32* pLengths = &lengths[0];
    return InternalCreate((void*)runtimeType->get_TypeHandle().get_Value(), lengths->get_Length(), pLengths, nullptr);
  }
}

Array<> Array___<>::CreateInstance(Type elementType, Array<Int32> lengths, Array<Int32> lowerBounds) {
  if (elementType == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (lengths == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lengths);
  }
  if (lowerBounds == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lowerBounds);
  }
  if (lengths->get_Length() != lowerBounds->get_Length()) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RanksAndBounds);
  }
  if (lengths->get_Length() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_NeedAtLeast1Rank);
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(elementType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_MustBeType, ExceptionArgument::elementType);
  }
  for (Int32 i = 0; i < lengths->get_Length(); i++) {
    if (lengths[i] < 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::lengths, i, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
    }
  }
  {
    Int32* pLengths = &lengths[0];
    {
      Int32* pLowerBounds = &lowerBounds[0];
      return InternalCreate((void*)runtimeType->get_TypeHandle().get_Value(), lengths->get_Length(), pLengths, pLowerBounds);
    }
  }
}

void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int32 length) {
  if (sourceArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::sourceArray);
  }
  if (destinationArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::destinationArray);
  }
  MethodTable* methodTable = RuntimeHelpers::GetMethodTable(sourceArray);
  if (methodTable == RuntimeHelpers::GetMethodTable(destinationArray) && !methodTable->get_IsMultiDimensionalArray() && (UInt64)(UInt32)length <= (UInt64)(UIntPtr)(void*)sourceArray->get_LongLength() && (UInt64)(UInt32)length <= (UInt64)(UIntPtr)(void*)destinationArray->get_LongLength()) {
    UIntPtr uIntPtr = (UIntPtr)(void*)((Int64)(UInt32)length * (Int64)methodTable->ComponentSize);
    Byte data = Unsafe::As<RawArrayData>(sourceArray)->Data;
    Byte data2 = Unsafe::As<RawArrayData>(destinationArray)->Data;
    if (methodTable->get_ContainsGCPointers()) {
      Buffer::BulkMoveWithWriteBarrier(data2, data, uIntPtr);
    } else {
      Buffer::Memmove<Byte>(data2, data, uIntPtr);
    }
  } else {
    Copy(sourceArray, sourceArray->GetLowerBound(0), destinationArray, destinationArray->GetLowerBound(0), length, false);
  }
}

void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
  if (sourceArray != nullptr && destinationArray != nullptr) {
    MethodTable* methodTable = RuntimeHelpers::GetMethodTable(sourceArray);
    if (methodTable == RuntimeHelpers::GetMethodTable(destinationArray) && !methodTable->get_IsMultiDimensionalArray() && length >= 0 && sourceIndex >= 0 && destinationIndex >= 0 && (UInt64)(UInt32)(sourceIndex + length) <= (UInt64)(UIntPtr)(void*)sourceArray->get_LongLength() && (UInt64)(UInt32)(destinationIndex + length) <= (UInt64)(UIntPtr)(void*)destinationArray->get_LongLength()) {
      UIntPtr uIntPtr = (UIntPtr)(void*)methodTable->ComponentSize;
      UIntPtr uIntPtr2 = (UIntPtr)(void*)((Int64)(UInt32)length * (Int64)(UInt64)uIntPtr);
      Byte source = Unsafe::AddByteOffset(Unsafe::As<RawArrayData>(sourceArray)->Data, (UIntPtr)(void*)((Int64)(UInt32)sourceIndex * (Int64)(UInt64)uIntPtr));
      Byte destination = Unsafe::AddByteOffset(Unsafe::As<RawArrayData>(destinationArray)->Data, (UIntPtr)(void*)((Int64)(UInt32)destinationIndex * (Int64)(UInt64)uIntPtr));
      if (methodTable->get_ContainsGCPointers()) {
        Buffer::BulkMoveWithWriteBarrier(destination, source, uIntPtr2);
      } else {
        Buffer::Memmove<Byte>(destination, source, uIntPtr2);
      }
      return;
    }
  }
  Copy(sourceArray, sourceIndex, destinationArray, destinationIndex, length, false);
}

void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length, Boolean reliable) {
  if (sourceArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::sourceArray);
  }
  if (destinationArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::destinationArray);
  }
  if (sourceArray->GetType() != destinationArray->GetType() && sourceArray->get_Rank() != destinationArray->get_Rank()) {
    rt::throw_exception<RankException>(SR::get_Rank_MustMatch());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 lowerBound = sourceArray->GetLowerBound(0);
  if (sourceIndex < lowerBound || sourceIndex - lowerBound < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceIndex", SR::get_ArgumentOutOfRange_ArrayLB());
  }
  sourceIndex -= lowerBound;
  Int32 lowerBound2 = destinationArray->GetLowerBound(0);
  if (destinationIndex < lowerBound2 || destinationIndex - lowerBound2 < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("destinationIndex", SR::get_ArgumentOutOfRange_ArrayLB());
  }
  destinationIndex -= lowerBound2;
  if ((UInt64)(UInt32)(sourceIndex + length) > (UInt64)(UIntPtr)(void*)sourceArray->get_LongLength()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_LongerThanSrcArray(), "sourceArray");
  }
  if ((UInt64)(UInt32)(destinationIndex + length) > (UInt64)(UIntPtr)(void*)destinationArray->get_LongLength()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_LongerThanDestArray(), "destinationArray");
  }
  if (sourceArray->GetType() == destinationArray->GetType() || IsSimpleCopy(sourceArray, destinationArray)) {
    MethodTable* methodTable = RuntimeHelpers::GetMethodTable(sourceArray);
    UIntPtr uIntPtr = (UIntPtr)(void*)methodTable->ComponentSize;
    UIntPtr uIntPtr2 = (UIntPtr)(void*)((Int64)(UInt32)length * (Int64)(UInt64)uIntPtr);
    Byte source = Unsafe::AddByteOffset(RuntimeHelpers::GetRawArrayData(sourceArray), (UIntPtr)(void*)((Int64)(UInt32)sourceIndex * (Int64)(UInt64)uIntPtr));
    Byte destination = Unsafe::AddByteOffset(RuntimeHelpers::GetRawArrayData(destinationArray), (UIntPtr)(void*)((Int64)(UInt32)destinationIndex * (Int64)(UInt64)uIntPtr));
    if (methodTable->get_ContainsGCPointers()) {
      Buffer::BulkMoveWithWriteBarrier(destination, source, uIntPtr2);
    } else {
      Buffer::Memmove<Byte>(destination, source, uIntPtr2);
    }
  } else {
    if (reliable) {
      rt::throw_exception<ArrayTypeMismatchException>(SR::get_ArrayTypeMismatch_ConstrainedCopy());
    }
    CopySlow(sourceArray, sourceIndex, destinationArray, destinationIndex, length);
  }
}

void Array___<>::ConstrainedCopy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
  Copy(sourceArray, sourceIndex, destinationArray, destinationIndex, length, true);
}

void Array___<>::Clear(Array<> array, Int32 index, Int32 length) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Byte source = Unsafe::As<RawArrayData>(array)->Data;
  Int32 num = 0;
  MethodTable* methodTable = RuntimeHelpers::GetMethodTable(array);
  if (methodTable->get_IsMultiDimensionalArray()) {
    Int32 multiDimensionalArrayRank = methodTable->get_MultiDimensionalArrayRank();
    num = Unsafe::Add(Unsafe::As<Byte, Int32>(source), multiDimensionalArrayRank);
    source = Unsafe::Add(source, 8 * multiDimensionalArrayRank);
  }
  Int32 num2 = index - num;
  if (index < num || num2 < 0 || length < 0 || (UInt64)(UInt32)(num2 + length) > (UInt64)(UIntPtr)(void*)array->get_LongLength()) {
    ThrowHelper::ThrowIndexOutOfRangeException();
  }
  UIntPtr uIntPtr = (UIntPtr)(void*)methodTable->ComponentSize;
  Byte reference = Unsafe::AddByteOffset(source, (UIntPtr)(void*)((Int64)(UInt32)num2 * (Int64)(UInt64)uIntPtr));
  UIntPtr uIntPtr2 = (UIntPtr)(void*)((Int64)(UInt32)length * (Int64)(UInt64)uIntPtr);
  if (methodTable->get_ContainsGCPointers()) {
    SpanHelpers::ClearWithReferences(Unsafe::As<Byte, IntPtr>(reference), (UIntPtr)(void*)((UInt64)uIntPtr2 / (UInt64)(UInt32)sizeof(IntPtr)));
  } else {
    SpanHelpers::ClearWithoutReferences(reference, uIntPtr2);
  }
}

Object Array___<>::GetValue(Array<Int32> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  if (get_Rank() != indices->get_Length()) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RankIndices);
  }
  TypedReference typedReference = TypedReference();
  {
    Int32* pIndices = &indices[0];
    InternalGetReference(&typedReference, indices->get_Length(), pIndices);
  }
  return TypedReference::InternalToObject(&typedReference);
}

Object Array___<>::GetValue(Int32 index) {
  if (get_Rank() != 1) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need1DArray);
  }
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 1, &index);
  return TypedReference::InternalToObject(&typedReference);
}

Object Array___<>::GetValue(Int32 index1, Int32 index2) {
  if (get_Rank() != 2) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need2DArray);
  }
  Int32 default[2] = {};
  Int32* ptr = default;
  *ptr = index1;
  ptr[1] = index2;
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 2, ptr);
  return TypedReference::InternalToObject(&typedReference);
}

Object Array___<>::GetValue(Int32 index1, Int32 index2, Int32 index3) {
  if (get_Rank() != 3) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need3DArray);
  }
  Int32 default[3] = {};
  Int32* ptr = default;
  *ptr = index1;
  ptr[1] = index2;
  ptr[2] = index3;
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 3, ptr);
  return TypedReference::InternalToObject(&typedReference);
}

void Array___<>::SetValue(Object value, Int32 index) {
  if (get_Rank() != 1) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need1DArray);
  }
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 1, &index);
  InternalSetValue(&typedReference, value);
}

void Array___<>::SetValue(Object value, Int32 index1, Int32 index2) {
  if (get_Rank() != 2) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need2DArray);
  }
  Int32 default[2] = {};
  Int32* ptr = default;
  *ptr = index1;
  ptr[1] = index2;
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 2, ptr);
  InternalSetValue(&typedReference, value);
}

void Array___<>::SetValue(Object value, Int32 index1, Int32 index2, Int32 index3) {
  if (get_Rank() != 3) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need3DArray);
  }
  Int32 default[3] = {};
  Int32* ptr = default;
  *ptr = index1;
  ptr[1] = index2;
  ptr[2] = index3;
  TypedReference typedReference = TypedReference();
  InternalGetReference(&typedReference, 3, ptr);
  InternalSetValue(&typedReference, value);
}

void Array___<>::SetValue(Object value, Array<Int32> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  if (get_Rank() != indices->get_Length()) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RankIndices);
  }
  TypedReference typedReference = TypedReference();
  {
    Int32* pIndices = &indices[0];
    InternalGetReference(&typedReference, indices->get_Length(), pIndices);
  }
  InternalSetValue(&typedReference, value);
}

Int32 Array___<>::GetLength(Int32 dimension) {
  Int32 multiDimensionalArrayRank = RuntimeHelpers::GetMultiDimensionalArrayRank((Array<>)this);
  if (multiDimensionalArrayRank == 0 && dimension == 0) {
    return get_Length();
  }
  if ((UInt32)dimension >= (UInt32)multiDimensionalArrayRank) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_ArrayRankIndex());
  }
  return Unsafe::Add(RuntimeHelpers::GetMultiDimensionalArrayBounds((Array<>)this), dimension);
}

Int32 Array___<>::GetUpperBound(Int32 dimension) {
  Int32 multiDimensionalArrayRank = RuntimeHelpers::GetMultiDimensionalArrayRank((Array<>)this);
  if (multiDimensionalArrayRank == 0 && dimension == 0) {
    return get_Length() - 1;
  }
  if ((UInt32)dimension >= (UInt32)multiDimensionalArrayRank) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_ArrayRankIndex());
  }
  Int32 multiDimensionalArrayBounds = RuntimeHelpers::GetMultiDimensionalArrayBounds((Array<>)this);
  return Unsafe::Add(multiDimensionalArrayBounds, dimension) + Unsafe::Add(multiDimensionalArrayBounds, multiDimensionalArrayRank + dimension) - 1;
}

Int32 Array___<>::GetLowerBound(Int32 dimension) {
  Int32 multiDimensionalArrayRank = RuntimeHelpers::GetMultiDimensionalArrayRank((Array<>)this);
  if (multiDimensionalArrayRank == 0 && dimension == 0) {
    return 0;
  }
  if ((UInt32)dimension >= (UInt32)multiDimensionalArrayRank) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_ArrayRankIndex());
  }
  return Unsafe::Add(RuntimeHelpers::GetMultiDimensionalArrayBounds((Array<>)this), multiDimensionalArrayRank + dimension);
}

Boolean Array___<>::IsValueOfElementType(Object value) {
  MethodTable* methodTable = RuntimeHelpers::GetMethodTable((Array<>)this);
  return (IntPtr)methodTable->ElementType == (IntPtr)(void*)RuntimeHelpers::GetMethodTable(value);
}

Array<> Array___<>::CreateInstance(Type elementType, Array<Int64> lengths) {
  if (lengths == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lengths);
  }
  if (lengths->get_Length() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_NeedAtLeast1Rank);
  }
  Int32 array = rt::newarr<Array<Int32>>(lengths->get_Length());
  for (Int32 i = 0; i < lengths->get_Length(); i++) {
    Int64 num = lengths[i];
    Int32 num2 = (Int32)num;
    if (num != num2) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::len, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
    }
    array[i] = num2;
  }
  return CreateInstance(elementType, array);
}

void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int64 length) {
  Int32 num = (Int32)length;
  if (length != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  Copy(sourceArray, destinationArray, num);
}

void Array___<>::Copy(Array<> sourceArray, Int64 sourceIndex, Array<> destinationArray, Int64 destinationIndex, Int64 length) {
  Int32 num = (Int32)sourceIndex;
  Int32 num2 = (Int32)destinationIndex;
  Int32 num3 = (Int32)length;
  if (sourceIndex != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceIndex, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (destinationIndex != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::destinationIndex, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (length != num3) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  Copy(sourceArray, num, destinationArray, num2, num3);
}

Object Array___<>::GetValue(Int64 index) {
  Int32 num = (Int32)index;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return GetValue(num);
}

Object Array___<>::GetValue(Int64 index1, Int64 index2) {
  Int32 num = (Int32)index1;
  Int32 num2 = (Int32)index2;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return GetValue(num, num2);
}

Object Array___<>::GetValue(Int64 index1, Int64 index2, Int64 index3) {
  Int32 num = (Int32)index1;
  Int32 num2 = (Int32)index2;
  Int32 num3 = (Int32)index3;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index3 != num3) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index3, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return GetValue(num, num2, num3);
}

Object Array___<>::GetValue(Array<Int64> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  if (get_Rank() != indices->get_Length()) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RankIndices);
  }
  Int32 array = rt::newarr<Array<Int32>>(indices->get_Length());
  for (Int32 i = 0; i < indices->get_Length(); i++) {
    Int64 num = indices[i];
    Int32 num2 = (Int32)num;
    if (num != num2) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
    }
    array[i] = num2;
  }
  return GetValue(array);
}

void Array___<>::SetValue(Object value, Int64 index) {
  Int32 num = (Int32)index;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  SetValue(value, num);
}

void Array___<>::SetValue(Object value, Int64 index1, Int64 index2) {
  Int32 num = (Int32)index1;
  Int32 num2 = (Int32)index2;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  SetValue(value, num, num2);
}

void Array___<>::SetValue(Object value, Int64 index1, Int64 index2, Int64 index3) {
  Int32 num = (Int32)index1;
  Int32 num2 = (Int32)index2;
  Int32 num3 = (Int32)index3;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index3 != num3) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index3, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  SetValue(value, num, num2, num3);
}

void Array___<>::SetValue(Object value, Array<Int64> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  if (get_Rank() != indices->get_Length()) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RankIndices);
  }
  Int32 array = rt::newarr<Array<Int32>>(indices->get_Length());
  for (Int32 i = 0; i < indices->get_Length(); i++) {
    Int64 num = indices[i];
    Int32 num2 = (Int32)num;
    if (num != num2) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
    }
    array[i] = num2;
  }
  SetValue(value, array);
}

Int32 Array___<>::GetMedian(Int32 low, Int32 hi) {
  return low + (hi - low >> 1);
}

Int64 Array___<>::GetLongLength(Int32 dimension) {
  return GetLength(dimension);
}

Object Array___<>::Clone() {
  return MemberwiseClone();
}

Int32 Array___<>::BinarySearch(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return BinarySearch(array, array->GetLowerBound(0), array->get_Length(), value, nullptr);
}

Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value) {
  return BinarySearch(array, index, length, value, nullptr);
}

Int32 Array___<>::BinarySearch(Array<> array, Object value, IComparer1 comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return BinarySearch(array, array->GetLowerBound(0), array->get_Length(), value, comparer);
}

template <class T>
static Int32 GenericBinarySearch(Array<> array, Int32 adjustedIndex, Int32 length, Object value) {
  return MemoryExtensions::BinarySearch(UnsafeArrayAsSpan<T>(array, adjustedIndex, length), Unsafe::As<Byte, T>(RuntimeHelpers::GetRawData(value)));
}
Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value, IComparer1 comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  if (index < lowerBound) {
    ThrowHelper::ThrowIndexArgumentOutOfRange_NeedNonNegNumException();
  }
  if (length < 0) {
    ThrowHelper::ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum();
  }
  if (array->get_Length() - (index - lowerBound) < length) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Argument_InvalidOffLen);
  }
  if (array->get_Rank() != 1) {
    ThrowHelper::ThrowRankException(ExceptionResource::Rank_MultiDimNotSupported);
  }
  if (comparer == nullptr) {
    comparer = Comparer::in::Default;
  }
  Int32 num = index;
  Int32 num2 = index + length - 1;
  Object array2 = rt::as<Object>(array);
  if (array2 != nullptr) {
    while (num <= num2) {
      Int32 median = GetMedian(num, num2);
      Int32 num3;
      try{
        num3 = comparer->Compare(array2[median], value);
      } catch (Exception e) {
      }
      if (num3 == 0) {
        return median;
      }
      if (num3 < 0) {
        num = median + 1;
      } else {
        num2 = median - 1;
      }
    }
    return ~num;
  }
  if (comparer == Comparer::in::Default) {
    CorElementType corElementTypeOfElementType = array->GetCorElementTypeOfElementType();
    if (RuntimeHelpers::IsPrimitiveType(corElementTypeOfElementType)) {
      if (value == nullptr) {
        return ~index;
      }
      if (array->IsValueOfElementType(value)) {
        Int32 adjustedIndex2 = index - lowerBound;
        Int32 num4 = -1;
        switch (corElementTypeOfElementType) {
          case CorElementType::ELEMENT_TYPE_I1:
            num4 = GenericBinarySearch<SByte>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_BOOLEAN:
          case CorElementType::ELEMENT_TYPE_U1:
            num4 = GenericBinarySearch<Byte>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_I2:
            num4 = GenericBinarySearch<Int16>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_CHAR:
          case CorElementType::ELEMENT_TYPE_U2:
            num4 = GenericBinarySearch<UInt16>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_I4:
            num4 = GenericBinarySearch<Int32>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_U4:
            num4 = GenericBinarySearch<UInt32>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_I8:
          case CorElementType::ELEMENT_TYPE_I:
            num4 = GenericBinarySearch<Int64>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_U8:
          case CorElementType::ELEMENT_TYPE_U:
            num4 = GenericBinarySearch<UInt64>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_R4:
            num4 = GenericBinarySearch<Single>(array, adjustedIndex2, length, value);
            break;
          case CorElementType::ELEMENT_TYPE_R8:
            num4 = GenericBinarySearch<Double>(array, adjustedIndex2, length, value);
            break;
        }
        if (num4 < 0) {
          return ~(index + ~num4);
        }
        return index + num4;
      }
    }
  }
  while (num <= num2) {
    Int32 median2 = GetMedian(num, num2);
    Int32 num5;
    try{
      num5 = comparer->Compare(array->GetValue(median2), value);
    } catch (Exception e2) {
    }
    if (num5 == 0) {
      return median2;
    }
    if (num5 < 0) {
      num = median2 + 1;
    } else {
      num2 = median2 - 1;
    }
  }
  return ~num;
}

void Array___<>::CopyTo(Array<> array, Int32 index) {
  if (array != nullptr && array->get_Rank() != 1) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_RankMultiDimNotSupported);
  }
  Copy((Array<>)this, GetLowerBound(0), array, index, get_Length());
}

void Array___<>::CopyTo(Array<> array, Int64 index) {
  Int32 num = (Int32)index;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  CopyTo(array, num);
}

Int32 Array___<>::IndexOf(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return IndexOf(array, value, array->GetLowerBound(0), array->get_Length());
}

Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  return IndexOf(array, value, startIndex, array->get_Length() - startIndex + lowerBound);
}

template <class T>
static Int32 GenericIndexOf(Array<> array, Object value, Int32 adjustedIndex, Int32 length) {
  return MemoryExtensions::IndexOf(UnsafeArrayAsSpan<T>(array, adjustedIndex, length), Unsafe::As<Byte, T>(RuntimeHelpers::GetRawData(value)));
}
Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  if (array->get_Rank() != 1) {
    ThrowHelper::ThrowRankException(ExceptionResource::Rank_MultiDimNotSupported);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  if (startIndex < lowerBound || startIndex > array->get_Length() + lowerBound) {
    ThrowHelper::ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index();
  }
  if (count < 0 || count > array->get_Length() - startIndex + lowerBound) {
    ThrowHelper::ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count();
  }
  Int32 num = startIndex + count;
  Object array2 = rt::as<Object>(array);
  if (array2 != nullptr) {
    if (value == nullptr) {
      for (Int32 i = startIndex; i < num; i++) {
        if (array2[i] == nullptr) {
          return i;
        }
      }
    } else {
      for (Int32 j = startIndex; j < num; j++) {
        Object obj = array2[j];
        if (obj != nullptr && obj->Equals(value)) {
          return j;
        }
      }
    }
    return -1;
  }
  CorElementType corElementTypeOfElementType = array->GetCorElementTypeOfElementType();
  if (RuntimeHelpers::IsPrimitiveType(corElementTypeOfElementType)) {
    if (value == nullptr) {
      return lowerBound - 1;
    }
    if (array->IsValueOfElementType(value)) {
      Int32 adjustedIndex2 = startIndex - lowerBound;
      Int32 num2 = -1;
      switch (corElementTypeOfElementType) {
        case CorElementType::ELEMENT_TYPE_BOOLEAN:
        case CorElementType::ELEMENT_TYPE_I1:
        case CorElementType::ELEMENT_TYPE_U1:
          num2 = GenericIndexOf<Byte>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_CHAR:
        case CorElementType::ELEMENT_TYPE_I2:
        case CorElementType::ELEMENT_TYPE_U2:
          num2 = GenericIndexOf<Char>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_I4:
        case CorElementType::ELEMENT_TYPE_U4:
          num2 = GenericIndexOf<Int32>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_I8:
        case CorElementType::ELEMENT_TYPE_U8:
        case CorElementType::ELEMENT_TYPE_I:
        case CorElementType::ELEMENT_TYPE_U:
          num2 = GenericIndexOf<Int64>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_R4:
          num2 = GenericIndexOf<Single>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_R8:
          num2 = GenericIndexOf<Double>(array, value, adjustedIndex2, count);
          break;
      }
      return ((num2 >= 0) ? startIndex : lowerBound) + num2;
    }
  }
  for (Int32 k = startIndex; k < num; k++) {
    Object value2 = array->GetValue(k);
    if (value2 == nullptr) {
      if (value == nullptr) {
        return k;
      }
    } else if (value2->Equals(value)) {
      return k;
    }

  }
  return lowerBound - 1;
}

Int32 Array___<>::LastIndexOf(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  return LastIndexOf(array, value, array->get_Length() - 1 + lowerBound, array->get_Length());
}

Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  return LastIndexOf(array, value, startIndex, startIndex + 1 - lowerBound);
}

template <class T>
static Int32 GenericLastIndexOf(Array<> array, Object value, Int32 adjustedIndex, Int32 length) {
  return MemoryExtensions::LastIndexOf(UnsafeArrayAsSpan<T>(array, adjustedIndex, length), Unsafe::As<Byte, T>(RuntimeHelpers::GetRawData(value)));
}
Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  if (array->get_Length() == 0) {
    return lowerBound - 1;
  }
  if (startIndex < lowerBound || startIndex >= array->get_Length() + lowerBound) {
    ThrowHelper::ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index();
  }
  if (count < 0) {
    ThrowHelper::ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count();
  }
  if (count > startIndex - lowerBound + 1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::endIndex, ExceptionResource::ArgumentOutOfRange_EndIndexStartIndex);
  }
  if (array->get_Rank() != 1) {
    ThrowHelper::ThrowRankException(ExceptionResource::Rank_MultiDimNotSupported);
  }
  Int32 num = startIndex - count + 1;
  Object array2 = rt::as<Object>(array);
  if (array2 != nullptr) {
    if (value == nullptr) {
      for (Int32 num2 = startIndex; num2 >= num; num2--) {
        if (array2[num2] == nullptr) {
          return num2;
        }
      }
    } else {
      for (Int32 num3 = startIndex; num3 >= num; num3--) {
        Object obj = array2[num3];
        if (obj != nullptr && obj->Equals(value)) {
          return num3;
        }
      }
    }
    return -1;
  }
  CorElementType corElementTypeOfElementType = array->GetCorElementTypeOfElementType();
  if (RuntimeHelpers::IsPrimitiveType(corElementTypeOfElementType)) {
    if (value == nullptr) {
      return lowerBound - 1;
    }
    if (array->IsValueOfElementType(value)) {
      Int32 adjustedIndex2 = num - lowerBound;
      Int32 num4 = -1;
      switch (corElementTypeOfElementType) {
        case CorElementType::ELEMENT_TYPE_BOOLEAN:
        case CorElementType::ELEMENT_TYPE_I1:
        case CorElementType::ELEMENT_TYPE_U1:
          num4 = GenericLastIndexOf<Byte>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_CHAR:
        case CorElementType::ELEMENT_TYPE_I2:
        case CorElementType::ELEMENT_TYPE_U2:
          num4 = GenericLastIndexOf<Char>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_I4:
        case CorElementType::ELEMENT_TYPE_U4:
          num4 = GenericLastIndexOf<Int32>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_I8:
        case CorElementType::ELEMENT_TYPE_U8:
        case CorElementType::ELEMENT_TYPE_I:
        case CorElementType::ELEMENT_TYPE_U:
          num4 = GenericLastIndexOf<Int64>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_R4:
          num4 = GenericLastIndexOf<Single>(array, value, adjustedIndex2, count);
          break;
        case CorElementType::ELEMENT_TYPE_R8:
          num4 = GenericLastIndexOf<Double>(array, value, adjustedIndex2, count);
          break;
      }
      return ((num4 >= 0) ? num : lowerBound) + num4;
    }
  }
  for (Int32 num5 = startIndex; num5 >= num; num5--) {
    Object value2 = array->GetValue(num5);
    if (value2 == nullptr) {
      if (value == nullptr) {
        return num5;
      }
    } else if (value2->Equals(value)) {
      return num5;
    }

  }
  return lowerBound - 1;
}

void Array___<>::Reverse(Array<> array) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Reverse(array, array->GetLowerBound(0), array->get_Length());
}

void Array___<>::Reverse(Array<> array, Int32 index, Int32 length) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int32 lowerBound = array->GetLowerBound(0);
  if (index < lowerBound) {
    ThrowHelper::ThrowIndexArgumentOutOfRange_NeedNonNegNumException();
  }
  if (length < 0) {
    ThrowHelper::ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum();
  }
  if (array->get_Length() - (index - lowerBound) < length) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Argument_InvalidOffLen);
  }
  if (array->get_Rank() != 1) {
    ThrowHelper::ThrowRankException(ExceptionResource::Rank_MultiDimNotSupported);
  }
  if (length <= 1) {
    return;
  }
  Int32 adjustedIndex = index - lowerBound;
  switch (array->GetCorElementTypeOfElementType()) {
    case CorElementType::ELEMENT_TYPE_BOOLEAN:
    case CorElementType::ELEMENT_TYPE_I1:
    case CorElementType::ELEMENT_TYPE_U1:
      MemoryExtensions::Reverse(UnsafeArrayAsSpan<Byte>(array, adjustedIndex, length));
      return;
    case CorElementType::ELEMENT_TYPE_CHAR:
    case CorElementType::ELEMENT_TYPE_I2:
    case CorElementType::ELEMENT_TYPE_U2:
      MemoryExtensions::Reverse(UnsafeArrayAsSpan<Int16>(array, adjustedIndex, length));
      return;
    case CorElementType::ELEMENT_TYPE_I4:
    case CorElementType::ELEMENT_TYPE_U4:
    case CorElementType::ELEMENT_TYPE_R4:
      MemoryExtensions::Reverse(UnsafeArrayAsSpan<Int32>(array, adjustedIndex, length));
      return;
    case CorElementType::ELEMENT_TYPE_I8:
    case CorElementType::ELEMENT_TYPE_U8:
    case CorElementType::ELEMENT_TYPE_R8:
    case CorElementType::ELEMENT_TYPE_I:
    case CorElementType::ELEMENT_TYPE_U:
      MemoryExtensions::Reverse(UnsafeArrayAsSpan<Int64>(array, adjustedIndex, length));
      return;
    case CorElementType::ELEMENT_TYPE_ARRAY:
    case CorElementType::ELEMENT_TYPE_OBJECT:
    case CorElementType::ELEMENT_TYPE_SZARRAY:
      MemoryExtensions::Reverse(UnsafeArrayAsSpan<Object>(array, adjustedIndex, length));
      return;
  }
  Int32 num = index;
  Int32 num2 = index + length - 1;
  while (num < num2) {
    Object value = array->GetValue(num);
    array->SetValue(array->GetValue(num2), num);
    array->SetValue(value, num2);
    num++;
    num2--;
  }
}

void Array___<>::Sort(Array<> array) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Sort(array, nullptr, array->GetLowerBound(0), array->get_Length(), nullptr);
}

void Array___<>::Sort(Array<> keys, Array<> items) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
  Sort(keys, items, keys->GetLowerBound(0), keys->get_Length(), nullptr);
}

void Array___<>::Sort(Array<> array, Int32 index, Int32 length) {
  Sort(array, nullptr, index, length, nullptr);
}

void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length) {
  Sort(keys, items, index, length, nullptr);
}

void Array___<>::Sort(Array<> array, IComparer1 comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Sort(array, nullptr, array->GetLowerBound(0), array->get_Length(), comparer);
}

void Array___<>::Sort(Array<> keys, Array<> items, IComparer1 comparer) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
  Sort(keys, items, keys->GetLowerBound(0), keys->get_Length(), comparer);
}

void Array___<>::Sort(Array<> array, Int32 index, Int32 length, IComparer1 comparer) {
  Sort(array, nullptr, index, length, comparer);
}

template <class T>
static void GenericSort(Array<> keys, Array<> items, Int32 adjustedIndex, Int32 length) {
  Span<T> span = UnsafeArrayAsSpan<T>(keys, adjustedIndex, length);
  if (items != nullptr) {
    MemoryExtensions::Sort(span, UnsafeArrayAsSpan<T>(items, adjustedIndex, length));
  } else {
    MemoryExtensions::Sort(span);
  }
}
void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length, IComparer1 comparer) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
  if (keys->get_Rank() != 1 || (items != nullptr && items->get_Rank() != 1)) {
    ThrowHelper::ThrowRankException(ExceptionResource::Rank_MultiDimNotSupported);
  }
  Int32 lowerBound = keys->GetLowerBound(0);
  if (items != nullptr && lowerBound != items->GetLowerBound(0)) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_LowerBoundsMustMatch);
  }
  if (index < lowerBound) {
    ThrowHelper::ThrowIndexArgumentOutOfRange_NeedNonNegNumException();
  }
  if (length < 0) {
    ThrowHelper::ThrowLengthArgumentOutOfRange_ArgumentOutOfRange_NeedNonNegNum();
  }
  if (keys->get_Length() - (index - lowerBound) < length || (items != nullptr && index - lowerBound > items->get_Length() - length)) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Argument_InvalidOffLen);
  }
  if (length <= 1) {
    return;
  }
  if (comparer == nullptr) {
    comparer = Comparer::in::Default;
  }
  Object array = rt::as<Object>(keys);
  if (array != nullptr) {
    Object array2 = rt::as<Object>(items);
    if (items == nullptr || array2 != nullptr) {
      rt::newobj<Array<>::in::SorterObjectArray>(array, array2, comparer).Sort(index, length);
      return;
    }
  }
  if (comparer == Comparer::in::Default) {
    CorElementType corElementTypeOfElementType = keys->GetCorElementTypeOfElementType();
    if (items == nullptr || items->GetCorElementTypeOfElementType() == corElementTypeOfElementType) {
      Int32 adjustedIndex2 = index - lowerBound;
      switch (corElementTypeOfElementType) {
        case CorElementType::ELEMENT_TYPE_I1:
          GenericSort<SByte>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_BOOLEAN:
        case CorElementType::ELEMENT_TYPE_U1:
          GenericSort<Byte>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_I2:
          GenericSort<Int16>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_CHAR:
        case CorElementType::ELEMENT_TYPE_U2:
          GenericSort<UInt16>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_I4:
          GenericSort<Int32>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_U4:
          GenericSort<UInt32>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_I8:
        case CorElementType::ELEMENT_TYPE_I:
          GenericSort<Int64>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_U8:
        case CorElementType::ELEMENT_TYPE_U:
          GenericSort<UInt64>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_R4:
          GenericSort<Single>(keys, items, adjustedIndex2, length);
          return;
        case CorElementType::ELEMENT_TYPE_R8:
          GenericSort<Double>(keys, items, adjustedIndex2, length);
          return;
      }
    }
  }
  rt::newobj<Array<>::in::SorterGenericArray>(keys, items, comparer).Sort(index, length);
}

IEnumerator Array___<>::GetEnumerator() {
  Int32 lowerBound = GetLowerBound(0);
  if (get_Rank() == 1 && lowerBound == 0) {
    return rt::newobj<SZArrayEnumerator>((Array<>)this);
  }
  return rt::newobj<ArrayEnumerator>((Array<>)this, lowerBound, get_Length());
}

} // namespace System::Private::CoreLib::System::ArrayNamespace
