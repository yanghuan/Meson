#include "IntPtr-dep.h"

#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::IntPtrNamespace {
Int32 IntPtr::get_Size() {
  return Int32();
};

IntPtr IntPtr::get_MaxValue() {
  return IntPtr();
};

IntPtr IntPtr::get_MinValue() {
  return IntPtr();
};

IntPtr::IntPtr(Int32 value) {
};

IntPtr::IntPtr(Int64 value) {
};

IntPtr::IntPtr(void* value) {
};

IntPtr::IntPtr(SerializationInfo info, StreamingContext context) {
};

Boolean IntPtr::Equals(Object obj) {
  return Boolean();
};

Int32 IntPtr::GetHashCode() {
  return Int32();
};

Int32 IntPtr::ToInt32() {
  return Int32();
};

Int64 IntPtr::ToInt64() {
  return Int64();
};

IntPtr IntPtr::op_Explicit(Int32 value) {
  return IntPtr();
};

IntPtr IntPtr::op_Explicit(Int64 value) {
  return IntPtr();
};

IntPtr IntPtr::op_Explicit(void* value) {
  return IntPtr();
};

void* IntPtr::op_Explicit(IntPtr value, void*) {
  return nullptr;
};

Int32 IntPtr::op_Explicit(IntPtr value, Int32) {
  return Int32();
};

Int64 IntPtr::op_Explicit(IntPtr value, Int64) {
  return Int64();
};

Boolean IntPtr::op_Equality(IntPtr value1, IntPtr value2) {
  return Boolean();
};

Boolean IntPtr::op_Inequality(IntPtr value1, IntPtr value2) {
  return Boolean();
};

IntPtr IntPtr::Add(IntPtr pointer, Int32 offset) {
  return IntPtr();
};

IntPtr IntPtr::op_Addition(IntPtr pointer, Int32 offset) {
  return IntPtr();
};

IntPtr IntPtr::Subtract(IntPtr pointer, Int32 offset) {
  return IntPtr();
};

IntPtr IntPtr::op_Subtraction(IntPtr pointer, Int32 offset) {
  return IntPtr();
};

void* IntPtr::ToPointer() {
  return nullptr;
};

Int32 IntPtr::CompareTo(Object value) {
  return Int32();
};

Int32 IntPtr::CompareTo(IntPtr value) {
  return Int32();
};

Boolean IntPtr::Equals(IntPtr other) {
  return Boolean();
};

String IntPtr::ToString() {
  return nullptr;
};

String IntPtr::ToString(String format) {
  return nullptr;
};

String IntPtr::ToString(IFormatProvider provider) {
  return nullptr;
};

String IntPtr::ToString(String format, IFormatProvider provider) {
  return nullptr;
};

IntPtr IntPtr::Parse(String s) {
  return IntPtr();
};

IntPtr IntPtr::Parse(String s, NumberStyles style) {
  return IntPtr();
};

IntPtr IntPtr::Parse(String s, IFormatProvider provider) {
  return IntPtr();
};

IntPtr IntPtr::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return IntPtr();
};

Boolean IntPtr::TryParse(String s, IntPtr& result) {
  return Boolean();
};

Boolean IntPtr::TryParse(String s, NumberStyles style, IFormatProvider provider, IntPtr& result) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::IntPtrNamespace
