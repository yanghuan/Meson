#include "Uri-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/NormalizationForm.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.Uri/System/Collections/Generic/ArrayBuilder-dep.h>
#include <System.Private.Uri/System/DomainNameHelper-dep.h>
#include <System.Private.Uri/System/IPv4AddressHelper-dep.h>
#include <System.Private.Uri/System/IPv6AddressHelper-dep.h>
#include <System.Private.Uri/System/IriHelper-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.Uri/System/UnescapeMode.h>
#include <System.Private.Uri/System/Uri-dep.h>
#include <System.Private.Uri/System/UriComponents.h>
#include <System.Private.Uri/System/UriFormat.h>
#include <System.Private.Uri/System/UriHelper-dep.h>
#include <System.Private.Uri/System/UriKind.h>
#include <System.Private.Uri/System/UriSyntaxFlags.h>

namespace System::Private::Uri::System::UriNamespace {
using namespace ::System::Private::CoreLib::Internal::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
using namespace ::System::Private::CoreLib::System::Threading;
using namespace System::Collections::Generic;
using namespace System::Text;

void Uri___::MoreInfo___::ctor() {
}

Uri::in::MoreInfo Uri___::UriInfo___::get_MoreInfo() {
  if (_moreInfo == nullptr) {
    Interlocked::CompareExchange(_moreInfo, rt::newobj<MoreInfo>(), nullptr);
  }
  return _moreInfo;
}

void Uri___::UriInfo___::ctor() {
}

Boolean Uri___::get_IsImplicitFile() {
}

Boolean Uri___::get_IsUncOrDosPath() {
}

Boolean Uri___::get_IsDosPath() {
}

Boolean Uri___::get_IsUncPath() {
}

Uri::in::Flags Uri___::get_HostType() {
}

UriParser Uri___::get_Syntax() {
  return _syntax;
}

Boolean Uri___::get_IsNotAbsoluteUri() {
  return _syntax == nullptr;
}

Boolean Uri___::get_IriParsing() {
  return IriParsingStatic(_syntax);
}

Boolean Uri___::get_UserDrivenParsing() {
}

Int32 Uri___::get_SecuredPathIndex() {
  if (get_IsDosPath()) {
    Char c = _string[_info->Offset.Path];
    if (c != 47 && c != 92) {
      return 2;
    }
    return 3;
  }
  return 0;
}

String Uri___::get_AbsolutePath() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  String text = get_PrivateAbsolutePath();
  if (get_IsDosPath() && text[0] == 47) {
    text = text->Substring(1);
  }
  return text;
}

String Uri___::get_PrivateAbsolutePath() {
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
}

String Uri___::get_AbsoluteUri() {
  if (_syntax == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
}

String Uri___::get_LocalPath() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return GetLocalPath();
}

String Uri___::get_Authority() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
}

UriHostNameType Uri___::get_HostNameType() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (_syntax->get_IsSimple()) {
    EnsureUriInfo();
  } else {
    EnsureHostString(false);
  }
  switch (get_HostType()) {
    case Flags::DnsHostType:
      return UriHostNameType::Dns;
    case Flags::IPv4HostType:
      return UriHostNameType::IPv4;
    case Flags::IPv6HostType:
      return UriHostNameType::IPv6;
    case Flags::BasicHostType:
      return UriHostNameType::Basic;
    case Flags::UncHostType:
      return UriHostNameType::Basic;
    case Flags::HostTypeMask:
      return UriHostNameType::Unknown;
    default:
      return UriHostNameType::Unknown;
  }
}

Boolean Uri___::get_IsDefaultPort() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (_syntax->get_IsSimple()) {
    EnsureUriInfo();
  } else {
    EnsureHostString(false);
  }
  return NotAny(Flags::NotDefaultPort);
}

Boolean Uri___::get_IsFile() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return (Object)_syntax->get_SchemeName() == UriSchemeFile;
}

Boolean Uri___::get_IsLoopback() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  EnsureHostString(false);
  return InFact(Flags::LoopbackHost);
}

String Uri___::get_PathAndQuery() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  UriInfo uriInfo = EnsureUriInfo();
  if (uriInfo->PathAndQuery == nullptr) {
    String text = GetParts(UriComponents::PathAndQuery, UriFormat::UriEscaped);
    if (get_IsDosPath() && text[0] == 47) {
      text = text->Substring(1);
    }
    uriInfo->PathAndQuery = text;
  }
  return uriInfo->PathAndQuery;
}

Array<String> Uri___::get_Segments() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  String privateAbsolutePath = get_PrivateAbsolutePath();
  if (privateAbsolutePath->get_Length() == 0) {
    return Array<>::in::Empty<String>();
  }
  ArrayBuilder<String> arrayBuilder = ArrayBuilder<T>();
  Int32 num = 0;
  while (num < privateAbsolutePath->get_Length()) {
    Int32 num2 = privateAbsolutePath->IndexOf(47, num);
    if (num2 == -1) {
      num2 = privateAbsolutePath->get_Length() - 1;
    }
    arrayBuilder.Add(privateAbsolutePath->Substring(num, num2 - num + 1));
    num = num2 + 1;
  }
  return arrayBuilder.ToArray();
}

Boolean Uri___::get_IsUnc() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return get_IsUncPath();
}

String Uri___::get_Host() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return GetParts(UriComponents::Host, UriFormat::UriEscaped);
}

Int32 Uri___::get_Port() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (_syntax->get_IsSimple()) {
    EnsureUriInfo();
  } else {
    EnsureHostString(false);
  }
  if (InFact(Flags::NotDefaultPort)) {
    return _info->Offset.PortValue;
  }
  return _syntax->get_DefaultPort();
}

String Uri___::get_Query() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
}

String Uri___::get_Fragment() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
}

String Uri___::get_Scheme() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return _syntax->get_SchemeName();
}

String Uri___::get_OriginalString() {
}

String Uri___::get_DnsSafeHost() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  EnsureHostString(false);
  Flags hostType = get_HostType();
}

String Uri___::get_IdnHost() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
}

Boolean Uri___::get_IsAbsoluteUri() {
  return _syntax != nullptr;
}

Boolean Uri___::get_UserEscaped() {
  return InFact(Flags::UserEscaped);
}

String Uri___::get_UserInfo() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return GetParts(UriComponents::UserInfo, UriFormat::UriEscaped);
}

Boolean Uri___::get_HasAuthority() {
  return InFact(Flags::AuthorityFound);
}

void Uri___::InterlockedSetFlags(Flags flags) {
  if (_syntax->get_IsSimple()) {
    Interlocked::Or(Unsafe::As<Flags, UInt64>(_flags), (UInt64)flags);
    return;
  }
}

Boolean Uri___::IriParsingStatic(UriParser syntax) {
}

Boolean Uri___::NotAny(Flags flags) {
}

Boolean Uri___::InFact(Flags flags) {
}

Boolean Uri___::StaticNotAny(Flags allFlags, Flags checkFlags) {
}

Boolean Uri___::StaticInFact(Flags allFlags, Flags checkFlags) {
}

Uri::in::UriInfo Uri___::EnsureUriInfo() {
  Flags flags = _flags;
}

void Uri___::EnsureParseRemaining() {
}

void Uri___::EnsureHostString(Boolean allowDnsOptimization) {
  UriInfo uriInfo = EnsureUriInfo();
  if (uriInfo->Host == nullptr && (!allowDnsOptimization || !InFact(Flags::CanonicalDnsHost))) {
    CreateHostString();
  }
}

void Uri___::ctor(String uriString) {
  if (uriString == nullptr) {
    rt::throw_exception<ArgumentNullException>("uriString");
  }
  CreateThis(uriString, false, UriKind::Absolute);
}

