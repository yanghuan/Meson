#include "FastResourceComparer-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Resources/FastResourceComparer-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Resources::FastResourceComparerNamespace {
Int32 FastResourceComparer___::GetHashCode(Object key) {
  String key2 = (String)key;
  return HashFunction(key2);
}

Int32 FastResourceComparer___::GetHashCode(String key) {
  return HashFunction(key);
}

Int32 FastResourceComparer___::HashFunction(String key) {
  UInt32 num = 5381u;
  for (Int32 i = 0; i < key->get_Length(); i++) {
    num = (((num << 5) + num) ^ key[i]);
  }
  return (Int32)num;
}

Int32 FastResourceComparer___::Compare(Object a, Object b) {
  if (a == b) {
    return 0;
  }
  String strA = (String)a;
  String strB = (String)b;
  return String::in::CompareOrdinal(strA, strB);
}

Int32 FastResourceComparer___::Compare(String a, String b) {
  return String::in::CompareOrdinal(a, b);
}

Boolean FastResourceComparer___::Equals(String a, String b) {
  return String::in::Equals(a, b);
}

Boolean FastResourceComparer___::Equals(Object a, Object b) {
  if (a == b) {
    return true;
  }
  String a2 = (String)a;
  String b2 = (String)b;
  return String::in::Equals(a2, b2);
}

Int32 FastResourceComparer___::CompareOrdinal(String a, Array<Byte> bytes, Int32 bCharLength) {
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = a->get_Length();
  if (num3 > bCharLength) {
    num3 = bCharLength;
  }
  if (bCharLength == 0) {
    if (a->get_Length() != 0) {
      return -1;
    }
    return 0;
  }
  {
    Byte* ptr = bytes;
    Byte* ptr2 = ptr;
    while (num < num3 && num2 == 0) {
      Int32 num4 = *ptr2 | (ptr2[1] << 8);
      num2 = a[num++] - num4;
      ptr2 += 2;
    }
  }
  if (num2 != 0) {
    return num2;
  }
  return a->get_Length() - bCharLength;
}

Int32 FastResourceComparer___::CompareOrdinal(Array<Byte> bytes, Int32 aCharLength, String b) {
}

Int32 FastResourceComparer___::CompareOrdinal(Byte* a, Int32 byteLen, String b) {
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = byteLen >> 1;
  if (num3 > b->get_Length()) {
    num3 = b->get_Length();
  }
  while (num2 < num3 && num == 0) {
    Char c = (Char)(*(a++) | (*(a++) << 8));
    num = c - b[num2++];
  }
  if (num != 0) {
    return num;
  }
  return byteLen - b->get_Length() * 2;
}

void FastResourceComparer___::ctor() {
}

void FastResourceComparer___::cctor() {
  Default = rt::newobj<FastResourceComparer>();
}

} // namespace System::Private::CoreLib::System::Resources::FastResourceComparerNamespace
