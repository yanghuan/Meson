#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(String)
FORWARDS(UInt32)
namespace MdUtf8StringNamespace {
struct MdUtf8String {
  private: static Boolean EqualsCaseInsensitive(void* szLhs, void* szRhs, Int32 cSz);
  private: static UInt32 HashCaseInsensitive(void* sz, Int32 cSz);
  public: explicit MdUtf8String(void* pStringHeap);
  public: explicit MdUtf8String(Byte* pUtf8String, Int32 cUtf8String);
  public: Boolean Equals(MdUtf8String s);
  public: Boolean EqualsCaseInsensitive(MdUtf8String s);
  public: UInt32 HashCaseInsensitive();
  public: String ToString();
  public: explicit MdUtf8String() {}
  private: Byte* m_pStringHeap;
  private: Int32 m_StringHeapByteLength;
};
} // namespace MdUtf8StringNamespace
using MdUtf8String = MdUtf8StringNamespace::MdUtf8String;
} // namespace System::Private::CoreLib::System
