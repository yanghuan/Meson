#include "OrdinalCasing-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::OrdinalCasingNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

Char OrdinalCasing::ToUpper(Char c) {
  Int32 num = (Int32)c >> 8;
  if (num == 0) {
    return (Char)s_basicLatin[c];
  }
  Array<UInt16> array = s_casingTable[num];
  if (array == s_noCasingPage) {
    return c;
  }
  if (array == nullptr) {
    array = InitOrdinalCasingPage(num);
  }
  return (Char)array[c & 255];
}

Char OrdinalCasing::ToUpperInvariantMode(Char c) {
  if (c > 'ÿ') {
    return c;
  }
  return (Char)s_basicLatin[c];
}

void OrdinalCasing::ToUpperInvariantMode(ReadOnlySpan<Char> source, Span<Char> destination) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    destination[i] = ToUpperInvariantMode(source[i]);
  }
}

void OrdinalCasing::ToUpperOrdinal(ReadOnlySpan<Char> source, Span<Char> destination) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    Char c = source[i];
    if (c <= 'ÿ') {
      destination[i] = (Char)s_basicLatin[c];
    } else if (Char::IsHighSurrogate(c) && i < source.get_Length() - 1 && Char::IsLowSurrogate(source[i + 1])) {
      UInt16 hr;
      UInt16 lr;
      ToUpperSurrogate(c, source[i + 1], hr, lr);
      destination[i] = (Char)hr;
      destination[i + 1] = (Char)lr;
      i++;
    } else {
      destination[i] = ToUpper(c);
    }

  }
}

void OrdinalCasing::ToUpperSurrogate(UInt16 h, UInt16 l, UInt16& hr, UInt16& lr) {
  switch (h.get()) {
    case 55297:
      switch (l.get()) {
        case 56360:
        case 56361:
        case 56362:
        case 56363:
        case 56364:
        case 56365:
        case 56366:
        case 56367:
        case 56368:
        case 56369:
        case 56370:
        case 56371:
        case 56372:
        case 56373:
        case 56374:
        case 56375:
        case 56376:
        case 56377:
        case 56378:
        case 56379:
        case 56380:
        case 56381:
        case 56382:
        case 56383:
        case 56384:
        case 56385:
        case 56386:
        case 56387:
        case 56388:
        case 56389:
        case 56390:
        case 56391:
        case 56392:
        case 56393:
        case 56394:
        case 56395:
        case 56396:
        case 56397:
        case 56398:
        case 56399:
          hr = h;
          lr = (UInt16)(l - 56360 + 56320);
          return;
        case 56536:
        case 56537:
        case 56538:
        case 56539:
        case 56540:
        case 56541:
        case 56542:
        case 56543:
        case 56544:
        case 56545:
        case 56546:
        case 56547:
        case 56548:
        case 56549:
        case 56550:
        case 56551:
        case 56552:
        case 56553:
        case 56554:
        case 56555:
        case 56556:
        case 56557:
        case 56558:
        case 56559:
        case 56560:
        case 56561:
        case 56562:
        case 56563:
        case 56564:
        case 56565:
        case 56566:
        case 56567:
        case 56568:
        case 56569:
        case 56570:
        case 56571:
          hr = h;
          lr = (UInt16)(l - 56536 + 56496);
          return;
      }
      break;
    case 55299:
      if ((UInt32)(l - 56512) <= 50u) {
        hr = h;
        lr = (UInt16)(l - 56512 + 56448);
        return;
      }
      break;
    case 55302:
      if ((UInt32)(l - 56512) <= 31u) {
        hr = h;
        lr = (UInt16)(l - 56512 + 56480);
        return;
      }
      break;
    case 55323:
      if ((UInt32)(l - 56928) <= 31u) {
        hr = h;
        lr = (UInt16)(l - 56928 + 56896);
        return;
      }
      break;
    case 55354:
      if ((UInt32)(l - 56610) <= 33u) {
        hr = h;
        lr = (UInt16)(l - 56610 + 56576);
        return;
      }
      break;
  }
  hr = h;
  lr = l;
}

Boolean OrdinalCasing::EqualSurrogate(Char h1, Char l1, Char h2, Char l2) {
  UInt16 hr;
  UInt16 lr;
  ToUpperSurrogate(h1, l1, hr, lr);
  UInt16 hr2;
  UInt16 lr2;
  ToUpperSurrogate(h2, l2, hr2, lr2);
  if (hr == hr2) {
    return lr == lr2;
  }
  return false;
}

