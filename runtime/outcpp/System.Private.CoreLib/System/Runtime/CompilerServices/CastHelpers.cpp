#include "CastHelpers-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/CastHelpers-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::CastHelpersNamespace {
Int32 CastHelpers::KeyToBucket(Int32& tableData, UIntPtr source, UIntPtr target) {
  return Int32();
}

Int32& CastHelpers::TableData(Array<Int32> table) {
  return Int32();
}

CastHelpers::CastCacheEntry& CastHelpers::Element(Int32& tableData, Int32 index) {
  return CastHelpers::CastCacheEntry();
}

Int32 CastHelpers::HashShift(Int32& tableData) {
  return Int32();
}

Int32 CastHelpers::TableMask(Int32& tableData) {
  return Int32();
}

CastHelpers::CastResult CastHelpers::TryGet(UIntPtr source, UIntPtr target) {
  return CastHelpers::CastResult::MaybeCast;
}

Object CastHelpers::IsInstanceOfAny(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::IsInstanceOfInterface(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::IsInstanceOfClass(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::IsInstance_Helper(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::ChkCastAny(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::ChkCast_Helper(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::ChkCastInterface(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::ChkCastClass(void* toTypeHnd, Object obj) {
  return nullptr;
}

Object CastHelpers::ChkCastClassSpecial(void* toTypeHnd, Object obj) {
  return nullptr;
}

Byte& CastHelpers::Unbox(void* toTypeHnd, Object obj) {
  return Byte();
}

Object& CastHelpers::ThrowArrayMismatchException() {
  return Object();
}

Object& CastHelpers::LdelemaRef(Array<> array, Int32 index, void* type) {
  return Object();
}

void CastHelpers::StelemRef(Array<> array, Int32 index, Object obj) {
}

void CastHelpers::StelemRef_Helper(Object& element, void* elementType, Object obj) {
}

void CastHelpers::StelemRef_Helper_NoCacheLookup(Object& element, void* elementType, Object obj) {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::CastHelpersNamespace
