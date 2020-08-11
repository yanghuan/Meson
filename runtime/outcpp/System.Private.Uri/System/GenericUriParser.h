#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
enum class GenericUriParserOptions : int32_t;
enum class UriSyntaxFlags : int32_t;
namespace GenericUriParserNamespace {
CLASS(GenericUriParser) : public UriParser::in {
  public: void ctor(GenericUriParserOptions options);
  private: static UriSyntaxFlags MapGenericParserOptions(GenericUriParserOptions options);
};
} // namespace GenericUriParserNamespace
using GenericUriParser = GenericUriParserNamespace::GenericUriParser;
} // namespace System::Private::Uri::System