Int32 OrdinalCasing::CompareStringIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  Int32 num = Math::Min(lengthA, lengthB);
  Char& reference = strA;
  Char& reference2 = strB;
  while (num != 0) {
    if (reference <= 'ÿ' || num == 1 || !Char::IsHighSurrogate(reference) || !Char::IsHighSurrogate(reference2)) {
      if (reference == reference2) {
        num--;
        reference = Unsafe::Add(reference, 1);
        reference2 = Unsafe::Add(reference2, 1);
        continue;
      }
      Char c = ToUpper(reference);
      Char c2 = ToUpper(reference2);
      if (c == c2) {
        num--;
        reference = Unsafe::Add(reference, 1);
        reference2 = Unsafe::Add(reference2, 1);
        continue;
      }
      return c - c2;
    }
    Char c3 = reference;
    Char c4 = reference2;
    num--;
    reference = Unsafe::Add(reference, 1);
    reference2 = Unsafe::Add(reference2, 1);
    if (!Char::IsLowSurrogate(reference) || !Char::IsLowSurrogate(reference2)) {
      if (c3 == c4) {
        continue;
      }
      return c3 - c4;
    }
    UInt16 hr;
    UInt16 lr;
    ToUpperSurrogate(c3, reference, hr, lr);
    UInt16 hr2;
    UInt16 lr2;
    ToUpperSurrogate(c4, reference2, hr2, lr2);
    if (hr != hr2) {
      return hr - hr2;
    }
    if (lr != lr2) {
      return lr - lr2;
    }
    num--;
    reference = Unsafe::Add(reference, 1);
    reference2 = Unsafe::Add(reference2, 1);
  }
  return lengthA - lengthB;
}

Int32 OrdinalCasing::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value) {
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(value);
      Char* ptr2 = ptr + (source.get_Length() - value.get_Length());
      Char* ptr4 = ptr3 + value.get_Length() - 1;
      for (Char* ptr5 = ptr; ptr5 <= ptr2; ptr5++) {
        Char* ptr6 = ptr3;
        Char* ptr7 = ptr5;
        while (ptr6 <= ptr4) {
          if (!Char::IsHighSurrogate(*ptr6) || ptr6 == ptr4) {
            if (*ptr6 != *ptr7 && ToUpper(*ptr6) != ToUpper(*ptr7)) {
              break;
            }
            ptr6++;
            ptr7++;
          } else if (Char::IsHighSurrogate(*ptr7) && Char::IsLowSurrogate(ptr7[1]) && Char::IsLowSurrogate(ptr6[1])) {
            if (!EqualSurrogate(*ptr7, ptr7[1], *ptr6, ptr6[1])) {
              break;
            }
            ptr7 += 2;
            ptr6 += 2;
          } else {
            if (*ptr6 != *ptr7) {
              break;
            }
            ptr7++;
            ptr6++;
          }

        }
        if (ptr6 > ptr4) {
          return (Int32)(ptr5 - ptr);
        }
      }
      return -1;
    }
  }
}

Int32 OrdinalCasing::LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value) {
  {
    Char* ptr3 = &MemoryMarshal::GetReference(source);
    {
      Char* ptr = &MemoryMarshal::GetReference(value);
      Char* ptr2 = ptr + value.get_Length() - 1;
      for (Char* ptr4 = ptr3 + (source.get_Length() - value.get_Length()); ptr4 >= ptr3; ptr4--) {
        Char* ptr5 = ptr;
        Char* ptr6 = ptr4;
        while (ptr5 <= ptr2) {
          if (!Char::IsHighSurrogate(*ptr5) || ptr5 == ptr2) {
            if (*ptr5 != *ptr6 && ToUpper(*ptr5) != ToUpper(*ptr6)) {
              break;
            }
            ptr5++;
            ptr6++;
          } else if (Char::IsHighSurrogate(*ptr6) && Char::IsLowSurrogate(ptr6[1]) && Char::IsLowSurrogate(ptr5[1])) {
            if (!EqualSurrogate(*ptr6, ptr6[1], *ptr5, ptr5[1])) {
              break;
            }
            ptr6 += 2;
            ptr5 += 2;
          } else {
            if (*ptr5 != *ptr6) {
              break;
            }
            ptr6++;
            ptr5++;
          }

        }
        if (ptr5 > ptr2) {
          return (Int32)(ptr4 - ptr3);
        }
      }
      return -1;
    }
  }
}

Array<UInt16> OrdinalCasing::InitOrdinalCasingPage(Int32 pageNumber) {
  Array<UInt16> array = rt::newarr<Array<UInt16>>(256);
  {
    UInt16* ptr = array;
    Char* pTarget = (Char*)ptr;
    Interop::Globalization::InitOrdinalCasingPage(pageNumber, pTarget);
  }
  s_casingTable[pageNumber] = array;
  return array;
}

void OrdinalCasing::cctor() {
  s_noCasingPage = Array<>::in::Empty<UInt16>();
  s_basicLatin = rt::newarr<Array<UInt16>>(256);
  s_casingTable = rt::newarr<Array<Array<UInt16>>>(256);
}

} // namespace System::Private::CoreLib::System::Globalization::OrdinalCasingNamespace
