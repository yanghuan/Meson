#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace LazyInitializerNamespace {
class LazyInitializer {
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
