#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Console::System::Text {
namespace EncodingExtensionsNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class EncodingExtensions {
  public: static Encoding RemovePreamble(Encoding encoding);
};
} // namespace EncodingExtensionsNamespace
using EncodingExtensions = EncodingExtensionsNamespace::EncodingExtensions;
} // namespace System::Console::System::Text
