#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
namespace ObjectNamespace {
CLASS(Object) : public rt::object {
  public: Type GetType();
  protected: Object MemberwiseClone();
  public: void ctor();
  protected: void Finalize();
  public: String ToString();
  public: Boolean Equals(Object obj);
  public: static Boolean Equals(Object objA, Object objB);
  public: static Boolean ReferenceEquals(Object objA, Object objB);
  public: Int32 GetHashCode();
};
} // namespace ObjectNamespace
using Object = ObjectNamespace::Object;
} // namespace System::Private::CoreLib::System
