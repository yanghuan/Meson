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
using namespace Collections;
using namespace Collections::Generic;
using namespace Globalization;
using Collections::Generic::IEnumerator;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(ResourceFallbackManager) : public Object::in {
  public: using interface = rt::TypeList<IEnumerable<CultureInfo>, IEnumerable1>;
  public: void Ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents);
  public: IEnumerator<CultureInfo> GetEnumerator();
  private: CultureInfo m_startingCulture;
  private: CultureInfo m_neutralResourcesCulture;
  private: Boolean m_useParents;
};
} // namespace ResourceFallbackManagerNamespace
using ResourceFallbackManager = ResourceFallbackManagerNamespace::ResourceFallbackManager;
} // namespace System::Private::CoreLib::System::Resources
