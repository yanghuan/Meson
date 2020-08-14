#include "RuntimeResourceSet-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IO/FileStream-dep.h>
#include <System.Private.CoreLib/System/IO/Stream-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Resources/FastResourceComparer-dep.h>
#include <System.Private.CoreLib/System/Resources/IResourceReader.h>
#include <System.Private.CoreLib/System/Resources/ResourceLocator-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceTypeCode.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Resources::RuntimeResourceSetNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;

void RuntimeResourceSet___::ctor(String fileName) {
  _resCache = rt::newobj<Dictionary<String, ResourceLocator>>(FastResourceComparer::in::Default);
  Stream stream = rt::newobj<FileStream>(fileName, FileMode::Open, FileAccess::Read, FileShare::Read);
  _defaultReader = rt::newobj<ResourceReader>(stream, _resCache, false);
  Reader = _defaultReader;
}

void RuntimeResourceSet___::ctor(Stream stream, Boolean permitDeserialization) {
  _resCache = rt::newobj<Dictionary<String, ResourceLocator>>(FastResourceComparer::in::Default);
  _defaultReader = rt::newobj<ResourceReader>(stream, _resCache, permitDeserialization);
  Reader = _defaultReader;
}

void RuntimeResourceSet___::Dispose(Boolean disposing) {
  if (Reader == nullptr) {
    return;
  }
  if (disposing) {
  } else {
    _resCache = nullptr;
    _caseInsensitiveTable = nullptr;
    _defaultReader = nullptr;
  }
}

IDictionaryEnumerator RuntimeResourceSet___::GetEnumerator() {
  return GetEnumeratorHelper();
}

IDictionaryEnumerator RuntimeResourceSet___::GetEnumeratorHelper() {
  IResourceReader reader = Reader;
  if (reader == nullptr || _resCache == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
  }
  return reader->GetEnumerator();
}

String RuntimeResourceSet___::GetString(String key) {
  Object object = GetObject(key, false, true);
  return (String)object;
}

String RuntimeResourceSet___::GetString(String key, Boolean ignoreCase) {
  Object object = GetObject(key, ignoreCase, true);
  return (String)object;
}

Object RuntimeResourceSet___::GetObject(String key) {
  return GetObject(key, false, false);
}

Object RuntimeResourceSet___::GetObject(String key, Boolean ignoreCase) {
  return GetObject(key, ignoreCase, false);
}

Object RuntimeResourceSet___::GetObject(String key, Boolean ignoreCase, Boolean isString) {
  if (key == nullptr) {
    rt::throw_exception<ArgumentNullException>("key");
  }
  if (Reader == nullptr || _resCache == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
  }
  Object obj = nullptr;
}

Object RuntimeResourceSet___::ResolveResourceLocator(ResourceLocator resLocation, String key, Dictionary<String, ResourceLocator> copyOfCache, Boolean keyInWrongCase) {
  Object obj = resLocation.get_Value();
  if (obj == nullptr) {
    ResourceTypeCode typeCode;
  }
  return obj;
}

} // namespace System::Private::CoreLib::System::Resources::RuntimeResourceSetNamespace
