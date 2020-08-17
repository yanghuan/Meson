#include "ResourceSet-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceSetNamespace {
using namespace System::Collections;
using namespace System::Reflection;

void ResourceSet___::ctor() {
  Table = rt::newobj<Hashtable>();
}

void ResourceSet___::ctor(Boolean junk) {
}

void ResourceSet___::ctor(String fileName) {
  Reader = rt::newobj<ResourceReader>(fileName);
  ReadResources();
}

void ResourceSet___::ctor(Stream stream) {
  Reader = rt::newobj<ResourceReader>(stream);
  ReadResources();
}

void ResourceSet___::ctor(IResourceReader reader) {
  auto& default = reader;
  if (default == nullptr) rt::throw_exception(rt::newobj<ArgumentNullException>("reader"));
  Reader = (default);
  ReadResources();
}

void ResourceSet___::Close() {
  Dispose(true);
}

void ResourceSet___::Dispose(Boolean disposing) {
  if (disposing) {
    IResourceReader reader = Reader;
    Reader = nullptr;
    auto& default = reader;
    default == nullptr ? nullptr : default->Close();
  }
  Reader = nullptr;
  _caseInsensitiveTable = nullptr;
  Table = nullptr;
}

void ResourceSet___::Dispose() {
  Dispose(true);
}

Type ResourceSet___::GetDefaultReader() {
  return rt::typeof<ResourceReader>();
}

Type ResourceSet___::GetDefaultWriter() {
  Assembly assembly = Assembly::in::Load("System.Resources.Writer, Version=4.0.1.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a");
  return assembly->GetType("System.Resources.ResourceWriter", true);
}

IDictionaryEnumerator ResourceSet___::GetEnumerator() {
  return GetEnumeratorHelper();
}

IDictionaryEnumerator ResourceSet___::GetEnumeratorHelper() {
  Hashtable table = Table;
  if (table == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
  }
  return table->GetEnumerator();
}

String ResourceSet___::GetString(String name) {
  Object objectInternal = GetObjectInternal(name);
  try {
    return (String)objectInternal;
  } catch (InvalidCastException) {
  }
}

String ResourceSet___::GetString(String name, Boolean ignoreCase) {
  Object objectInternal = GetObjectInternal(name);
  String text;
  try {
    text = (String)objectInternal;
  } catch (InvalidCastException) {
  }
  if (text != nullptr || !ignoreCase) {
    return text;
  }
  objectInternal = GetCaseInsensitiveObjectInternal(name);
  try {
    return (String)objectInternal;
  } catch (InvalidCastException) {
  }
}

Object ResourceSet___::GetObject(String name) {
  return GetObjectInternal(name);
}

Object ResourceSet___::GetObject(String name, Boolean ignoreCase) {
  Object objectInternal = GetObjectInternal(name);
  if (objectInternal != nullptr || !ignoreCase) {
    return objectInternal;
  }
  return GetCaseInsensitiveObjectInternal(name);
}

void ResourceSet___::ReadResources() {
  IDictionaryEnumerator enumerator = Reader->GetEnumerator();
  while (enumerator->MoveNext()) {
    Object value = enumerator->get_Value();
    Table->Add(enumerator->get_Key(), value);
  }
}

Object ResourceSet___::GetObjectInternal(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  Hashtable table = Table;
  if (table == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
  }
  return table[name];
}

Object ResourceSet___::GetCaseInsensitiveObjectInternal(String name) {
  Hashtable table = Table;
  if (table == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
  }
  Hashtable hashtable = _caseInsensitiveTable;
  if (hashtable == nullptr) {
    hashtable = rt::newobj<Hashtable>(StringComparer::in::get_OrdinalIgnoreCase());
    IDictionaryEnumerator enumerator = table->GetEnumerator();
    while (enumerator->MoveNext()) {
      hashtable->Add(enumerator->get_Key(), enumerator->get_Value());
    }
    _caseInsensitiveTable = hashtable;
  }
  return hashtable[name];
}

} // namespace System::Private::CoreLib::System::Resources::ResourceSetNamespace
