#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Resources {
FORWARD(IResourceReader)
namespace ResourceSetNamespace {
using namespace System::Collections;
using namespace System::IO;
CLASS(ResourceSet) : public Object::in {
  public: using interface = rt::TypeList<IDisposable, IEnumerable>;
  protected: void ctor();
  public: void ctor(Boolean junk);
  public: void ctor(String fileName);
  public: void ctor(Stream stream);
  public: void ctor(IResourceReader reader);
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
