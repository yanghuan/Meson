#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
enum class GenericUriParserOptions;
enum class UriSyntaxFlags;
namespace GenericUriParserNamespace {
CLASS(GenericUriParser) : public UriParser::in {
  public: void ctor(GenericUriParserOptions options);
  private: static UriSyntaxFlags MapGenericParserOptions(GenericUriParserOptions options);
};
} // namespace GenericUriParserNamespace
using GenericUriParser = GenericUriParserNamespace::GenericUriParser;
} // namespace System::Private::Uri::System
