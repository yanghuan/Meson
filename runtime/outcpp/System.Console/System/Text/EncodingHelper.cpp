#include "EncodingHelper-dep.h"

#include <System.Console/System/Text/OSEncoding-dep.h>
#include <System.Private.CoreLib/System/Text/UTF8Encoding-dep.h>

namespace System::Console::System::Text::EncodingHelperNamespace {
using namespace ::System::Private::CoreLib::System::Text;

Encoding EncodingHelper::GetSupportedConsoleEncoding(Int32 codepage) {
  Int32 codePage = Encoding::in::GetEncoding((Int32)0)->get_CodePage();
  if (codePage == codepage || codePage != Encoding::in::get_UTF8()->get_CodePage()) {
    return Encoding::in::GetEncoding(codepage);
  }
  if (codepage != Encoding::in::get_UTF8()->get_CodePage()) {
    return rt::newobj<OSEncoding>(codepage);
  }
  return rt::newobj<UTF8Encoding>(false);
}

} // namespace System::Console::System::Text::EncodingHelperNamespace
