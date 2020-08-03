#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
FORWARD(DateTimeFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TokenType;
FORWARD_(Array, T1, T2)
FORWARDS(DTSubString)
FORWARD(String)
namespace __DTStringNamespace {
using namespace Globalization;
struct __DTString : public valueType<__DTString> {
  public: Int32 get_Length();
  public: CompareInfo get_CompareInfo();
  public: explicit __DTString(ReadOnlySpan<Char> str, DateTimeFormatInfo dtfi, Boolean checkDigitToken);
  public: explicit __DTString(ReadOnlySpan<Char> str, DateTimeFormatInfo dtfi);
  public: Boolean GetNext();
  public: Boolean AtEnd();
  public: Boolean Advance(Int32 count);
  public: void GetRegularToken(TokenType& tokenType, Int32& tokenValue, DateTimeFormatInfo dtfi);
  public: TokenType GetSeparatorToken(DateTimeFormatInfo dtfi, Int32& indexBeforeSeparator, Char& charBeforeSeparator);
  public: Boolean MatchSpecifiedWord(String target);
  public: Boolean MatchSpecifiedWords(String target, Boolean checkWordBoundary, Int32& matchLength);
  public: Boolean Match(String str);
  public: Boolean Match(Char ch);
  public: Int32 MatchLongestWords(Array<String> words, Int32& maxMatchStrLen);
  public: Int32 GetRepeatCount();
  public: Boolean GetNextDigit();
  public: Char GetChar();
  public: Int32 GetDigit();
  public: void SkipWhiteSpaces();
  public: Boolean SkipWhiteSpaceCurrent();
  public: void TrimTail();
  public: void RemoveTrailingInQuoteSpaces();
  public: void RemoveLeadingInQuoteSpaces();
  public: DTSubString GetSubString();
  public: void ConsumeSubString(DTSubString sub);
  private: static void SCtor();
  public: explicit __DTString() {}
  public: ReadOnlySpan<Char> Value;
  public: Int32 Index;
  public: Char m_current;
  private: CompareInfo m_info;
  private: Boolean m_checkDigitToken;
  private: static Array<Char> WhiteSpaceChecks;
};
} // namespace __DTStringNamespace
using __DTString = __DTStringNamespace::__DTString;
} // namespace System::Private::CoreLib::System
