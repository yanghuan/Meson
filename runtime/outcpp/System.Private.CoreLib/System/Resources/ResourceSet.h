#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Type)
FORWARD(String)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IDictionaryEnumerator)
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Resources {
FORWARD(IResourceReader)
namespace ResourceSetNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(ResourceSet) {
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: void Dispose();
  public: Type GetDefaultReader();
  public: Type GetDefaultWriter();
  public: IDictionaryEnumerator GetEnumerator();
  private: IDictionaryEnumerator GetEnumeratorHelper();
  public: String GetString(String name);
  public: String GetString(String name, Boolean ignoreCase);
  public: Object GetObject(String name);
  public: Object GetObject(String name, Boolean ignoreCase);
  protected: void ReadResources();
  private: Object GetObjectInternal(String name);
  private: Object GetCaseInsensitiveObjectInternal(String name);
  protected: IResourceReader Reader;
  public: Hashtable Table;
  private: Hashtable _caseInsensitiveTable;
};
} // namespace ResourceSetNamespace
using ResourceSet = ResourceSetNamespace::ResourceSet;
} // namespace System::Private::CoreLib::System::Resources
