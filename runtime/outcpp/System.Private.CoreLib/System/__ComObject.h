#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(Hashtable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(RuntimeType)
namespace __ComObjectNamespace {
using namespace Collections;
CLASS(__ComObject) : public MarshalByRefObject::in {
  protected: void Ctor();
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
