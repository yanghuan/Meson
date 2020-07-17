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
  public: Int32 get_UIFamilyCodePage() { return UIFamilyCodePage; }
  public: String get_WebName() { return WebName; }
  public: String get_HeaderName() { return HeaderName; }
  public: String get_BodyName() { return BodyName; }
  public: String get_DisplayName() { return DisplayName; }
  public: UInt32 get_Flags() { return Flags; }
  public: void Ctor(Int32 uiFamilyCodePage, String webName, String headerName, String bodyName, String displayName, UInt32 flags);
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
