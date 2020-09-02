#include "__ComObject-dep.h"

#include <System.Private.CoreLib/System/__ComObject-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/IDisposable.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::__ComObjectNamespace {
using namespace System::Collections;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

void __ComObject___::ctor() {
}

Object __ComObject___::GetData(Object key) {
  Object result = nullptr;
  {
    rt::lock((__ComObject)this);
    if (m_ObjectToDataMap != nullptr) {
      return m_ObjectToDataMap[key];
    }
    return result;
  }
}

Boolean __ComObject___::SetData(Object key, Object data) {
  Boolean result = false;
  {
    rt::lock((__ComObject)this);
    if (m_ObjectToDataMap == nullptr) {
      m_ObjectToDataMap = rt::newobj<Hashtable>();
    }
    if (m_ObjectToDataMap[key] == nullptr) {
      m_ObjectToDataMap[key] = data;
      return true;
    }
    return result;
  }
}

void __ComObject___::ReleaseAllData() {
  {
    rt::lock((__ComObject)this);
    if (m_ObjectToDataMap == nullptr) {
      return;
    }
    for (Object&& value : rt::each(m_ObjectToDataMap->get_Values())) {
      IDisposable disposable = rt::as<IDisposable>(value);
      if (disposable != nullptr) {
        disposable->Dispose();
      }
      __ComObject _ComObject = rt::as<__ComObject>(value);
      if (_ComObject != nullptr) {
        Marshal::ReleaseComObject(_ComObject);
      }
    }
    m_ObjectToDataMap = nullptr;
  }
}

Object __ComObject___::GetEventProvider(RuntimeType t) {
  Object data = GetData(t);
  if (data != nullptr) {
    return data;
  }
  return CreateEventProvider(t);
}

Int32 __ComObject___::ReleaseSelf() {
  return Marshal::InternalReleaseComObject((__ComObject)this);
}

void __ComObject___::FinalReleaseSelf() {
  Marshal::InternalFinalReleaseComObject((__ComObject)this);
}

Object __ComObject___::CreateEventProvider(RuntimeType t) {
  Object obj = Activator::CreateInstance(t, BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic | BindingFlags::CreateInstance, nullptr, rt::newarr<Array<Object>>(1), nullptr);
  if (!SetData(t, obj)) {
    IDisposable disposable = rt::as<IDisposable>(obj);
    if (disposable != nullptr) {
      disposable->Dispose();
    }
    obj = GetData(t);
  }
  return obj;
}

} // namespace System::Private::CoreLib::System::__ComObjectNamespace
