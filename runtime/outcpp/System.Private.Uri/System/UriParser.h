#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::Uri::System {
enum class UriComponents;
enum class UriFormat;
enum class UriSyntaxFlags;
FORWARD(Uri)
FORWARD(UriFormatException)
namespace UriParserNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(UriParser) : public Object::in {
  friend class BuiltInUriParser___;
  public: String get_SchemeName();
  public: Int32 get_DefaultPort();
  public: UriSyntaxFlags get_Flags();
  public: Boolean get_IsSimple();
  protected: void Ctor();
  protected: UriParser OnNewUri();
  protected: void OnRegister(String schemeName, Int32 defaultPort);
  protected: void InitializeAndValidate(Uri uri, UriFormatException& parsingError);
  protected: String Resolve(Uri baseUri, Uri relativeUri, UriFormatException& parsingError);
  protected: Boolean IsBaseOf(Uri baseUri, Uri relativeUri);
  protected: String GetComponents(Uri uri, UriComponents components, UriFormat format);
  protected: Boolean IsWellFormedOriginalString(Uri uri);
  public: static void Register(UriParser uriParser, String schemeName, Int32 defaultPort);
  public: static Boolean IsKnownScheme(String schemeName);
  public: Boolean NotAny(UriSyntaxFlags flags);
  public: Boolean InFact(UriSyntaxFlags flags);
  public: Boolean IsAllSet(UriSyntaxFlags flags);
  private: Boolean IsFullMatch(UriSyntaxFlags flags, UriSyntaxFlags expected);
  public: void Ctor(UriSyntaxFlags flags);
  private: static void FetchSyntax(UriParser syntax, String lwrCaseSchemeName, Int32 defaultPort);
  public: static UriParser FindOrFetchAsUnknownV1Syntax(String lwrCaseScheme);
  public: static UriParser GetSyntax(String lwrCaseScheme);
  public: void CheckSetIsSimpleFlag();
  public: UriParser InternalOnNewUri();
  public: void InternalValidate(Uri thisUri, UriFormatException& parsingError);
  public: String InternalResolve(Uri thisBaseUri, Uri uriLink, UriFormatException& parsingError);
  public: Boolean InternalIsBaseOf(Uri thisBaseUri, Uri uriLink);
  public: String InternalGetComponents(Uri thisUri, UriComponents uriComponents, UriFormat uriFormat);
  public: Boolean InternalIsWellFormedOriginalString(Uri thisUri);
  private: static void SCtor();
  public: static UriParser HttpUri;
  public: static UriParser HttpsUri;
  public: static UriParser WsUri;
  public: static UriParser WssUri;
  public: static UriParser FtpUri;
  public: static UriParser FileUri;
  public: static UriParser UnixFileUri;
  public: static UriParser GopherUri;
  public: static UriParser NntpUri;
  public: static UriParser NewsUri;
  public: static UriParser MailToUri;
  public: static UriParser UuidUri;
  public: static UriParser TelnetUri;
  public: static UriParser LdapUri;
  public: static UriParser NetTcpUri;
  public: static UriParser NetPipeUri;
  public: static UriParser VsMacrosUri;
  private: static Hashtable s_table;
  private: static Hashtable s_tempTable;
  private: UriSyntaxFlags _flags;
  private: Int32 _port;
  private: String _scheme;
};
CLASS(BuiltInUriParser) : public UriParser::in {
  public: void Ctor(String lwrCaseScheme, Int32 defaultPort, UriSyntaxFlags syntaxFlags);
};
} // namespace UriParserNamespace
using UriParser = UriParserNamespace::UriParser;
} // namespace System::Private::Uri::System
