#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS_(Nullable, T1, T2)
FORWARDS(Boolean)
FORWARD(LazyHelper)
FORWARD(String)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
namespace LazyNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(Lazy, T) {
  public: T get_ValueForDebugDisplay();
  public: Nullable<LazyThreadSafetyMode> get_Mode();
  public: Boolean get_IsValueFaulted();
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  private: static T CreateViaDefaultConstructor();
  private: void ViaConstructor();
  private: void ViaFactory(LazyThreadSafetyMode mode);
  private: void ExecutionAndPublication(LazyHelper executionAndPublication, Boolean useDefaultConstructor);
  private: void PublicationOnly(LazyHelper publicationOnly, T possibleValue);
  private: void PublicationOnlyViaConstructor(LazyHelper initializer);
  private: void PublicationOnlyViaFactory(LazyHelper initializer);
  private: void PublicationOnlyWaitForOtherThreadToPublish();
  private: T CreateValue();
  public: String ToString();
  private: LazyHelper _state;
  private: Func<T> _factory;
  private: T _value;
};
} // namespace LazyNamespace
template <class T>
using Lazy = LazyNamespace::Lazy<T>;
} // namespace System::Private::CoreLib::System
