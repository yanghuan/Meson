#include "__DTString-dep.h"

#include <System.Private.CoreLib/System/DateTimeParse-dep.h>
#include <System.Private.CoreLib/System/DTSubStringType.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatFlags.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::System::__DTStringNamespace {
using namespace System::Globalization;

Int32 __DTString::get_Length() {
  return Value.get_Length();
}

CompareInfo __DTString::get_CompareInfo() {
  return m_info;
}

__DTString::__DTString(ReadOnlySpan<Char> str, DateTimeFormatInfo dtfi, Boolean checkDigitToken) {
  m_checkDigitToken = checkDigitToken;
}

__DTString::__DTString(ReadOnlySpan<Char> str, DateTimeFormatInfo dtfi) {
  Index = -1;
  Value = str;
  m_current = 0;
  m_info = dtfi->get_CompareInfo();
  m_checkDigitToken = ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseDigitPrefixInTokens) != 0);
}

Boolean __DTString::GetNext() {
  Index++;
  if (Index < get_Length()) {
    m_current = Value[Index];
    return true;
  }
  return false;
}

Boolean __DTString::AtEnd() {
  if (Index >= get_Length()) {
    return true;
  }
  return false;
}

Boolean __DTString::Advance(Int32 count) {
  Index += count;
  if (Index < get_Length()) {
    m_current = Value[Index];
    return true;
  }
  return false;
}

void __DTString::GetRegularToken(TokenType& tokenType, Int32& tokenValue, DateTimeFormatInfo dtfi) {
  tokenValue = 0;
  if (Index >= get_Length()) {
    tokenType = TokenType::EndOfString;
    return;
  }
  while (true) {
    if (DateTimeParse::IsDigit(m_current)) {
      tokenValue = m_current - 48;
      Int32 index = Index;
      while (++Index < get_Length()) {
        m_current = Value[Index];
        Int32 num = m_current - 48;
        if (num < 0 || num > 9) {
          break;
        }
        tokenValue = tokenValue * 10 + num;
      }
      if (Index - index > 8) {
        tokenType = TokenType::NumberToken;
        tokenValue = -1;
      } else if (Index - index < 3) {
        tokenType = TokenType::NumberToken;
      } else {
        tokenType = TokenType::YearNumberToken;
      }

      if (m_checkDigitToken) {
        Int32 index2 = Index;
        Char current = m_current;
        Index = index;
        m_current = Value[Index];
      }
      break;
    }
    if (Char::IsWhiteSpace(m_current)) {
    }
    dtfi->Tokenize(TokenType::RegularTokenMask, tokenType, tokenValue, *this);
    break;
  }
}

TokenType __DTString::GetSeparatorToken(DateTimeFormatInfo dtfi, Int32& indexBeforeSeparator, Char& charBeforeSeparator) {
  indexBeforeSeparator = Index;
  charBeforeSeparator = m_current;
  if (!SkipWhiteSpaceCurrent()) {
    return TokenType::SEP_End;
  }
  TokenType tokenType;
  if (!DateTimeParse::IsDigit(m_current)) {
  }
  tokenType = TokenType::SEP_Space;
  return tokenType;
}

Boolean __DTString::MatchSpecifiedWord(String target) {
  if (Index + target->get_Length() <= get_Length()) {
    return m_info->Compare(Value.Slice(Index, target->get_Length()), target, CompareOptions::IgnoreCase) == 0;
  }
  return false;
}

Boolean __DTString::MatchSpecifiedWords(String target, Boolean checkWordBoundary, Int32& matchLength) {
  Int32 num = Value.get_Length() - Index;
  matchLength = target->get_Length();
  if (matchLength > num || m_info->Compare(Value.Slice(Index, matchLength), target, CompareOptions::IgnoreCase) != 0) {
    Int32 num2 = 0;
    Int32 num3 = Index;
    Int32 num4 = target->IndexOfAny(WhiteSpaceChecks, num2);
    if (num4 == -1) {
      return false;
    }
  }
  if (checkWordBoundary) {
    Int32 num7 = Index + matchLength;
    if (num7 < Value.get_Length() && Char::IsLetter(Value[num7])) {
      return false;
    }
  }
  return true;
}

Boolean __DTString::Match(String str) {
  if (++Index >= get_Length()) {
    return false;
  }
  if (str->get_Length() > Value.get_Length() - Index) {
    return false;
  }
  if (m_info->Compare(Value.Slice(Index, str->get_Length()), str, CompareOptions::Ordinal) == 0) {
    Index += str->get_Length() - 1;
    return true;
  }
  return false;
}

