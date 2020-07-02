#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Text {
FORWARD(EncodingInfo)
FORWARD(CodePageDataItem)
namespace EncodingTableNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
class EncodingTable {
  public: static Int32 GetCodePageFromName(String name);
  private: static Int32 InternalGetCodePageFromName(String name);
  public: static Array<EncodingInfo> GetEncodings();
  public: static CodePageDataItem GetCodePageDataItem(Int32 codePage);
  private: static CodePageDataItem InternalGetCodePageDataItem(Int32 codePage, Int32 index);
  private: static String GetDisplayName(Int32 codePage, Int32 englishNameIndex);
  private: static Array<Int32> s_encodingNameIndices;
  private: static Array<UInt16> s_codePagesByName;
  private: static Array<UInt16> s_mappedCodePages;
  private: static Array<Int32> s_uiFamilyCodePages;
  private: static Array<Int32> s_webNameIndices;
  private: static Array<Int32> s_englishNameIndices;
  private: static Array<UInt32> s_flags;
  private: static Hashtable s_nameToCodePage;
  private: static Array<CodePageDataItem> s_codePageToCodePageData;
};
} // namespace EncodingTableNamespace
using EncodingTable = EncodingTableNamespace::EncodingTable;
} // namespace System::Private::CoreLib::System::Text
