#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
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
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
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
using IEnumerator_ = Collections::IEnumerator;
CLASS(ResourceFallbackManager) : public object {
  public: using interface = rt::TypeList<IEnumerable<CultureInfo>, IEnumerable_>;
  private: CLASS(_GetEnumerator_d__5) : public object {
    public: using interface = rt::TypeList<IEnumerator<CultureInfo>, IDisposable, IEnumerator_>;
    private: CultureInfo get_CurrentOfCultureInfo();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: Int32 __1__state;
    private: CultureInfo __2__current;
    public: ResourceFallbackManager __4__this;
    private: Boolean _reachedNeutralResourcesCulture_5__2;
    private: CultureInfo _currentCulture_5__3;
  };
  public: void ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents);
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  public: IEnumerator<CultureInfo> GetEnumerator();
  private: CultureInfo m_startingCulture;
  private: CultureInfo m_neutralResourcesCulture;
  private: Boolean m_useParents;
};
} // namespace ResourceFallbackManagerNamespace
using ResourceFallbackManager = ResourceFallbackManagerNamespace::ResourceFallbackManager;
} // namespace System::Private::CoreLib::System::Resources