void Uri___::ctor(String uriString, Boolean dontEscape) {
  if (uriString == nullptr) {
    rt::throw_exception<ArgumentNullException>("uriString");
  }
  CreateThis(uriString, dontEscape, UriKind::Absolute);
}

void Uri___::ctor(Uri baseUri, String relativeUri, Boolean dontEscape) {
  if ((Object)baseUri == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseUri");
  }
  if (!baseUri->get_IsAbsoluteUri()) {
    rt::throw_exception<ArgumentOutOfRangeException>("baseUri");
  }
  CreateUri(baseUri, relativeUri, dontEscape);
}

void Uri___::ctor(String uriString, UriKind uriKind) {
  if (uriString == nullptr) {
    rt::throw_exception<ArgumentNullException>("uriString");
  }
  CreateThis(uriString, false, uriKind);
}

void Uri___::ctor(Uri baseUri, String relativeUri) {
  if ((Object)baseUri == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseUri");
  }
  if (!baseUri->get_IsAbsoluteUri()) {
    rt::throw_exception<ArgumentOutOfRangeException>("baseUri");
  }
  CreateUri(baseUri, relativeUri, false);
}

void Uri___::ctor(SerializationInfo serializationInfo, StreamingContext streamingContext) {
  String string = serializationInfo->GetString("AbsoluteUri");
  if (string->get_Length() != 0) {
    CreateThis(string, false, UriKind::Absolute);
    return;
  }
  string = serializationInfo->GetString("RelativeUri");
  if (string == nullptr) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_InvalidNullArgument(), "RelativeUri"), "serializationInfo");
  }
  CreateThis(string, false, UriKind::Relative);
}

void Uri___::GetObjectData(SerializationInfo serializationInfo, StreamingContext streamingContext) {
  if (get_IsAbsoluteUri()) {
    serializationInfo->AddValue("AbsoluteUri", GetParts(UriComponents::SerializationInfoString, UriFormat::UriEscaped));
    return;
  }
  serializationInfo->AddValue("AbsoluteUri", String::in::Empty);
  serializationInfo->AddValue("RelativeUri", GetParts(UriComponents::SerializationInfoString, UriFormat::UriEscaped));
}

void Uri___::CreateUri(Uri baseUri, String relativeUri, Boolean dontEscape) {
  CreateThis(relativeUri, dontEscape, UriKind::RelativeOrAbsolute);
  if (baseUri->get_Syntax()->get_IsSimple()) {
    Uri uri = ResolveHelper(baseUri, (Uri)this, relativeUri, dontEscape);
    if (uri != nullptr) {
      if ((Object)(Uri)this != uri) {
        CreateThisFromUri(uri);
      }
      return;
    }
  } else {
    dontEscape = false;
  }
  _flags = Flags::Zero;
  _info = nullptr;
  _syntax = nullptr;
  CreateThis(relativeUri, dontEscape, UriKind::Absolute);
}

void Uri___::ctor(Uri baseUri, Uri relativeUri) {
  if ((Object)baseUri == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseUri");
  }
  if (!baseUri->get_IsAbsoluteUri()) {
    rt::throw_exception<ArgumentOutOfRangeException>("baseUri");
  }
  CreateThisFromUri(relativeUri);
  String newUriString = nullptr;
  Boolean userEscaped;
  if (baseUri->get_Syntax()->get_IsSimple()) {
    userEscaped = InFact(Flags::UserEscaped);
    Uri uri = ResolveHelper(baseUri, (Uri)this, newUriString, userEscaped);
    if (uri != nullptr) {
      if ((Object)(Uri)this != uri) {
        CreateThisFromUri(uri);
      }
      return;
    }
  } else {
    userEscaped = false;
  }
  _flags = Flags::Zero;
  _info = nullptr;
  _syntax = nullptr;
  CreateThis(newUriString, userEscaped, UriKind::Absolute);
}

void Uri___::GetCombinedString(Uri baseUri, String relativeStr, Boolean dontEscape, String& result) {
  for (Int32 i = 0; i < relativeStr->get_Length() && relativeStr[i] != 47 && relativeStr[i] != 92 && relativeStr[i] != 63 && relativeStr[i] != 35; i++) {
    if (relativeStr[i] == 58) {
      if (i < 2) {
        break;
      }
      UriParser syntax = nullptr;
      if (CheckSchemeSyntax(MemoryExtensions::AsSpan(relativeStr, 0, i), syntax) != 0) {
        break;
      }
      if (baseUri->get_Syntax() == syntax) {
        relativeStr = ((i + 1 >= relativeStr->get_Length()) ? String::in::Empty : relativeStr->Substring(i + 1));
        break;
      }
      result = relativeStr;
      return;
    }
  }
  if (relativeStr->get_Length() == 0) {
    result = baseUri->get_OriginalString();
  } else {
    result = CombineUri(baseUri, relativeStr, dontEscape ? UriFormat::UriEscaped : UriFormat::SafeUnescaped);
  }
}

UriFormatException Uri___::GetException(ParsingError err) {
  switch (err) {
    case ParsingError::None:
      return nullptr;
    case ParsingError::BadFormat:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadFormat());
    case ParsingError::BadScheme:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadScheme());
    case ParsingError::BadAuthority:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadAuthority());
    case ParsingError::EmptyUriString:
      return rt::newobj<UriFormatException>(SR::get_net_uri_EmptyUri());
    case ParsingError::SchemeLimit:
      return rt::newobj<UriFormatException>(SR::get_net_uri_SchemeLimit());
    case ParsingError::SizeLimit:
      return rt::newobj<UriFormatException>(SR::get_net_uri_SizeLimit());
    case ParsingError::MustRootedPath:
      return rt::newobj<UriFormatException>(SR::get_net_uri_MustRootedPath());
    case ParsingError::BadHostName:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadHostName());
    case ParsingError::NonEmptyHost:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadFormat());
    case ParsingError::BadPort:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadPort());
    case ParsingError::BadAuthorityTerminator:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadAuthorityTerminator());
    case ParsingError::CannotCreateRelative:
      return rt::newobj<UriFormatException>(SR::get_net_uri_CannotCreateRelative());
    default:
      return rt::newobj<UriFormatException>(SR::get_net_uri_BadFormat());
  }
}

Boolean Uri___::StaticIsFile(UriParser syntax) {
  return syntax->InFact(UriSyntaxFlags::FileLikeUri);
}

String Uri___::GetLocalPath() {
  EnsureParseRemaining();
  if (get_IsUncOrDosPath()) {
    EnsureHostString(false);
    Int32 num;
  }
}

UriHostNameType Uri___::CheckHostName(String name) {
  if (name == nullptr || name->get_Length() == 0 || name->get_Length() > 32767) {
    return UriHostNameType::Unknown;
  }
  Int32 end = name->get_Length();
  {
    Char* ptr = name;
    Char* name2 = ptr;
    if (name[0] == 91 && name[name->get_Length() - 1] == 93 && IPv6AddressHelper::IsValid(name2, 1, end) && end == name->get_Length()) {
      return UriHostNameType::IPv6;
    }
    end = name->get_Length();
    if (IPv4AddressHelper::IsValid(name2, 0, end, false, false, false) && end == name->get_Length()) {
      return UriHostNameType::IPv4;
    }
    end = name->get_Length();
    Boolean notCanonical = false;
    if (DomainNameHelper::IsValid(name2, 0, end, notCanonical, false) && end == name->get_Length()) {
      return UriHostNameType::Dns;
    }
    end = name->get_Length();
    notCanonical = false;
    if (DomainNameHelper::IsValidByIri(name2, 0, end, notCanonical, false) && end == name->get_Length()) {
      return UriHostNameType::Dns;
    }
  }
  end = name->get_Length() + 2;
  name = "[" + name + "]";
  {
    Char* ptr2 = name;
    Char* name3 = ptr2;
    if (IPv6AddressHelper::IsValid(name3, 1, end) && end == name->get_Length()) {
      return UriHostNameType::IPv6;
    }
  }
  return UriHostNameType::Unknown;
}

String Uri___::GetLeftPart(UriPartial part) {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  EnsureUriInfo();
}

String Uri___::HexEscape(Char character) {
  if (character > 255) {
    rt::throw_exception<ArgumentOutOfRangeException>("character");
  }
}

Char Uri___::HexUnescape(String pattern, Int32& index) {
  if (index < 0 || index >= pattern->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  if (pattern[index] == 37 && pattern->get_Length() - index >= 3) {
    Char c = UriHelper::DecodeHexChars(pattern[index + 1], pattern[index + 2]);
    if (c != 65535) {
      index += 3;
      return c;
    }
  }
  return pattern[index++];
}

Boolean Uri___::IsHexEncoding(String pattern, Int32 index) {
  if (pattern->get_Length() - index >= 3 && pattern[index] == 37 && IsHexDigit(pattern[index + 1])) {
    return IsHexDigit(pattern[index + 2]);
  }
  return false;
}

Boolean Uri___::CheckSchemeName(String schemeName) {
  if (schemeName == nullptr || schemeName->get_Length() == 0 || !UriHelper::IsAsciiLetter(schemeName[0])) {
    return false;
  }
  for (Int32 num = schemeName->get_Length() - 1; num > 0; num--) {
    if (!UriHelper::IsAsciiLetterOrDigit(schemeName[num]) && schemeName[num] != 43 && schemeName[num] != 45 && schemeName[num] != 46) {
      return false;
    }
  }
  return true;
}

Boolean Uri___::IsHexDigit(Char character) {
  if ((UInt32)(character - 48) > 9u && (UInt32)(character - 65) > 5u) {
    return (UInt32)(character - 97) <= 5u;
  }
  return true;
}

Int32 Uri___::FromHex(Char digit) {
  switch (digit.get()) {
    default:
      rt::throw_exception<ArgumentException>(nullptr, "digit");
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
      return digit - 97 + 10;
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
      return digit - 65 + 10;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
      return digit - 48;
  }
}

Int32 Uri___::GetHashCode() {
  if (get_IsNotAbsoluteUri()) {
    return get_OriginalString()->GetHashCode();
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
}

String Uri___::ToString() {
  if (_syntax == nullptr) {
    return _string;
  }
  EnsureUriInfo();
  if (_info->String == nullptr) {
    if (_syntax->get_IsSimple()) {
      _info->String = GetComponentsHelper(UriComponents::AbsoluteUri, (UriFormat)32767);
    } else {
      _info->String = GetParts(UriComponents::AbsoluteUri, UriFormat::SafeUnescaped);
    }
  }
  return _info->String;
}

Boolean Uri___::op_Equality(Uri uri1, Uri uri2) {
  if ((Object)uri1 == uri2) {
    return true;
  }
  if ((Object)uri1 == nullptr || (Object)uri2 == nullptr) {
    return false;
  }
  return uri1->Equals(uri2);
}

Boolean Uri___::op_Inequality(Uri uri1, Uri uri2) {
  if ((Object)uri1 == uri2) {
    return false;
  }
  if ((Object)uri1 == nullptr || (Object)uri2 == nullptr) {
    return true;
  }
  return !uri1->Equals(uri2);
}

Boolean Uri___::Equals(Object comparand) {
  if (comparand == nullptr) {
    return false;
  }
  if ((Uri)this == comparand) {
    return true;
  }
  Uri result = rt::as<Uri>(comparand);
  if ((Object)result == nullptr) {
    String text = rt::as<String>(comparand);
    if (text == nullptr) {
      return false;
    }
    if ((Object)text == get_OriginalString()) {
      return true;
    }
    if (!TryCreate(text, UriKind::RelativeOrAbsolute, result)) {
      return false;
    }
  }
  if ((Object)get_OriginalString() == result->get_OriginalString()) {
    return true;
  }
  if (get_IsAbsoluteUri() != result->get_IsAbsoluteUri()) {
    return false;
  }
  if (get_IsNotAbsoluteUri()) {
    return get_OriginalString()->Equals(result->get_OriginalString());
  }
  if ((NotAny(Flags::AllUriInfoSet) || result->NotAny(Flags::AllUriInfoSet)) && String::in::Equals(_string, result->_string, get_IsUncOrDosPath() ? StringComparison::OrdinalIgnoreCase : StringComparison::Ordinal)) {
    return true;
  }
  EnsureUriInfo();
  result->EnsureUriInfo();
  if (!get_UserDrivenParsing() && !result->get_UserDrivenParsing() && get_Syntax()->get_IsSimple() && result->get_Syntax()->get_IsSimple()) {
    if (InFact(Flags::CanonicalDnsHost) && result->InFact(Flags::CanonicalDnsHost)) {
      Int32 num = _info->Offset.Host;
      Int32 num2 = _info->Offset.Path;
      Int32 num3 = result->_info->Offset.Host;
      Int32 path = result->_info->Offset.Path;
      String string = result->_string;
      if (num2 - num > path - num3) {
        num2 = num + path - num3;
      }
      while (num < num2) {
        if (_string[num] != string[num3]) {
          return false;
        }
        if (string[num3] == 58) {
          break;
        }
        num++;
        num3++;
      }
      if (num < _info->Offset.Path && _string[num] != 58) {
        return false;
      }
      if (num3 < path && string[num3] != 58) {
        return false;
      }
    } else {
      EnsureHostString(false);
      result->EnsureHostString(false);
      if (!_info->Host->Equals(result->_info->Host)) {
        return false;
      }
    }
    if (get_Port() != result->get_Port()) {
      return false;
    }
  }
  MoreInfo moreInfo = _info->get_MoreInfo();
  MoreInfo moreInfo2 = result->_info->get_MoreInfo();
  MoreInfo moreInfo3 = moreInfo;
}

Uri Uri___::MakeRelativeUri(Uri uri) {
  if ((Object)uri == nullptr) {
    rt::throw_exception<ArgumentNullException>("uri");
  }
  if (get_IsNotAbsoluteUri() || uri->get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (get_Scheme() == uri->get_Scheme() && get_Host() == uri->get_Host() && get_Port() == uri->get_Port()) {
    String absolutePath = uri->get_AbsolutePath();
    String text = PathDifference(get_AbsolutePath(), absolutePath, !get_IsUncOrDosPath());
    if (CheckForColonInFirstPathSegment(text) && (!uri->get_IsDosPath() || !absolutePath->Equals(text, StringComparison::Ordinal))) {
      text = "./" + text;
    }
  }
  return uri;
}

Boolean Uri___::CheckForColonInFirstPathSegment(String uriString) {
  Int32 num = uriString->IndexOfAny(s_pathDelims);
  if (num >= 0) {
    return uriString[num] == 58;
  }
  return false;
}

String Uri___::InternalEscapeString(String rawString) {
  if (rawString != nullptr) {
    return UriHelper::EscapeString(rawString, true, UriHelper::get_UnreservedReservedTable(), 63, 35);
  }
  return String::in::Empty;
}

ParsingError Uri___::ParseScheme(String uriString, Flags& flags, UriParser& syntax) {
  Int32 length = uriString->get_Length();
  if (length == 0) {
    return ParsingError::EmptyUriString;
  }
  if (length >= 65520) {
    return ParsingError::SizeLimit;
  }
  {
    Char* ptr = uriString;
    Char* uriString2 = ptr;
    ParsingError err = ParsingError::None;
    Int32 num = ParseSchemeCheckImplicitFile(uriString2, length, err, flags, syntax);
    if (err != 0) {
      return err;
    }
    flags |= (Flags)num;
  }
  return ParsingError::None;
}

UriFormatException Uri___::ParseMinimal() {
  ParsingError parsingError = PrivateParseMinimal();
  if (parsingError == ParsingError::None) {
    return nullptr;
  }
  _flags |= Flags::ErrorOrParsingRecursion;
  return GetException(parsingError);
}

ParsingError Uri___::PrivateParseMinimal() {
}

void Uri___::CreateUriInfo(Flags cF) {
  UriInfo uriInfo = rt::newobj<UriInfo>();
  uriInfo->Offset.End = (UInt16)_string->get_Length();
  if (!get_UserDrivenParsing()) {
    Boolean flag = false;
    Int32 i;
  }
  cF |= Flags::MinimalUriInfoSet;
  Interlocked::CompareExchange(_info, uriInfo, nullptr);
  Flags flags = _flags;
}

void Uri___::CreateHostString() {
  if (!_syntax->get_IsSimple()) {
  }
  Flags flags = _flags;
  String text = CreateHostStringHelper(_string, _info->Offset.Host, _info->Offset.Path, flags, _info->ScopeId);
  if (text->get_Length() != 0) {
    if (get_HostType() == Flags::BasicHostType) {
      Int32 idx = 0;
      Check check;
      {
        Char* ptr = text;
        Char* str = ptr;
        check = CheckCanonical(str, idx, text->get_Length(), 65535);
      }
    } else if (NotAny(Flags::CanonicalDnsHost)) {
      if (_info->ScopeId != nullptr) {
      } else {
        for (Int32 i = 0; i < text->get_Length(); i++) {
          if (_info->Offset.Host + i >= _info->Offset.End || text[i] != _string[_info->Offset.Host + i]) {
          }
        }
      }
    }

  }
  _info->Host = text;
  InterlockedSetFlags(flags);
}

String Uri___::CreateHostStringHelper(String str, Int32 idx, Int32 end, Flags& flags, String& scopeId) {
  Boolean loopback = false;
  String text;
}

void Uri___::GetHostViaCustomSyntax() {
  if (_info->Host != nullptr) {
    return;
  }
  String text = _syntax->InternalGetComponents((Uri)this, UriComponents::Host, UriFormat::UriEscaped);
  if (_info->Host == nullptr) {
    if (text->get_Length() >= 65520) {
      rt::throw_exception(GetException(ParsingError::SizeLimit));
    }
    ParsingError err = ParsingError::None;
  }
  String text2 = _syntax->InternalGetComponents((Uri)this, UriComponents::StrongPort, UriFormat::UriEscaped);
  Int32 num = 0;
  if (text2 == nullptr || text2->get_Length() == 0) {
    _flags &= ~Flags::NotDefaultPort;
  } else {
    for (Int32 j = 0; j < text2->get_Length(); j++) {
      Int32 num2 = text2[j] - 48;
      if (num2 < 0 || num2 > 9 || (num = num * 10 + num2) > 65535) {
        rt::throw_exception<UriFormatException>(SR::Format(SR::get_net_uri_PortOutOfRange(), _syntax->GetType(), text2));
      }
    }
    if (num != _info->Offset.PortValue) {
      if (num == _syntax->get_DefaultPort()) {
        _flags &= ~Flags::NotDefaultPort;
      } else {
        _flags |= Flags::NotDefaultPort;
      }
    }
  }
  _info->Host = text;
}

String Uri___::GetParts(UriComponents uriParts, UriFormat formatAs) {
  return GetComponents(uriParts, formatAs);
}

String Uri___::GetEscapedParts(UriComponents uriParts) {
}

String Uri___::GetUnescapedParts(UriComponents uriParts, UriFormat formatAs) {
}

String Uri___::ReCreateParts(UriComponents parts, UInt16 nonCanonical, UriFormat formatAs) {
  EnsureHostString(false);
}

String Uri___::GetUriPartsFromUserString(UriComponents uriParts) {
}

void Uri___::GetLengthWithoutTrailingSpaces(String str, Int32& length, Int32 idx) {
  Int32 num = length;
  while (num > idx && UriHelper::IsLWS(str[num - 1])) {
    num--;
  }
  length = num;
}

void Uri___::ParseRemaining() {
  EnsureUriInfo();
  Flags flags = Flags::Zero;
  if (!get_UserDrivenParsing()) {
  }
}

Int32 Uri___::ParseSchemeCheckImplicitFile(Char* uriString, Int32 length, ParsingError& err, Flags& flags, UriParser& syntax) {
  Int32 i;
  for (i = 0; i < length && UriHelper::IsLWS(uriString[i]); i++) {
  }
  Int32 j;
  for (j = i; j < length && uriString[j] != 58; j++) {
  }
  if (IntPtr::get_Size() == 4) {
  }
  if (i + 2 >= length || j == i) {
    err = ParsingError::BadFormat;
    return 0;
  }
  Char c;
  if ((c = uriString[i + 1]) == 58 || c == 124) {
    if (UriHelper::IsAsciiLetter(uriString[i])) {
      if ((c = uriString[i + 2]) == 92 || c == 47) {
      }
      err = ParsingError::MustRootedPath;
      return 0;
    }
    if (c == 58) {
      err = ParsingError::BadScheme;
    } else {
      err = ParsingError::BadFormat;
    }
    return 0;
  }
  if ((c = uriString[i]) == 47 || c == 92) {
    if ((c = uriString[i + 1]) == 92 || c == 47) {
    }
    err = ParsingError::BadFormat;
    return 0;
  }
  if (j == length) {
    err = ParsingError::BadFormat;
    return 0;
  }
  err = CheckSchemeSyntax(ReadOnlySpan<Char>(uriString + i, j - i), syntax);
  if (err != 0) {
    return 0;
  }
  return j + 1;
}

ParsingError Uri___::CheckSchemeSyntax(ReadOnlySpan<Char> span, UriParser& syntax) {
  if (span.get_Length() == 0) {
    return ParsingError::BadScheme;
  }
  Char c2 = span[0];
}

Int32 Uri___::CheckAuthorityHelper(Char* pString, Int32 idx, Int32 length, ParsingError& err, Flags& flags, UriParser syntax, String& newHost) {
  Int32 i = length;
  Int32 num = idx;
  Int32 j = idx;
  newHost = nullptr;
  Boolean justNormalized = false;
  Boolean flag = IriParsingStatic(syntax);
}

void Uri___::CheckAuthorityHelperHandleDnsIri(Char* pString, Int32 start, Int32 end, Boolean hasUnicode, Flags& flags, Boolean& justNormalized, String& newHost, ParsingError& err) {
  flags |= Flags::DnsHostType;
  if (hasUnicode) {
    String text = UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char>(pString + start, end - start));
    try{
      newHost += text->Normalize(NormalizationForm::FormC);
    } catch (ArgumentException) {
    }
    justNormalized = true;
  }
  flags |= Flags::HostUnicodeNormalized;
}

Uri::in::Check Uri___::CheckCanonical(Char* str, Int32& idx, Int32 end, Char delim) {
  Check check = Check::None;
  Boolean flag = false;
  Boolean flag2 = false;
  Boolean iriParsing = get_IriParsing();
  Int32 i;
  for (i = idx; i < end; i++) {
    Char c = str[i];
    if (c <= 31 || (c >= 127 && c <= 159)) {
      flag = true;
      flag2 = true;
      check |= Check::ReservedFound;
    }
    if (c > 126) {
      if (iriParsing) {
        Boolean flag3 = false;
        check |= Check::FoundNonAscii;
        if (Char::IsHighSurrogate(c)) {
          if (i + 1 < end) {
          }
        } else {
          flag3 = IriHelper::CheckIriUnicodeRange(c, true);
        }
        if (!flag3) {
          check |= Check::NotIriCanonical;
        }
      }
      if (!flag) {
        flag = true;
      }
    }
    if (c == delim || (delim == 63 && c == 35 && _syntax != nullptr && _syntax->InFact(UriSyntaxFlags::MayHaveFragment))) {
      break;
    }
    if (c == 63) {
      if (get_IsImplicitFile() || (_syntax != nullptr && !_syntax->InFact(UriSyntaxFlags::MayHaveQuery) && delim != 65534)) {
        check |= Check::ReservedFound;
        flag2 = true;
        flag = true;
      }
    }
    if (c == 35) {
      flag = true;
      if (get_IsImplicitFile() || (_syntax != nullptr && !_syntax->InFact(UriSyntaxFlags::MayHaveFragment))) {
        check |= Check::ReservedFound;
        flag2 = true;
      }
    }
    if (c == 47 || c == 92) {
    }
    if (c == 46) {
    }
    if ((c > 34 || c == 33) && (c < 91 || c > 94)) {
    }
    if (!flag) {
      flag = true;
    }
  }
  if (flag2) {
    if (!flag) {
      check |= Check::EscapedCanonical;
    }
  } else {
    check |= Check::DisplayCanonical;
    if (!flag) {
      check |= Check::EscapedCanonical;
    }
  }
  idx = i;
  return check;
}

Array<Char> Uri___::GetCanonicalPath(Array<Char> dest, Int32& pos, UriFormat formatAs) {
  if (InFact(Flags::FirstSlashAbsent)) {
    dest[pos++] = 47;
  }
  if (_info->Offset.Path == _info->Offset.Query) {
    return dest;
  }
  Int32 end = pos;
  Int32 securedPathIndex = get_SecuredPathIndex();
  if (formatAs == UriFormat::UriEscaped) {
    if (InFact(Flags::ShouldBeCompressed)) {
      _string->CopyTo(_info->Offset.Path, dest, end, _info->Offset.Query - _info->Offset.Path);
      end += _info->Offset.Query - _info->Offset.Path;
      if (_syntax->InFact(UriSyntaxFlags::UnEscapeDotsAndSlashes) && InFact(Flags::PathNotCanonical) && !get_IsImplicitFile()) {
        {
          Char* pch = dest;
          UnescapeOnly(pch, pos, end, 46, 47, _syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) ? 92 : 65535);
        }
      }
    } else if (InFact(Flags::E_PathNotCanonical) && NotAny(Flags::UserEscaped)) {
      String text = _string;
      if (securedPathIndex != 0 && text[securedPathIndex + _info->Offset.Path - 1] == 124) {
        text = text->Remove(securedPathIndex + _info->Offset.Path - 1, 1);
        text = text->Insert(securedPathIndex + _info->Offset.Path - 1, ":");
      }
      dest = UriHelper::EscapeString(MemoryExtensions::AsSpan(text, _info->Offset.Path, _info->Offset.Query - _info->Offset.Path), dest, end, !get_IsImplicitFile(), 63, 35);
    } else {
      _string->CopyTo(_info->Offset.Path, dest, end, _info->Offset.Query - _info->Offset.Path);
      end += _info->Offset.Query - _info->Offset.Path;
    }

  } else {
    _string->CopyTo(_info->Offset.Path, dest, end, _info->Offset.Query - _info->Offset.Path);
    end += _info->Offset.Query - _info->Offset.Path;
    if (InFact(Flags::ShouldBeCompressed) && _syntax->InFact(UriSyntaxFlags::UnEscapeDotsAndSlashes) && InFact(Flags::PathNotCanonical) && !get_IsImplicitFile()) {
      {
        Char* pch2 = dest;
        UnescapeOnly(pch2, pos, end, 46, 47, _syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) ? 92 : 65535);
      }
    }
  }
  if (securedPathIndex != 0 && dest[securedPathIndex + pos - 1] == 124) {
    dest[securedPathIndex + pos - 1] = 58;
  }
  if (InFact(Flags::ShouldBeCompressed)) {
    dest = Compress(dest, (UInt16)(pos + securedPathIndex), end, _syntax);
    if (dest[pos] == 92) {
      dest[pos] = 47;
    }
    if (formatAs == UriFormat::UriEscaped && NotAny(Flags::UserEscaped) && InFact(Flags::E_PathNotCanonical)) {
      dest = UriHelper::EscapeString(rt::newobj<String>(dest, pos, end - pos), dest, pos, !get_IsImplicitFile(), 63, 35);
      end = pos;
    }
  } else if (_syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) && InFact(Flags::BackslashInPath)) {
    for (Int32 i = pos; i < end; i++) {
      if (dest[i] == 92) {
        dest[i] = 47;
      }
    }
  }

  if (formatAs != UriFormat::UriEscaped && InFact(Flags::PathNotCanonical)) {
    UnescapeMode unescapeMode;
    if (InFact(Flags::PathNotCanonical)) {
    } else {
      unescapeMode = UnescapeMode::CopyOnly;
    }
    Array<Char> array = rt::newarr<Array<Char>>(dest->get_Length());
    Buffer::BlockCopy(dest, 0, array, 0, end * 2);
    {
      Char* pStr = array;
      dest = UriHelper::UnescapeString(pStr, pos, end, dest, pos, 63, 35, 65535, unescapeMode, _syntax, false);
    }
  } else {
    pos = end;
  }
  return dest;
}

