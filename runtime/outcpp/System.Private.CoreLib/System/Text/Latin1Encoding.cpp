#include "Latin1Encoding-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderFallback-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderLatin1BestFitFallback-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/EncoderReplacementFallback-dep.h>
#include <System.Private.CoreLib/System/Text/Latin1Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/Latin1Utility-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::Latin1EncodingNamespace {
using namespace System::Runtime::InteropServices;

Object Latin1EncodingSealed___::Clone() {
  return rt::newobj<Latin1Encoding>();
}

void Latin1EncodingSealed___::ctor() {
}

void Latin1Encoding___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void Latin1Encoding___::__c___::ctor() {
}

void Latin1Encoding___::__c___::_GetString_b__29_0(Span<Char> chars, ValueTuple<Latin1Encoding, Array<Byte>> args) {
  {
    Byte* pBytes = rt::fixed(args.Item2);
    {
      Char* pChars = rt::fixed(chars);
      args.Item1->GetCharsCommon(pBytes, args.Item2->get_Length(), pChars, chars.get_Length());
    }
  }
}

void Latin1Encoding___::__c___::_GetString_b__30_0(Span<Char> chars, ValueTuple<Latin1Encoding, Array<Byte>, Int32> args) {
  {
    Byte* ptr = rt::fixed(args.Item2);
    {
      Char* pChars = rt::fixed(chars);
      args.Item1->GetCharsCommon(ptr + args.Item3, chars.get_Length(), pChars, chars.get_Length());
    }
  }
}

ReadOnlySpan<Byte> Latin1Encoding___::get_Preamble() {
  return rt::default__;
}

Boolean Latin1Encoding___::get_IsSingleByte() {
  return true;
}

void Latin1Encoding___::ctor() {
}

void Latin1Encoding___::SetDefaultFallbacks() {
  encoderFallback = EncoderLatin1BestFitFallback::in::SingletonInstance;
  decoderFallback = DecoderFallback::in::get_ReplacementFallback();
}

Int32 Latin1Encoding___::GetByteCount(Char* chars, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetByteCountCommon(chars, count);
}

Int32 Latin1Encoding___::GetByteCount(Array<Char> chars, Int32 index, Int32 count) {
  if (chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (chars->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::chars, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  {
    Char* ptr = rt::fixed(chars);
    return GetByteCountCommon(ptr + index, count);
  }
}

Int32 Latin1Encoding___::GetByteCount(ReadOnlySpan<Char> chars) {
  {
    Char* pChars = rt::fixed(&MemoryMarshal::GetReference(chars));
    return GetByteCountCommon(pChars, chars.get_Length());
  }
}

Int32 Latin1Encoding___::GetByteCount(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  {
    Char* ptr = rt::fixed(s);
    Char* pChars = ptr;
    return GetByteCountCommon(pChars, s->get_Length());
  }
}

Int32 Latin1Encoding___::GetByteCountCommon(Char* pChars, Int32 charCount) {
  Int32 charsConsumed;
  Int32 num = GetByteCountFast(pChars, charCount, nullptr, charsConsumed);
  if (charsConsumed != charCount) {
    num += GetByteCountWithFallback(pChars, charCount, charsConsumed);
    if (num < 0) {
      Encoding::in::ThrowConversionOverflow();
    }
  }
  return num;
}

Int32 Latin1Encoding___::GetByteCountFast(Char* pChars, Int32 charsLength, EncoderFallback fallback, Int32& charsConsumed) {
  Int32 num = charsLength;
  if (!FallbackSupportsFastGetByteCount(fallback)) {
    num = (Int32)Latin1Utility::GetIndexOfFirstNonLatin1Char(pChars, (UInt32)charsLength);
  }
  charsConsumed = num;
  return num;
}

Int32 Latin1Encoding___::GetMaxByteCount(Int32 charCount) {
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int64 num = (Int64)charCount + 1;
  if (Encoding::in::get_EncoderFallback()->get_MaxCharCount() > 1) {
    num *= Encoding::in::get_EncoderFallback()->get_MaxCharCount();
  }
  if (num > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GetByteCountOverflow());
  }
  return (Int32)num;
}

Int32 Latin1Encoding___::GetBytes(Char* chars, Int32 charCount, Byte* bytes, Int32 byteCount) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charCount | byteCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charCount < 0) ? ExceptionArgument::charCount : ExceptionArgument::byteCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetBytesCommon(chars, charCount, bytes, byteCount);
}

