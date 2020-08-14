#include "__ComObject-dep.h"

#include <System.Private.CoreLib/System/__ComObject-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::__ComObjectNamespace {
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

void __ComObject___::ctor() {
}

Object __ComObject___::GetData(Object key) {
  Object result = nullptr;
}

Boolean __ComObject___::SetData(Object key, Object data) {
  Boolean result = false;
}

void __ComObject___::ReleaseAllData() {
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
  }
  return obj;
}

} // namespace System::Private::CoreLib::System::__ComObjectNamespace