void Uri___::UnescapeOnly(Char* pch, Int32 start, Int32& end, Char ch1, Char ch2, Char ch3) {
  if (end - start < 3) {
    return;
  }
  Char* ptr = pch + end - 2;
  pch += start;
  Char* ptr2 = nullptr;
  while (pch < ptr) {
    Char* num = pch;
    pch = num + 1;
    if (*num != 37) {
    }
    Char* num2 = pch;
    pch = num2 + 1;
    Char first = *num2;
    Char* num3 = pch;
    pch = num3 + 1;
    Char c = UriHelper::DecodeHexChars(first, *num3);
    if (c != ch1 && c != ch2 && c != ch3) {
    }
    ptr2 = pch - 2;
    *(ptr2 - 1) = c;
    while (pch < ptr) {
      Char* num4 = ptr2;
      ptr2 = num4 + 1;
      Char* num5 = pch;
      pch = num5 + 1;
      Char c2;
      *num4 = (c2 = *num5);
      if (c2 == 37) {
        Char* num6 = ptr2;
        ptr2 = num6 + 1;
        Char* num7 = pch;
        pch = num7 + 1;
        *num6 = (c2 = *num7);
        Char first2 = c2;
        Char* num8 = ptr2;
        ptr2 = num8 + 1;
        Char* num9 = pch;
        pch = num9 + 1;
        *num8 = (c2 = *num9);
        c = UriHelper::DecodeHexChars(first2, c2);
        if (c == ch1 || c == ch2 || c == ch3) {
          ptr2 -= 2;
          *(ptr2 - 1) = c;
        }
      }
    }
    break;
  }
  ptr += 2;
  if (ptr2 == nullptr) {
    return;
  }
  if (pch == ptr) {
    end -= (Int32)(pch - ptr2);
    return;
  }
  Char* num10 = ptr2;
  ptr2 = num10 + 1;
  Char* num11 = pch;
  pch = num11 + 1;
  *num10 = *num11;
  if (pch == ptr) {
    end -= (Int32)(pch - ptr2);
    return;
  }
  Char* num12 = ptr2;
  ptr2 = num12 + 1;
  Char* num13 = pch;
  pch = num13 + 1;
  *num12 = *num13;
  end -= (Int32)(pch - ptr2);
}

