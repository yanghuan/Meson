#include "Normalization-dep.h"

namespace System::Private::CoreLib::System::Globalization::NormalizationNamespace {
Boolean Normalization::IsNormalized(String strInput, NormalizationForm normalizationForm) {
  return Boolean();
}

String Normalization::Normalize(String strInput, NormalizationForm normalizationForm) {
  return nullptr;
}

Boolean Normalization::IcuIsNormalized(String strInput, NormalizationForm normalizationForm) {
  return Boolean();
}

String Normalization::IcuNormalize(String strInput, NormalizationForm normalizationForm) {
  return nullptr;
}

void Normalization::ValidateArguments(String strInput, NormalizationForm normalizationForm) {
}

Boolean Normalization::HasInvalidUnicodeSequence(String s) {
  return Boolean();
}

Boolean Normalization::NlsIsNormalized(String strInput, NormalizationForm normalizationForm) {
  return Boolean();
}

String Normalization::NlsNormalize(String strInput, NormalizationForm normalizationForm) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Globalization::NormalizationNamespace
