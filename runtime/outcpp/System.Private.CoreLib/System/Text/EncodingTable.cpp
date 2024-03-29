#include "EncodingTable-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::EncodingTableNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Threading;

Int32 EncodingTable::GetCodePageFromName(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  Object obj = s_nameToCodePage[name];
  if (obj != nullptr) {
    return (Int32)obj;
  }
  Int32 num = InternalGetCodePageFromName(name);
  s_nameToCodePage[name] = num;
  return num;
}

Int32 EncodingTable::InternalGetCodePageFromName(String name) {
  Int32 i = 0;
  Int32 num = s_encodingNameIndices->get_Length() - 2;
  ReadOnlySpan<Char> strA = MemoryExtensions::AsSpan(name->ToLowerInvariant());
  while (num - i > 3) {
    Int32 num2 = (num - i) / 2 + i;
    Int32 num3 = String::in::CompareOrdinal(strA, MemoryExtensions::AsSpan("ansi_x3.4-1968ansi_x3.4-1986asciicp367cp819csasciicsisolatin1csunicode11utf7ibm367ibm819iso-10646-ucs-2iso-8859-1iso-ir-100iso-ir-6iso646-usiso8859-1iso_646.irv:1991iso_8859-1iso_8859-1:1987l1latin1ucs-2unicodeunicode-1-1-utf-7unicode-1-1-utf-8unicode-2-0-utf-7unicode-2-0-utf-8unicodefffeusus-asciiutf-16utf-16beutf-16leutf-32utf-32beutf-32leutf-7utf-8x-unicode-1-1-utf-7x-unicode-1-1-utf-8x-unicode-2-0-utf-7x-unicode-2-0-utf-8", s_encodingNameIndices[num2], s_encodingNameIndices[num2 + 1] - s_encodingNameIndices[num2]));
    if (num3 == 0) {
      return s_codePagesByName[num2];
    }
    if (num3 < 0) {
      num = num2;
    } else {
      i = num2;
    }
  }
  for (; i <= num; i++) {
    if (String::in::CompareOrdinal(strA, MemoryExtensions::AsSpan("ansi_x3.4-1968ansi_x3.4-1986asciicp367cp819csasciicsisolatin1csunicode11utf7ibm367ibm819iso-10646-ucs-2iso-8859-1iso-ir-100iso-ir-6iso646-usiso8859-1iso_646.irv:1991iso_8859-1iso_8859-1:1987l1latin1ucs-2unicodeunicode-1-1-utf-7unicode-1-1-utf-8unicode-2-0-utf-7unicode-2-0-utf-8unicodefffeusus-asciiutf-16utf-16beutf-16leutf-32utf-32beutf-32leutf-7utf-8x-unicode-1-1-utf-7x-unicode-1-1-utf-8x-unicode-2-0-utf-7x-unicode-2-0-utf-8", s_encodingNameIndices[i], s_encodingNameIndices[i + 1] - s_encodingNameIndices[i])) == 0) {
      return s_codePagesByName[i];
    }
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_EncodingNotSupported(), name), "name");
}

Array<EncodingInfo> EncodingTable::GetEncodings() {
  Array<UInt16> array = s_mappedCodePages;
  Array<EncodingInfo> array2 = rt::newarr<Array<EncodingInfo>>(LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding() ? array->get_Length() : (array->get_Length() - 1));
  String text = "utf-16utf-16BEutf-32utf-32BEus-asciiiso-8859-1utf-7utf-8";
  Array<Int32> array3 = s_webNameIndices;
  Int32 num = 0;
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Int32 num2 = array[i];
    if (num2 != 65000 || LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding()) {
      Int32 num3 = num++;
      Int32 num4 = array3[i];
      Int32 length = array3[i + 1] - num4;
      array2[num3] = rt::newobj<EncodingInfo>(num2, text->Substring(num4, length), GetDisplayName(num2, i));
    }
  }
  return array2;
}