Array<Char> Uri___::Compress(Array<Char> dest, Int32 start, Int32& destLength, UriParser syntax) {
  UInt16 num = 0;
  UInt16 num2 = 0;
  UInt16 num3 = 0;
  UInt16 num4 = 0;
  UInt16 num5 = (UInt16)((UInt16)destLength - 1);
  for (start = (UInt16)(start - 1); num5 != start; num5 = (UInt16)(num5 - 1)) {
    Char c = dest[num5];
    if (c == 92 && syntax->InFact(UriSyntaxFlags::ConvertPathSlashes)) {
      c = (dest[num5] = 47);
    }
    if (c == 47) {
      num = (UInt16)(num + 1);
    } else {
      if (num > 1) {
        num2 = (UInt16)(num5 + 1);
      }
      num = 0;
    }
    if (c == 46) {
      num3 = (UInt16)(num3 + 1);
    }
    if (num3 != 0) {
      if ((!syntax->NotAny(UriSyntaxFlags::CanonicalizeAsFilePath) || (num3 <= 2 && c == 47 && num5 != start)) && c == 47 && (num2 == num5 + num3 + 1 || (num2 == 0 && num5 + num3 + 1 == destLength)) && num3 <= 2) {
        num2 = (UInt16)(num5 + 1 + num3 + ((num2 != 0) ? 1 : 0));
        Buffer::BlockCopy(dest, num2 * 2, dest, (num5 + 1) * 2, (destLength - num2) * 2);
        destLength -= num2 - num5 - 1;
        num2 = num5;
        if (num3 == 2) {
          num4 = (UInt16)(num4 + 1);
        }
        num3 = 0;
      }
      num3 = 0;
    }
    if (c == 47) {
      if (num4 != 0) {
        num4 = (UInt16)(num4 - 1);
        num2 = (UInt16)(num2 + 1);
        Buffer::BlockCopy(dest, num2 * 2, dest, (num5 + 1) * 2, (destLength - num2) * 2);
        destLength -= num2 - num5 - 1;
      }
      num2 = num5;
    }
  }
  start = (UInt16)((UInt16)start + 1);
  if ((UInt16)destLength > start && syntax->InFact(UriSyntaxFlags::CanonicalizeAsFilePath) && num <= 1) {
    if (num4 != 0 && dest[start] != 47) {
      num2 = (UInt16)(num2 + 1);
      Buffer::BlockCopy(dest, num2 * 2, dest, start * 2, (destLength - num2) * 2);
      destLength -= num2;
    } else if (num3 != 0 && (num2 == num3 + 1 || (num2 == 0 && num3 + 1 == destLength))) {
      num3 = (UInt16)(num3 + ((num2 != 0) ? 1 : 0));
      Buffer::BlockCopy(dest, num3 * 2, dest, start * 2, (destLength - num3) * 2);
      destLength -= num3;
    }

  }
  return dest;
}

