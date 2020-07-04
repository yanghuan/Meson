#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
namespace StringNormalizationExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class StringNormalizationExtensions {
  public: static Boolean IsNormalized(String strInput);
  public: static Boolean IsNormalized(String strInput, NormalizationForm normalizationForm);
  public: static String Normalize(String strInput);
  public: static String Normalize(String strInput, NormalizationForm normalizationForm);
};
} // namespace StringNormalizationExtensionsNamespace
using StringNormalizationExtensions = StringNormalizationExtensionsNamespace::StringNormalizationExtensions;
} // namespace System::Private::CoreLib::System
