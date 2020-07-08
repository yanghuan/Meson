#include "Array-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TypedReference-dep.h>

namespace System::Private::CoreLib::System::ArrayNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
void Array___<>::SorterObjectArray::SwapIfGreater(Int32 a, Int32 b) {
};
void Array___<>::SorterObjectArray::Swap(Int32 i, Int32 j) {
};
void Array___<>::SorterObjectArray::Sort(Int32 left, Int32 length) {
};
void Array___<>::SorterObjectArray::IntrospectiveSort(Int32 left, Int32 length) {
};
void Array___<>::SorterObjectArray::IntroSort(Int32 lo, Int32 hi, Int32 depthLimit) {
};
Int32 Array___<>::SorterObjectArray::PickPivotAndPartition(Int32 lo, Int32 hi) {
  return Int32();
};
void Array___<>::SorterObjectArray::Heapsort(Int32 lo, Int32 hi) {
};
void Array___<>::SorterObjectArray::DownHeap(Int32 i, Int32 n, Int32 lo) {
};
void Array___<>::SorterObjectArray::InsertionSort(Int32 lo, Int32 hi) {
};
void Array___<>::SorterGenericArray::SwapIfGreater(Int32 a, Int32 b) {
};
void Array___<>::SorterGenericArray::Swap(Int32 i, Int32 j) {
};
void Array___<>::SorterGenericArray::Sort(Int32 left, Int32 length) {
};
void Array___<>::SorterGenericArray::IntrospectiveSort(Int32 left, Int32 length) {
};
void Array___<>::SorterGenericArray::IntroSort(Int32 lo, Int32 hi, Int32 depthLimit) {
};
Int32 Array___<>::SorterGenericArray::PickPivotAndPartition(Int32 lo, Int32 hi) {
  return Int32();
};
void Array___<>::SorterGenericArray::Heapsort(Int32 lo, Int32 hi) {
};
void Array___<>::SorterGenericArray::DownHeap(Int32 i, Int32 n, Int32 lo) {
};
void Array___<>::SorterGenericArray::InsertionSort(Int32 lo, Int32 hi) {
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length) {
  if ((elementType)Object1 == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2) {
  if ((elementType)Object1 == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2, Int32 length3) {
  if ((elementType)Object1 == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Array<Int32> lengths) {
  if ((elementType)Object1 == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::elementType);
  }
  if (lengths == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lengths);
  }
  return nullptr;
};
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
  return nullptr;
};
void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int32 length) {
  if (sourceArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::sourceArray);
  }
  if (destinationArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::destinationArray);
  }
};
void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
};
void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length, Boolean reliable) {
  if (sourceArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::sourceArray);
  }
  if (destinationArray == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::destinationArray);
  }
};
void Array___<>::ConstrainedCopy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
};
void Array___<>::Clear(Array<> array, Int32 index, Int32 length) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
};
Object Array___<>::GetValue(Array<Int32> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  return nullptr;
};
Object Array___<>::GetValue(Int32 index) {
  if (get_Rank() != 1) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need1DArray);
  }
  return nullptr;
};
Object Array___<>::GetValue(Int32 index1, Int32 index2) {
  if (get_Rank() != 2) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need2DArray);
  }
  return nullptr;
};
Object Array___<>::GetValue(Int32 index1, Int32 index2, Int32 index3) {
  if (get_Rank() != 3) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need3DArray);
  }
  return nullptr;
};
void Array___<>::SetValue(Object value, Int32 index) {
  if (get_Rank() != 1) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need1DArray);
  }
};
void Array___<>::SetValue(Object value, Int32 index1, Int32 index2) {
  if (get_Rank() != 2) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need2DArray);
  }
};
void Array___<>::SetValue(Object value, Int32 index1, Int32 index2, Int32 index3) {
  if (get_Rank() != 3) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Arg_Need3DArray);
  }
};
void Array___<>::SetValue(Object value, Array<Int32> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
};
Int32 Array___<>::GetLength(Int32 dimension) {
  return Int32();
};
Int32 Array___<>::GetUpperBound(Int32 dimension) {
  return Int32();
};
Int32 Array___<>::GetLowerBound(Int32 dimension) {
  return Int32();
};
Boolean Array___<>::IsValueOfElementType(Object value) {
  return Boolean();
};
Array<> Array___<>::CreateInstance(Type elementType, Array<Int64> lengths) {
  if (lengths == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::lengths);
  }
  return nullptr;
};
void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int64 length) {
  Int321 num == (length)Int321;
  if (length != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::length, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  Copy(sourceArray, destinationArray, num);
};
void Array___<>::Copy(Array<> sourceArray, Int64 sourceIndex, Array<> destinationArray, Int64 destinationIndex, Int64 length) {
  Int321 num == (sourceIndex)Int321;
  Int321 num2 == (destinationIndex)Int321;
  Int321 num3 == (length)Int321;
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
};
Object Array___<>::GetValue(Int64 index) {
  Int321 num == (index)Int321;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return nullptr;
};
Object Array___<>::GetValue(Int64 index1, Int64 index2) {
  Int321 num == (index1)Int321;
  Int321 num2 == (index2)Int321;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return nullptr;
};
Object Array___<>::GetValue(Int64 index1, Int64 index2, Int64 index3) {
  Int321 num == (index1)Int321;
  Int321 num2 == (index2)Int321;
  Int321 num3 == (index3)Int321;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index3 != num3) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index3, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  return nullptr;
};
Object Array___<>::GetValue(Array<Int64> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
  return nullptr;
};
void Array___<>::SetValue(Object value, Int64 index) {
  Int321 num == (index)Int321;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  SetValue(value, num);
};
void Array___<>::SetValue(Object value, Int64 index1, Int64 index2) {
  Int321 num == (index1)Int321;
  Int321 num2 == (index2)Int321;
  if (index1 != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index1, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  if (index2 != num2) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index2, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  SetValue(value, num, num2);
};
void Array___<>::SetValue(Object value, Int64 index1, Int64 index2, Int64 index3) {
  Int321 num == (index1)Int321;
  Int321 num2 == (index2)Int321;
  Int321 num3 == (index3)Int321;
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
};
void Array___<>::SetValue(Object value, Array<Int64> indices) {
  if (indices == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::indices);
  }
};
Int32 Array___<>::GetMedian(Int32 low, Int32 hi) {
  return Int32();
};
Int64 Array___<>::GetLongLength(Int32 dimension) {
  return Int64();
};
Object Array___<>::Clone() {
  return nullptr;
};
Int32 Array___<>::BinarySearch(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value) {
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Object value, IComparer comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value, IComparer comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
  return Int32();
};
void Array___<>::CopyTo(Array<> array, Int32 index) {
};
void Array___<>::CopyTo(Array<> array, Int64 index) {
  Int321 num == (index)Int321;
  if (index != num) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index, ExceptionResource::ArgumentOutOfRange_HugeArrayNotSupported);
  }
  CopyTo(array, num);
};
Int32 Array___<>::IndexOf(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return Int32();
};
Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
  return Int32();
};
Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
  return Int32();
};
void Array___<>::Reverse(Array<> array) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
};
void Array___<>::Reverse(Array<> array, Int32 index, Int32 length) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
  Int321 lowerBound == array->GetLowerBound(0);
};
void Array___<>::Sort(Array<> array) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
};
void Array___<>::Sort(Array<> keys, Array<> items) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
};
void Array___<>::Sort(Array<> array, Int32 index, Int32 length) {
  Sort(array, nullptr, index, length, nullptr);
};
void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length) {
  Sort(keys, items, index, length, nullptr);
};
void Array___<>::Sort(Array<> array, IComparer comparer) {
  if (array == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::array);
  }
};
void Array___<>::Sort(Array<> keys, Array<> items, IComparer comparer) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
};
void Array___<>::Sort(Array<> array, Int32 index, Int32 length, IComparer comparer) {
  Sort(array, nullptr, index, length, comparer);
};
void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length, IComparer comparer) {
  if (keys == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::keys);
  }
};
IEnumerator Array___<>::GetEnumerator() {
  Int321 lowerBound == GetLowerBound(0);
  return nullptr;
};
} // namespace System::Private::CoreLib::System::ArrayNamespace
