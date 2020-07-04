#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm;
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
namespace NormalizationNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class Normalization {
  public: static Boolean IsNormalized(String strInput, NormalizationForm normalizationForm);
  public: static String Normalize(String strInput, NormalizationForm normalizationForm);
  private: static Boolean IcuIsNormalized(String strInput, NormalizationForm normalizationForm);
  private: static String IcuNormalize(String strInput, NormalizationForm normalizationForm);
  private: static void ValidateArguments(String strInput, NormalizationForm normalizationForm);
  private: static Boolean HasInvalidUnicodeSequence(String s);
  private: static Boolean NlsIsNormalized(String strInput, NormalizationForm normalizationForm);
  private: static String NlsNormalize(String strInput, NormalizationForm normalizationForm);
};
} // namespace NormalizationNamespace
using Normalization = NormalizationNamespace::Normalization;
} // namespace System::Private::CoreLib::System::Globalization
