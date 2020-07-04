#include "Array-dep.h"

namespace System::Private::CoreLib::System::ArrayNamespace {
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
Int32 Array___<>::get_Length() {
  return Int32();
};
Int64 Array___<>::get_LongLength() {
  return Int64();
};
Int32 Array___<>::get_Rank() {
  return Int32();
};
Int32 Array___<>::get_CountOfICollection() {
  return Int32();
};
Object Array___<>::get_SyncRoot() {
  return nullptr;
};
Boolean Array___<>::get_IsReadOnly() {
  return Boolean();
};
Boolean Array___<>::get_IsFixedSize() {
  return Boolean();
};
Boolean Array___<>::get_IsSynchronized() {
  return Boolean();
};
Object Array___<>::get_ItemOfIList(Int32 index) {
  return nullptr;
};
void Array___<>::set_ItemOfIList(Int32 index, Object value) {
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length) {
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2) {
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Int32 length1, Int32 length2, Int32 length3) {
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Array<Int32> lengths) {
  return nullptr;
};
Array<> Array___<>::CreateInstance(Type elementType, Array<Int32> lengths, Array<Int32> lowerBounds) {
  return nullptr;
};
void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int32 length) {
};
void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
};
void Array___<>::Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length, Boolean reliable) {
};
void Array___<>::ConstrainedCopy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length) {
};
void Array___<>::Clear(Array<> array, Int32 index, Int32 length) {
};
Object Array___<>::GetValue(Array<Int32> indices) {
  return nullptr;
};
Object Array___<>::GetValue(Int32 index) {
  return nullptr;
};
Object Array___<>::GetValue(Int32 index1, Int32 index2) {
  return nullptr;
};
Object Array___<>::GetValue(Int32 index1, Int32 index2, Int32 index3) {
  return nullptr;
};
void Array___<>::SetValue(Object value, Int32 index) {
};
void Array___<>::SetValue(Object value, Int32 index1, Int32 index2) {
};
void Array___<>::SetValue(Object value, Int32 index1, Int32 index2, Int32 index3) {
};
void Array___<>::SetValue(Object value, Array<Int32> indices) {
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
Array<> Array___<>::CreateInstance(Type elementType, Array<Int64> lengths) {
  return nullptr;
};
void Array___<>::Copy(Array<> sourceArray, Array<> destinationArray, Int64 length) {
};
void Array___<>::Copy(Array<> sourceArray, Int64 sourceIndex, Array<> destinationArray, Int64 destinationIndex, Int64 length) {
};
Object Array___<>::GetValue(Int64 index) {
  return nullptr;
};
Object Array___<>::GetValue(Int64 index1, Int64 index2) {
  return nullptr;
};
Object Array___<>::GetValue(Int64 index1, Int64 index2, Int64 index3) {
  return nullptr;
};
Object Array___<>::GetValue(Array<Int64> indices) {
  return nullptr;
};
void Array___<>::SetValue(Object value, Int64 index) {
};
void Array___<>::SetValue(Object value, Int64 index1, Int64 index2) {
};
void Array___<>::SetValue(Object value, Int64 index1, Int64 index2, Int64 index3) {
};
void Array___<>::SetValue(Object value, Array<Int64> indices) {
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
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value) {
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Object value, IComparer comparer) {
  return Int32();
};
Int32 Array___<>::BinarySearch(Array<> array, Int32 index, Int32 length, Object value, IComparer comparer) {
  return Int32();
};
void Array___<>::CopyTo(Array<> array, Int32 index) {
};
void Array___<>::CopyTo(Array<> array, Int64 index) {
};
Int32 Array___<>::IndexOf(Array<> array, Object value) {
  return Int32();
};
Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex) {
  return Int32();
};
Int32 Array___<>::IndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value) {
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex) {
  return Int32();
};
Int32 Array___<>::LastIndexOf(Array<> array, Object value, Int32 startIndex, Int32 count) {
  return Int32();
};
void Array___<>::Reverse(Array<> array) {
};
void Array___<>::Reverse(Array<> array, Int32 index, Int32 length) {
};
void Array___<>::Sort(Array<> array) {
};
void Array___<>::Sort(Array<> keys, Array<> items) {
};
void Array___<>::Sort(Array<> array, Int32 index, Int32 length) {
};
void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length) {
};
void Array___<>::Sort(Array<> array, IComparer comparer) {
};
void Array___<>::Sort(Array<> keys, Array<> items, IComparer comparer) {
};
void Array___<>::Sort(Array<> array, Int32 index, Int32 length, IComparer comparer) {
};
void Array___<>::Sort(Array<> keys, Array<> items, Int32 index, Int32 length, IComparer comparer) {
};
IEnumerator Array___<>::GetEnumerator() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::ArrayNamespace
