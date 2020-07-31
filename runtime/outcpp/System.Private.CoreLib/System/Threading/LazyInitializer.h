#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace LazyInitializerNamespace {
class LazyInitializer : public Object::in {
  public: template <class T>
  static T EnsureInitialized(T& target);
  private: template <class T>
  static T EnsureInitializedCore(T& target);
  public: template <class T>
  static T EnsureInitialized(T& target, Func<T> valueFactory);
  private: template <class T>
  static T EnsureInitializedCore(T& target, Func<T> valueFactory);
  public: template <class T>
  static T EnsureInitialized(T& target, Boolean& initialized, Object& syncLock);
  private: template <class T>
  static T EnsureInitializedCore(T& target, Boolean& initialized, Object& syncLock);
  public: template <class T>
  static T EnsureInitialized(T& target, Boolean& initialized, Object& syncLock, Func<T> valueFactory);
  private: template <class T>
  static T EnsureInitializedCore(T& target, Boolean& initialized, Object& syncLock, Func<T> valueFactory);
  public: template <class T>
  static T EnsureInitialized(T& target, Object& syncLock, Func<T> valueFactory);
  private: template <class T>
  static T EnsureInitializedCore(T& target, Object& syncLock, Func<T> valueFactory);
  private: static Object EnsureLockInitialized(Object& syncLock);
};
} // namespace LazyInitializerNamespace
using LazyInitializer = LazyInitializerNamespace::LazyInitializer;
} // namespace System::Private::CoreLib::System::Threading
