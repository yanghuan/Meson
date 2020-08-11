#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
enum class UriComponents : int32_t;
namespace IriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
class IriHelper {
  public: static Boolean CheckIriUnicodeRange(Char unicode, Boolean isQuery);
  public: static Boolean CheckIriUnicodeRange(Char highSurr, Char lowSurr, Boolean& isSurrogatePair, Boolean isQuery);
  public: static Boolean CheckIsReserved(Char ch, UriComponents component);
  public: static String EscapeUnescapeIri(Char* pInput, Int32 start, Int32 end, UriComponents component);
};
} // namespace IriHelperNamespace
using IriHelper = IriHelperNamespace::IriHelper;
} // namespace System::Private::Uri::System
