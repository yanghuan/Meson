#include "Uri-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/NormalizationForm.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.Uri/System/Collections/Generic/ArrayBuilder-dep.h>
#include <System.Private.Uri/System/DomainNameHelper-dep.h>
#include <System.Private.Uri/System/HexConverter-dep.h>
#include <System.Private.Uri/System/IPv4AddressHelper-dep.h>
#include <System.Private.Uri/System/IPv6AddressHelper-dep.h>
#include <System.Private.Uri/System/IriHelper-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.Uri/System/UncNameHelper-dep.h>
#include <System.Private.Uri/System/UnescapeMode.h>
#include <System.Private.Uri/System/Uri-dep.h>
#include <System.Private.Uri/System/UriComponents.h>
#include <System.Private.Uri/System/UriFormat.h>
#include <System.Private.Uri/System/UriFormatException-dep.h>
#include <System.Private.Uri/System/UriHelper-dep.h>
#include <System.Private.Uri/System/UriKind.h>
#include <System.Private.Uri/System/UriSyntaxFlags.h>

namespace System::Private::Uri::System::UriNamespace {
using namespace ::System::Private::CoreLib::Internal::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Text;
using namespace ::System::Private::CoreLib::System::Threading;
using namespace System::Collections::Generic;
using namespace System::Text;

void Uri___::MoreInfo___::ctor() {
}

Uri::in::MoreInfo Uri___::UriInfo___::get_MoreInfo() {
  if (_moreInfo == nullptr) {
    Interlocked::CompareExchange(_moreInfo, rt::newobj<MoreInfo>(), (MoreInfo)nullptr);
  }
  return _moreInfo;
}

void Uri___::UriInfo___::ctor() {
}

void Uri___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void Uri___::__c___::ctor() {
}

void Uri___::__c___::_HexEscape_b__119_0(Span<Char> chars, Byte b) {
  chars[0] = '%';
  HexConverter::ToCharsBuffer(b, chars, 1);
}

void Uri___::__c___::_CheckSchemeSyntax_b__151_1(Span<Char> buffer, ValueTuple<IntPtr, Int32> state) {
  Int32 num = MemoryExtensions::ToLowerInvariant(ReadOnlySpan<Char>((void*)state.Item1, state.Item2), buffer);
}

Boolean Uri___::get_IsImplicitFile() {
  return (_flags & Flags::ImplicitFile) != 0;
}

Boolean Uri___::get_IsUncOrDosPath() {
  return (_flags & (Flags::DosPath | Flags::UncPath)) != 0;
}

Boolean Uri___::get_IsDosPath() {
  return (_flags & Flags::DosPath) != 0;
}

Boolean Uri___::get_IsUncPath() {
  return (_flags & Flags::UncPath) != 0;
}

Uri::in::Flags Uri___::get_HostType() {
  return _flags & Flags::HostTypeMask;
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
  return (_flags & Flags::UserDrivenParsing) != 0;
}

Int32 Uri___::get_SecuredPathIndex() {
  if (get_IsDosPath()) {
    Char c = _string[_info->Offset.Path];
    if (c != '/' && c != '\\') {
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
  if (get_IsDosPath() && text[0] == '/') {
    text = text->Substring(1);
  }
  return text;
}

String Uri___::get_PrivateAbsolutePath() {
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
  String as = moreInfo2->Path;
  return as != nullptr ? as : (moreInfo2->Path = GetParts(UriComponents::Path | UriComponents::KeepDelimiter, UriFormat::UriEscaped));
}

String Uri___::get_AbsoluteUri() {
  if (_syntax == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
  String as = moreInfo2->AbsoluteUri;
  return as != nullptr ? as : (moreInfo2->AbsoluteUri = GetParts(UriComponents::AbsoluteUri, UriFormat::UriEscaped));
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
  return GetParts(UriComponents::Host | UriComponents::Port, UriFormat::UriEscaped);
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
    if (get_IsDosPath() && text[0] == '/') {
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
  ArrayBuilder<String> arrayBuilder;
  Int32 num = 0;
  while (num < privateAbsolutePath->get_Length()) {
    Int32 num2 = privateAbsolutePath->IndexOf('/', num);
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
  String as = moreInfo2->Query;
  return as != nullptr ? as : (moreInfo2->Query = GetParts(UriComponents::Query | UriComponents::KeepDelimiter, UriFormat::UriEscaped));
}

String Uri___::get_Fragment() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
  String as = moreInfo2->Fragment;
  return as != nullptr ? as : (moreInfo2->Fragment = GetParts(UriComponents::Fragment | UriComponents::KeepDelimiter, UriFormat::UriEscaped));
}

String Uri___::get_Scheme() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return _syntax->get_SchemeName();
}

String Uri___::get_OriginalString() {
  String as = _originalUnicodeString;
  return as != nullptr ? as : _string;
}

String Uri___::get_DnsSafeHost() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  EnsureHostString(false);
  Flags hostType = get_HostType();
  if (hostType == Flags::IPv6HostType || (hostType == Flags::BasicHostType && InFact(Flags::HostNotCanonical | Flags::E_HostNotCanonical))) {
    return get_IdnHost();
  }
  return _info->Host;
}

String Uri___::get_IdnHost() {
  if (get_IsNotAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  UriInfo info = _info;
  if (((info != nullptr) ? info->IdnHost : nullptr) == nullptr) {
    EnsureHostString(false);
    String text = _info->Host;
    switch (get_HostType()) {
      case Flags::DnsHostType:
        text = DomainNameHelper::IdnEquivalent(text);
        break;
      case Flags::IPv6HostType:
        text = ((_info->ScopeId != nullptr) ? String::in::Concat(MemoryExtensions::AsSpan(text, 1, text->get_Length() - 2), _info->ScopeId) : text->Substring(1, text->get_Length() - 2));
        break;
      case Flags::BasicHostType:
        if (InFact(Flags::HostNotCanonical | Flags::E_HostNotCanonical)) {
          Char as[256] = {};
          Span<Char> initialBuffer = as;
          ValueStringBuilder dest = ValueStringBuilder(initialBuffer);
          UriHelper::UnescapeString(text, 0, text->get_Length(), dest, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, _syntax, false);
          text = dest.ToString();
        }
        break;
    }
    _info->IdnHost = text;
  }
  return _info->IdnHost;
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
  {
    rt::lock(_info);
    _flags |= flags;
  }
}

Boolean Uri___::IriParsingStatic(UriParser syntax) {
  if (syntax != nullptr) {
    return syntax->InFact(UriSyntaxFlags::AllowIriParsing);
  }
  return true;
}

Boolean Uri___::NotAny(Flags flags) {
  return (_flags & flags) == 0;
}

Boolean Uri___::InFact(Flags flags) {
  return (_flags & flags) != 0;
}

Boolean Uri___::StaticNotAny(Flags allFlags, Flags checkFlags) {
  return (allFlags & checkFlags) == 0;
}

Boolean Uri___::StaticInFact(Flags allFlags, Flags checkFlags) {
  return (allFlags & checkFlags) != 0;
}

Uri::in::UriInfo Uri___::EnsureUriInfo() {
  Flags flags = _flags;
  if ((flags & Flags::MinimalUriInfoSet) == Flags::Zero) {
    CreateUriInfo(flags);
  }
  return _info;
}

void Uri___::EnsureParseRemaining() {
  if ((_flags & Flags::AllUriInfoSet) == Flags::Zero) {
    ParseRemaining();
  }
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

void Uri___::GetObjectDataOfISerializable(SerializationInfo serializationInfo, StreamingContext streamingContext) {
  GetObjectData(serializationInfo, streamingContext);
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
    UriFormatException parsingError;
    relativeUri = baseUri->get_Syntax()->InternalResolve(baseUri, (Uri)this, parsingError);
    if (parsingError != nullptr) {
      rt::throw_exception(parsingError);
    }
  }
  _flags = Flags::Zero;
  _info = nullptr;
  _syntax = nullptr;
  _originalUnicodeString = nullptr;
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
    UriFormatException parsingError;
    newUriString = baseUri->get_Syntax()->InternalResolve(baseUri, (Uri)this, parsingError);
    if (parsingError != nullptr) {
      rt::throw_exception(parsingError);
    }
  }
  _flags = Flags::Zero;
  _info = nullptr;
  _syntax = nullptr;
  _originalUnicodeString = nullptr;
  CreateThis(newUriString, userEscaped, UriKind::Absolute);
}

void Uri___::GetCombinedString(Uri baseUri, String relativeStr, Boolean dontEscape, String& result) {
  for (Int32 i = 0; i < relativeStr->get_Length() && relativeStr[i] != '/' && relativeStr[i] != '\\' && relativeStr[i] != '?' && relativeStr[i] != '#'; i++) {
    if (relativeStr[i] == ':') {
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
    if (NotAny(Flags::HostNotCanonical | Flags::PathNotCanonical | Flags::ShouldBeCompressed)) {
      num = (get_IsUncPath() ? (_info->Offset.Host - 2) : _info->Offset.Path);
      String text = (get_IsImplicitFile() && _info->Offset.Host == ((!get_IsDosPath()) ? 2 : 0) && _info->Offset.Query == _info->Offset.End) ? _string : ((get_IsDosPath() && (_string[num] == '/' || _string[num] == '\\')) ? _string->Substring(num + 1, _info->Offset.Query - num - 1) : _string->Substring(num, _info->Offset.Query - num));
      if (get_IsDosPath() && text[1] == '|') {
        text = text->Remove(1, 1);
        text = text->Insert(1, ":");
      }
      for (Int32 i = 0; i < text->get_Length(); i++) {
        if (text[i] == '/') {
          text = text->Replace('/', '\\');
          break;
        }
      }
      return text;
    }
    Int32 destPosition = 0;
    num = _info->Offset.Path;
    String host = _info->Host;
    Array<Char> array = rt::newarr<Array<Char>>(host->get_Length() + 3 + _info->Offset.Fragment - _info->Offset.Path);
    if (get_IsUncPath()) {
      array[0] = '\\';
      array[1] = '\\';
      destPosition = 2;
      UriHelper::UnescapeString(host, 0, host->get_Length(), array, destPosition, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, false);
    } else if (_string[num] == '/' || _string[num] == '\\') {
      num++;
    }

    UInt16 num2 = (UInt16)destPosition;
    UnescapeMode unescapeMode = (InFact(Flags::PathNotCanonical) && !get_IsImplicitFile()) ? (UnescapeMode::Unescape | UnescapeMode::UnescapeAll) : UnescapeMode::CopyOnly;
    UriHelper::UnescapeString(_string, num, _info->Offset.Query, array, destPosition, 'ÿ', 'ÿ', 'ÿ', unescapeMode, _syntax, true);
    if (array[1] == '|') {
      array[1] = ':';
    }
    if (InFact(Flags::ShouldBeCompressed)) {
      array = Compress(array, (UInt16)(get_IsDosPath() ? (num2 + 2) : num2), destPosition, _syntax);
    }
    for (UInt16 num3 = 0; num3 < (UInt16)destPosition; num3 = (UInt16)(num3 + 1)) {
      if (array[num3] == '/') {
        array[num3] = '\\';
      }
    }
    return rt::newstr<String>(array, 0, destPosition);
  }
  return GetUnescapedParts(UriComponents::Path | UriComponents::KeepDelimiter, UriFormat::Unescaped);
}

UriHostNameType Uri___::CheckHostName(String name) {
  if (name == nullptr || name->get_Length() == 0 || name->get_Length() > 32767) {
    return UriHostNameType::Unknown;
  }
  Int32 end = name->get_Length();
  {
    Char* ptr = name;
    Char* name2 = ptr;
    if (name[0] == '[' && name[name->get_Length() - 1] == ']' && IPv6AddressHelper::IsValid(name2, 1, end) && end == name->get_Length()) {
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
  switch (part) {
    case UriPartial::Scheme:
      return GetParts(UriComponents::Scheme | UriComponents::KeepDelimiter, UriFormat::UriEscaped);
    case UriPartial::Authority:
      if (NotAny(Flags::AuthorityFound) || get_IsDosPath()) {
        return String::in::Empty;
      }
      return GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port, UriFormat::UriEscaped);
    case UriPartial::Path:
      return GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path, UriFormat::UriEscaped);
    case UriPartial::Query:
      return GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path | UriComponents::Query, UriFormat::UriEscaped);
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidUriSubcomponent(), part), "part");
  }
}

String Uri___::HexEscape(Char character) {
  if (character > 'ÿ') {
    rt::throw_exception<ArgumentOutOfRangeException>("character");
  }
  SpanAction<Char, Byte> as = __c::in::__9__119_0;
  return String::in::Create(3, (Byte)character, as != nullptr ? as : (__c::in::__9__119_0 = {__c::in::__9, &__c::in::_HexEscape_b__119_0}));
}

Char Uri___::HexUnescape(String pattern, Int32& index) {
  if (index < 0 || index >= pattern->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  if (pattern[index] == '%' && pattern->get_Length() - index >= 3) {
    Char c = UriHelper::DecodeHexChars(pattern[index + 1], pattern[index + 2]);
    if (c != 'ÿ') {
      index += 3;
      return c;
    }
  }
  return pattern[index++];
}

Boolean Uri___::IsHexEncoding(String pattern, Int32 index) {
  if (pattern->get_Length() - index >= 3 && pattern[index] == '%' && IsHexDigit(pattern[index + 1])) {
    return IsHexDigit(pattern[index + 2]);
  }
  return false;
}

Boolean Uri___::CheckSchemeName(String schemeName) {
  if (schemeName == nullptr || schemeName->get_Length() == 0 || !UriHelper::IsAsciiLetter(schemeName[0])) {
    return false;
  }
  for (Int32 num = schemeName->get_Length() - 1; num > 0; num--) {
    if (!UriHelper::IsAsciiLetterOrDigit(schemeName[num]) && schemeName[num] != '+' && schemeName[num] != '-' && schemeName[num] != '.') {
      return false;
    }
  }
  return true;
}

Boolean Uri___::IsHexDigit(Char character) {
  return HexConverter::IsHexChar(character);
}

Int32 Uri___::FromHex(Char digit) {
  Int32 num = HexConverter::FromChar(digit);
  if (num == 255) {
    rt::throw_exception<ArgumentException>(nullptr, "digit");
  }
  return num;
}

Int32 Uri___::GetHashCode() {
  if (get_IsNotAbsoluteUri()) {
    return get_OriginalString()->GetHashCode();
  }
  MoreInfo moreInfo = EnsureUriInfo()->get_MoreInfo();
  MoreInfo moreInfo2 = moreInfo;
  String as = moreInfo2->RemoteUrl;
  String text = as != nullptr ? as : (moreInfo2->RemoteUrl = GetParts(UriComponents::HttpRequestUrl, UriFormat::SafeUnescaped));
  if (get_IsUncOrDosPath()) {
    return text->GetHashCode(StringComparison::OrdinalIgnoreCase);
  }
  return text->GetHashCode();
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
        if (string[num3] == ':') {
          break;
        }
        num++;
        num3++;
      }
      if (num < _info->Offset.Path && _string[num] != ':') {
        return false;
      }
      if (num3 < path && string[num3] != ':') {
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
  String as = moreInfo3->RemoteUrl;
  String a = as != nullptr ? as : (moreInfo3->RemoteUrl = GetParts(UriComponents::HttpRequestUrl, UriFormat::SafeUnescaped));
  moreInfo3 = moreInfo2;
  String is = moreInfo3->RemoteUrl;
  String b = is != nullptr ? is : (moreInfo3->RemoteUrl = result->GetParts(UriComponents::HttpRequestUrl, UriFormat::SafeUnescaped));
  return String::in::Equals(a, b, get_IsUncOrDosPath() ? StringComparison::OrdinalIgnoreCase : StringComparison::Ordinal);
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
    text += uri->GetParts(UriComponents::Query | UriComponents::Fragment, UriFormat::UriEscaped);
    return rt::newobj<Uri>(text, UriKind::Relative);
  }
  return uri;
}

Boolean Uri___::CheckForColonInFirstPathSegment(String uriString) {
  Int32 num = uriString->IndexOfAny(s_pathDelims);
  if (num >= 0) {
    return uriString[num] == ':';
  }
  return false;
}

String Uri___::InternalEscapeString(String rawString) {
  if (rawString != nullptr) {
    return UriHelper::EscapeString(rawString, true, UriHelper::get_UnreservedReservedTable(), '?', '#');
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
  Int32 num = (Int32)(_flags & Flags::IndexMask);
  Int32 num2 = _string->get_Length();
  String newHost = nullptr;
  _flags &= ~(Flags::SchemeNotCanonical | Flags::UserNotCanonical | Flags::HostNotCanonical | Flags::PortNotCanonical | Flags::PathNotCanonical | Flags::QueryNotCanonical | Flags::FragmentNotCanonical | Flags::E_UserNotCanonical | Flags::E_HostNotCanonical | Flags::E_PortNotCanonical | Flags::E_PathNotCanonical | Flags::E_QueryNotCanonical | Flags::E_FragmentNotCanonical | Flags::ShouldBeCompressed | Flags::FirstSlashAbsent | Flags::BackslashInPath | Flags::UserDrivenParsing);
  {
    Char* ptr = ((_flags & Flags::HostUnicodeNormalized) == Flags::Zero) ? get_OriginalString() : _string;
    Char* ptr2 = ptr;
    if (num2 > num && UriHelper::IsLWS(*(ptr2 + num2 - 1))) {
      num2--;
      while (num2 != num && UriHelper::IsLWS(*(ptr2 + --num2))) {
      }
      num2++;
    }
    if (_syntax->IsAllSet(UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowDOSPath) && NotAny(Flags::ImplicitFile) && num + 1 < num2) {
      Int32 i;
      for (i = num; i < num2; i++) {
        Char c;
        if ((c = *(ptr2 + i)) != '\\' && c != '/') {
          break;
        }
      }
      if (_syntax->InFact(UriSyntaxFlags::FileLikeUri) || i - num <= 3) {
        if (i - num >= 2) {
          _flags |= Flags::AuthorityFound;
        }
        Char c;
        if (i + 1 < num2 && ((c = *(ptr2 + i + 1)) == ':' || c == '|') && UriHelper::IsAsciiLetter(*(ptr2 + i))) {
          if (i + 2 >= num2 || ((c = *(ptr2 + i + 2)) != '\\' && c != '/')) {
            if (_syntax->InFact(UriSyntaxFlags::FileLikeUri)) {
              return ParsingError::MustRootedPath;
            }
          } else {
            _flags |= Flags::DosPath;
            if (_syntax->InFact(UriSyntaxFlags::MustHaveAuthority)) {
              _flags |= Flags::AuthorityFound;
            }
            num = ((i == num || i - num == 2) ? i : (i - 1));
          }
        } else if (_syntax->InFact(UriSyntaxFlags::FileLikeUri) && i - num >= 2 && i - num != 3 && i < num2 && *(ptr2 + i) != '?' && *(ptr2 + i) != '#') {
          _flags |= Flags::UncPath;
          num = i;
        }

      }
    }
    if ((_flags & (Flags::DosPath | Flags::UncPath | Flags::UnixPath)) == Flags::Zero) {
      if (num + 2 <= num2) {
        Char c2 = *(ptr2 + num);
        Char c3 = *(ptr2 + num + 1);
        if (_syntax->InFact(UriSyntaxFlags::MustHaveAuthority)) {
          if ((c2 != '/' && c2 != '\\') || (c3 != '/' && c3 != '\\')) {
            return ParsingError::BadAuthority;
          }
          _flags |= Flags::AuthorityFound;
          num += 2;
        } else if (_syntax->InFact(UriSyntaxFlags::OptionalAuthority) && (InFact(Flags::AuthorityFound) || (c2 == '/' && c3 == '/'))) {
          _flags |= Flags::AuthorityFound;
          num += 2;
        } else if (_syntax->NotAny(UriSyntaxFlags::MailToLikeUri)) {
          if ((_flags & (Flags::HasUnicode | Flags::HostUnicodeNormalized)) == Flags::HasUnicode) {
            _string = _string->Substring(0, num);
          }
          _flags |= (Flags)((Int64)num | 458752);
          return ParsingError::None;
        }


      } else {
        if (_syntax->InFact(UriSyntaxFlags::MustHaveAuthority)) {
          return ParsingError::BadAuthority;
        }
        if (_syntax->NotAny(UriSyntaxFlags::MailToLikeUri)) {
          if ((_flags & (Flags::HasUnicode | Flags::HostUnicodeNormalized)) == Flags::HasUnicode) {
            _string = _string->Substring(0, num);
          }
          _flags |= (Flags)((Int64)num | 458752);
          return ParsingError::None;
        }
      }
    }
    if (InFact(Flags::DosPath)) {
      _flags |= (Flags)(((_flags & Flags::AuthorityFound) != Flags::Zero) ? 327680 : 458752);
      _flags |= (Flags)num;
      return ParsingError::None;
    }
    ParsingError err = ParsingError::None;
    num = CheckAuthorityHelper(ptr2, num, num2, err, _flags, _syntax, newHost);
    if (err != 0) {
      return err;
    }
    if (num < num2) {
      Char c4 = *(ptr2 + num);
      if (c4 == '\\' && NotAny(Flags::ImplicitFile) && _syntax->NotAny(UriSyntaxFlags::AllowDOSPath)) {
        return ParsingError::BadAuthorityTerminator;
      }
    }
    _flags |= (Flags)num;
  }
  if (get_IriParsing() && newHost != nullptr) {
    _string = newHost;
  }
  return ParsingError::None;
}

void Uri___::CreateUriInfo(Flags cF) {
  UriInfo uriInfo = rt::newobj<UriInfo>();
  uriInfo->Offset.End = (UInt16)_string->get_Length();
  if (!get_UserDrivenParsing()) {
    Boolean flag = false;
    Int32 i;
    if ((cF & Flags::ImplicitFile) != Flags::Zero) {
      i = 0;
      while (UriHelper::IsLWS(_string[i])) {
        i++;
        uriInfo->Offset.Scheme++;
      }
      if (StaticInFact(cF, Flags::UncPath)) {
        i += 2;
        for (Int32 num = (Int32)(cF & Flags::IndexMask); i < num && (_string[i] == '/' || _string[i] == '\\'); i++) {
        }
      }
    } else {
      i = _syntax->get_SchemeName()->get_Length();
      while (_string[i++] != ':') {
        uriInfo->Offset.Scheme++;
      }
      if ((cF & Flags::AuthorityFound) != Flags::Zero) {
        if (_string[i] == '\\' || _string[i + 1] == '\\') {
          flag = true;
        }
        i += 2;
        if ((cF & (Flags::DosPath | Flags::UncPath)) != Flags::Zero) {
          for (Int32 num2 = (Int32)(cF & Flags::IndexMask); i < num2 && (_string[i] == '/' || _string[i] == '\\'); i++) {
            flag = true;
          }
        }
      }
    }
    if (_syntax->get_DefaultPort() != -1) {
      uriInfo->Offset.PortValue = (UInt16)_syntax->get_DefaultPort();
    }
    if ((cF & Flags::HostTypeMask) == Flags::HostTypeMask || StaticInFact(cF, Flags::DosPath)) {
      uriInfo->Offset.User = (UInt16)(cF & Flags::IndexMask);
      uriInfo->Offset.Host = uriInfo->Offset.User;
      uriInfo->Offset.Path = uriInfo->Offset.User;
      cF = (Flags)((UInt64)cF & 18446744073709486080);
      if (flag) {
        cF |= Flags::SchemeNotCanonical;
      }
    } else {
      uriInfo->Offset.User = (UInt16)i;
      if (get_HostType() == Flags::BasicHostType) {
        uriInfo->Offset.Host = (UInt16)i;
        uriInfo->Offset.Path = (UInt16)(cF & Flags::IndexMask);
        cF = (Flags)((UInt64)cF & 18446744073709486080);
      } else {
        if ((cF & Flags::HasUserInfo) != Flags::Zero) {
          for (; _string[i] != '@'; i++) {
          }
          i++;
          uriInfo->Offset.Host = (UInt16)i;
        } else {
          uriInfo->Offset.Host = (UInt16)i;
        }
        i = (Int32)(cF & Flags::IndexMask);
        cF = (Flags)((UInt64)cF & 18446744073709486080);
        if (flag) {
          cF |= Flags::SchemeNotCanonical;
        }
        uriInfo->Offset.Path = (UInt16)i;
        Boolean flag2 = false;
        if ((cF & Flags::HasUnicode) != Flags::Zero) {
          uriInfo->Offset.End = (UInt16)_originalUnicodeString->get_Length();
        }
        if (i < uriInfo->Offset.End) {
          {
            Char* ptr = get_OriginalString();
            Char* ptr2 = ptr;
            if (*(ptr2 + i) == ':') {
              Int32 num3 = 0;
              if (++i < uriInfo->Offset.End) {
                num3 = *(ptr2 + i) - 48;
                if ((UInt32)num3 <= 9u) {
                  flag2 = true;
                  if (num3 == 0) {
                    cF |= (Flags::PortNotCanonical | Flags::E_PortNotCanonical);
                  }
                  for (i++; i < uriInfo->Offset.End; i++) {
                    Int32 num4 = *(ptr2 + i) - 48;
                    if ((UInt32)num4 > 9u) {
                      break;
                    }
                    num3 = num3 * 10 + num4;
                  }
                }
              }
              if (flag2 && uriInfo->Offset.PortValue != num3) {
                uriInfo->Offset.PortValue = (UInt16)num3;
                cF |= Flags::NotDefaultPort;
              } else {
                cF |= (Flags::PortNotCanonical | Flags::E_PortNotCanonical);
              }
              uriInfo->Offset.Path = (UInt16)i;
            }
          }
        }
      }
    }
  }
  cF |= Flags::MinimalUriInfoSet;
  Interlocked::CompareExchange(_info, uriInfo, (UriInfo)nullptr);
  Flags flags = _flags;
  while ((flags & Flags::MinimalUriInfoSet) == Flags::Zero) {
    Flags value = (Flags)((UInt64)((Int64)flags & -65536) | (UInt64)cF);
    UInt64 num5 = Interlocked::CompareExchange(Unsafe::As<Flags, UInt64>(_flags), (UInt64)value, (UInt64)flags);
    if (num5 == (UInt64)flags) {
      break;
    }
    flags = (Flags)num5;
  }
}

void Uri___::CreateHostString() {
  if (!_syntax->get_IsSimple()) {
    {
      rt::lock(_info);
      if (NotAny(Flags::ErrorOrParsingRecursion)) {
        _flags |= Flags::ErrorOrParsingRecursion;
        GetHostViaCustomSyntax();
        _flags &= ~Flags::ErrorOrParsingRecursion;
        return;
      }
    }
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
        check = CheckCanonical(str, idx, text->get_Length(), 'ÿ');
      }
      if ((check & Check::DisplayCanonical) == 0 && (NotAny(Flags::ImplicitFile) || (check & Check::ReservedFound) != 0)) {
        flags |= Flags::HostNotCanonical;
      }
      if (InFact(Flags::ImplicitFile) && (check & (Check::EscapedCanonical | Check::ReservedFound)) != 0) {
        check &= ~Check::EscapedCanonical;
      }
      if ((check & (Check::EscapedCanonical | Check::BackslashInPath)) != Check::EscapedCanonical) {
        flags |= Flags::E_HostNotCanonical;
        if (NotAny(Flags::UserEscaped)) {
          text = UriHelper::EscapeString(text, !get_IsImplicitFile(), UriHelper::get_UnreservedReservedTable(), '?', '#');
        }
      }
    } else if (NotAny(Flags::CanonicalDnsHost)) {
      if (_info->ScopeId != nullptr) {
        flags |= (Flags::HostNotCanonical | Flags::E_HostNotCanonical);
      } else {
        for (Int32 i = 0; i < text->get_Length(); i++) {
          if (_info->Offset.Host + i >= _info->Offset.End || text[i] != _string[_info->Offset.Host + i]) {
            flags |= (Flags::HostNotCanonical | Flags::E_HostNotCanonical);
            break;
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
  switch (flags & Flags::HostTypeMask) {
    case Flags::DnsHostType:
      text = DomainNameHelper::ParseCanonicalName(str, idx, end, loopback);
      break;
    case Flags::IPv6HostType:
      text = IPv6AddressHelper::ParseCanonicalName(str, idx, loopback, scopeId);
      break;
    case Flags::IPv4HostType:
      text = IPv4AddressHelper::ParseCanonicalName(str, idx, end, loopback);
      break;
    case Flags::UncHostType:
      text = UncNameHelper::ParseCanonicalName(str, idx, end, loopback);
      break;
    case Flags::BasicHostType:
      text = ((!StaticInFact(flags, Flags::DosPath)) ? str->Substring(idx, end - idx) : String::in::Empty);
      if (text->get_Length() == 0) {
        loopback = true;
      }
      break;
    case Flags::HostTypeMask:
      text = String::in::Empty;
      break;
    default:
      rt::throw_exception(GetException(ParsingError::BadHostName));
  }
  if (loopback) {
    flags |= Flags::LoopbackHost;
  }
  return text;
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
    Flags flags = (Flags)((UInt64)_flags & 18446744073709092863);
    {
      Char* ptr = text;
      Char* pString = ptr;
      String newHost = nullptr;
      if (CheckAuthorityHelper(pString, 0, text->get_Length(), err, flags, _syntax, newHost) != text->get_Length()) {
        flags = (Flags)((UInt64)flags & 18446744073709092863);
        flags |= Flags::HostTypeMask;
      }
    }
    if (err != 0 || (flags & Flags::HostTypeMask) == Flags::HostTypeMask) {
      _flags = (Flags)(((Int64)_flags & -458753) | 327680);
    } else {
      text = CreateHostStringHelper(text, 0, text->get_Length(), flags, _info->ScopeId);
      for (Int32 i = 0; i < text->get_Length(); i++) {
        if (_info->Offset.Host + i >= _info->Offset.End || text[i] != _string[_info->Offset.Host + i]) {
          _flags |= (Flags::HostNotCanonical | Flags::E_HostNotCanonical);
          break;
        }
      }
      _flags = (Flags)((UInt64)((Int64)_flags & -458753) | (UInt64)(flags & Flags::HostTypeMask));
    }
  }
  String text2 = _syntax->InternalGetComponents((Uri)this, UriComponents::StrongPort, UriFormat::UriEscaped);
  Int32 num = 0;
  if (text2 == nullptr || text2->get_Length() == 0) {
    _flags &= ~Flags::NotDefaultPort;
    _flags |= (Flags::PortNotCanonical | Flags::E_PortNotCanonical);
    _info->Offset.PortValue = 0;
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
      _flags |= (Flags::PortNotCanonical | Flags::E_PortNotCanonical);
      _info->Offset.PortValue = (UInt16)num;
    }
  }
  _info->Host = text;
}

String Uri___::GetParts(UriComponents uriParts, UriFormat formatAs) {
  return GetComponents(uriParts, formatAs);
}

String Uri___::GetEscapedParts(UriComponents uriParts) {
  UInt16 num = (UInt16)(((UInt16)_flags & 16256) >> 6);
  if (InFact(Flags::SchemeNotCanonical)) {
    num = (UInt16)(num | 1);
  }
  if ((uriParts & UriComponents::Path) != 0) {
    if (InFact(Flags::ShouldBeCompressed | Flags::FirstSlashAbsent | Flags::BackslashInPath)) {
      num = (UInt16)(num | 16);
    } else if (get_IsDosPath() && _string[_info->Offset.Path + get_SecuredPathIndex() - 1] == '|') {
      num = (UInt16)(num | 16);
    }

  }
  if (((UInt16)uriParts & num) == 0) {
    String uriPartsFromUserString = GetUriPartsFromUserString(uriParts);
    if (uriPartsFromUserString != nullptr) {
      return uriPartsFromUserString;
    }
  }
  return ReCreateParts(uriParts, num, UriFormat::UriEscaped);
}

String Uri___::GetUnescapedParts(UriComponents uriParts, UriFormat formatAs) {
  UInt16 num = (UInt16)((UInt16)_flags & 127);
  if ((uriParts & UriComponents::Path) != 0) {
    if ((_flags & (Flags::ShouldBeCompressed | Flags::FirstSlashAbsent | Flags::BackslashInPath)) != Flags::Zero) {
      num = (UInt16)(num | 16);
    } else if (get_IsDosPath() && _string[_info->Offset.Path + get_SecuredPathIndex() - 1] == '|') {
      num = (UInt16)(num | 16);
    }

  }
  if (((UInt16)uriParts & num) == 0) {
    String uriPartsFromUserString = GetUriPartsFromUserString(uriParts);
    if (uriPartsFromUserString != nullptr) {
      return uriPartsFromUserString;
    }
  }
  return ReCreateParts(uriParts, num, formatAs);
}

String Uri___::ReCreateParts(UriComponents parts, UInt16 nonCanonical, UriFormat formatAs) {
  EnsureHostString(false);
  String text = ((parts & UriComponents::Host) == 0) ? String::in::Empty : _info->Host;
  Int32 num = (_info->Offset.End - _info->Offset.User) * ((formatAs != UriFormat::UriEscaped) ? 1 : 12);
  Array<Char> array = rt::newarr<Array<Char>>(text->get_Length() + num + _syntax->get_SchemeName()->get_Length() + 3 + 1);
  num = 0;
  if ((parts & UriComponents::Scheme) != 0) {
    _syntax->get_SchemeName()->CopyTo(0, array, num, _syntax->get_SchemeName()->get_Length());
    num += _syntax->get_SchemeName()->get_Length();
    if (parts != UriComponents::Scheme) {
      array[num++] = ':';
      if (InFact(Flags::AuthorityFound)) {
        array[num++] = '/';
        array[num++] = '/';
      }
    }
  }
  if ((parts & UriComponents::UserInfo) != 0 && InFact(Flags::HasUserInfo)) {
    if ((nonCanonical & 2) != 0) {
      switch (formatAs) {
        case UriFormat::UriEscaped:
          if (NotAny(Flags::UserEscaped)) {
            array = UriHelper::EscapeString(MemoryExtensions::AsSpan(_string, _info->Offset.User, _info->Offset.Host - _info->Offset.User), array, num, true, '?', '#');
            break;
          }
          InFact(Flags::E_UserNotCanonical);
          _string->CopyTo(_info->Offset.User, array, num, _info->Offset.Host - _info->Offset.User);
          num += _info->Offset.Host - _info->Offset.User;
          break;
        case UriFormat::SafeUnescaped:
          array = UriHelper::UnescapeString(_string, _info->Offset.User, _info->Offset.Host - 1, array, num, '@', '/', '\\', InFact(Flags::UserEscaped) ? UnescapeMode::Unescape : UnescapeMode::EscapeUnescape, _syntax, false);
          array[num++] = '@';
          break;
        case UriFormat::Unescaped:
          array = UriHelper::UnescapeString(_string, _info->Offset.User, _info->Offset.Host, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, _syntax, false);
          break;
        default:
          array = UriHelper::UnescapeString(_string, _info->Offset.User, _info->Offset.Host, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, false);
          break;
      }
    } else {
      UriHelper::UnescapeString(_string, _info->Offset.User, _info->Offset.Host, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, false);
    }
    if (parts == UriComponents::UserInfo) {
      num--;
    }
  }
  if ((parts & UriComponents::Host) != 0 && text->get_Length() != 0) {
    UnescapeMode unescapeMode = (formatAs != UriFormat::UriEscaped && get_HostType() == Flags::BasicHostType && (nonCanonical & 4) != 0) ? ((formatAs == UriFormat::Unescaped) ? (UnescapeMode::Unescape | UnescapeMode::UnescapeAll) : (InFact(Flags::UserEscaped) ? UnescapeMode::Unescape : UnescapeMode::EscapeUnescape)) : UnescapeMode::CopyOnly;
    if ((parts & UriComponents::NormalizedHost) != 0) {
      {
        Char* ptr = text;
        Char* hostname = ptr;
        Boolean allAscii = false;
        Boolean atLeastOneValidIdn = false;
        try {
          text = DomainNameHelper::UnicodeEquivalent(hostname, 0, text->get_Length(), allAscii, atLeastOneValidIdn);
        } catch (UriFormatException) {
        }
      }
    }
    array = UriHelper::UnescapeString(text, 0, text->get_Length(), array, num, '/', '?', '#', unescapeMode, _syntax, false);
    if ((parts & UriComponents::SerializationInfoString) != 0 && get_HostType() == Flags::IPv6HostType && _info->ScopeId != nullptr) {
      _info->ScopeId->CopyTo(0, array, num - 1, _info->ScopeId->get_Length());
      num += _info->ScopeId->get_Length();
      array[num - 1] = ']';
    }
  }
  if ((parts & UriComponents::Port) != 0) {
    if ((nonCanonical & 8) == 0) {
      if (InFact(Flags::NotDefaultPort)) {
        Int32 num2 = _info->Offset.Path;
        while (_string[--num2] != ':') {
        }
        _string->CopyTo(num2, array, num, _info->Offset.Path - num2);
        num += _info->Offset.Path - num2;
      } else if ((parts & UriComponents::StrongPort) != 0 && _syntax->get_DefaultPort() != -1) {
        array[num++] = ':';
        text = _info->Offset.PortValue.ToString(CultureInfo::in::get_InvariantCulture());
        text->CopyTo(0, array, num, text->get_Length());
        num += text->get_Length();
      }

    } else if (InFact(Flags::NotDefaultPort) || ((parts & UriComponents::StrongPort) != 0 && _syntax->get_DefaultPort() != -1)) {
      array[num++] = ':';
      text = _info->Offset.PortValue.ToString(CultureInfo::in::get_InvariantCulture());
      text->CopyTo(0, array, num, text->get_Length());
      num += text->get_Length();
    }

  }
  if ((parts & UriComponents::Path) != 0) {
    array = GetCanonicalPath(array, num, formatAs);
    if (parts == UriComponents::Path) {
      Int32 startIndex;
      if (InFact(Flags::AuthorityFound) && num != 0 && array[0] == '/') {
        startIndex = 1;
        num--;
      } else {
        startIndex = 0;
      }
      if (num != 0) {
        return rt::newstr<String>(array, startIndex, num);
      }
      return String::in::Empty;
    }
  }
  if ((parts & UriComponents::Query) != 0 && _info->Offset.Query < _info->Offset.Fragment) {
    Int32 startIndex = _info->Offset.Query + 1;
    if (parts != UriComponents::Query) {
      array[num++] = '?';
    }
    if ((nonCanonical & 32) != 0) {
      switch (formatAs) {
        case UriFormat::UriEscaped:
          if (NotAny(Flags::UserEscaped)) {
            array = UriHelper::EscapeString(MemoryExtensions::AsSpan(_string, startIndex, _info->Offset.Fragment - startIndex), array, num, true, '#');
          } else {
            UriHelper::UnescapeString(_string, startIndex, _info->Offset.Fragment, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, true);
          }
          break;
        case (UriFormat)32767:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.Fragment, array, num, '#', 'ÿ', 'ÿ', (UnescapeMode)((InFact(Flags::UserEscaped) ? 2 : 3) | 4), _syntax, true);
          break;
        case UriFormat::Unescaped:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.Fragment, array, num, '#', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, _syntax, true);
          break;
        default:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.Fragment, array, num, '#', 'ÿ', 'ÿ', InFact(Flags::UserEscaped) ? UnescapeMode::Unescape : UnescapeMode::EscapeUnescape, _syntax, true);
          break;
      }
    } else {
      UriHelper::UnescapeString(_string, startIndex, _info->Offset.Fragment, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, true);
    }
  }
  if ((parts & UriComponents::Fragment) != 0 && _info->Offset.Fragment < _info->Offset.End) {
    Int32 startIndex = _info->Offset.Fragment + 1;
    if (parts != UriComponents::Fragment) {
      array[num++] = '#';
    }
    if ((nonCanonical & 64) != 0) {
      switch (formatAs) {
        case UriFormat::UriEscaped:
          if (NotAny(Flags::UserEscaped)) {
            array = UriHelper::EscapeString(MemoryExtensions::AsSpan(_string, startIndex, _info->Offset.End - startIndex), array, num, true);
          } else {
            UriHelper::UnescapeString(_string, startIndex, _info->Offset.End, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, false);
          }
          break;
        case (UriFormat)32767:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.End, array, num, '#', 'ÿ', 'ÿ', (UnescapeMode)((InFact(Flags::UserEscaped) ? 2 : 3) | 4), _syntax, false);
          break;
        case UriFormat::Unescaped:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.End, array, num, '#', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, _syntax, false);
          break;
        default:
          array = UriHelper::UnescapeString(_string, startIndex, _info->Offset.End, array, num, '#', 'ÿ', 'ÿ', InFact(Flags::UserEscaped) ? UnescapeMode::Unescape : UnescapeMode::EscapeUnescape, _syntax, false);
          break;
      }
    } else {
      UriHelper::UnescapeString(_string, startIndex, _info->Offset.End, array, num, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::CopyOnly, _syntax, false);
    }
  }
  return rt::newstr<String>(array, 0, num);
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
    Boolean flag = (_flags & (Flags::HasUnicode | Flags::RestUnicodeNormalized)) == Flags::HasUnicode;
    Int32 scheme = _info->Offset.Scheme;
    Int32 length = _string->get_Length();
    Check check = Check::None;
    UriSyntaxFlags flags2 = _syntax->get_Flags();
    {
      Char* ptr = _string;
      Char* ptr2 = ptr;
      GetLengthWithoutTrailingSpaces(_string, length, scheme);
      if (get_IsImplicitFile()) {
        flags |= Flags::SchemeNotCanonical;
      } else {
        String schemeName = _syntax->get_SchemeName();
        Int32 i;
        for (i = 0; i < schemeName->get_Length(); i++) {
          if (schemeName[i] != *(ptr2 + scheme + i)) {
            flags |= Flags::SchemeNotCanonical;
          }
        }
        if ((_flags & Flags::AuthorityFound) != Flags::Zero && (scheme + i + 3 >= length || *(ptr2 + scheme + i + 1) != '/' || *(ptr2 + scheme + i + 2) != '/')) {
          flags |= Flags::SchemeNotCanonical;
        }
      }
      if ((_flags & Flags::HasUserInfo) != Flags::Zero) {
        scheme = _info->Offset.User;
        check = CheckCanonical(ptr2, scheme, _info->Offset.Host, '@');
        if ((check & Check::DisplayCanonical) == 0) {
          flags |= Flags::UserNotCanonical;
        }
        if ((check & (Check::EscapedCanonical | Check::BackslashInPath)) != Check::EscapedCanonical) {
          flags |= Flags::E_UserNotCanonical;
        }
        if (get_IriParsing() && (check & (Check::EscapedCanonical | Check::DisplayCanonical | Check::BackslashInPath | Check::NotIriCanonical | Check::FoundNonAscii)) == (Check::DisplayCanonical | Check::FoundNonAscii)) {
          flags |= Flags::UserIriCanonical;
        }
      }
    }
    scheme = _info->Offset.Path;
    Int32 num = _info->Offset.Path;
    if (flag) {
      if (get_IsFile() && !get_IsUncPath()) {
        if (get_IsImplicitFile()) {
          _string = String::in::Empty;
        } else {
          _string = _syntax->get_SchemeName() + SchemeDelimiter;
        }
      }
      _info->Offset.Path = (UInt16)_string->get_Length();
      scheme = _info->Offset.Path;
      Int32 start = num;
      if (get_IsImplicitFile() || (flags2 & (UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment)) == 0) {
        num = _originalUnicodeString->get_Length();
      } else {
        ReadOnlySpan<Char> span = MemoryExtensions::AsSpan(_originalUnicodeString, num);
        Int32 num2 = (!_syntax->InFact(UriSyntaxFlags::MayHaveQuery)) ? MemoryExtensions::IndexOf(span, '#') : ((!_syntax->InFact(UriSyntaxFlags::MayHaveFragment)) ? MemoryExtensions::IndexOf(span, '?') : MemoryExtensions::IndexOfAny(span, '?', '#'));
        num = ((num2 == -1) ? _originalUnicodeString->get_Length() : (num2 + num));
      }
      _string += EscapeUnescapeIri(_originalUnicodeString, start, num, UriComponents::Path);
      if (_string->get_Length() > 65535) {
        UriFormatException exception = GetException(ParsingError::SizeLimit);
        rt::throw_exception(exception);
      }
      length = _string->get_Length();
      if (_string == _originalUnicodeString) {
        GetLengthWithoutTrailingSpaces(_string, length, scheme);
      }
    }
    {
      Char* ptr3 = _string;
      Char* ptr4 = ptr3;
      check = ((!get_IsImplicitFile() && (flags2 & (UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment)) != 0) ? CheckCanonical(ptr4, scheme, length, ((flags2 & UriSyntaxFlags::MayHaveQuery) != 0) ? '?' : (_syntax->InFact(UriSyntaxFlags::MayHaveFragment) ? '#' : 'þ')) : CheckCanonical(ptr4, scheme, length, 'ÿ'));
      if ((_flags & Flags::AuthorityFound) != Flags::Zero && (flags2 & UriSyntaxFlags::PathIsRooted) != 0 && (_info->Offset.Path == length || (*(ptr4 + (Int32)_info->Offset.Path) != '/' && *(ptr4 + (Int32)_info->Offset.Path) != '\\'))) {
        flags |= Flags::FirstSlashAbsent;
      }
    }
    Boolean flag2 = false;
    if (get_IsDosPath() || ((_flags & Flags::AuthorityFound) != Flags::Zero && ((flags2 & (UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath)) != 0 || _syntax->InFact(UriSyntaxFlags::UnEscapeDotsAndSlashes)))) {
      if ((check & Check::DotSlashEscaped) != 0 && _syntax->InFact(UriSyntaxFlags::UnEscapeDotsAndSlashes)) {
        flags |= (Flags::PathNotCanonical | Flags::E_PathNotCanonical);
        flag2 = true;
      }
      if ((flags2 & UriSyntaxFlags::ConvertPathSlashes) != 0 && (check & Check::BackslashInPath) != 0) {
        flags |= (Flags::PathNotCanonical | Flags::E_PathNotCanonical);
        flag2 = true;
      }
      if ((flags2 & UriSyntaxFlags::CompressPath) != 0 && ((flags & Flags::E_PathNotCanonical) != Flags::Zero || (check & Check::DotSlashAttn) != 0)) {
        flags |= Flags::ShouldBeCompressed;
      }
      if ((check & Check::BackslashInPath) != 0) {
        flags |= Flags::BackslashInPath;
      }
    } else if ((check & Check::BackslashInPath) != 0) {
      flags |= Flags::E_PathNotCanonical;
      flag2 = true;
    }

    if ((check & Check::DisplayCanonical) == 0 && ((_flags & Flags::ImplicitFile) == Flags::Zero || (_flags & Flags::UserEscaped) != Flags::Zero || (check & Check::ReservedFound) != 0)) {
      flags |= Flags::PathNotCanonical;
      flag2 = true;
    }
    if ((_flags & Flags::ImplicitFile) != Flags::Zero && (check & (Check::EscapedCanonical | Check::ReservedFound)) != 0) {
      check &= ~Check::EscapedCanonical;
    }
    if ((check & Check::EscapedCanonical) == 0) {
      flags |= Flags::E_PathNotCanonical;
    }
    if (get_IriParsing() && !flag2 && (check & (Check::EscapedCanonical | Check::DisplayCanonical | Check::NotIriCanonical | Check::FoundNonAscii)) == (Check::DisplayCanonical | Check::FoundNonAscii)) {
      flags |= Flags::PathIriCanonical;
    }
    if (flag) {
      Int32 start2 = num;
      if (num < _originalUnicodeString->get_Length() && _originalUnicodeString[num] == '?') {
        if ((flags2 & UriSyntaxFlags::MayHaveFragment) != 0) {
          num++;
          Int32 num3 = MemoryExtensions::IndexOf(MemoryExtensions::AsSpan(_originalUnicodeString, num), '#');
          num = ((num3 == -1) ? _originalUnicodeString->get_Length() : (num3 + num));
        } else {
          num = _originalUnicodeString->get_Length();
        }
        _string += EscapeUnescapeIri(_originalUnicodeString, start2, num, UriComponents::Query);
        if (_string->get_Length() > 65535) {
          UriFormatException exception2 = GetException(ParsingError::SizeLimit);
          rt::throw_exception(exception2);
        }
        length = _string->get_Length();
        if (_string == _originalUnicodeString) {
          GetLengthWithoutTrailingSpaces(_string, length, scheme);
        }
      }
    }
    _info->Offset.Query = (UInt16)scheme;
    {
      Char* ptr5 = _string;
      Char* ptr6 = ptr5;
      if (scheme < length && *(ptr6 + scheme) == '?') {
        scheme++;
        check = CheckCanonical(ptr6, scheme, length, ((flags2 & UriSyntaxFlags::MayHaveFragment) != 0) ? '#' : 'þ');
        if ((check & Check::DisplayCanonical) == 0) {
          flags |= Flags::QueryNotCanonical;
        }
        if ((check & (Check::EscapedCanonical | Check::BackslashInPath)) != Check::EscapedCanonical) {
          flags |= Flags::E_QueryNotCanonical;
        }
        if (get_IriParsing() && (check & (Check::EscapedCanonical | Check::DisplayCanonical | Check::BackslashInPath | Check::NotIriCanonical | Check::FoundNonAscii)) == (Check::DisplayCanonical | Check::FoundNonAscii)) {
          flags |= Flags::QueryIriCanonical;
        }
      }
    }
    if (flag) {
      Int32 start3 = num;
      if (num < _originalUnicodeString->get_Length() && _originalUnicodeString[num] == '#') {
        num = _originalUnicodeString->get_Length();
        _string += EscapeUnescapeIri(_originalUnicodeString, start3, num, UriComponents::Fragment);
        if (_string->get_Length() > 65535) {
          UriFormatException exception3 = GetException(ParsingError::SizeLimit);
          rt::throw_exception(exception3);
        }
        length = _string->get_Length();
        GetLengthWithoutTrailingSpaces(_string, length, scheme);
      }
    }
    _info->Offset.Fragment = (UInt16)scheme;
    {
      Char* ptr7 = _string;
      Char* ptr8 = ptr7;
      if (scheme < length && *(ptr8 + scheme) == '#') {
        scheme++;
        check = CheckCanonical(ptr8, scheme, length, 'þ');
        if ((check & Check::DisplayCanonical) == 0) {
          flags |= Flags::FragmentNotCanonical;
        }
        if ((check & (Check::EscapedCanonical | Check::BackslashInPath)) != Check::EscapedCanonical) {
          flags |= Flags::E_FragmentNotCanonical;
        }
        if (get_IriParsing() && (check & (Check::EscapedCanonical | Check::DisplayCanonical | Check::BackslashInPath | Check::NotIriCanonical | Check::FoundNonAscii)) == (Check::DisplayCanonical | Check::FoundNonAscii)) {
          flags |= Flags::FragmentIriCanonical;
        }
      }
    }
    _info->Offset.End = (UInt16)scheme;
  }
  flags |= (Flags::AllUriInfoSet | Flags::RestUnicodeNormalized);
  InterlockedSetFlags(flags);
}

