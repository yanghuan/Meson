#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(IdnMapping)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::Uri::System {
namespace DomainNameHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;
class DomainNameHelper {
  public: static String ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& loopback);
  public: static Boolean IsValid(Char* name, Int32 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile);
  public: static Boolean IsValidByIri(Char* name, Int32 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile);
  public: static String IdnEquivalent(String hostname);
  private: static Boolean IsIdnAce(String input, Int32 index);
  public: static String UnicodeEquivalent(Char* hostname, Int32 start, Int32 end, Boolean& allAscii, Boolean& atLeastOneValidIdn);
  private: static Boolean IsASCIILetterOrDigit(Char character, Boolean& notCanonical);
  private: static Boolean IsValidDomainLabelCharacter(Char character, Boolean& notCanonical);
  public: static Boolean ContainsCharactersUnsafeForNormalizedHost(String host);
  public: static void cctor();
  private: static IdnMapping s_idnMapping;
  private: static Array<Char> s_UnsafeForNormalizedHost;
};
} // namespace DomainNameHelperNamespace
using DomainNameHelper = DomainNameHelperNamespace::DomainNameHelper;
} // namespace System::Private::Uri::System
