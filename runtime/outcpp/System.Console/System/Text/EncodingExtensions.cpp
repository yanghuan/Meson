#include "EncodingExtensions-dep.h"

#include <System.Console/System/Text/ConsoleEncoding-dep.h>

namespace System::Console::System::Text::EncodingExtensionsNamespace {
Encoding EncodingExtensions::RemovePreamble(Encoding encoding) {
  if (encoding->get_Preamble().get_Length() == 0) {
    return encoding;
  }
  return rt::newobj<ConsoleEncoding>(encoding);
}

} // namespace System::Console::System::Text::EncodingExtensionsNamespace
