#include "RuntimeResourceSet-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/DictionaryEntry-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
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
#include <System.Private.CoreLib/System/StringComparer-dep.h>

namespace System::Private::CoreLib::System::Resources::RuntimeResourceSetNamespace {
using namespace System::Collections;
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
    {
      rt::lock(Reader);
      _resCache = nullptr;
      if (_defaultReader != nullptr) {
        _defaultReader->Close();
        _defaultReader = nullptr;
      }
      _caseInsensitiveTable = nullptr;
      ResourceSet::in::Dispose(disposing);
    }
  } else {
    _resCache = nullptr;
    _caseInsensitiveTable = nullptr;
    _defaultReader = nullptr;
    ResourceSet::in::Dispose(disposing);
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
  {
    rt::lock(Reader);
    if (Reader == nullptr) {
      rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ResourceSet());
    }
    ResourceLocator value;
    if (_defaultReader != nullptr) {
      Int32 num = -1;
      if (_resCache->TryGetValue(key, value)) {
        obj = value.set_Value();
        num = value.get_DataPosition();
      }
      if (num == -1 && obj == nullptr) {
        num = _defaultReader->FindPosForResource(key);
      }
      if (num != -1 && obj == nullptr) {
        ResourceTypeCode typeCode;
        if (isString) {
          obj = _defaultReader->LoadString(num);
          typeCode = ResourceTypeCode::String;
        } else {
          obj = _defaultReader->LoadObject(num, typeCode);
        }
        value = ResourceLocator(num, ResourceLocator::CanCache(typeCode) ? obj : nullptr);
        {
          rt::lock(_resCache);
          _resCache[key] = value;
        }
      }
      if (obj != nullptr || !ignoreCase) {
        return obj;
      }
    }
    if (!_haveReadFromReader) {
      if (ignoreCase && _caseInsensitiveTable == nullptr) {
        _caseInsensitiveTable = rt::newobj<Dictionary<String, ResourceLocator>>(StringComparer::in::get_OrdinalIgnoreCase());
      }
      if (_defaultReader == nullptr) {
        IDictionaryEnumerator enumerator = Reader->GetEnumerator();
        while (enumerator->MoveNext()) {
          DictionaryEntry entry = enumerator->get_Entry();
          String key2 = (String)entry.get_Key();
          ResourceLocator value2 = ResourceLocator(-1, entry.get_Value());
          _resCache->Add(key2, value2);
          if (ignoreCase) {
            _caseInsensitiveTable->Add(key2, value2);
          }
        }
        if (!ignoreCase) {
          Reader->Close();
        }
      } else {
        ResourceReader::in::ResourceEnumerator enumeratorInternal = _defaultReader->GetEnumeratorInternal();
        while (enumeratorInternal->MoveNext()) {
          String key3 = (String)enumeratorInternal->get_Key();
          Int32 dataPosition = enumeratorInternal->get_DataPosition();
          ResourceLocator value3 = ResourceLocator(dataPosition, nullptr);
          _caseInsensitiveTable->Add(key3, value3);
        }
      }
      _haveReadFromReader = true;
    }
    Object result = nullptr;
    Boolean flag = false;
    Boolean keyInWrongCase = false;
    if (_defaultReader != nullptr && _resCache->TryGetValue(key, value)) {
      flag = true;
      result = ResolveResourceLocator(value, key, _resCache, keyInWrongCase);
    }
    if (!flag && ignoreCase && _caseInsensitiveTable->TryGetValue(key, value)) {
      flag = true;
      keyInWrongCase = true;
      result = ResolveResourceLocator(value, key, _resCache, keyInWrongCase);
    }
    return result;
  }
}

Object RuntimeResourceSet___::ResolveResourceLocator(ResourceLocator resLocation, String key, Dictionary<String, ResourceLocator> copyOfCache, Boolean keyInWrongCase) {
  Object obj = resLocation.get_Value();
  if (obj == nullptr) {
    ResourceTypeCode typeCode;
    {
      rt::lock(Reader);
      obj = _defaultReader->LoadObject(resLocation.get_DataPosition(), typeCode);
    }
    if (!keyInWrongCase && ResourceLocator::CanCache(typeCode)) {
      resLocation.set_Value(obj);
      copyOfCache[key] = resLocation;
    }
  }
  return obj;
}

} // namespace System::Private::CoreLib::System::Resources::RuntimeResourceSetNamespace
