#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
namespace StringNormalizationExtensionsNamespace {
using namespace Text;
class StringNormalizationExtensions : public Object::in {
  public: static Boolean IsNormalized(String strInput);
  public: static Boolean IsNormalized(String strInput, NormalizationForm normalizationForm);
  public: static String Normalize(String strInput);
  public: static String Normalize(String strInput, NormalizationForm normalizationForm);
};
} // namespace StringNormalizationExtensionsNamespace
using StringNormalizationExtensions = StringNormalizationExtensionsNamespace::StringNormalizationExtensions;
} // namespace System::Private::CoreLib::System
