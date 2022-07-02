#include "ParserHelpers-dep.h"

#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::ParserHelpersNamespace {
Boolean ParserHelpers::IsDigit(Int32 i) {
  return (UInt32)(i - 48) <= 9u;
}

Boolean ParserHelpers::TryParseThrowFormatException(Int32& bytesConsumed) {
  bytesConsumed = 0;
  ThrowHelper::ThrowFormatException_BadFormatSpecifier();
  return false;
}

} // namespace System::Private::CoreLib::System::Buffers::Text::ParserHelpersNamespace
