#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IObjectReference)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace UnitySerializationHolderNamespace {
using namespace Runtime::Serialization;
CLASS(UnitySerializationHolder) : public Object::in {
  public: using interface = rt::TypeList<ISerializable, IObjectReference>;
  public: static void GetUnitySerializationInfo(SerializationInfo info, Int32 unityType);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Object GetRealObject(StreamingContext context);
  private: Int32 _unityType;
  private: String _data;
};
} // namespace UnitySerializationHolderNamespace
using UnitySerializationHolder = UnitySerializationHolderNamespace::UnitySerializationHolder;
} // namespace System::Private::CoreLib::System
