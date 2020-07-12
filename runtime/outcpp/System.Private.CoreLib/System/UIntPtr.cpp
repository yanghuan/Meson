#include "UIntPtr-dep.h"

#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::UIntPtrNamespace {
Int32 UIntPtr::get_Size() {
  return Int32();
};

UIntPtr UIntPtr::get_MaxValue() {
  return UIntPtr();
};

UIntPtr UIntPtr::get_MinValue() {
  return UIntPtr();
};

Boolean UIntPtr::Equals(Object obj) {
  return Boolean();
};

Int32 UIntPtr::GetHashCode() {
  return Int32();
};

UInt32 UIntPtr::ToUInt32() {
  return UInt32();
};

UInt64 UIntPtr::ToUInt64() {
  return UInt64();
};

UIntPtr UIntPtr::op_Explicit(UInt32 value) {
  return UIntPtr();
};

UIntPtr UIntPtr::op_Explicit(UInt64 value) {
  return UIntPtr();
};

UIntPtr UIntPtr::op_Explicit(void* value) {
  return UIntPtr();
};

void* UIntPtr::op_Explicit(UIntPtr value) {
  return nullptr;
};

UInt32 UIntPtr::op_Explicit(UIntPtr value) {
  return UInt32();
};

UInt64 UIntPtr::op_Explicit(UIntPtr value) {
  return UInt64();
};

Boolean UIntPtr::op_Equality(UIntPtr value1, UIntPtr value2) {
  return Boolean();
};

Boolean UIntPtr::op_Inequality(UIntPtr value1, UIntPtr value2) {
  return Boolean();
};

UIntPtr UIntPtr::Add(UIntPtr pointer, Int32 offset) {
  return UIntPtr();
};

UIntPtr UIntPtr::op_Addition(UIntPtr pointer, Int32 offset) {
  return UIntPtr();
};

UIntPtr UIntPtr::Subtract(UIntPtr pointer, Int32 offset) {
  return UIntPtr();
};

UIntPtr UIntPtr::op_Subtraction(UIntPtr pointer, Int32 offset) {
  return UIntPtr();
};

void* UIntPtr::ToPointer() {
  return nullptr;
};

Int32 UIntPtr::CompareTo(Object value) {
  return Int32();
};

Int32 UIntPtr::CompareTo(UIntPtr value) {
  return Int32();
};

Boolean UIntPtr::Equals(UIntPtr other) {
  return Boolean();
};

String UIntPtr::ToString() {
  return nullptr;
};

String UIntPtr::ToString(String format) {
  return nullptr;
};

String UIntPtr::ToString(IFormatProvider provider) {
  return nullptr;
};

String UIntPtr::ToString(String format, IFormatProvider provider) {
  return nullptr;
};

UIntPtr UIntPtr::Parse(String s) {
  return UIntPtr();
};

UIntPtr UIntPtr::Parse(String s, NumberStyles style) {
  return UIntPtr();
};

UIntPtr UIntPtr::Parse(String s, IFormatProvider provider) {
  return UIntPtr();
};

UIntPtr UIntPtr::Parse(String s, NumberStyles style, IFormatProvider provider) {
  return UIntPtr();
};

Boolean UIntPtr::TryParse(String s, UIntPtr& result) {
  return Boolean();
};

Boolean UIntPtr::TryParse(String s, NumberStyles style, IFormatProvider provider, UIntPtr& result) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::UIntPtrNamespace
