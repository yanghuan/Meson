#include "StringNormalizationExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Text/NormalizationForm.h>

namespace System::Private::CoreLib::System::StringNormalizationExtensionsNamespace {
using namespace System::Text;

Boolean StringNormalizationExtensions::IsNormalized(String strInput) {
  return IsNormalized(strInput, NormalizationForm::FormC);
}

Boolean StringNormalizationExtensions::IsNormalized(String strInput, NormalizationForm normalizationForm) {
  if (strInput == nullptr) {
    rt::throw_exception<ArgumentNullException>("strInput");
  }
  return strInput->IsNormalized(normalizationForm);
}

String StringNormalizationExtensions::Normalize(String strInput) {
  return Normalize(strInput, NormalizationForm::FormC);
}

String StringNormalizationExtensions::Normalize(String strInput, NormalizationForm normalizationForm) {
  if (strInput == nullptr) {
    rt::throw_exception<ArgumentNullException>("strInput");
  }
  return strInput->Normalize(normalizationForm);
}

} // namespace System::Private::CoreLib::System::StringNormalizationExtensionsNamespace
