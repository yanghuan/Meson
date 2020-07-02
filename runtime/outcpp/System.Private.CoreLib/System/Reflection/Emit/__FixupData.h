#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/Label.h>

namespace System::Private::CoreLib::System::Reflection::Emit {
namespace __FixupDataNamespace {
struct __FixupData {
  public: Label m_fixupLabel;
  public: Int32 m_fixupPos;
  public: Int32 m_fixupInstSize;
};
} // namespace __FixupDataNamespace
using __FixupData = __FixupDataNamespace::__FixupData;
} // namespace System::Private::CoreLib::System::Reflection::Emit
