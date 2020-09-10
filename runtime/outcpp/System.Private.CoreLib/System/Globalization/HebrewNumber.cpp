#include "HebrewNumber-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber-dep.h>

namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace {
HebrewNumber::HebrewValue::HebrewValue(HebrewToken token, Int16 value) {
  this->token = token;
  this->value = value;
}

void HebrewNumber::Append(StringBuilder outputBuffer, Int32 Number) {
  Int32 length = outputBuffer->get_Length();
  Char c = '\0';
  if (Number > 5000) {
    Number -= 5000;
  }
  Int32 num = Number / 100;
  if (num > 0) {
    Number -= num * 100;
    for (Int32 i = 0; i < num / 4; i++) {
      outputBuffer->Append('ê');
    }
    Int32 num2 = num % 4;
    if (num2 > 0) {
      outputBuffer->Append((Char)(1510 + num2));
    }
  }
  Int32 num3 = Number / 10;
  Number %= 10;
  switch (num3.get()) {
    case 0:
      c = '\0';
      break;
    case 1:
      c = 'Ù';
      break;
    case 2:
      c = 'Û';
      break;
    case 3:
      c = 'Ü';
      break;
    case 4:
      c = 'Þ';
      break;
    case 5:
      c = 'à';
      break;
    case 6:
      c = 'á';
      break;
    case 7:
      c = 'â';
      break;
    case 8:
      c = 'ä';
      break;
    case 9:
      c = 'æ';
      break;
  }
  Char c2 = (Char)((Number > 0) ? (1488 + Number - 1) : 0);
  if (c2 == 'Ô' && c == 'Ù') {
    c2 = 'Õ';
    c = 'Ø';
  }
  if (c2 == 'Õ' && c == 'Ù') {
    c2 = 'Ö';
    c = 'Ø';
  }
  if (c != 0) {
    outputBuffer->Append(c);
  }
  if (c2 != 0) {
    outputBuffer->Append(c2);
  }
  if (outputBuffer->get_Length() - length > 1) {
    outputBuffer->Insert(outputBuffer->get_Length() - 1, '"');
  } else {
    outputBuffer->Append('\'');
  }
}

HebrewNumberParsingState HebrewNumber::ParseByChar(Char ch, HebrewNumberParsingContext& context) {
  HebrewToken hebrewToken;
  switch (ch.get()) {
    case '\'':
      hebrewToken = HebrewToken::SingleQuote;
      break;
    case '"':
      hebrewToken = HebrewToken::DoubleQuote;
      break;
    default:
      {
        Int32 num = ch - 1488;
        if (num >= 0 && num < s_hebrewValues->get_Length()) {
          hebrewToken = s_hebrewValues[num].token;
          if (hebrewToken == HebrewToken::Invalid) {
            return HebrewNumberParsingState::NotHebrewDigit;
          }
          context.result += s_hebrewValues[num].value;
          break;
        }
        return HebrewNumberParsingState::NotHebrewDigit;
      }}
  context.state = s_numberPasingState[(Int32)context.state * 10 + (Int32)hebrewToken];
  if (context.state == HS::_err) {
    return HebrewNumberParsingState::InvalidHebrewNumber;
  }
  if (context.state == HS::END) {
    return HebrewNumberParsingState::FoundEndOfHebrewNumber;
  }
  return HebrewNumberParsingState::ContinueParsing;
}

Boolean HebrewNumber::IsDigit(Char ch) {
  if (ch >= 'Ð' && ch <= s_maxHebrewNumberCh) {
    return s_hebrewValues[ch - 1488].value >= 0;
  }
  if (ch != '\'') {
    return ch == '"';
  }
  return true;
}

void HebrewNumber::cctor() {
  s_hebrewValues = rt::newarr<Array<HebrewValue>>(27);
  s_maxHebrewNumberCh = (Char)(1488 + s_hebrewValues->get_Length() - 1);
  s_numberPasingState = rt::newarr<Array<HS>>(170);
}

} // namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace
