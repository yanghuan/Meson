#include "ValueStringBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/ICustomFormatter.h>
#include <System.Private.CoreLib/System/IFormattable.h>
#include <System.Private.CoreLib/System/ISpanFormattable.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::ValueStringBuilderNamespace {
using namespace System::Buffers;
using namespace System::Runtime::InteropServices;

Int32 ValueStringBuilder::get_Length() {
  return _pos;
}

void ValueStringBuilder::set_Length(Int32 value) {
  _pos = value;
}

Int32 ValueStringBuilder::get_Capacity() {
  return _chars.get_Length();
}

Char& ValueStringBuilder::get_Item(Int32 index) {
  return _chars[index];
}

Span<Char> ValueStringBuilder::get_RawChars() {
  return _chars;
}

void ValueStringBuilder::AppendFormatHelper(IFormatProvider provider, String format, ParamsArray args) {
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  Int32 num = 0;
  Int32 length = format->get_Length();
  Char c = u'\0';
  ICustomFormatter customFormatter = (ICustomFormatter)((provider != nullptr) ? provider->GetFormat(typeof<ICustomFormatter>()) : nullptr);
  while (true) {
    if (num < length) {
      c = format[num];
      num++;
      if (c == u'}') {
        if (num < length && format[num] == u'}') {
          num++;
        } else {
          ThrowFormatError();
        }
      } else if (c == u'{') {
        if (num >= length || format[num] != u'{') {
          num--;
          goto IL_008f;
        }
        num++;
      }

      Append(c);
      continue;
    }
    goto IL_008f;

  IL_008f:
    if (num == length) {
      break;
    }
    num++;
    if (num == length || (c = format[num]) < u'0' || c > u'9') {
      ThrowFormatError();
    }
    Int32 num2 = 0;
    do {
      num2 = num2 * 10 + c - 48;
      num++;
      if (num == length) {
        ThrowFormatError();
      }
      c = format[num];
    } while (c >= u'0' && c <= u'9' && num2 < 1000000);
    if (num2 >= args.get_Length()) {
      rt::throw_exception<FormatException>(SR::get_Format_IndexOutOfRange());
    }
    for (; num < length; num++) {
      if ((c = format[num]) != u' ') {
        break;
      }
    }
    Boolean flag = false;
    Int32 num3 = 0;
    if (c == u',') {
      for (num++; num < length && format[num] == u' '; num++) {
      }
      if (num == length) {
        ThrowFormatError();
      }
      c = format[num];
      if (c == u'-') {
        flag = true;
        num++;
        if (num == length) {
          ThrowFormatError();
        }
        c = format[num];
      }
      if (c < u'0' || c > u'9') {
        ThrowFormatError();
      }
      do {
        num3 = num3 * 10 + c - 48;
        num++;
        if (num == length) {
          ThrowFormatError();
        }
        c = format[num];
      } while (c >= u'0' && c <= u'9' && num3 < 1000000);
    }
    for (; num < length; num++) {
      if ((c = format[num]) != u' ') {
        break;
      }
    }
    Object obj = args[num2];
    ReadOnlySpan<Char> readOnlySpan;
    switch (c.get()) {
      case u':':
        {
          num++;
          Int32 num4 = num;
          while (true) {
            if (num == length) {
              ThrowFormatError();
            }
            c = format[num];
            switch (c.get()) {
              case u'{':
                ThrowFormatError();
                goto IL_0205;
              default:
                goto IL_0205;
              case u'}':
                break;
            }
            break;

          IL_0205:
            num++;
          }
          if (num > num4) {
            readOnlySpan = MemoryExtensions::AsSpan(format, num4, num - num4);
          }
          break;
        }default:
        ThrowFormatError();
        break;
      case u'}':
        break;
    }
    num++;
    String text = nullptr;
    String text2 = nullptr;
    if (customFormatter != nullptr) {
      if (readOnlySpan.get_Length() != 0) {
        text2 = rt::newstr<String>(readOnlySpan);
      }
      text = customFormatter->Format(text2, obj, provider);
    }
    if (text == nullptr) {
      ISpanFormattable spanFormattable = rt::as<ISpanFormattable>(obj);
      Int32 charsWritten;
      if (spanFormattable != nullptr && (flag || num3 == 0) && spanFormattable->TryFormat(_chars.Slice(_pos), charsWritten, readOnlySpan, provider)) {
        _pos += charsWritten;
        Int32 num5 = num3 - charsWritten;
        if (flag && num5 > 0) {
          Append(u' ', num5);
        }
        continue;
      }
      IFormattable formattable = rt::as<IFormattable>(obj);
      if (formattable != nullptr) {
        if (readOnlySpan.get_Length() != 0 && text2 == nullptr) {
          text2 = rt::newstr<String>(readOnlySpan);
        }
        text = formattable->ToString(text2, provider);
      } else if (obj != nullptr) {
        text = obj->ToString();
      }

    }
    if (text == nullptr) {
      text = String::in::Empty;
    }
    Int32 num6 = num3 - text->get_Length();
    if (!flag && num6 > 0) {
      Append(u' ', num6);
    }
    Append(text);
    if (flag && num6 > 0) {
      Append(u' ', num6);
    }
  }
}

