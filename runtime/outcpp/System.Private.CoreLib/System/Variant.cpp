#include "Variant-dep.h"

namespace System::Private::CoreLib::System::VariantNamespace {
Int32 Variant::get_CVType() {
  return Int32();
};

Variant::Variant(Int32 flags, Object or_, Int64 data) {
};

Variant::Variant(Boolean val) {
};

Variant::Variant(SByte val) {
};

Variant::Variant(Byte val) {
};

Variant::Variant(Int16 val) {
};

Variant::Variant(UInt16 val) {
};

Variant::Variant(Char val) {
};

Variant::Variant(Int32 val) {
};

Variant::Variant(UInt32 val) {
};

Variant::Variant(Int64 val) {
};

Variant::Variant(UInt64 val) {
};

Variant::Variant(Single val) {
};

Variant::Variant(Double val) {
};

Variant::Variant(DateTime val) {
};

Variant::Variant(Decimal val) {
};

Variant::Variant(Object obj) {
};

Object Variant::ToObject() {
  return nullptr;
};

void Variant::MarshalHelperConvertObjectToVariant(Object o, Variant& v) {
};

Object Variant::MarshalHelperConvertVariantToObject(Variant& v) {
  return nullptr;
};

void Variant::MarshalHelperCastVariant(Object pValue, Int32 vt, Variant& v) {
};

void Variant::SCtor() {
};

} // namespace System::Private::CoreLib::System::VariantNamespace
