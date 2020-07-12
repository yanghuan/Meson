#include "Variant-dep.h"

namespace System::Private::CoreLib::System::VariantNamespace {
Int32 Variant::get_CVType() {
  return Int32();
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

} // namespace System::Private::CoreLib::System::VariantNamespace