void ValueStringBuilder::ThrowFormatError() {
  rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
}

ValueStringBuilder::ValueStringBuilder(Span<Char> initialBuffer) {
  _arrayToReturnToPool = nullptr;
  _chars = initialBuffer;
  _pos = 0;
}

ValueStringBuilder::ValueStringBuilder(Int32 initialCapacity) {
  _arrayToReturnToPool = ArrayPool<Char>::in::get_Shared()->Rent(initialCapacity);
  _chars = _arrayToReturnToPool;
  _pos = 0;
}

void ValueStringBuilder::EnsureCapacity(Int32 capacity) {
  if (capacity > _chars.get_Length()) {
    Grow(capacity - _pos);
  }
}

Char& ValueStringBuilder::GetPinnableReference() {
  return MemoryMarshal::GetReference(_chars);
}

Char& ValueStringBuilder::GetPinnableReference(Boolean terminate) {
  if (terminate) {
    EnsureCapacity(get_Length() + 1);
    _chars[get_Length()] = u'\0';
  }
  return MemoryMarshal::GetReference(_chars);
}

String ValueStringBuilder::ToString() {
  String result = _chars.Slice(0, _pos).ToString();
  Dispose();
  return result;
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Boolean terminate) {
  if (terminate) {
    EnsureCapacity(get_Length() + 1);
    _chars[get_Length()] = u'\0';
  }
  return _chars.Slice(0, _pos);
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan() {
  return _chars.Slice(0, _pos);
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start) {
  return _chars.Slice(start, _pos - start);
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start, Int32 length) {
  return _chars.Slice(start, length);
}

Boolean ValueStringBuilder::TryCopyTo(Span<Char> destination, Int32& charsWritten) {
  if (_chars.Slice(0, _pos).TryCopyTo(destination)) {
    charsWritten = _pos;
    Dispose();
    return true;
  }
  charsWritten = 0;
  Dispose();
  return false;
}

void ValueStringBuilder::Insert(Int32 index, String s) {
  if (s != nullptr) {
    Int32 length = s->get_Length();
    if (_pos > _chars.get_Length() - length) {
      Grow(length);
    }
    Int32 length2 = _pos - index;
    _chars.Slice(index, length2).CopyTo(_chars.Slice(index + length));
    MemoryExtensions::AsSpan(s).CopyTo(_chars.Slice(index));
    _pos += length;
  }
}

void ValueStringBuilder::Append(Char c) {
  Int32 pos = _pos;
  if ((UInt32)pos < (UInt32)_chars.get_Length()) {
    _chars[pos] = c;
    _pos = pos + 1;
  } else {
    GrowAndAppend(c);
  }
}

void ValueStringBuilder::Append(String s) {
  if (s != nullptr) {
    Int32 pos = _pos;
    if (s->get_Length() == 1 && (UInt32)pos < (UInt32)_chars.get_Length()) {
      _chars[pos] = s[0];
      _pos = pos + 1;
    } else {
      AppendSlow(s);
    }
  }
}

void ValueStringBuilder::AppendSlow(String s) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - s->get_Length()) {
    Grow(s->get_Length());
  }
  MemoryExtensions::AsSpan(s).CopyTo(_chars.Slice(pos));
  _pos += s->get_Length();
}

void ValueStringBuilder::Append(Char c, Int32 count) {
  if (_pos > _chars.get_Length() - count) {
    Grow(count);
  }
  Span<Char> span = _chars.Slice(_pos, count);
  for (Int32 i = 0; i < span.get_Length(); i++) {
    span[i] = c;
  }
  _pos += count;
}

void ValueStringBuilder::Append(Char* value, Int32 length) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - length) {
    Grow(length);
  }
  Span<Char> span = _chars.Slice(_pos, length);
  for (Int32 i = 0; i < span.get_Length(); i++) {
    Char& reference = span[i];
    Char* intPtr = value;
    value = intPtr + 1;
    reference = *intPtr;
  }
  _pos += length;
}

void ValueStringBuilder::Append(ReadOnlySpan<Char> value) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - value.get_Length()) {
    Grow(value.get_Length());
  }
  value.CopyTo(_chars.Slice(_pos));
  _pos += value.get_Length();
}

Span<Char> ValueStringBuilder::AppendSpan(Int32 length) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - length) {
    Grow(length);
  }
  _pos = pos + length;
  return _chars.Slice(pos, length);
}

void ValueStringBuilder::GrowAndAppend(Char c) {
  Grow(1);
  Append(c);
}

void ValueStringBuilder::Grow(Int32 additionalCapacityBeyondPos) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(Math::Max(_pos + additionalCapacityBeyondPos, _chars.get_Length() * 2));
  _chars.Slice(0, _pos).CopyTo(array);
  Array<Char> arrayToReturnToPool = _arrayToReturnToPool;
  _chars = (_arrayToReturnToPool = array);
  if (arrayToReturnToPool != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(arrayToReturnToPool);
  }
}

void ValueStringBuilder::Dispose() {
  Array<Char> arrayToReturnToPool = _arrayToReturnToPool;
  *this = rt::default__;
  if (arrayToReturnToPool != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(arrayToReturnToPool);
  }
}

} // namespace System::Private::CoreLib::System::Text::ValueStringBuilderNamespace
