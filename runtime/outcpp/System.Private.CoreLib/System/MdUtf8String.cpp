#include "MdUtf8String-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::MdUtf8StringNamespace {
using namespace System::Text;

MdUtf8String::MdUtf8String(void* pStringHeap) {
  if (pStringHeap != nullptr) {
    m_StringHeapByteLength = String::in::strlen((Byte*)pStringHeap);
  } else {
    m_StringHeapByteLength = 0;
  }
  m_pStringHeap = (Byte*)pStringHeap;
}

MdUtf8String::MdUtf8String(Byte* pUtf8String, Int32 cUtf8String) {
  m_pStringHeap = pUtf8String;
  m_StringHeapByteLength = cUtf8String;
}

Boolean MdUtf8String::Equals(MdUtf8String s) {
  if (s.m_StringHeapByteLength != m_StringHeapByteLength) {
    return false;
  }
  return SpanHelpers::SequenceEqual(*s.m_pStringHeap, *m_pStringHeap, (UIntPtr)(UInt32)m_StringHeapByteLength);
}

Boolean MdUtf8String::EqualsCaseInsensitive(MdUtf8String s) {
  if (s.m_StringHeapByteLength != m_StringHeapByteLength) {
    return false;
  }
  if (m_StringHeapByteLength != 0) {
    return EqualsCaseInsensitive(s.m_pStringHeap, m_pStringHeap, m_StringHeapByteLength);
  }
  return true;
}

UInt32 MdUtf8String::HashCaseInsensitive() {
  return HashCaseInsensitive(m_pStringHeap, m_StringHeapByteLength);
}

String MdUtf8String::ToString() {
  return Encoding::in::get_UTF8()->GetString(ReadOnlySpan<Byte>(m_pStringHeap, m_StringHeapByteLength));
}

} // namespace System::Private::CoreLib::System::MdUtf8StringNamespace
