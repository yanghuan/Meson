#include "Utf8Constants-dep.h"

#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::Utf8ConstantsNamespace {
void Utf8Constants::cctor() {
  NullUtcOffset = TimeSpan::MinValue;
}

} // namespace System::Private::CoreLib::System::Buffers::Text::Utf8ConstantsNamespace