Int32 Uri___::ParseSchemeCheckImplicitFile(Char* uriString, Int32 length, ParsingError& err, Flags& flags, UriParser& syntax) {
  Int32 i;
  for (i = 0; i < length && UriHelper::IsLWS(*(uriString + i)); i++) {
  }
  Int32 j;
  for (j = i; j < length && *(uriString + j) != ':'; j++) {
  }
  if (IntPtr::get_Size() == 4) {
  }
  if (i + 2 >= length || j == i) {
    err = ParsingError::BadFormat;
    return 0;
  }
  Char c;
  if ((c = *(uriString + i + 1)) == ':' || c == '|') {
    if (UriHelper::IsAsciiLetter(*(uriString + i))) {
      if ((c = *(uriString + i + 2)) == '\\' || c == '/') {
        flags |= (Flags::AuthorityFound | Flags::DosPath | Flags::ImplicitFile);
        syntax = UriParser::in::FileUri;
        return i;
      }
      err = ParsingError::MustRootedPath;
      return 0;
    }
    if (c == ':') {
      err = ParsingError::BadScheme;
    } else {
      err = ParsingError::BadFormat;
    }
    return 0;
  }
  if ((c = *(uriString + i)) == '/' || c == '\\') {
    if ((c = *(uriString + i + 1)) == '\\' || c == '/') {
      flags |= (Flags::AuthorityFound | Flags::UncPath | Flags::ImplicitFile);
      syntax = UriParser::in::FileUri;
      for (i += 2; i < length; i++) {
        if ((c = *(uriString + i)) != '/' && c != '\\') {
          break;
        }
      }
      return i;
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
  auto ToLowerCaseAscii = [](Char c) -> Char {
    if ((UInt32)(c - 65) > 25u) {
      return c;
    }
    return (Char)(c | 32);
  };
  if (span.get_Length() == 0) {
    return ParsingError::BadScheme;
  }
  Char c2 = span[0];
  switch (c2.get()) {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      c2 = (Char)(c2 | 32);
      break;
    default:
      return ParsingError::BadScheme;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      break;
  }
  switch (span.get_Length().get()) {
    case 2:
      if (30579 == (((UInt32)c2 << 8) | ToLowerCaseAscii(span[1]))) {
        syntax = UriParser::in::WsUri;
        return ParsingError::None;
      }
      break;
    case 3:
      switch (((UInt32)c2 << 16) | ((UInt32)ToLowerCaseAscii(span[1]) << 8) | ToLowerCaseAscii(span[2]).get()) {
        case 6714480u:
          syntax = UriParser::in::FtpUri;
          return ParsingError::None;
        case 7828339u:
          syntax = UriParser::in::WssUri;
          return ParsingError::None;
      }
      break;
    case 4:
      switch (((UInt32)c2 << 24) | ((UInt32)ToLowerCaseAscii(span[1]) << 16) | ((UInt32)ToLowerCaseAscii(span[2]) << 8) | ToLowerCaseAscii(span[3]).get()) {
        case 1752462448u:
          syntax = UriParser::in::HttpUri;
          return ParsingError::None;
        case 1718185061u:
          syntax = UriParser::in::FileUri;
          return ParsingError::None;
      }
      break;
    case 5:
      if (1752462448 == (((UInt32)c2 << 24) | ((UInt32)ToLowerCaseAscii(span[1]) << 16) | ((UInt32)ToLowerCaseAscii(span[2]) << 8) | ToLowerCaseAscii(span[3])) && ToLowerCaseAscii(span[4]) == 's') {
        syntax = UriParser::in::HttpsUri;
        return ParsingError::None;
      }
      break;
    case 6:
      if (1835100524 == (((UInt32)c2 << 24) | ((UInt32)ToLowerCaseAscii(span[1]) << 16) | ((UInt32)ToLowerCaseAscii(span[2]) << 8) | ToLowerCaseAscii(span[3])) && ToLowerCaseAscii(span[4]) == 't' && ToLowerCaseAscii(span[5]) == 'o') {
        syntax = UriParser::in::MailToUri;
        return ParsingError::None;
      }
      break;
  }
  for (Int32 i = 1; i < span.get_Length(); i++) {
    Char c3 = span[i];
    if ((UInt32)(c3 - 97) > 25u && (UInt32)(c3 - 65) > 25u && (UInt32)(c3 - 48) > 9u && c3 != '+' && c3 != '-' && c3 != '.') {
      return ParsingError::BadScheme;
    }
  }
  if (span.get_Length() > 1024) {
    return ParsingError::SchemeLimit;
  }
  String lwrCaseScheme;
  {
    Char* value = span;
    SpanAction<Char, ValueTuple<IntPtr, Int32>> as = __c::in::__9__151_1;
    lwrCaseScheme = String::in::Create(span.get_Length(), {(IntPtr)(void*)value, span.get_Length()}, as != nullptr ? as : (__c::in::__9__151_1 = rt::newobj<SpanAction<Char, ValueTuple<IntPtr, Int32>>>(&_CheckSchemeSyntax_b__151_1)));
  }
  syntax = UriParser::in::FindOrFetchAsUnknownV1Syntax(lwrCaseScheme);
  return ParsingError::None;
}

Int32 Uri___::CheckAuthorityHelper(Char* pString, Int32 idx, Int32 length, ParsingError& err, Flags& flags, UriParser syntax, String& newHost) {
  Int32 i = length;
  Int32 num = idx;
  Int32 j = idx;
  newHost = nullptr;
  Boolean justNormalized = false;
  Boolean flag = IriParsingStatic(syntax);
  Boolean flag2 = (flags & Flags::HasUnicode) != 0;
  Boolean flag3 = flag2 && (flags & Flags::HostUnicodeNormalized) == 0;
  UriSyntaxFlags flags2 = syntax->get_Flags();
  Char c;
  if (idx == length || (c = *(pString + idx)) == '/' || (c == '\\' && StaticIsFile(syntax)) || c == '#' || c == '?') {
    if (syntax->InFact(UriSyntaxFlags::AllowEmptyHost)) {
      flags &= ~Flags::UncPath;
      if (StaticInFact(flags, Flags::ImplicitFile)) {
        err = ParsingError::BadHostName;
      } else {
        flags |= Flags::BasicHostType;
      }
    } else {
      err = ParsingError::BadHostName;
    }
    if (flag3) {
      flags |= Flags::HostUnicodeNormalized;
    }
    return idx;
  }
  if (flag3) {
    newHost = _originalUnicodeString->Substring(0, num);
  }
  String text = nullptr;
  if ((flags2 & UriSyntaxFlags::MayHaveUserInfo) != 0) {
    for (; j < i; j++) {
      if (j == i - 1 || *(pString + j) == '?' || *(pString + j) == '#' || *(pString + j) == '\\' || *(pString + j) == '/') {
        j = idx;
        break;
      }
      if (*(pString + j) != '@') {
        continue;
      }
      flags |= Flags::HasUserInfo;
      if (flag) {
        if (flag3) {
          text = IriHelper::EscapeUnescapeIri(pString, num, j + 1, UriComponents::UserInfo);
          newHost += text;
          if (newHost->get_Length() > 65535) {
            err = ParsingError::SizeLimit;
            return idx;
          }
        } else {
          text = rt::newstr<String>(pString, num, j - num + 1);
        }
      }
      j++;
      c = *(pString + j);
      break;
    }
  }
  Boolean notCanonical = (flags2 & UriSyntaxFlags::SimpleUserSyntax) == 0;
  if (c == '[' && syntax->InFact(UriSyntaxFlags::AllowIPv6Host) && IPv6AddressHelper::IsValid(pString, j + 1, i)) {
    flags |= Flags::IPv6HostType;
    if (flag3) {
      newHost += rt::newstr<String>(pString, j, i - j);
      flags |= Flags::HostUnicodeNormalized;
      justNormalized = true;
    }
  } else if (c <= '9' && c >= '0' && syntax->InFact(UriSyntaxFlags::AllowIPv4Host) && IPv4AddressHelper::IsValid(pString, j, i, false, StaticNotAny(flags, Flags::ImplicitFile), syntax->InFact(UriSyntaxFlags::V1_UnknownUri))) {
    flags |= Flags::IPv4HostType;
    if (flag3) {
      newHost += rt::newstr<String>(pString, j, i - j);
      flags |= Flags::HostUnicodeNormalized;
      justNormalized = true;
    }
  } else if ((flags2 & UriSyntaxFlags::AllowDnsHost) != 0 && !flag && DomainNameHelper::IsValid(pString, j, i, notCanonical, StaticNotAny(flags, Flags::ImplicitFile))) {
    flags |= Flags::DnsHostType;
    if (!notCanonical) {
      flags |= Flags::CanonicalDnsHost;
    }
  } else if ((flags2 & UriSyntaxFlags::AllowDnsHost) != 0 && (flag3 || syntax->InFact(UriSyntaxFlags::AllowIdn)) && DomainNameHelper::IsValidByIri(pString, j, i, notCanonical, StaticNotAny(flags, Flags::ImplicitFile))) {
    CheckAuthorityHelperHandleDnsIri(pString, j, i, flag2, flags, justNormalized, newHost, err);
  } else if ((flags2 & UriSyntaxFlags::AllowUncHost) != 0 && UncNameHelper::IsValid(pString, j, i, StaticNotAny(flags, Flags::ImplicitFile)) && i - j <= 256) {
    flags |= Flags::UncHostType;
    if (flag3) {
      newHost += rt::newstr<String>(pString, j, i - j);
      flags |= Flags::HostUnicodeNormalized;
      justNormalized = true;
    }
  }




  if (i < length && *(pString + i) == '\\' && (flags & Flags::HostTypeMask) != Flags::Zero && !StaticIsFile(syntax)) {
    if (syntax->InFact(UriSyntaxFlags::V1_UnknownUri)) {
      err = ParsingError::BadHostName;
      flags |= Flags::HostTypeMask;
      return i;
    }
    flags &= ~Flags::HostTypeMask;
  } else if (i < length && *(pString + i) == ':') {
    if (syntax->InFact(UriSyntaxFlags::MayHavePort)) {
      Int32 num2 = 0;
      Int32 num3 = i;
      for (idx = i + 1; idx < length; idx++) {
        Int32 num4 = *(pString + idx) - 48;
        switch (num4.get()) {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
          case 9:
            if ((num2 = num2 * 10 + num4) <= 65535) {
              continue;
            }
            break;
          default:
            if (syntax->InFact(UriSyntaxFlags::AllowAnyOtherHost) && syntax->NotAny(UriSyntaxFlags::V1_UnknownUri)) {
              flags &= ~Flags::HostTypeMask;
              break;
            }
            err = ParsingError::BadPort;
            return idx;
          case -13:
          case -1:
          case 15:
            break;
        }
        break;
      }
      if (num2 > 65535) {
        if (!syntax->InFact(UriSyntaxFlags::AllowAnyOtherHost)) {
          err = ParsingError::BadPort;
          return idx;
        }
        flags &= ~Flags::HostTypeMask;
      }
      if (flag2 && justNormalized) {
        newHost += rt::newstr<String>(pString, num3, idx - num3);
      }
    } else {
      flags &= ~Flags::HostTypeMask;
    }
  }

  if ((flags & Flags::HostTypeMask) == Flags::Zero) {
    flags &= ~Flags::HasUserInfo;
    if (syntax->InFact(UriSyntaxFlags::AllowAnyOtherHost)) {
      flags |= Flags::BasicHostType;
      for (i = idx; i < length && *(pString + i) != '/' && *(pString + i) != '?' && *(pString + i) != '#'; i++) {
      }
      if (flag3) {
        String text2 = rt::newstr<String>(pString, num, i - num);
        try {
          newHost += text2->Normalize(NormalizationForm::FormC);
        } catch (ArgumentException) {
          err = ParsingError::BadHostName;
        }
        flags |= Flags::HostUnicodeNormalized;
      }
    } else if (syntax->InFact(UriSyntaxFlags::V1_UnknownUri)) {
      Boolean flag4 = false;
      Int32 num5 = idx;
      for (i = idx; i < length && (!flag4 || (*(pString + i) != '/' && *(pString + i) != '?' && *(pString + i) != '#')); i++) {
        if (i < idx + 2 && *(pString + i) == '.') {
          flag4 = true;
          continue;
        }
        err = ParsingError::BadHostName;
        flags |= Flags::HostTypeMask;
        return idx;
      }
      flags |= Flags::BasicHostType;
      if (flag3) {
        String text3 = rt::newstr<String>(pString, num5, i - num5);
        try {
          newHost += text3->Normalize(NormalizationForm::FormC);
        } catch (ArgumentException) {
          err = ParsingError::BadFormat;
          return idx;
        }
        flags |= Flags::HostUnicodeNormalized;
      }
    } else if (syntax->InFact(UriSyntaxFlags::MustHaveAuthority) || syntax->InFact(UriSyntaxFlags::MailToLikeUri)) {
      err = ParsingError::BadHostName;
      flags |= Flags::HostTypeMask;
      return idx;
    }


  }
  return i;
}

void Uri___::CheckAuthorityHelperHandleDnsIri(Char* pString, Int32 start, Int32 end, Boolean hasUnicode, Flags& flags, Boolean& justNormalized, String& newHost, ParsingError& err) {
  flags |= Flags::DnsHostType;
  if (hasUnicode) {
    String text = UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char>(pString + start, end - start));
    try {
      newHost += text->Normalize(NormalizationForm::FormC);
    } catch (ArgumentException) {
      err = ParsingError::BadHostName;
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
    Char c = *(str + i);
    if (c <= '' || (c >= '' && c <= '')) {
      flag = true;
      flag2 = true;
      check |= Check::ReservedFound;
      continue;
    }
    if (c > '~') {
      if (iriParsing) {
        Boolean flag3 = false;
        check |= Check::FoundNonAscii;
        if (Char::IsHighSurrogate(c)) {
          if (i + 1 < end) {
            Boolean isSurrogatePair;
            flag3 = IriHelper::CheckIriUnicodeRange(c, *(str + i + 1), isSurrogatePair, true);
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
      continue;
    }
    if (c == delim || (delim == '?' && c == '#' && _syntax != nullptr && _syntax->InFact(UriSyntaxFlags::MayHaveFragment))) {
      break;
    }
    if (c == '?') {
      if (get_IsImplicitFile() || (_syntax != nullptr && !_syntax->InFact(UriSyntaxFlags::MayHaveQuery) && delim != 'þ')) {
        check |= Check::ReservedFound;
        flag2 = true;
        flag = true;
      }
      continue;
    }
    if (c == '#') {
      flag = true;
      if (get_IsImplicitFile() || (_syntax != nullptr && !_syntax->InFact(UriSyntaxFlags::MayHaveFragment))) {
        check |= Check::ReservedFound;
        flag2 = true;
      }
      continue;
    }
    if (c == '/' || c == '\\') {
      if ((check & Check::BackslashInPath) == 0 && c == '\\') {
        check |= Check::BackslashInPath;
      }
      if ((check & Check::DotSlashAttn) == 0 && i + 1 != end && (*(str + i + 1) == '/' || *(str + i + 1) == '\\')) {
        check |= Check::DotSlashAttn;
      }
      continue;
    }
    if (c == '.') {
      if (((check & Check::DotSlashAttn) == 0 && i + 1 == end) || *(str + i + 1) == '.' || *(str + i + 1) == '/' || *(str + i + 1) == '\\' || *(str + i + 1) == '?' || *(str + i + 1) == '#') {
        check |= Check::DotSlashAttn;
      }
      continue;
    }
    if ((c > '"' || c == '!') && (c < '[' || c > '^')) {
      switch (c.get()) {
        case '<':
        case '>':
        case '`':
          break;
        case '{':
        case '|':
        case '}':
          flag = true;
          continue;
        default:
          if (c != '%') {
            continue;
          }
          if (!flag2) {
            flag2 = true;
          }
          if (i + 2 < end && (c = UriHelper::DecodeHexChars(*(str + i + 1), *(str + i + 2))) != 'ÿ') {
            if (c == '.' || c == '/' || c == '\\') {
              check |= Check::DotSlashEscaped;
            }
            i += 2;
          } else if (!flag) {
            flag = true;
          }

          continue;
      }
    }
    if (!flag) {
      flag = true;
    }
    if ((_flags & Flags::HasUnicode) != Flags::Zero) {
      check |= Check::NotIriCanonical;
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
    dest[pos++] = '/';
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
          UnescapeOnly(pch, pos, end, '.', '/', _syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) ? '\\' : 'ÿ');
        }
      }
    } else if (InFact(Flags::E_PathNotCanonical) && NotAny(Flags::UserEscaped)) {
      String text = _string;
      if (securedPathIndex != 0 && text[securedPathIndex + _info->Offset.Path - 1] == '|') {
        text = text->Remove(securedPathIndex + _info->Offset.Path - 1, 1);
        text = text->Insert(securedPathIndex + _info->Offset.Path - 1, ":");
      }
      dest = UriHelper::EscapeString(MemoryExtensions::AsSpan(text, _info->Offset.Path, _info->Offset.Query - _info->Offset.Path), dest, end, !get_IsImplicitFile(), '?', '#');
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
        UnescapeOnly(pch2, pos, end, '.', '/', _syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) ? '\\' : 'ÿ');
      }
    }
  }
  if (securedPathIndex != 0 && dest[securedPathIndex + pos - 1] == '|') {
    dest[securedPathIndex + pos - 1] = ':';
  }
  if (InFact(Flags::ShouldBeCompressed)) {
    dest = Compress(dest, (UInt16)(pos + securedPathIndex), end, _syntax);
    if (dest[pos] == '\\') {
      dest[pos] = '/';
    }
    if (formatAs == UriFormat::UriEscaped && NotAny(Flags::UserEscaped) && InFact(Flags::E_PathNotCanonical)) {
      dest = UriHelper::EscapeString(rt::newstr<String>(dest, pos, end - pos), dest, pos, !get_IsImplicitFile(), '?', '#');
      end = pos;
    }
  } else if (_syntax->InFact(UriSyntaxFlags::ConvertPathSlashes) && InFact(Flags::BackslashInPath)) {
    for (Int32 i = pos; i < end; i++) {
      if (dest[i] == '\\') {
        dest[i] = '/';
      }
    }
  }

  if (formatAs != UriFormat::UriEscaped && InFact(Flags::PathNotCanonical)) {
    UnescapeMode unescapeMode;
    if (InFact(Flags::PathNotCanonical)) {
      switch (formatAs) {
        case (UriFormat)32767:
          unescapeMode = (UnescapeMode)((InFact(Flags::UserEscaped) ? 2 : 3) | 4);
          if (get_IsImplicitFile()) {
            unescapeMode &= ~UnescapeMode::Unescape;
          }
          break;
        case UriFormat::Unescaped:
          unescapeMode = ((!get_IsImplicitFile()) ? (UnescapeMode::Unescape | UnescapeMode::UnescapeAll) : UnescapeMode::CopyOnly);
          break;
        default:
          unescapeMode = (InFact(Flags::UserEscaped) ? UnescapeMode::Unescape : UnescapeMode::EscapeUnescape);
          if (get_IsImplicitFile()) {
            unescapeMode &= ~UnescapeMode::Unescape;
          }
          break;
      }
    } else {
      unescapeMode = UnescapeMode::CopyOnly;
    }
    Array<Char> array = rt::newarr<Array<Char>>(dest->get_Length());
    Buffer::BlockCopy(dest, 0, array, 0, end * 2);
    {
      Char* pStr = array;
      dest = UriHelper::UnescapeString(pStr, pos, end, dest, pos, '?', '#', 'ÿ', unescapeMode, _syntax, false);
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
    Char* intPtr = pch;
    pch = intPtr + 1;
    if (*intPtr != '%') {
      continue;
    }
    Char* intPtr2 = pch;
    pch = intPtr2 + 1;
    Char first = *intPtr2;
    Char* intPtr3 = pch;
    pch = intPtr3 + 1;
    Char c = UriHelper::DecodeHexChars(first, *intPtr3);
    if (c != ch1 && c != ch2 && c != ch3) {
      continue;
    }
    ptr2 = pch - 2;
    *(ptr2 - 1) = c;
    while (pch < ptr) {
      Char* intPtr4 = ptr2;
      ptr2 = intPtr4 + 1;
      Char* intPtr5 = pch;
      pch = intPtr5 + 1;
      Char c2;
      *intPtr4 = (c2 = *intPtr5);
      if (c2 == '%') {
        Char* intPtr6 = ptr2;
        ptr2 = intPtr6 + 1;
        Char* intPtr7 = pch;
        pch = intPtr7 + 1;
        *intPtr6 = (c2 = *intPtr7);
        Char first2 = c2;
        Char* intPtr8 = ptr2;
        ptr2 = intPtr8 + 1;
        Char* intPtr9 = pch;
        pch = intPtr9 + 1;
        *intPtr8 = (c2 = *intPtr9);
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
  Char* intPtr10 = ptr2;
  ptr2 = intPtr10 + 1;
  Char* intPtr11 = pch;
  pch = intPtr11 + 1;
  *intPtr10 = *intPtr11;
  if (pch == ptr) {
    end -= (Int32)(pch - ptr2);
    return;
  }
  Char* intPtr12 = ptr2;
  ptr2 = intPtr12 + 1;
  Char* intPtr13 = pch;
  pch = intPtr13 + 1;
  *intPtr12 = *intPtr13;
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
    if (c == '\\' && syntax->InFact(UriSyntaxFlags::ConvertPathSlashes)) {
      c = (dest[num5] = '/');
    }
    if (c == '/') {
      num = (UInt16)(num + 1);
    } else {
      if (num > 1) {
        num2 = (UInt16)(num5 + 1);
      }
      num = 0;
    }
    if (c == '.') {
      num3 = (UInt16)(num3 + 1);
      continue;
    }
    if (num3 != 0) {
      if ((!syntax->NotAny(UriSyntaxFlags::CanonicalizeAsFilePath) || (num3 <= 2 && c == '/' && num5 != start)) && c == '/' && (num2 == num5 + num3 + 1 || (num2 == 0 && num5 + num3 + 1 == destLength)) && num3 <= 2) {
        num2 = (UInt16)(num5 + 1 + num3 + ((num2 != 0) ? 1 : 0));
        Buffer::BlockCopy(dest, num2 * 2, dest, (num5 + 1) * 2, (destLength - num2) * 2);
        destLength -= num2 - num5 - 1;
        num2 = num5;
        if (num3 == 2) {
          num4 = (UInt16)(num4 + 1);
        }
        num3 = 0;
        continue;
      }
      num3 = 0;
    }
    if (c == '/') {
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
    if (num4 != 0 && dest[start] != '/') {
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
  if (basePart->get_IsDosPath() && (c == '/' || c == '\\') && (relativePart->get_Length() == 1 || (relativePart[1] != '/' && relativePart[1] != '\\'))) {
    Int32 num = basePart->get_OriginalString()->IndexOf(':');
    if (basePart->get_IsImplicitFile()) {
      return String::in::Concat(MemoryExtensions::AsSpan(basePart->get_OriginalString(), 0, num + 1), relativePart);
    }
    num = basePart->get_OriginalString()->IndexOf(':', num + 1);
    return String::in::Concat(MemoryExtensions::AsSpan(basePart->get_OriginalString(), 0, num + 1), relativePart);
  }
  if (StaticIsFile(basePart->get_Syntax()) && (c == '\\' || c == '/')) {
    if (relativePart->get_Length() >= 2 && (relativePart[1] == '\\' || relativePart[1] == '/')) {
      if (!basePart->get_IsImplicitFile()) {
        return "file:" + relativePart;
      }
      return relativePart;
    }
    if (basePart->get_IsUnc()) {
      String text = basePart->GetParts(UriComponents::Path | UriComponents::KeepDelimiter, UriFormat::Unescaped);
      for (Int32 i = 1; i < text->get_Length(); i++) {
        if (text[i] == '/') {
          text = text->Substring(0, i);
          break;
        }
      }
      if (basePart->get_IsImplicitFile()) {
        return "\\\\" + basePart->GetParts(UriComponents::Host, UriFormat::Unescaped) + text + relativePart;
      }
      return "file://" + basePart->GetParts(UriComponents::Host, uriFormat) + text + relativePart;
    }
    return "file://" + relativePart;
  }
  Boolean flag = basePart->get_Syntax()->InFact(UriSyntaxFlags::ConvertPathSlashes);
  String text2 = nullptr;
  if (c == '/' || (c == '\\' && flag)) {
    if (relativePart->get_Length() >= 2 && relativePart[1] == '/') {
      return basePart->get_Scheme() + ":" + relativePart;
    }
    text2 = ((basePart->get_HostType() != Flags::IPv6HostType) ? basePart->GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port, uriFormat) : (basePart->GetParts(UriComponents::Scheme | UriComponents::UserInfo, uriFormat) + "[" + basePart->get_DnsSafeHost() + "]" + basePart->GetParts(UriComponents::Port | UriComponents::KeepDelimiter, uriFormat)));
    if (!flag || c != '\\') {
      return text2 + relativePart;
    }
    return text2 + "/" + MemoryExtensions::AsSpan(relativePart, 1);
  }
  text2 = basePart->GetParts(UriComponents::Path | UriComponents::KeepDelimiter, basePart->get_IsImplicitFile() ? UriFormat::Unescaped : uriFormat);
  Int32 num2 = text2->get_Length();
  Array<Char> array = rt::newarr<Array<Char>>(num2 + relativePart->get_Length());
  if (num2 > 0) {
    text2->CopyTo(0, array, 0, num2);
    while (num2 > 0) {
      if (array[--num2] == '/') {
        num2++;
        break;
      }
    }
  }
  relativePart->CopyTo(0, array, num2, relativePart->get_Length());
  c = (basePart->get_Syntax()->InFact(UriSyntaxFlags::MayHaveQuery) ? '?' : 'ÿ');
  Char c2 = (!basePart->get_IsImplicitFile() && basePart->get_Syntax()->InFact(UriSyntaxFlags::MayHaveFragment)) ? '#' : 'ÿ';
  ReadOnlySpan<Char> readOnlySpan = String::in::Empty;
  if (c != 'ÿ' || c2 != 'ÿ') {
    Int32 j;
    for (j = 0; j < relativePart->get_Length() && array[num2 + j] != c && array[num2 + j] != c2; j++) {
    }
    if (j == 0) {
      readOnlySpan = relativePart;
    } else if (j < relativePart->get_Length()) {
      readOnlySpan = MemoryExtensions::AsSpan(relativePart, j);
    }

    num2 += j;
  } else {
    num2 += relativePart->get_Length();
  }
  if (basePart->get_HostType() == Flags::IPv6HostType) {
    text2 = ((!basePart->get_IsImplicitFile()) ? (basePart->GetParts(UriComponents::Scheme | UriComponents::UserInfo, uriFormat) + "[" + basePart->get_DnsSafeHost() + "]" + basePart->GetParts(UriComponents::Port | UriComponents::KeepDelimiter, uriFormat)) : ("\\\\[" + basePart->get_DnsSafeHost() + "]"));
  } else if (basePart->get_IsImplicitFile()) {
    if (basePart->get_IsDosPath()) {
      array = Compress(array, 3, num2, basePart->get_Syntax());
      return String::in::Concat(MemoryExtensions::AsSpan(array, 1, num2 - 1), readOnlySpan);
    }
    text2 = "\\\\" + basePart->GetParts(UriComponents::Host, UriFormat::Unescaped);
  } else {
    text2 = basePart->GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port, uriFormat);
  }

  array = Compress(array, basePart->get_SecuredPathIndex(), num2, basePart->get_Syntax());
  return String::in::Concat(text2, MemoryExtensions::AsSpan(array, 0, num2), readOnlySpan);
}

String Uri___::PathDifference(String path1, String path2, Boolean compareCase) {
  Int32 num = -1;
  Int32 i;
  for (i = 0; i < path1->get_Length() && i < path2->get_Length() && (path1[i] == path2[i] || (!compareCase && Char::ToLowerInvariant(path1[i]) == Char::ToLowerInvariant(path2[i]))); i++) {
    if (path1[i] == '/') {
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
    if (path1[i] == '/') {
      stringBuilder->Append((String)"../");
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
  dest = UriHelper::UnescapeString(path, 0, path->get_Length(), dest, destPosition, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, nullptr, false);
  return rt::newstr<String>(dest, 0, destPosition);
}

String Uri___::EscapeString(String str) {
  if (str != nullptr) {
    return UriHelper::EscapeString(str, true, UriHelper::get_UnreservedReservedTable(), '?', '#');
  }
  return String::in::Empty;
}

void Uri___::CheckSecurity() {
}

Boolean Uri___::IsReservedCharacter(Char character) {
  if (character != ';' && character != '/' && character != ':' && character != '@' && character != '&' && character != '=' && character != '+' && character != '$') {
    return character == ',';
  }
  return true;
}

Boolean Uri___::IsExcludedCharacter(Char character) {
  if (character > ' ' && character < '' && character != '<' && character != '>' && character != '#' && character != '%' && character != '"' && character != '{' && character != '}' && character != '|' && character != '\\' && character != '^' && character != '[' && character != ']') {
    return character == '`';
  }
  return true;
}

Boolean Uri___::IsBadFileSystemCharacter(Char character) {
  if (character >= ' ' && character != ';' && character != '/' && character != '?' && character != ':' && character != '&' && character != '=' && character != ',' && character != '*' && character != '<' && character != '>' && character != '"' && character != '|' && character != '\\') {
    return character == '^';
  }
  return true;
}

void Uri___::CreateThis(String uri, Boolean dontEscape, UriKind uriKind) {
  if (uriKind < UriKind::RelativeOrAbsolute || uriKind > UriKind::Relative) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_net_uri_InvalidUriKind(), uriKind));
  }
  String as = uri;
  _string = (as != nullptr ? as : String::in::Empty);
  if (dontEscape) {
    _flags |= Flags::UserEscaped;
  }
  ParsingError err = ParseScheme(_string, _flags, _syntax);
  UriFormatException e;
  InitializeUri(err, uriKind, e);
  if (e != nullptr) {
    rt::throw_exception(e);
  }
}

void Uri___::InitializeUri(ParsingError err, UriKind uriKind, UriFormatException& e) {
  if (err == ParsingError::None) {
    if (get_IsImplicitFile()) {
      if (NotAny(Flags::DosPath) && uriKind != UriKind::Absolute && (uriKind == UriKind::Relative || (_string->get_Length() >= 2 && (_string[0] != '\\' || _string[1] != '\\')))) {
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
        try {
          EnsureParseRemaining();
        } catch (UriFormatException ex) {
          UriFormatException ex2 = e = ex;
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
      _flags = (Flags::UserDrivenParsing | (_flags & Flags::UserEscaped));
    } else if (uriKind == UriKind::Relative) {
      e = GetException(ParsingError::CannotCreateRelative);
    }

    if (flag) {
      try {
        EnsureParseRemaining();
      } catch (UriFormatException ex3) {
        UriFormatException ex4 = e = ex3;
      }
    }
  } else if (err != 0 && uriKind != UriKind::Absolute && err <= ParsingError::EmptyUriString) {
    e = nullptr;
    _flags &= (Flags::UserEscaped | Flags::HasUnicode);
    if (flag) {
      _string = EscapeUnescapeIri(_originalUnicodeString, 0, _originalUnicodeString->get_Length(), (UriComponents)0);
      if (_string->get_Length() > 65535) {
        err = ParsingError::SizeLimit;
      }
    }
  } else {
    _string = nullptr;
    e = GetException(err);
  }

}

Boolean Uri___::CheckForUnicodeOrEscapedUnreserved(String data) {
  for (Int32 i = 0; i < data->get_Length(); i++) {
    Char c = data[i];
    if (c == '%') {
      if ((UInt32)(i + 2) < (UInt32)data->get_Length()) {
        Char c2 = UriHelper::DecodeHexChars(data[i + 1], data[i + 2]);
        if (c2 >= UriHelper::get_UnreservedTable().get_Length() || UriHelper::get_UnreservedTable()[c2]) {
          return true;
        }
        i += 2;
      }
    } else if (c > '') {
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
  Uri result2;
  if (TryCreate(relativeUri, UriKind::RelativeOrAbsolute, result2)) {
    if (!result2->get_IsAbsoluteUri()) {
      return TryCreate(baseUri, result2, result);
    }
    result = result2;
    return true;
  }
  result = nullptr;
  return false;
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
  if ((components & UriComponents::SerializationInfoString) != 0 && components != UriComponents::SerializationInfoString) {
    rt::throw_exception<ArgumentOutOfRangeException>("components", components, SR::get_net_uri_NotJustSerialization());
  }
  if ((format & (UriFormat)(-4)) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("format");
  }
  if (get_IsNotAbsoluteUri()) {
    if (components == UriComponents::SerializationInfoString) {
      return GetRelativeSerializationString(format);
    }
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (get_Syntax()->get_IsSimple()) {
    return GetComponentsHelper(components, format);
  }
  return get_Syntax()->InternalGetComponents((Uri)this, components, format);
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
  Uri result;
  if (!TryCreate(uriString, uriKind, result)) {
    return false;
  }
  return result->IsWellFormedOriginalString();
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
      return (CheckCanonical(ptr2, idx, _string->get_Length(), 'þ') & (Check::EscapedCanonical | Check::BackslashInPath)) == Check::EscapedCanonical;
    }
    if (get_IsImplicitFile()) {
      return false;
    }
    EnsureParseRemaining();
    Flags flags = _flags & (Flags::E_UserNotCanonical | Flags::E_HostNotCanonical | Flags::E_PortNotCanonical | Flags::E_PathNotCanonical | Flags::E_QueryNotCanonical | Flags::E_FragmentNotCanonical | Flags::UserIriCanonical | Flags::PathIriCanonical | Flags::QueryIriCanonical | Flags::FragmentIriCanonical);
    if ((flags & Flags::IriCanonical) != Flags::Zero) {
      if ((flags & (Flags::E_UserNotCanonical | Flags::UserIriCanonical)) == (Flags::E_UserNotCanonical | Flags::UserIriCanonical)) {
        flags = (Flags)((UInt64)flags & 18446743523953737599);
      }
      if ((flags & (Flags::E_PathNotCanonical | Flags::PathIriCanonical)) == (Flags::E_PathNotCanonical | Flags::PathIriCanonical)) {
        flags = (Flags)((UInt64)flags & 18446742974197922815);
      }
      if ((flags & (Flags::E_QueryNotCanonical | Flags::QueryIriCanonical)) == (Flags::E_QueryNotCanonical | Flags::QueryIriCanonical)) {
        flags = (Flags)((UInt64)flags & 18446741874686294015);
      }
      if ((flags & (Flags::E_FragmentNotCanonical | Flags::FragmentIriCanonical)) == (Flags::E_FragmentNotCanonical | Flags::FragmentIriCanonical)) {
        flags = (Flags)((UInt64)flags & 18446739675663036415);
      }
    }
    if ((flags & Flags::E_CannotDisplayCanonical & (Flags::E_UserNotCanonical | Flags::E_PathNotCanonical | Flags::E_QueryNotCanonical | Flags::E_FragmentNotCanonical)) != Flags::Zero) {
      return false;
    }
    if (InFact(Flags::AuthorityFound)) {
      idx = _info->Offset.Scheme + _syntax->get_SchemeName()->get_Length() + 2;
      if (idx >= _info->Offset.User || _string[idx - 1] == '\\' || _string[idx] == '\\') {
        return false;
      }
      if (InFact(Flags::DosPath | Flags::UncPath) && ++idx < _info->Offset.User && (_string[idx] == '/' || _string[idx] == '\\')) {
        return false;
      }
    }
    if (InFact(Flags::FirstSlashAbsent) && _info->Offset.Query > _info->Offset.Path) {
      return false;
    }
    if (InFact(Flags::BackslashInPath)) {
      return false;
    }
    if (get_IsDosPath() && _string[_info->Offset.Path + get_SecuredPathIndex() - 1] == '|') {
      return false;
    }
    if ((_flags & Flags::CanonicalDnsHost) == Flags::Zero && get_HostType() != Flags::IPv6HostType) {
      idx = _info->Offset.User;
      Check check = CheckCanonical(ptr2, idx, _info->Offset.Path, '/');
      if ((check & (Check::EscapedCanonical | Check::BackslashInPath | Check::ReservedFound)) != Check::EscapedCanonical && (!get_IriParsing() || (check & (Check::DisplayCanonical | Check::NotIriCanonical | Check::FoundNonAscii)) != (Check::DisplayCanonical | Check::FoundNonAscii))) {
        return false;
      }
    }
    if ((_flags & (Flags::SchemeNotCanonical | Flags::AuthorityFound)) == (Flags::SchemeNotCanonical | Flags::AuthorityFound)) {
      idx = _syntax->get_SchemeName()->get_Length();
      while (*(ptr2 + idx++) != ':') {
      }
      if (idx + 1 >= _string->get_Length() || *(ptr2 + idx) != '/' || *(ptr2 + idx + 1) != '/') {
        return false;
      }
    }
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
  Int32 num = stringToUnescape->IndexOf('%');
  if (num == -1) {
    return stringToUnescape;
  }
  Char as[256] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder dest = ValueStringBuilder(initialBuffer);
  dest.EnsureCapacity(stringToUnescape->get_Length());
  dest.Append(MemoryExtensions::AsSpan(stringToUnescape, 0, num));
  UriHelper::UnescapeString(stringToUnescape, num, stringToUnescape->get_Length(), dest, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::Unescape | UnescapeMode::UnescapeAll, nullptr, false);
  return dest.ToString();
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
      return rt::newobj<Uri>(flags & Flags::UserEscaped, nullptr, uriString);
    }
    return nullptr;
  }
  Uri uri = rt::newobj<Uri>(flags, syntax, uriString);
  try {
    uri->InitializeUri(parsingError, uriKind, e);
    if (e == nullptr) {
      return uri;
    }
    return nullptr;
  } catch (UriFormatException ex) {
    UriFormatException ex2 = e = ex;
    return nullptr;
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
    text = text->Trim(UriHelper::s_WSchars);
  }
  if (text->get_Length() == 0) {
    newUriString = baseUri->GetParts(UriComponents::AbsoluteUri, baseUri->get_UserEscaped() ? UriFormat::UriEscaped : UriFormat::SafeUnescaped);
    return nullptr;
  }
  if (text[0] == '#' && !baseUri->get_IsImplicitFile() && baseUri->get_Syntax()->InFact(UriSyntaxFlags::MayHaveFragment)) {
    newUriString = baseUri->GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path | UriComponents::Query, UriFormat::UriEscaped) + text;
    return nullptr;
  }
  if (text[0] == '?' && !baseUri->get_IsImplicitFile() && baseUri->get_Syntax()->InFact(UriSyntaxFlags::MayHaveQuery)) {
    newUriString = baseUri->GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path, UriFormat::UriEscaped) + text;
    return nullptr;
  }
  if (text->get_Length() >= 3 && (text[1] == ':' || text[1] == '|') && UriHelper::IsAsciiLetter(text[0]) && (text[2] == '\\' || text[2] == '/')) {
    if (baseUri->get_IsImplicitFile()) {
      newUriString = text;
      return nullptr;
    }
    if (baseUri->get_Syntax()->InFact(UriSyntaxFlags::AllowDOSPath)) {
      String str = (!baseUri->InFact(Flags::AuthorityFound)) ? (baseUri->get_Syntax()->InFact(UriSyntaxFlags::PathIsRooted) ? ":/" : ":") : (baseUri->get_Syntax()->InFact(UriSyntaxFlags::PathIsRooted) ? ":///" : "://");
      newUriString = baseUri->get_Scheme() + str + text;
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
        dest = UriHelper::UnescapeString(_string, 0, _string->get_Length(), dest, destPosition, 'ÿ', 'ÿ', 'ÿ', UnescapeMode::EscapeUnescape, nullptr, false);
        return rt::newstr<String>(dest, 0, destPosition);
      }default:
      rt::throw_exception<ArgumentOutOfRangeException>("format");
  }
}

String Uri___::GetComponentsHelper(UriComponents uriComponents, UriFormat uriFormat) {
  if (uriComponents == UriComponents::Scheme) {
    return _syntax->get_SchemeName();
  }
  if ((uriComponents & UriComponents::SerializationInfoString) != 0) {
    uriComponents |= UriComponents::AbsoluteUri;
  }
  EnsureParseRemaining();
  if ((uriComponents & UriComponents::NormalizedHost) != 0) {
    uriComponents |= UriComponents::Host;
  }
  if ((uriComponents & UriComponents::Host) != 0) {
    EnsureHostString(true);
  }
  if (uriComponents == UriComponents::Port || uriComponents == UriComponents::StrongPort) {
    if ((_flags & Flags::NotDefaultPort) != Flags::Zero || (uriComponents == UriComponents::StrongPort && _syntax->get_DefaultPort() != -1)) {
      return _info->Offset.PortValue.ToString(CultureInfo::in::get_InvariantCulture());
    }
    return String::in::Empty;
  }
  if ((uriComponents & UriComponents::StrongPort) != 0) {
    uriComponents |= UriComponents::Port;
  }
  if (uriComponents == UriComponents::Host && (uriFormat == UriFormat::UriEscaped || (_flags & (Flags::HostNotCanonical | Flags::E_HostNotCanonical)) == Flags::Zero)) {
    EnsureHostString(false);
    return _info->Host;
  }
  switch (uriFormat) {
    case UriFormat::UriEscaped:
      return GetEscapedParts(uriComponents);
    case UriFormat::Unescaped:
    case UriFormat::SafeUnescaped:
    case (UriFormat)32767:
      return GetUnescapedParts(uriComponents, uriFormat);
    default:
      rt::throw_exception<ArgumentOutOfRangeException>("uriFormat");
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
  String parts = GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path | UriComponents::Query, UriFormat::SafeUnescaped);
  String parts2 = uriLink->GetParts(UriComponents::Scheme | UriComponents::UserInfo | UriComponents::Host | UriComponents::Port | UriComponents::Path | UriComponents::Query, UriFormat::SafeUnescaped);
  {
    Char* ptr = parts;
    Char* selfPtr = ptr;
    {
      Char* ptr2 = parts2;
      Char* otherPtr = ptr2;
      return UriHelper::TestForSubPath(selfPtr, parts->get_Length(), otherPtr, parts2->get_Length(), get_IsUncOrDosPath() || uriLink->get_IsUncOrDosPath());
    }
  }
}

void Uri___::CreateThisFromUri(Uri otherUri) {
  _info = nullptr;
  _flags = otherUri->_flags;
  if (InFact(Flags::MinimalUriInfoSet)) {
    _flags &= ~(Flags::SchemeNotCanonical | Flags::UserNotCanonical | Flags::HostNotCanonical | Flags::PortNotCanonical | Flags::PathNotCanonical | Flags::QueryNotCanonical | Flags::FragmentNotCanonical | Flags::E_UserNotCanonical | Flags::E_HostNotCanonical | Flags::E_PortNotCanonical | Flags::E_PathNotCanonical | Flags::E_QueryNotCanonical | Flags::E_FragmentNotCanonical | Flags::ShouldBeCompressed | Flags::FirstSlashAbsent | Flags::BackslashInPath | Flags::MinimalUriInfoSet | Flags::AllUriInfoSet);
    Int32 num = otherUri->_info->Offset.Path;
    if (InFact(Flags::NotDefaultPort)) {
      while (otherUri->_string[num] != ':' && num > otherUri->_info->Offset.Host) {
        num--;
      }
      if (otherUri->_string[num] != ':') {
        num = otherUri->_info->Offset.Path;
      }
    }
    _flags |= (Flags)num;
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

Char Uri___::_CheckSchemeSyntax_g__ToLowerCaseAscii151_0(Char c) {
  if ((UInt32)(c - 65) > 25u) {
    return c;
  }
  return (Char)(c | 32);
}

} // namespace System::Private::Uri::System::UriNamespace
