#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(SerializationEntry)
namespace SerializationInfoEnumeratorNamespace {
using namespace System::Collections;
CLASS(SerializationInfoEnumerator) : public Object::in {
  public: using interface = rt::TypeList<IEnumerator>;
  private: Object get_CurrentOfIEnumerator();
  public: SerializationEntry get_Current();
  public: String get_Name();
  public: Object get_Value();
  public: Type get_ObjectType();
  public: void ctor(Array<String> members, Array<Object> info, Array<Type> types, Int32 numItems);
  public: Boolean MoveNext();
  public: void Reset();
  private: Array<String> _members;
  private: Array<Object> _data;
  private: Array<Type> _types;
  private: Int32 _numItems;
  private: Int32 _currItem;
  private: Boolean _current;
};
} // namespace SerializationInfoEnumeratorNamespace
using SerializationInfoEnumerator = SerializationInfoEnumeratorNamespace::SerializationInfoEnumerator;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
