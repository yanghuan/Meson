#include "AssemblyNameFormatter-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/FileLoadException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyNameFormatter-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyNameFormatterNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

String AssemblyNameFormatter::ComputeDisplayName(String name, Version version, String cultureName, Array<Byte> pkt, AssemblyNameFlags flags, AssemblyContentType contentType) {
  if (name == String::in::Empty) {
    rt::throw_exception<FileLoadException>();
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  if (name != nullptr) {
    AssemblyNameFormatter::AppendQuoted(stringBuilder, name);
  }
  if (version != nullptr) {
    Version version2 = AssemblyNameFormatter::CanonicalizeVersion(version);
    if (version2->get_Major() != 65535) {
      stringBuilder->Append(", Version=");
      stringBuilder->Append(version2->get_Major());
      if (version2->get_Minor() != 65535) {
        stringBuilder->Append(46);
        stringBuilder->Append(version2->get_Minor());
        if (version2->get_Build() != 65535) {
          stringBuilder->Append(46);
          stringBuilder->Append(version2->get_Build());
          if (version2->get_Revision() != 65535) {
            stringBuilder->Append(46);
            stringBuilder->Append(version2->get_Revision());
          }
        }
      }
    }
  }
  if (cultureName != nullptr) {
    if (cultureName->get_Length() == 0) {
      cultureName = "neutral";
    }
    stringBuilder->Append(", Culture=");
    AssemblyNameFormatter::AppendQuoted(stringBuilder, cultureName);
  }
  if (pkt != nullptr) {
    if (pkt->get_Length() > 8) {
      rt::throw_exception<ArgumentException>();
    }
    stringBuilder->Append(", PublicKeyToken=");
    if (pkt->get_Length() == 0) {
      stringBuilder->Append("null");
    } else {
      stringBuilder->Append(HexConverter::ToString(pkt, HexConverter::Casing::Lower));
    }
  }
  if ((flags & AssemblyNameFlags::Retargetable) != 0) {
    stringBuilder->Append(", Retargetable=Yes");
  }
  if (contentType == AssemblyContentType::WindowsRuntime) {
    stringBuilder->Append(", ContentType=WindowsRuntime");
  }
  return stringBuilder->ToString();
}

void AssemblyNameFormatter::AppendQuoted(StringBuilder sb, String s) {
  Boolean flag = false;
  if (s != s->Trim() || s->Contains(34) || s->Contains(39)) {
    flag = true;
  }
  if (flag) {
    sb->Append(34);
  }
  for (Int32 i = 0; i < s->get_Length(); i++) {
    Boolean flag2 = false;
    Array<KeyValuePair<Char, String>> escapeSequences = EscapeSequences;
    for (Int32 j = 0; j < escapeSequences->get_Length(); j++) {
      KeyValuePair<Char, String> keyValuePair = escapeSequences[j];
      String value = keyValuePair.get_Value();
      if (s[i] == value[0] && s->get_Length() - i >= value->get_Length() && MemoryExtensions::SequenceEqual(MemoryExtensions::AsSpan(s, i, value->get_Length()), value)) {
        sb->Append(92);
        sb->Append(keyValuePair.get_Key());
        flag2 = true;
      }
    }
    if (!flag2) {
      sb->Append(s[i]);
    }
  }
  if (flag) {
    sb->Append(34);
  }
}

Version AssemblyNameFormatter::CanonicalizeVersion(Version version) {
  UInt16 num = (UInt16)version->get_Major();
  UInt16 num2 = (UInt16)version->get_Minor();
  UInt16 num3 = (UInt16)version->get_Build();
  UInt16 num4 = (UInt16)version->get_Revision();
  if (num == version->get_Major() && num2 == version->get_Minor() && num3 == version->get_Build() && num4 == version->get_Revision()) {
    return version;
  }
  return rt::newobj<Version>(num, num2, num3, num4);
}

void AssemblyNameFormatter::cctor() {
  EscapeSequences = rt::newarr<Array<KeyValuePair<Char, String>>>(7);
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyNameFormatterNamespace
