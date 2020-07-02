#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Resources {
FORWARDS(ResourceLocator)
FORWARD(ResourceReader)
namespace RuntimeResourceSetNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(RuntimeResourceSet) {
  protected: void Dispose(Boolean disposing);
  public: IDictionaryEnumerator GetEnumerator();
  private: IDictionaryEnumerator GetEnumeratorHelper();
  public: String GetString(String key);
  public: String GetString(String key, Boolean ignoreCase);
  public: Object GetObject(String key);
  public: Object GetObject(String key, Boolean ignoreCase);
  private: Object GetObject(String key, Boolean ignoreCase, Boolean isString);
  private: Object ResolveResourceLocator(ResourceLocator resLocation, String key, Dictionary<String, ResourceLocator> copyOfCache, Boolean keyInWrongCase);
  private: Dictionary<String, ResourceLocator> _resCache;
  private: ResourceReader _defaultReader;
  private: Dictionary<String, ResourceLocator> _caseInsensitiveTable;
  private: Boolean _haveReadFromReader;
};
} // namespace RuntimeResourceSetNamespace
using RuntimeResourceSet = RuntimeResourceSetNamespace::RuntimeResourceSet;
} // namespace System::Private::CoreLib::System::Resources