Int32 Latin1Encoding___::GetBytes(Array<Char> chars, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (chars == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((chars == nullptr) ? ExceptionArgument::chars : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charIndex | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charIndex < 0) ? ExceptionArgument::charIndex : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (chars->get_Length() - charIndex < charCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::chars, ExceptionResource::ArgumentOutOfRange_IndexCount);
  }
  if ((UInt32)byteIndex > bytes->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::byteIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Char* ptr = rt::fixed(chars);
    {
      Byte* ptr2 = rt::fixed(bytes);
      return GetBytesCommon(ptr + charIndex, charCount, ptr2 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 Latin1Encoding___::GetBytes(ReadOnlySpan<Char> chars, Span<Byte> bytes) {
  {
    Char* pChars = rt::fixed(&MemoryMarshal::GetReference(chars));
    {
      Byte* pBytes = rt::fixed(&MemoryMarshal::GetReference(bytes));
      return GetBytesCommon(pChars, chars.get_Length(), pBytes, bytes.get_Length());
    }
  }
}

Int32 Latin1Encoding___::GetBytes(String s, Int32 charIndex, Int32 charCount, Array<Byte> bytes, Int32 byteIndex) {
  if (s == nullptr || bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException((s == nullptr) ? ExceptionArgument::s : ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((charIndex | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((charIndex < 0) ? ExceptionArgument::charIndex : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (s->get_Length() - charIndex < charCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::s, ExceptionResource::ArgumentOutOfRange_IndexCount);
  }
  if ((UInt32)byteIndex > bytes->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::byteIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Char* ptr = rt::fixed(s);
    Char* ptr2 = ptr;
    {
      Byte* ptr3 = rt::fixed(bytes);
      return GetBytesCommon(ptr2 + charIndex, charCount, ptr3 + byteIndex, bytes->get_Length() - byteIndex);
    }
  }
}

Int32 Latin1Encoding___::GetBytesCommon(Char* pChars, Int32 charCount, Byte* pBytes, Int32 byteCount) {
  Int32 charsConsumed;
  Int32 bytesFast = GetBytesFast(pChars, charCount, pBytes, byteCount, charsConsumed);
  if (charsConsumed == charCount) {
    return bytesFast;
  }
  return GetBytesWithFallback(pChars, charCount, pBytes, byteCount, charsConsumed, bytesFast);
}

Int32 Latin1Encoding___::GetBytesFast(Char* pChars, Int32 charsLength, Byte* pBytes, Int32 bytesLength, Int32& charsConsumed) {
  return charsConsumed = (Int32)Latin1Utility::NarrowUtf16ToLatin1(pChars, pBytes, (UInt32)Math::Min(charsLength, bytesLength));
}

Int32 Latin1Encoding___::GetCharCount(Byte* bytes, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes);
  }
  if (count < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return count;
}

Int32 Latin1Encoding___::GetCharCount(Array<Byte> bytes) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes);
  }
  return bytes->get_Length();
}

Int32 Latin1Encoding___::GetCharCount(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  return count;
}

Int32 Latin1Encoding___::GetCharCount(ReadOnlySpan<Byte> bytes) {
  return bytes.get_Length();
}

Int32 Latin1Encoding___::GetCharCountFast(Byte* pBytes, Int32 bytesLength, DecoderFallback fallback, Int32& bytesConsumed) {
  bytesConsumed = bytesLength;
  return bytesLength;
}

Int32 Latin1Encoding___::GetMaxCharCount(Int32 byteCount) {
  if (byteCount < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::byteCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return byteCount;
}

Int32 Latin1Encoding___::GetChars(Byte* bytes, Int32 byteCount, Char* chars, Int32 charCount) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((byteCount | charCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((byteCount < 0) ? ExceptionArgument::byteCount : ExceptionArgument::charCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  return GetCharsCommon(bytes, byteCount, chars, charCount);
}

Array<Char> Latin1Encoding___::GetChars(Array<Byte> bytes) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes);
  }
  if (bytes->get_Length() == 0) {
    return Array<>::in::Empty<Char>();
  }
  Array<Char> array = rt::newarr<Array<Char>>(bytes->get_Length());
  {
    Byte* pBytes = rt::fixed(bytes);
    {
      Char* pChars = rt::fixed(array);
      GetCharsCommon(pBytes, bytes->get_Length(), pChars, array->get_Length());
    }
  }
  return array;
}

Int32 Latin1Encoding___::GetChars(Array<Byte> bytes, Int32 byteIndex, Int32 byteCount, Array<Char> chars, Int32 charIndex) {
  if (bytes == nullptr || chars == nullptr) {
    ThrowHelper::ThrowArgumentNullException((bytes == nullptr) ? ExceptionArgument::bytes : ExceptionArgument::chars, ExceptionResource::ArgumentNull_Array);
  }
  if ((byteIndex | byteCount) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((byteIndex < 0) ? ExceptionArgument::byteIndex : ExceptionArgument::byteCount, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - byteIndex < byteCount) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  if ((UInt32)charIndex > (UInt32)chars->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::charIndex, ExceptionResource::ArgumentOutOfRange_Index);
  }
  {
    Byte* ptr = rt::fixed(bytes);
    {
      Char* ptr2 = rt::fixed(chars);
      return GetCharsCommon(ptr + byteIndex, byteCount, ptr2 + charIndex, chars->get_Length() - charIndex);
    }
  }
}

Array<Char> Latin1Encoding___::GetChars(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  Array<Char> array = rt::newarr<Array<Char>>(count);
  {
    Byte* ptr = rt::fixed(bytes);
    {
      Char* pChars = rt::fixed(array);
      GetCharsCommon(ptr + index, count, pChars, array->get_Length());
    }
  }
  return array;
}

Int32 Latin1Encoding___::GetChars(ReadOnlySpan<Byte> bytes, Span<Char> chars) {
  {
    Byte* pBytes = rt::fixed(&MemoryMarshal::GetReference(bytes));
    {
      Char* pChars = rt::fixed(&MemoryMarshal::GetReference(chars));
      return GetCharsCommon(pBytes, bytes.get_Length(), pChars, chars.get_Length());
    }
  }
}

String Latin1Encoding___::GetString(Array<Byte> bytes) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes);
  }
  SpanAction<Char, ValueTuple<Latin1Encoding, Array<Byte>>> as = __c::in::__9__29_0;
  return String::in::Create(bytes->get_Length(), {(Latin1Encoding)this, bytes}, as != nullptr ? as : (__c::in::__9__29_0 = {__c::in::__9, &__c::in::_GetString_b__29_0}));
}

String Latin1Encoding___::GetString(Array<Byte> bytes, Int32 index, Int32 count) {
  if (bytes == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::bytes, ExceptionResource::ArgumentNull_Array);
  }
  if ((index | count) < 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException((index < 0) ? ExceptionArgument::index : ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_NeedNonNegNum);
  }
  if (bytes->get_Length() - index < count) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::bytes, ExceptionResource::ArgumentOutOfRange_IndexCountBuffer);
  }
  SpanAction<Char, ValueTuple<Latin1Encoding, Array<Byte>, Int32>> as = __c::in::__9__30_0;
  return String::in::Create(count, {(Latin1Encoding)this, bytes, index}, as != nullptr ? as : (__c::in::__9__30_0 = {__c::in::__9, &__c::in::_GetString_b__30_0}));
}