Boolean __DTString::Match(Char ch) {
  if (++Index >= get_Length()) {
    return false;
  }
  if (Value[Index] == ch) {
    m_current = ch;
    return true;
  }
  Index--;
  return false;
}

Int32 __DTString::MatchLongestWords(Array<String> words, Int32& maxMatchStrLen) {
  Int32 result = -1;
  for (Int32 i = 0; i < words->get_Length(); i++) {
    String text = words[i];
    Int32 matchLength = text->get_Length();
    if (MatchSpecifiedWords(text, false, matchLength) && matchLength > maxMatchStrLen) {
      maxMatchStrLen = matchLength;
      result = i;
    }
  }
  return result;
}

Int32 __DTString::GetRepeatCount() {
  Char c = Value[Index];
  Int32 i;
  for (i = Index + 1; i < get_Length() && Value[i] == c; i++) {
  }
  Int32 result = i - Index;
  Index = i - 1;
  return result;
}

Boolean __DTString::GetNextDigit() {
  if (++Index < get_Length()) {
    return DateTimeParse::IsDigit(Value[Index]);
  }
  return false;
}

Char __DTString::GetChar() {
  return Value[Index];
}

Int32 __DTString::GetDigit() {
  return Value[Index] - 48;
}

void __DTString::SkipWhiteSpaces() {
  while (Index + 1 < get_Length()) {
    Char c = Value[Index + 1];
    if (!Char::IsWhiteSpace(c)) {
      break;
    }
    Index++;
  }
}

Boolean __DTString::SkipWhiteSpaceCurrent() {
  if (Index >= get_Length()) {
    return false;
  }
  if (!Char::IsWhiteSpace(m_current)) {
    return true;
  }
  while (++Index < get_Length()) {
    m_current = Value[Index];
    if (!Char::IsWhiteSpace(m_current)) {
      return true;
    }
  }
  return false;
}

void __DTString::TrimTail() {
  Int32 num = get_Length() - 1;
  while (num >= 0 && Char::IsWhiteSpace(Value[num])) {
    num--;
  }
  Value = Value.Slice(0, num + 1);
}

void __DTString::RemoveTrailingInQuoteSpaces() {
  Int32 num = get_Length() - 1;
  if (num <= 1) {
    return;
  }
  Char c = Value[num];
  if ((c == 39 || c == 34) && Char::IsWhiteSpace(Value[num - 1])) {
    num--;
    while (num >= 1 && Char::IsWhiteSpace(Value[num - 1])) {
      num--;
    }
    Span<Char> span = rt::newarr<Array<Char>>(num + 1);
    span[num] = c;
    Value.Slice(0, num).CopyTo(span);
    Value = span;
  }
}

void __DTString::RemoveLeadingInQuoteSpaces() {
  if (get_Length() <= 2) {
    return;
  }
  Int32 i = 0;
  Char c = Value[i];
  if (c == 39 || c == 34) {
    for (; i + 1 < get_Length() && Char::IsWhiteSpace(Value[i + 1]); i++) {
    }
    if (i != 0) {
      Span<Char> span = rt::newarr<Array<Char>>(Value.get_Length() - i);
      span[0] = c;
      Value.Slice(i + 1).CopyTo(span.Slice(1));
      Value = span;
    }
  }
}

DTSubString __DTString::GetSubString() {
  DTSubString result = DTSubString();
  result.index = Index;
  result.s = Value;
  while (Index + result.length < get_Length()) {
    Char c = Value[Index + result.length];
    DTSubStringType dTSubStringType = (c < 48 || c > 57) ? DTSubStringType::Other : DTSubStringType::Number;
    if (result.length == 0) {
      result.type = dTSubStringType;
    } else if (result.type != dTSubStringType) {
      break;
    }

    result.length++;
    if (dTSubStringType != DTSubStringType::Number) {
      break;
    }
    if (result.length > 8) {
      result.type = DTSubStringType::Invalid;
      return result;
    }
    Int32 num = c - 48;
    result.value = result.value * 10 + num;
  }
  if (result.length == 0) {
    result.type = DTSubStringType::End;
    return result;
  }
  return result;
}

void __DTString::ConsumeSubString(DTSubString sub) {
  Index = sub.index + sub.length;
  if (Index < get_Length()) {
    m_current = Value[Index];
  }
}

void __DTString::cctor() {
  WhiteSpaceChecks = rt::newarr<Array<Char>>(2);
}

} // namespace System::Private::CoreLib::System::__DTStringNamespace
