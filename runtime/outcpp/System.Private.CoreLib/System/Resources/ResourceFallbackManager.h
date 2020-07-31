#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Resources {
namespace ResourceFallbackManagerNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using Collections::Generic::IEnumerator;
CLASS(ResourceFallbackManager) : public Object::in {
  public: void Ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents);
  public: IEnumerator<CultureInfo> GetEnumerator();
  private: CultureInfo m_startingCulture;
  private: CultureInfo m_neutralResourcesCulture;
  private: Boolean m_useParents;
};
} // namespace ResourceFallbackManagerNamespace
using ResourceFallbackManager = ResourceFallbackManagerNamespace::ResourceFallbackManager;
} // namespace System::Private::CoreLib::System::Resources
