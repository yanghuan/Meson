#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace CodePageDataItemNamespace {
CLASS(CodePageDataItem) {
  private: Int32 CodePage;
  private: Int32 UIFamilyCodePage;
  private: String WebName;
  private: String HeaderName;
  private: String BodyName;
  private: String DisplayName;
  private: UInt32 Flags;
};
} // namespace CodePageDataItemNamespace
using CodePageDataItem = CodePageDataItemNamespace::CodePageDataItem;
} // namespace System::Private::CoreLib::System::Text
