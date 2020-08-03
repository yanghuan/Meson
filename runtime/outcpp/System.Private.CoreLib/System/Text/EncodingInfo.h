#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
namespace EncodingInfoNamespace {
CLASS(EncodingInfo) : public Object::in {
  public: Int32 get_CodePage() { return CodePage; }
  public: String get_Name() { return Name; }
  public: String get_DisplayName() { return DisplayName; }
  public: void Ctor(Int32 codePage, String name, String displayName);
  public: Encoding GetEncoding();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  private: Int32 CodePage;
  private: String Name;
  private: String DisplayName;
};
} // namespace EncodingInfoNamespace
using EncodingInfo = EncodingInfoNamespace::EncodingInfo;
} // namespace System::Private::CoreLib::System::Text