String Uri___::CombineUri(Uri basePart, String relativePart, UriFormat uriFormat) {
  Char c = relativePart[0];
  if (basePart->get_IsDosPath() && (c == 47 || c == 92) && (relativePart->get_Length() == 1 || (relativePart[1] != 47 && relativePart[1] != 92))) {
    Int32 num = basePart->get_OriginalString()->IndexOf(58);
    if (basePart->get_IsImplicitFile()) {
      return String::in::Concat(MemoryExtensions::AsSpan(basePart->get_OriginalString(), 0, num + 1), relativePart);
    }
    num = basePart->get_OriginalString()->IndexOf(58, num + 1);
    return String::in::Concat(MemoryExtensions::AsSpan(basePart->get_OriginalString(), 0, num + 1), relativePart);
  }
  if (StaticIsFile(basePart->get_Syntax()) && (c == 92 || c == 47)) {
    if (relativePart->get_Length() >= 2 && (relativePart[1] == 92 || relativePart[1] == 47)) {
      if (!basePart->get_IsImplicitFile()) {
        return "file:" + relativePart;
      }
      return relativePart;
    }
    if (basePart->get_IsUnc()) {
    }
    return "file://" + relativePart;
  }
  Boolean flag = basePart->get_Syntax()->InFact(UriSyntaxFlags::ConvertPathSlashes);
  String text2 = nullptr;
  if (c == 47 || (c == 92 && flag)) {
    if (relativePart->get_Length() >= 2 && relativePart[1] == 47) {
      return basePart->get_Scheme() + ":" + relativePart;
    }
  }
}

String Uri___::PathDifference(String path1, String path2, Boolean compareCase) {
  Int32 num = -1;
  Int32 i;
  for (i = 0; i < path1->get_Length() && i < path2->get_Length() && (path1[i] == path2[i] || (!compareCase && Char::ToLowerInvariant(path1[i]) == Char::ToLowerInvariant(path2[i]))); i++) {
    if (path1[i] == 47) {
      num = i;
    }
  }
  if (i == 0) {
    return path2;
  }
  if (i == path1->get_Length() && i == path2->get_Length()) {
    return String::in::Empty;
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  for (; i < path1->get_Length(); i++) {
    if (path1[i] == 47) {
      stringBuilder->Append("../");
    }
  }
  if (stringBuilder->get_Length() == 0 && path2->get_Length() - 1 == num) {
    return "./";
  }
  return stringBuilder->Append(MemoryExtensions::AsSpan(path2, num + 1))->ToString();
}

String Uri___::MakeRelative(Uri toUri) {
  if (toUri == nullptr) {
    rt::throw_exception<ArgumentNullException>("toUri");
  }
  if (get_IsNotAbsoluteUri() || toUri->get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (get_Scheme() == toUri->get_Scheme() && get_Host() == toUri->get_Host() && get_Port() == toUri->get_Port()) {
    return PathDifference(get_AbsolutePath(), toUri->get_AbsolutePath(), !get_IsUncOrDosPath());
  }
  return toUri->ToString();
}

void Uri___::Canonicalize() {
}

void Uri___::Parse() {
}

void Uri___::Escape() {
}

String Uri___::Unescape(String path) {
  Array<Char> dest = rt::newarr<Array<Char>>(path->get_Length());
  Int32 destPosition = 0;
}

String Uri___::EscapeString(String str) {
  if (str != nullptr) {
    return UriHelper::EscapeString(str, true, UriHelper::get_UnreservedReservedTable(), 63, 35);
  }
  return String::in::Empty;
}

void Uri___::CheckSecurity() {
}

Boolean Uri___::IsReservedCharacter(Char character) {
  if (character != 59 && character != 47 && character != 58 && character != 64 && character != 38 && character != 61 && character != 43 && character != 36) {
    return character == 44;
  }
  return true;
}

Boolean Uri___::IsExcludedCharacter(Char character) {
  if (character > 32 && character < 127 && character != 60 && character != 62 && character != 35 && character != 37 && character != 34 && character != 123 && character != 125 && character != 124 && character != 92 && character != 94 && character != 91 && character != 93) {
    return character == 96;
  }
  return true;
}

Boolean Uri___::IsBadFileSystemCharacter(Char character) {
  if (character >= 32 && character != 59 && character != 47 && character != 63 && character != 58 && character != 38 && character != 61 && character != 44 && character != 42 && character != 60 && character != 62 && character != 34 && character != 124 && character != 92) {
    return character == 94;
  }
  return true;
}

void Uri___::CreateThis(String uri, Boolean dontEscape, UriKind uriKind) {
  if (uriKind < UriKind::RelativeOrAbsolute || uriKind > UriKind::Relative) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_net_uri_InvalidUriKind(), uriKind));
  }
}