Int32 Latin1Encoding___::GetCharsCommon(Byte* pBytes, Int32 byteCount, Char* pChars, Int32 charCount) {
  if (byteCount > charCount) {
    ThrowCharsOverflow();
  }
  Latin1Utility::WidenLatin1ToUtf16(pBytes, pChars, (UInt32)byteCount);
  return byteCount;
}

Int32 Latin1Encoding___::GetCharsFast(Byte* pBytes, Int32 bytesLength, Char* pChars, Int32 charsLength, Int32& bytesConsumed) {
  Int32 num = Math::Min(bytesLength, charsLength);
  Latin1Utility::WidenLatin1ToUtf16(pBytes, pChars, (UInt32)num);
  bytesConsumed = num;
  return num;
}

Decoder Latin1Encoding___::GetDecoder() {
  return rt::newobj<DecoderNLS>((Latin1Encoding)this);
}

Encoder Latin1Encoding___::GetEncoder() {
  return rt::newobj<EncoderNLS>((Latin1Encoding)this);
}

Boolean Latin1Encoding___::TryGetByteCount(Rune value, Int32& byteCount) {
  if (value.get_Value() <= 255) {
    byteCount = 1;
    return true;
  }
  byteCount = 0;
  return false;
}

OperationStatus Latin1Encoding___::EncodeRune(Rune value, Span<Byte> bytes, Int32& bytesWritten) {
  if (value.get_Value() <= 255) {
    if (!bytes.get_IsEmpty()) {
      bytes[0] = (Byte)value.get_Value();
      bytesWritten = 1;
      return OperationStatus::Done;
    }
    bytesWritten = 0;
    return OperationStatus::DestinationTooSmall;
  }
  bytesWritten = 0;
  return OperationStatus::InvalidData;
}

OperationStatus Latin1Encoding___::DecodeFirstRune(ReadOnlySpan<Byte> bytes, Rune& value, Int32& bytesConsumed) {
  if (!bytes.get_IsEmpty()) {
    Byte b = bytes[0];
    if (b <= Byte::MaxValue()) {
      value = Rune(b);
      bytesConsumed = 1;
      return OperationStatus::Done;
    }
    value = Rune::get_ReplacementChar();
    bytesConsumed = 1;
    return OperationStatus::InvalidData;
  }
  value = Rune::get_ReplacementChar();
  bytesConsumed = 0;
  return OperationStatus::NeedMoreData;
}

Boolean Latin1Encoding___::IsAlwaysNormalized(NormalizationForm form) {
  return form == NormalizationForm::FormC;
}

Boolean Latin1Encoding___::FallbackSupportsFastGetByteCount(EncoderFallback fallback) {
  if (fallback == nullptr) {
    return false;
  }
  if (rt::is<EncoderLatin1BestFitFallback>(fallback)) {
    return true;
  }
  EncoderReplacementFallback encoderReplacementFallback = rt::as<EncoderReplacementFallback>(fallback);
  if (encoderReplacementFallback != nullptr && encoderReplacementFallback->get_MaxCharCount() == 1 && encoderReplacementFallback->get_DefaultString()[0] <= u'ÿ') {
    return true;
  }
  return false;
}

void Latin1Encoding___::cctor() {
  s_default = rt::newobj<Latin1EncodingSealed>();
}

} // namespace System::Private::CoreLib::System::Text::Latin1EncodingNamespace
