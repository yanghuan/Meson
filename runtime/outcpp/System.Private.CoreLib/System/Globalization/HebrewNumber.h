#pragma once

#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class HebrewNumberParsingState : int32_t;
FORWARDS(HebrewNumberParsingContext)
namespace HebrewNumberNamespace {
using namespace System::Text;
class HebrewNumber {
  private: enum class HebrewToken : int16_t {
    Invalid = -1,
    Digit400 = 0,
    Digit200_300 = 1,
    Digit100 = 2,
    Digit10 = 3,
    Digit1 = 4,
    Digit6_7 = 5,
    Digit7 = 6,
    Digit9 = 7,
    SingleQuote = 8,
    DoubleQuote = 9,
  };
  public: enum class HS : int8_t {
    _err = -1,
    Start = 0,
    S400 = 1,
    S400_400 = 2,
    S400_X00 = 3,
    S400_X0 = 4,
    X00_DQ = 5,
    S400_X00_X0 = 6,
    X0_DQ = 7,
    X = 8,
    X0 = 9,
    X00 = 10,
    S400_DQ = 11,
    S400_400_DQ = 12,
    S400_400_100 = 13,
    S9 = 14,
    X00_S9 = 15,
    S9_DQ = 16,
    END = 100,
  };
  private: struct HebrewValue : public valueType<HebrewValue> {
    public: explicit HebrewValue(HebrewToken token, Int16 value);
    public: explicit HebrewValue() {}
    public: HebrewToken token;
    public: Int16 value;
  };
  public: static void Append(StringBuilder outputBuffer, Int32 Number);
  public: static HebrewNumberParsingState ParseByChar(Char ch, HebrewNumberParsingContext& context);
  public: static Boolean IsDigit(Char ch);
  public: static void cctor();
  private: static Array<HebrewValue> s_hebrewValues;
  private: static Char s_maxHebrewNumberCh;
  private: static Array<HS> s_numberPasingState;
};
} // namespace HebrewNumberNamespace
using HebrewNumber = HebrewNumberNamespace::HebrewNumber;
} // namespace System::Private::CoreLib::System::Globalization