void Uri___::InitializeUri(ParsingError err, UriKind uriKind, UriFormatException& e) {
  if (err == ParsingError::None) {
    if (get_IsImplicitFile()) {
      if (NotAny(Flags::DosPath) && uriKind != UriKind::Absolute && (uriKind == UriKind::Relative || (_string->get_Length() >= 2 && (_string[0] != 92 || _string[1] != 92)))) {
        _syntax = nullptr;
        _flags &= Flags::UserEscaped;
        e = nullptr;
        return;
      }
      if (uriKind == UriKind::Relative && InFact(Flags::DosPath)) {
        _syntax = nullptr;
        _flags &= Flags::UserEscaped;
        e = nullptr;
        return;
      }
    }
  } else if (err > ParsingError::EmptyUriString) {
    _string = nullptr;
    e = GetException(err);
    return;
  }

  Boolean flag = false;
  if (get_IriParsing() && CheckForUnicodeOrEscapedUnreserved(_string)) {
    _flags |= Flags::HasUnicode;
    flag = true;
    _originalUnicodeString = _string;
  }
  if (_syntax != nullptr) {
    if (_syntax->get_IsSimple()) {
      if ((err = PrivateParseMinimal()) != 0) {
        if (uriKind != UriKind::Absolute && err <= ParsingError::EmptyUriString) {
          _syntax = nullptr;
          e = nullptr;
          _flags &= Flags::UserEscaped;
          return;
        }
        e = GetException(err);
      } else if (uriKind == UriKind::Relative) {
        e = GetException(ParsingError::CannotCreateRelative);
      } else {
        e = nullptr;
      }

      if (flag) {
        try{
          EnsureParseRemaining();
        } catch (UriFormatException ex) {
        }
      }
      return;
    }
    _syntax = _syntax->InternalOnNewUri();
    _flags |= Flags::UserDrivenParsing;
    _syntax->InternalValidate((Uri)this, e);
    if (e != nullptr) {
      if (uriKind != UriKind::Absolute && err != 0 && err <= ParsingError::EmptyUriString) {
        _syntax = nullptr;
        e = nullptr;
        _flags &= Flags::UserEscaped;
      }
      return;
    }
    if (err != 0 || InFact(Flags::ErrorOrParsingRecursion)) {
    } else if (uriKind == UriKind::Relative) {
      e = GetException(ParsingError::CannotCreateRelative);
    }

    if (flag) {
      try{
        EnsureParseRemaining();
      } catch (UriFormatException ex3) {
      }
    }
  } else if (err != 0 && uriKind != UriKind::Absolute && err <= ParsingError::EmptyUriString) {
    e = nullptr;
  } else {
    _string = nullptr;
    e = GetException(err);
  }

}

Boolean Uri___::CheckForUnicodeOrEscapedUnreserved(String data) {
  for (Int32 i = 0; i < data->get_Length(); i++) {
    Char c = data[i];
    if (c == 37) {
      if ((UInt32)(i + 2) < (UInt32)data->get_Length()) {
        Char c2 = UriHelper::DecodeHexChars(data[i + 1], data[i + 2]);
        if (c2 >= UriHelper::get_UnreservedTable().get_Length() || UriHelper::get_UnreservedTable()[c2]) {
          return true;
        }
        i += 2;
      }
    } else if (c > 127) {
      return true;
    }

  }
  return false;
}

Boolean Uri___::TryCreate(String uriString, UriKind uriKind, Uri& result) {
  if (uriString == nullptr) {
    result = nullptr;
    return false;
  }
  UriFormatException e = nullptr;
  result = CreateHelper(uriString, false, uriKind, e);
  if (e == nullptr) {
    return result != nullptr;
  }
  return false;
}

Boolean Uri___::TryCreate(Uri baseUri, String relativeUri, Uri& result) {
}

Boolean Uri___::TryCreate(Uri baseUri, Uri relativeUri, Uri& result) {
  result = nullptr;
  if ((Object)baseUri == nullptr || (Object)relativeUri == nullptr) {
    return false;
  }
  if (baseUri->get_IsNotAbsoluteUri()) {
    return false;
  }
  UriFormatException parsingError = nullptr;
  String newUriString = nullptr;
  Boolean userEscaped;
  if (baseUri->get_Syntax()->get_IsSimple()) {
    userEscaped = relativeUri->get_UserEscaped();
    result = ResolveHelper(baseUri, relativeUri, newUriString, userEscaped);
  } else {
    userEscaped = false;
    newUriString = baseUri->get_Syntax()->InternalResolve(baseUri, relativeUri, parsingError);
    if (parsingError != nullptr) {
      return false;
    }
  }
  if ((Object)result == nullptr) {
    result = CreateHelper(newUriString, userEscaped, UriKind::Absolute, parsingError);
  }
  if (parsingError == nullptr && result != nullptr) {
    return result->get_IsAbsoluteUri();
  }
  return false;
}

String Uri___::GetComponents(UriComponents components, UriFormat format) {
}

Int32 Uri___::Compare(Uri uri1, Uri uri2, UriComponents partsToCompare, UriFormat compareFormat, StringComparison comparisonType) {
  if ((Object)uri1 == nullptr) {
    if (uri2 == nullptr) {
      return 0;
    }
    return -1;
  }
  if ((Object)uri2 == nullptr) {
    return 1;
  }
  if (!uri1->get_IsAbsoluteUri() || !uri2->get_IsAbsoluteUri()) {
    if (!uri1->get_IsAbsoluteUri()) {
      if (!uri2->get_IsAbsoluteUri()) {
        return String::in::Compare(uri1->get_OriginalString(), uri2->get_OriginalString(), comparisonType);
      }
      return -1;
    }
    return 1;
  }
  return String::in::Compare(uri1->GetParts(partsToCompare, compareFormat), uri2->GetParts(partsToCompare, compareFormat), comparisonType);
}

Boolean Uri___::IsWellFormedOriginalString() {
  if (get_IsNotAbsoluteUri() || get_Syntax()->get_IsSimple()) {
    return InternalIsWellFormedOriginalString();
  }
  return get_Syntax()->InternalIsWellFormedOriginalString((Uri)this);
}

Boolean Uri___::IsWellFormedUriString(String uriString, UriKind uriKind) {
}

Boolean Uri___::InternalIsWellFormedOriginalString() {
  if (get_UserDrivenParsing()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_UserDrivenParsing(), GetType()));
  }
  {
    Char* ptr = _string;
    Char* ptr2 = ptr;
    Int32 idx = 0;
    if (!get_IsAbsoluteUri()) {
      if (CheckForColonInFirstPathSegment(_string)) {
        return false;
      }
    }
    if (get_IsImplicitFile()) {
      return false;
    }
    EnsureParseRemaining();
  }
  return true;
}

String Uri___::UnescapeDataString(String stringToUnescape) {
  if (stringToUnescape == nullptr) {
    rt::throw_exception<ArgumentNullException>("stringToUnescape");
  }
  if (stringToUnescape->get_Length() == 0) {
    return String::in::Empty;
  }
  Int32 num = stringToUnescape->IndexOf(37);
  if (num == -1) {
    return stringToUnescape;
  }
  Char default[256] = {};
  Span<Char> initialBuffer = default;
  ValueStringBuilder dest = ValueStringBuilder(initialBuffer);
  dest.EnsureCapacity(stringToUnescape->get_Length());
  dest.Append(MemoryExtensions::AsSpan(stringToUnescape, 0, num));
}

String Uri___::EscapeUriString(String stringToEscape) {
  return UriHelper::EscapeString(stringToEscape, false, UriHelper::get_UnreservedReservedTable());
}

String Uri___::EscapeDataString(String stringToEscape) {
  return UriHelper::EscapeString(stringToEscape, false, UriHelper::get_UnreservedTable());
}

String Uri___::EscapeUnescapeIri(String input, Int32 start, Int32 end, UriComponents component) {
  {
    Char* ptr = input;
    Char* pInput = ptr;
    return IriHelper::EscapeUnescapeIri(pInput, start, end, component);
  }
}

void Uri___::ctor(Flags flags, UriParser uriParser, String uri) {
  _flags = flags;
  _syntax = uriParser;
  _string = uri;
}

Uri Uri___::CreateHelper(String uriString, Boolean dontEscape, UriKind uriKind, UriFormatException& e) {
  if (uriKind < UriKind::RelativeOrAbsolute || uriKind > UriKind::Relative) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_net_uri_InvalidUriKind(), uriKind));
  }
  UriParser syntax = nullptr;
  Flags flags = Flags::Zero;
  ParsingError parsingError = ParseScheme(uriString, flags, syntax);
  if (dontEscape) {
    flags |= Flags::UserEscaped;
  }
  if (parsingError != 0) {
    if (uriKind != UriKind::Absolute && parsingError <= ParsingError::EmptyUriString) {
    }
    return nullptr;
  }
  Uri uri = rt::newobj<Uri>(flags, syntax, uriString);
  try{
    uri->InitializeUri(parsingError, uriKind, e);
    if (e == nullptr) {
      return uri;
    }
    return nullptr;
  } catch (UriFormatException ex) {
  }
}

Uri Uri___::ResolveHelper(Uri baseUri, Uri relativeUri, String& newUriString, Boolean& userEscaped) {
  String text;
  if ((Object)relativeUri != nullptr) {
    if (relativeUri->get_IsAbsoluteUri()) {
      return relativeUri;
    }
    text = relativeUri->get_OriginalString();
    userEscaped = relativeUri->get_UserEscaped();
  } else {
    text = String::in::Empty;
  }
  if (text->get_Length() > 0 && (UriHelper::IsLWS(text[0]) || UriHelper::IsLWS(text[text->get_Length() - 1]))) {
    text = text->Trim(rt::newarr<Array<Char>>(1, UriHelper::s_WSchars));
  }
  if (text->get_Length() == 0) {
    newUriString = baseUri->GetParts(UriComponents::AbsoluteUri, baseUri->get_UserEscaped() ? UriFormat::UriEscaped : UriFormat::SafeUnescaped);
    return nullptr;
  }
  if (text[0] == 35 && !baseUri->get_IsImplicitFile() && baseUri->get_Syntax()->InFact(UriSyntaxFlags::MayHaveFragment)) {
  }
  if (text[0] == 63 && !baseUri->get_IsImplicitFile() && baseUri->get_Syntax()->InFact(UriSyntaxFlags::MayHaveQuery)) {
  }
  if (text->get_Length() >= 3 && (text[1] == 58 || text[1] == 124) && UriHelper::IsAsciiLetter(text[0]) && (text[2] == 92 || text[2] == 47)) {
    if (baseUri->get_IsImplicitFile()) {
      newUriString = text;
      return nullptr;
    }
    if (baseUri->get_Syntax()->InFact(UriSyntaxFlags::AllowDOSPath)) {
      newUriString = String::in::Concat(baseUri->get_Scheme(), (!baseUri->InFact(Flags::AuthorityFound)) ? (baseUri->get_Syntax()->InFact(UriSyntaxFlags::PathIsRooted) ? ":/" : ":") : (baseUri->get_Syntax()->InFact(UriSyntaxFlags::PathIsRooted) ? ":///" : "://"), text);
      return nullptr;
    }
  }
  GetCombinedString(baseUri, text, userEscaped, newUriString);
  if ((Object)newUriString == baseUri->_string) {
    return baseUri;
  }
  return nullptr;
}

String Uri___::GetRelativeSerializationString(UriFormat format) {
  switch (format) {
    case UriFormat::UriEscaped:
      return UriHelper::EscapeString(_string, true, UriHelper::get_UnreservedReservedTable());
    case UriFormat::Unescaped:
      return UnescapeDataString(_string);
    case UriFormat::SafeUnescaped:
      {
        if (_string->get_Length() == 0) {
          return String::in::Empty;
        }
        Array<Char> dest = rt::newarr<Array<Char>>(_string->get_Length());
        Int32 destPosition = 0;
        dest = UriHelper::UnescapeString(_string, 0, _string->get_Length(), dest, destPosition, 65535, 65535, 65535, UnescapeMode::EscapeUnescape, nullptr, false);
        return rt::newobj<String>(dest, 0, destPosition);
      }default:
      rt::throw_exception<ArgumentOutOfRangeException>("format");
  }
}

String Uri___::GetComponentsHelper(UriComponents uriComponents, UriFormat uriFormat) {
  if (uriComponents == UriComponents::Scheme) {
    return _syntax->get_SchemeName();
  }
}

Boolean Uri___::IsBaseOf(Uri uri) {
  if ((Object)uri == nullptr) {
    rt::throw_exception<ArgumentNullException>("uri");
  }
  if (!get_IsAbsoluteUri()) {
    return false;
  }
  if (get_Syntax()->get_IsSimple()) {
    return IsBaseOfHelper(uri);
  }
  return get_Syntax()->InternalIsBaseOf((Uri)this, uri);
}

Boolean Uri___::IsBaseOfHelper(Uri uriLink) {
  if (!get_IsAbsoluteUri() || get_UserDrivenParsing()) {
    return false;
  }
  if (!uriLink->get_IsAbsoluteUri()) {
    String newUriString = nullptr;
    Boolean userEscaped = false;
    uriLink = ResolveHelper((Uri)this, uriLink, newUriString, userEscaped);
    if ((Object)uriLink == nullptr) {
      UriFormatException e = nullptr;
      uriLink = CreateHelper(newUriString, userEscaped, UriKind::Absolute, e);
      if (e != nullptr) {
        return false;
      }
    }
  }
  if (get_Syntax()->get_SchemeName() != uriLink->get_Syntax()->get_SchemeName()) {
    return false;
  }
}

void Uri___::CreateThisFromUri(Uri otherUri) {
  _info = nullptr;
  _flags = otherUri->_flags;
  if (InFact(Flags::MinimalUriInfoSet)) {
  }
  _syntax = otherUri->_syntax;
  _string = otherUri->_string;
  _originalUnicodeString = otherUri->_originalUnicodeString;
}

void Uri___::cctor() {
  UriSchemeFile = UriParser::in::FileUri->get_SchemeName();
  UriSchemeFtp = UriParser::in::FtpUri->get_SchemeName();
  UriSchemeGopher = UriParser::in::GopherUri->get_SchemeName();
  UriSchemeHttp = UriParser::in::HttpUri->get_SchemeName();
  UriSchemeHttps = UriParser::in::HttpsUri->get_SchemeName();
  UriSchemeWs = UriParser::in::WsUri->get_SchemeName();
  UriSchemeWss = UriParser::in::WssUri->get_SchemeName();
  UriSchemeMailto = UriParser::in::MailToUri->get_SchemeName();
  UriSchemeNews = UriParser::in::NewsUri->get_SchemeName();
  UriSchemeNntp = UriParser::in::NntpUri->get_SchemeName();
  UriSchemeNetTcp = UriParser::in::NetTcpUri->get_SchemeName();
  UriSchemeNetPipe = UriParser::in::NetPipeUri->get_SchemeName();
  SchemeDelimiter = "://";
  s_pathDelims = rt::newarr<Array<Char>>(5);
}

} // namespace System::Private::Uri::System::UriNamespace
