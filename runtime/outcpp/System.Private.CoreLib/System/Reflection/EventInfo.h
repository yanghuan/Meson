#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
enum class EventAttributes;
FORWARD(MethodInfo)
namespace EventInfoNamespace {
CLASS(EventInfo) {
  public: MemberTypes get_MemberType();
  public: EventAttributes get_Attributes();
  public: Boolean get_IsSpecialName();
  public: MethodInfo get_AddMethod();
  public: MethodInfo get_RemoveMethod();
  public: MethodInfo get_RaiseMethod();
  public: Boolean get_IsMulticast();
  public: Type get_EventHandlerType();
  public: Array<MethodInfo> GetOtherMethods();
  public: Array<MethodInfo> GetOtherMethods(Boolean nonPublic);
  public: MethodInfo GetAddMethod();
  public: MethodInfo GetRemoveMethod();
  public: MethodInfo GetRaiseMethod();
  public: MethodInfo GetAddMethod(Boolean nonPublic);
  public: MethodInfo GetRemoveMethod(Boolean nonPublic);
  public: MethodInfo GetRaiseMethod(Boolean nonPublic);
  public: void AddEventHandler(Object target, Delegate handler);
  public: void RemoveEventHandler(Object target, Delegate handler);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace EventInfoNamespace
using EventInfo = EventInfoNamespace::EventInfo;
} // namespace System::Private::CoreLib::System::Reflection
