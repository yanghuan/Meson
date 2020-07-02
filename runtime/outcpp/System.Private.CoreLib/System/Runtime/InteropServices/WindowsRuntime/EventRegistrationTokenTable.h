#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARDS(EventRegistrationToken)
namespace EventRegistrationTokenTableNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(EventRegistrationTokenTable, T) {
  public: T get_InvocationList();
  public: void set_InvocationList(T value);
  public: EventRegistrationToken AddEventHandler(T handler);
  private: EventRegistrationToken AddEventHandlerNoLock(T handler);
  private: static EventRegistrationToken GetPreferredToken(T handler);
  public: Boolean RemoveEventHandler(EventRegistrationToken token, T& handler);
  public: void RemoveEventHandler(EventRegistrationToken token);
  public: void RemoveEventHandler(T handler);
  private: void RemoveEventHandlerNoLock(EventRegistrationToken token);
  public: static EventRegistrationTokenTable<T> GetOrCreateEventRegistrationTokenTable(EventRegistrationTokenTable<T>& refEventTable);
  private: Dictionary<EventRegistrationToken, T> m_tokens;
  private: T m_invokeList;
};
} // namespace EventRegistrationTokenTableNamespace
template <class T>
using EventRegistrationTokenTable = EventRegistrationTokenTableNamespace::EventRegistrationTokenTable<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
