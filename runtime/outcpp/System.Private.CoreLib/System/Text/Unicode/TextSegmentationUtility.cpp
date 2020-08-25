#include "TextSegmentationUtility-dep.h"

namespace System::Private::CoreLib::System::Text::Unicode::TextSegmentationUtilityNamespace {
Int32 TextSegmentationUtility::GetLengthOfFirstUtf16ExtendedGraphemeCluster(ReadOnlySpan<Char> input) {
  return GetLengthOfFirstExtendedGraphemeCluster(input, _utf16Decoder);
}

void TextSegmentationUtility::cctor() {
  _utf16Decoder = &Rune::DecodeFromUtf16;
}

} // namespace System::Private::CoreLib::System::Text::Unicode::TextSegmentationUtilityNamespace
