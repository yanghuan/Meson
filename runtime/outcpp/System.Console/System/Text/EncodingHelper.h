#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System::Text {
namespace EncodingHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
class EncodingHelper {
  public: static Encoding GetSupportedConsoleEncoding(Int32 codepage);
};
} // namespace EncodingHelperNamespace
using EncodingHelper = EncodingHelperNamespace::EncodingHelper;
} // namespace System::Console::System::Text
