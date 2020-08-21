#include "Normalization-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::NormalizationNamespace {
using namespace System::Buffers;
using namespace System::Runtime::InteropServices;

Boolean Normalization::IsNormalized(String strInput, NormalizationForm normalizationForm) {
  if (GlobalizationMode::get_Invariant()) {
    return true;
  }
  if (!GlobalizationMode::get_UseNls()) {
    return IcuIsNormalized(strInput, normalizationForm);
  }
  return NlsIsNormalized(strInput, normalizationForm);
}

String Normalization::Normalize(String strInput, NormalizationForm normalizationForm) {
  if (GlobalizationMode::get_Invariant()) {
    return strInput;
  }
  if (!GlobalizationMode::get_UseNls()) {
    return IcuNormalize(strInput, normalizationForm);
  }
  return NlsNormalize(strInput, normalizationForm);
}

Boolean Normalization::IcuIsNormalized(String strInput, NormalizationForm normalizationForm) {
  ValidateArguments(strInput, normalizationForm);
  Int32 num;
  {
    Char* ptr = strInput;
    Char* src = ptr;
    num = Interop::Globalization::IsNormalized(normalizationForm, src, strInput->get_Length());
  }
  if (num == -1) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
  }
  return num == 1;
}

String Normalization::IcuNormalize(String strInput, NormalizationForm normalizationForm) {
  ValidateArguments(strInput, normalizationForm);
  Array<Char> array = nullptr;
  try {
    Char as[512] = {};
    Span<Char> span = (strInput->get_Length() > 512) ? ((Span<Char>)(array = ArrayPool<Char>::in::get_Shared()->Rent(strInput->get_Length()))) : as;
    Span<Char> span2 = span;
    for (Int32 i = 0; i < 2; i++) {
      Int32 num;
      try {
        {
          Char* ptr = strInput;
          Char* src = ptr;
          try {
            {
              Char* dstBuffer = &MemoryMarshal::GetReference(span2);
              num = Interop::Globalization::NormalizeString(normalizationForm, src, strInput->get_Length(), dstBuffer, span2.get_Length());
            }
          } catch (...) {
          } finally: {
          }
        }
      } catch (...) {
      } finally: {
      }
      if (num == -1) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
      }
      if (num <= span2.get_Length()) {
        ReadOnlySpan<Char> readOnlySpan = span2.Slice(0, num);
        return MemoryExtensions::SequenceEqual(readOnlySpan, strInput) ? strInput : rt::newobj<String>(readOnlySpan);
      }
      if (i == 0) {
        if (array != nullptr) {
          Array<Char> array2 = array;
          array = nullptr;
          ArrayPool<Char>::in::get_Shared()->Return(array2);
        }
        span2 = (array = ArrayPool<Char>::in::get_Shared()->Rent(num));
      }
    }
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
  } catch (...) {
  } finally: {
    if (array != nullptr) {
      ArrayPool<Char>::in::get_Shared()->Return(array);
    }
  }
}

void Normalization::ValidateArguments(String strInput, NormalizationForm normalizationForm) {
  if (normalizationForm != NormalizationForm::FormC && normalizationForm != NormalizationForm::FormD && normalizationForm != NormalizationForm::FormKC && normalizationForm != NormalizationForm::FormKD) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNormalizationForm(), "normalizationForm");
  }
  if (HasInvalidUnicodeSequence(strInput)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
  }
}

Boolean Normalization::HasInvalidUnicodeSequence(String s) {
  for (Int32 i = 0; i < s->get_Length(); i++) {
    Char c = s[i];
    if (c < 55296) {
      continue;
    }
    if (c == 65534) {
      return true;
    }
    if (Char::IsLowSurrogate(c)) {
      return true;
    }
    if (Char::IsHighSurrogate(c)) {
      if (i + 1 >= s->get_Length() || !Char::IsLowSurrogate(s[i + 1])) {
        return true;
      }
      i++;
    }
  }
  return false;
}

Boolean Normalization::NlsIsNormalized(String strInput, NormalizationForm normalizationForm) {
  Interop::BOOL bOOL;
  {
    Char* ptr = strInput;
    Char* source = ptr;
    bOOL = Interop::Normaliz::IsNormalizedString(normalizationForm, source, strInput->get_Length());
  }
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  switch (lastWin32Error.get()) {
    case 87:
    case 1113:
      if (normalizationForm != NormalizationForm::FormC && normalizationForm != NormalizationForm::FormD && normalizationForm != NormalizationForm::FormKC && normalizationForm != NormalizationForm::FormKD) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNormalizationForm(), "normalizationForm");
      }
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
    case 8:
      rt::throw_exception<OutOfMemoryException>();
    default:
      rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_UnknownError_Num(), lastWin32Error));
    case 0:
      return bOOL != Interop::BOOL::FALSE;
  }
}

String Normalization::NlsNormalize(String strInput, NormalizationForm normalizationForm) {
  if (strInput->get_Length() == 0) {
    return String::in::Empty;
  }
  Array<Char> array = nullptr;
  try {
    Char as[512] = {};
    Span<Char> span = (strInput->get_Length() > 512) ? ((Span<Char>)(array = ArrayPool<Char>::in::get_Shared()->Rent(strInput->get_Length()))) : as;
    Span<Char> span2 = span;
    while (true) {
      Int32 num;
      try {
        {
          Char* ptr = strInput;
          Char* source = ptr;
          try {
            {
              Char* destination = &MemoryMarshal::GetReference(span2);
              num = Interop::Normaliz::NormalizeString(normalizationForm, source, strInput->get_Length(), destination, span2.get_Length());
            }
          } catch (...) {
          } finally: {
          }
        }
      } catch (...) {
      } finally: {
      }
      Int32 lastWin32Error = Marshal::GetLastWin32Error();
      switch (lastWin32Error.get()) {
        case 0:
          {
            ReadOnlySpan<Char> readOnlySpan = span2.Slice(0, num);
            return MemoryExtensions::SequenceEqual(readOnlySpan, strInput) ? strInput : rt::newobj<String>(readOnlySpan);
          }case 122:
          num = Math::Abs(num);
          if (array != nullptr) {
            Array<Char> array2 = array;
            array = nullptr;
            ArrayPool<Char>::in::get_Shared()->Return(array2);
          }
          break;
        case 87:
        case 1113:
          if (normalizationForm != NormalizationForm::FormC && normalizationForm != NormalizationForm::FormD && normalizationForm != NormalizationForm::FormKC && normalizationForm != NormalizationForm::FormKD) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidNormalizationForm(), "normalizationForm");
          }
          rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidCharSequenceNoIndex(), "strInput");
        case 8:
          rt::throw_exception<OutOfMemoryException>();
        default:
          rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_UnknownError_Num(), lastWin32Error));
      }
      span2 = (array = ArrayPool<Char>::in::get_Shared()->Rent(num));
    }
  } catch (...) {
  } finally: {
    if (array != nullptr) {
      ArrayPool<Char>::in::get_Shared()->Return(array);
    }
  }
}

} // namespace System::Private::CoreLib::System::Globalization::NormalizationNamespace
