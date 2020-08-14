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
  Char c = 0;
  if (Number > 5000) {
    Number -= 5000;
  }
  Int32 num = Number / 100;
  if (num > 0) {
    Number -= num * 100;
    for (Int32 i = 0; i < num / 4; i++) {
      outputBuffer->Append(1514);
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
      c = 0;
      break;
    case 1:
      c = 1497;
      break;
    case 2:
      c = 1499;
      break;
    case 3:
      c = 1500;
      break;
    case 4:
      c = 1502;
      break;
    case 5:
      c = 1504;
      break;
    case 6:
      c = 1505;
      break;
    case 7:
      c = 1506;
      break;
    case 8:
      c = 1508;
      break;
    case 9:
      c = 1510;
      break;
  }
  Char c2 = (Char)((Number > 0) ? (1488 + Number - 1) : 0);
  if (c2 == 1492 && c == 1497) {
    c2 = 1493;
    c = 1496;
  }
  if (c2 == 1493 && c == 1497) {
    c2 = 1494;
    c = 1496;
  }
  if (c != 0) {
    outputBuffer->Append(c);
  }
  if (c2 != 0) {
    outputBuffer->Append(c2);
  }
  if (outputBuffer->get_Length() - length > 1) {
    outputBuffer->Insert(outputBuffer->get_Length() - 1, 34);
  } else {
    outputBuffer->Append(39);
  }
}

HebrewNumberParsingState HebrewNumber::ParseByChar(Char ch, HebrewNumberParsingContext& context) {
  HebrewToken hebrewToken;
  switch (ch.get()) {
    case 39:
      hebrewToken = HebrewToken::SingleQuote;
      break;
    case 34:
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
  if (ch >= 1488 && ch <= s_maxHebrewNumberCh) {
    return s_hebrewValues[ch - 1488].value >= 0;
  }
  if (ch != 39) {
    return ch == 34;
  }
  return true;
}

void HebrewNumber::cctor() {
  s_hebrewValues = rt::newarr<Array<HebrewValue>>(27);
  s_maxHebrewNumberCh = (Char)(1488 + s_hebrewValues->get_Length() - 1);
  s_numberPasingState = rt::newarr<Array<HS>>(170);
}

} // namespace System::Private::CoreLib::System::Globalization::HebrewNumberNamespace
