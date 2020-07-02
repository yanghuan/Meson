#pragma once

#include <rt/GCObject.h>

namespace System::Private::Uri::System {
enum class GenericUriParserOptions;
enum class UriSyntaxFlags;
namespace GenericUriParserNamespace {
CLASS(GenericUriParser) {
  private: static UriSyntaxFlags MapGenericParserOptions(GenericUriParserOptions options);
};
} // namespace GenericUriParserNamespace
using GenericUriParser = GenericUriParserNamespace::GenericUriParser;
} // namespace System::Private::Uri::System
