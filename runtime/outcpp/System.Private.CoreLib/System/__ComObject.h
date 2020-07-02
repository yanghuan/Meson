#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(RuntimeType)
FORWARDS(Int32)
namespace __ComObjectNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(__ComObject) {
  public: String ToString();
  public: Object GetData(Object key);
  public: Boolean SetData(Object key, Object data);
  public: void ReleaseAllData();
  public: Object GetEventProvider(RuntimeType t);
  public: Int32 ReleaseSelf();
  public: void FinalReleaseSelf();
  private: Object CreateEventProvider(RuntimeType t);
  private: Hashtable m_ObjectToDataMap;
};
} // namespace __ComObjectNamespace
using __ComObject = __ComObjectNamespace::__ComObject;
} // namespace System::Private::CoreLib::System
