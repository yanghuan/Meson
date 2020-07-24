#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt16.h>

namespace System::Private::CoreLib::System {
enum class StringComparison;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::Uri::System {
enum class ParsingError;
enum class UriComponents;
enum class UriFormat;
enum class UriHostNameType;
enum class UriKind;
enum class UriPartial;
FORWARD(UriFormatException)
FORWARD(UriParser)
namespace UriNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(Uri) {
  public: enum class Flags : uint64_t {
    Zero = 0,
    SchemeNotCanonical = 1,
    UserNotCanonical = 2,
    HostNotCanonical = 4,
    PortNotCanonical = 8,
    PathNotCanonical = 16,
    QueryNotCanonical = 32,
    FragmentNotCanonical = 64,
    CannotDisplayCanonical = 127,
    E_UserNotCanonical = 128,
    E_HostNotCanonical = 256,
    E_PortNotCanonical = 512,
    E_PathNotCanonical = 1024,
    E_QueryNotCanonical = 2048,
    E_FragmentNotCanonical = 4096,
    E_CannotDisplayCanonical = 8064,
    ShouldBeCompressed = 8192,
    FirstSlashAbsent = 16384,
    BackslashInPath = 32768,
    IndexMask = 65535,
    HostTypeMask = 458752,
    HostNotParsed = 0,
    IPv6HostType = 65536,
    IPv4HostType = 131072,
    DnsHostType = 196608,
    UncHostType = 262144,
    BasicHostType = 327680,
    UnusedHostType = 393216,
    UnknownHostType = 458752,
    UserEscaped = 524288,
    AuthorityFound = 1048576,
    HasUserInfo = 2097152,
    LoopbackHost = 4194304,
    NotDefaultPort = 8388608,
    UserDrivenParsing = 16777216,
    CanonicalDnsHost = 33554432,
    ErrorOrParsingRecursion = 67108864,
    DosPath = 134217728,
    UncPath = 268435456,
    ImplicitFile = 536870912,
    MinimalUriInfoSet = 1073741824,
    AllUriInfoSet = 2147483648,
    IdnHost = 4294967296,
    HasUnicode = 8589934592,
    HostUnicodeNormalized = 17179869184,
    RestUnicodeNormalized = 34359738368,
    UnicodeHost = 68719476736,
    IntranetUri = 137438953472,
    UserIriCanonical = 549755813888,
    PathIriCanonical = 1099511627776,
    QueryIriCanonical = 2199023255552,
    FragmentIriCanonical = 4398046511104,
    IriCanonical = 8246337208320,
    UnixPath = 17592186044416,
    CustomParser_ParseMinimalAlreadyCalled = 4611686018427387904,
    Debug_LeftConstructor = 9223372036854775808,
  };
  private: enum class Check {
    None = 0,
    EscapedCanonical = 1,
    DisplayCanonical = 2,
    DotSlashAttn = 4,
    DotSlashEscaped = 128,
    BackslashInPath = 16,
    ReservedFound = 32,
    NotIriCanonical = 64,
    FoundNonAscii = 8,
  };
  private: struct Offset {
    public: UInt16 Scheme;
    public: UInt16 User;
    public: UInt16 Host;
    public: UInt16 PortValue;
    public: UInt16 Path;
    public: UInt16 Query;
    public: UInt16 Fragment;
    public: UInt16 End;
  };
  private: CLASS(MoreInfo) {
    public: void Ctor();
    public: String Path;
    public: String Query;
    public: String Fragment;
    public: String AbsoluteUri;
    public: String RemoteUrl;
  };
  private: CLASS(UriInfo) {
    public: MoreInfo get_MoreInfo();
    public: void Ctor();
    public: Offset Offset;
    public: String String;
    public: ::System::Private::CoreLib::System::String Host;
    public: ::System::Private::CoreLib::System::String IdnHost;
    public: ::System::Private::CoreLib::System::String PathAndQuery;
    public: ::System::Private::CoreLib::System::String ScopeId;
    private: MoreInfo _moreInfo;
  };
  private: Boolean get_IsImplicitFile();
  private: Boolean get_IsUncOrDosPath();
  private: Boolean get_IsDosPath();
  private: Boolean get_IsUncPath();
  private: Flags get_HostType();
  private: UriParser get_Syntax();
  private: Boolean get_IsNotAbsoluteUri();
  private: Boolean get_IriParsing();
  public: Boolean get_UserDrivenParsing();
  private: Int32 get_SecuredPathIndex();
  public: String get_AbsolutePath();
  private: String get_PrivateAbsolutePath();
  public: String get_AbsoluteUri();
  public: String get_LocalPath();
  public: String get_Authority();
  public: UriHostNameType get_HostNameType();
  public: Boolean get_IsDefaultPort();
  public: Boolean get_IsFile();
  public: Boolean get_IsLoopback();
  public: String get_PathAndQuery();
  public: Array<String> get_Segments();
  public: Boolean get_IsUnc();
  public: String get_Host();
  public: Int32 get_Port();
  public: String get_Query();
  public: String get_Fragment();
  public: String get_Scheme();
  public: String get_OriginalString();
  public: String get_DnsSafeHost();
  public: String get_IdnHost();
  public: Boolean get_IsAbsoluteUri();
  public: Boolean get_UserEscaped();
  public: String get_UserInfo();
  public: Boolean get_HasAuthority();
  private: void InterlockedSetFlags(Flags flags);
  public: static Boolean IriParsingStatic(UriParser syntax);
  private: Boolean NotAny(Flags flags);
  private: Boolean InFact(Flags flags);
  private: static Boolean StaticNotAny(Flags allFlags, Flags checkFlags);
  private: static Boolean StaticInFact(Flags allFlags, Flags checkFlags);
  private: UriInfo EnsureUriInfo();
  private: void EnsureParseRemaining();
  private: void EnsureHostString(Boolean allowDnsOptimization);
  public: void Ctor(String uriString);
  public: void Ctor(String uriString, Boolean dontEscape);
  public: void Ctor(Uri baseUri, String relativeUri, Boolean dontEscape);
  public: void Ctor(String uriString, UriKind uriKind);
  public: void Ctor(Uri baseUri, String relativeUri);
  protected: void Ctor(SerializationInfo serializationInfo, StreamingContext streamingContext);
  protected: void GetObjectData(SerializationInfo serializationInfo, StreamingContext streamingContext);
  private: void CreateUri(Uri baseUri, String relativeUri, Boolean dontEscape);
  public: void Ctor(Uri baseUri, Uri relativeUri);
  private: static void GetCombinedString(Uri baseUri, String relativeStr, Boolean dontEscape, String& result);
  private: static UriFormatException GetException(ParsingError err);
  private: static Boolean StaticIsFile(UriParser syntax);
  private: String GetLocalPath();
  public: static UriHostNameType CheckHostName(String name);
  public: String GetLeftPart(UriPartial part);
  public: static String HexEscape(Char character);
  public: static Char HexUnescape(String pattern, Int32& index);
  public: static Boolean IsHexEncoding(String pattern, Int32 index);
  public: static Boolean CheckSchemeName(String schemeName);
  public: static Boolean IsHexDigit(Char character);
  public: static Int32 FromHex(Char digit);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Boolean op_Equality(Uri uri1, Uri uri2);
  public: static Boolean op_Inequality(Uri uri1, Uri uri2);
  public: Boolean Equals(Object comparand);
  public: Uri MakeRelativeUri(Uri uri);
  private: static Boolean CheckForColonInFirstPathSegment(String uriString);
  public: static String InternalEscapeString(String rawString);
  private: static ParsingError ParseScheme(String uriString, Flags& flags, UriParser& syntax);
  public: UriFormatException ParseMinimal();
  private: ParsingError PrivateParseMinimal();
  private: void CreateUriInfo(Flags cF);
  private: void CreateHostString();
  private: static String CreateHostStringHelper(String str, Int32 idx, Int32 end, Flags& flags, String& scopeId);
  private: void GetHostViaCustomSyntax();
  public: String GetParts(UriComponents uriParts, UriFormat formatAs);
  private: String GetEscapedParts(UriComponents uriParts);
  private: String GetUnescapedParts(UriComponents uriParts, UriFormat formatAs);
  private: String ReCreateParts(UriComponents parts, UInt16 nonCanonical, UriFormat formatAs);
  private: String GetUriPartsFromUserString(UriComponents uriParts);
  private: void GetLengthWithoutTrailingSpaces(String str, Int32& length, Int32 idx);
  private: void ParseRemaining();
  private: static Int32 ParseSchemeCheckImplicitFile(Char* uriString, Int32 length, ParsingError& err, Flags& flags, UriParser& syntax);
  private: static ParsingError CheckSchemeSyntax(ReadOnlySpan<Char> span, UriParser& syntax);
  private: Int32 CheckAuthorityHelper(Char* pString, Int32 idx, Int32 length, ParsingError& err, Flags& flags, UriParser syntax, String& newHost);
  private: void CheckAuthorityHelperHandleDnsIri(Char* pString, Int32 start, Int32 end, Boolean hasUnicode, Flags& flags, Boolean& justNormalized, String& newHost, ParsingError& err);
  private: Check CheckCanonical(Char* str, Int32& idx, Int32 end, Char delim);
  private: Array<Char> GetCanonicalPath(Array<Char> dest, Int32& pos, UriFormat formatAs);
  private: static void UnescapeOnly(Char* pch, Int32 start, Int32& end, Char ch1, Char ch2, Char ch3);
  private: static Array<Char> Compress(Array<Char> dest, Int32 start, Int32& destLength, UriParser syntax);
  private: static String CombineUri(Uri basePart, String relativePart, UriFormat uriFormat);
  private: static String PathDifference(String path1, String path2, Boolean compareCase);
  public: String MakeRelative(Uri toUri);
  protected: void Canonicalize();
  protected: void Parse();
  protected: void Escape();
  protected: String Unescape(String path);
  protected: static String EscapeString(String str);
  protected: void CheckSecurity();
  protected: Boolean IsReservedCharacter(Char character);
  protected: static Boolean IsExcludedCharacter(Char character);
  protected: Boolean IsBadFileSystemCharacter(Char character);
  private: void CreateThis(String uri, Boolean dontEscape, UriKind uriKind);
  private: void InitializeUri(ParsingError err, UriKind uriKind, UriFormatException& e);
  private: static Boolean CheckForUnicodeOrEscapedUnreserved(String data);
  public: static Boolean TryCreate(String uriString, UriKind uriKind, Uri& result);
  public: static Boolean TryCreate(Uri baseUri, String relativeUri, Uri& result);
  public: static Boolean TryCreate(Uri baseUri, Uri relativeUri, Uri& result);
  public: String GetComponents(UriComponents components, UriFormat format);
  public: static Int32 Compare(Uri uri1, Uri uri2, UriComponents partsToCompare, UriFormat compareFormat, StringComparison comparisonType);
  public: Boolean IsWellFormedOriginalString();
  public: static Boolean IsWellFormedUriString(String uriString, UriKind uriKind);
  public: Boolean InternalIsWellFormedOriginalString();
  public: static String UnescapeDataString(String stringToUnescape);
  public: static String EscapeUriString(String stringToEscape);
  public: static String EscapeDataString(String stringToEscape);
  public: String EscapeUnescapeIri(String input, Int32 start, Int32 end, UriComponents component);
  private: void Ctor(Flags flags, UriParser uriParser, String uri);
  public: static Uri CreateHelper(String uriString, Boolean dontEscape, UriKind uriKind, UriFormatException& e);
  public: static Uri ResolveHelper(Uri baseUri, Uri relativeUri, String& newUriString, Boolean& userEscaped);
  private: String GetRelativeSerializationString(UriFormat format);
  public: String GetComponentsHelper(UriComponents uriComponents, UriFormat uriFormat);
  public: Boolean IsBaseOf(Uri uri);
  public: Boolean IsBaseOfHelper(Uri uriLink);
  private: void CreateThisFromUri(Uri otherUri);
  private: static void SCtor();
  public: static String UriSchemeFile;
  public: static String UriSchemeFtp;
  public: static String UriSchemeGopher;
  public: static String UriSchemeHttp;
  public: static String UriSchemeHttps;
  public: static String UriSchemeWs;
  public: static String UriSchemeWss;
  public: static String UriSchemeMailto;
  public: static String UriSchemeNews;
  public: static String UriSchemeNntp;
  public: static String UriSchemeNetTcp;
  public: static String UriSchemeNetPipe;
  public: static String SchemeDelimiter;
  private: String _string;
  private: String _originalUnicodeString;
  public: UriParser _syntax;
  public: Flags _flags;
  private: UriInfo _info;
  private: static Array<Char> s_pathDelims;
};
} // namespace UriNamespace
using Uri = UriNamespace::Uri;
} // namespace System::Private::Uri::System
