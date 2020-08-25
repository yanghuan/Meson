#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Resources {
namespace ResourceFallbackManagerNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Globalization;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
CLASS(ResourceFallbackManager) : public object {
  public: using interface = rt::TypeList<IEnumerable<CultureInfo>, IEnumerable_>;
  public: void ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents);
  public: IEnumerator<CultureInfo> GetEnumerator();
  private: CultureInfo m_startingCulture;
  private: CultureInfo m_neutralResourcesCulture;
  private: Boolean m_useParents;
};
} // namespace ResourceFallbackManagerNamespace
using ResourceFallbackManager = ResourceFallbackManagerNamespace::ResourceFallbackManager;
} // namespace System::Private::CoreLib::System::Resources