Array<EncodingInfo> EncodingTable::GetEncodings(Dictionary<Int32, EncodingInfo> encodingInfoList) {
  Array<UInt16> array = s_mappedCodePages;
  String text = "utf-16utf-16BEutf-32utf-32BEus-asciiiso-8859-1utf-7utf-8";
  Array<Int32> array2 = s_webNameIndices;
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Int32 num = array[i];
    if (!encodingInfoList->ContainsKey(num) && (num != 65000 || LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding())) {
      Int32 num2 = array2[i];
      Int32 length = array2[i + 1] - num2;
      encodingInfoList[num] = rt::newobj<EncodingInfo>(num, text->Substring(num2, length), GetDisplayName(num, i));
    }
  }
  if (!LocalAppContextSwitches::get_EnableUnsafeUTF7Encoding()) {
    encodingInfoList->Remove(65000);
  }
  Array<EncodingInfo> array3 = rt::newarr<Array<EncodingInfo>>(encodingInfoList->get_Count());
  Int32 num3 = 0;
  for (KeyValuePair<Int32, EncodingInfo>&& encodingInfo : *encodingInfoList) {
    array3[num3++] = encodingInfo.get_Value();
  }
  return array3;
}

CodePageDataItem EncodingTable::GetCodePageDataItem(Int32 codePage) {
  if (s_codePageToCodePageData == nullptr) {
    Interlocked::CompareExchange(s_codePageToCodePageData, rt::newarr<Array<CodePageDataItem>>(s_mappedCodePages->get_Length()), (Array<CodePageDataItem>)nullptr);
  }
  Int32 num;
  switch (codePage.get()) {
    case 1200:
      num = 0;
      break;
    case 1201:
      num = 1;
      break;
    case 12000:
      num = 2;
      break;
    case 12001:
      num = 3;
      break;
    case 20127:
      num = 4;
      break;
    case 28591:
      num = 5;
      break;
    case 65000:
      num = 6;
      break;
    case 65001:
      num = 7;
      break;
    default:
      return nullptr;
  }
  CodePageDataItem codePageDataItem = s_codePageToCodePageData[num];
  if (codePageDataItem == nullptr) {
    Interlocked::CompareExchange(s_codePageToCodePageData[num], InternalGetCodePageDataItem(codePage, num), (CodePageDataItem)nullptr);
    codePageDataItem = s_codePageToCodePageData[num];
  }
  return codePageDataItem;
}

CodePageDataItem EncodingTable::InternalGetCodePageDataItem(Int32 codePage, Int32 index) {
  Int32 uiFamilyCodePage = s_uiFamilyCodePages[index];
  Int32 num = s_webNameIndices[index];
  Int32 length = s_webNameIndices[index + 1] - num;
  String text = "utf-16utf-16BEutf-32utf-32BEus-asciiiso-8859-1utf-7utf-8"->Substring(num, length);
  String headerName = text;
  String bodyName = text;
  String displayName = GetDisplayName(codePage, index);
  UInt32 flags = s_flags[index];
  return rt::newobj<CodePageDataItem>(uiFamilyCodePage, text, headerName, bodyName, displayName, flags);
}

String EncodingTable::GetDisplayName(Int32 codePage, Int32 englishNameIndex) {
  String text = SR::GetResourceString("Globalization_cp_" + codePage);
  if (String::in::IsNullOrEmpty(text)) {
    Int32 num = s_englishNameIndices[englishNameIndex];
    Int32 length = s_englishNameIndices[englishNameIndex + 1] - num;
    text = "UnicodeUnicode (Big-Endian)Unicode (UTF-32)Unicode (UTF-32 Big-Endian)US-ASCIIWestern European (ISO)Unicode (UTF-7)Unicode (UTF-8)"->Substring(num, length);
  }
  return text;
}

void EncodingTable::cctor() {
  s_encodingNameIndices = rt::newarr<Array<Int32>>(43);
  s_codePagesByName = rt::newarr<Array<UInt16>>(42);
  s_mappedCodePages = rt::newarr<Array<UInt16>>(8);
  s_uiFamilyCodePages = rt::newarr<Array<Int32>>(8);
  s_webNameIndices = rt::newarr<Array<Int32>>(9);
  s_englishNameIndices = rt::newarr<Array<Int32>>(9);
  s_flags = rt::newarr<Array<UInt32>>(8);
  s_nameToCodePage = Hashtable::in::Synchronized(rt::newobj<Hashtable>(StringComparer::in::get_OrdinalIgnoreCase()));
}

} // namespace System::Private::CoreLib::System::Text::EncodingTableNamespace
