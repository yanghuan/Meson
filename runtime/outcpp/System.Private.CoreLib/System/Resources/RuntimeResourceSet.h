#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Resources/ResourceSet.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Resources {
FORWARDS(ResourceLocator)
FORWARD(ResourceReader)
namespace RuntimeResourceSetNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using IEnumerable = Collections::IEnumerable;
CLASS(RuntimeResourceSet) : public ResourceSet::in {
  public: using interface = rt::TypeList<IEnumerable>;
  public: void ctor(String fileName);
  public: void ctor(Stream stream, Boolean permitDeserialization);
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
