#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(LazyHelper)
FORWARDS_(Nullable, T1, T2)
FORWARD(String)
namespace LazyNamespace {
using namespace System::Threading;
CLASS_FORWARD(Lazy, T1, T2, T3)
CLASS_(Lazy, T) : public Object::in {
  public: T get_ValueForDebugDisplay();
  public: Nullable<LazyThreadSafetyMode> get_Mode();
  public: Boolean get_IsValueFaulted();
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  private: static T CreateViaDefaultConstructor();
  public: void ctor();
  public: void ctor(T value);
  public: void ctor(Func<T> valueFactory);
  public: void ctor(Boolean isThreadSafe);
  public: void ctor(LazyThreadSafetyMode mode);
  public: void ctor(Func<T> valueFactory, Boolean isThreadSafe);
  public: void ctor(Func<T> valueFactory, LazyThreadSafetyMode mode);
  private: void ctor(Func<T> valueFactory, LazyThreadSafetyMode mode, Boolean useDefaultConstructor);
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
CLASS_(Lazy, T, TMetadata) : public Lazy<T>::in {
  public: TMetadata get_Metadata();
  public: void ctor(Func<T> valueFactory, TMetadata metadata);
  public: void ctor(TMetadata metadata);
  public: void ctor(TMetadata metadata, Boolean isThreadSafe);
  public: void ctor(Func<T> valueFactory, TMetadata metadata, Boolean isThreadSafe);
  public: void ctor(TMetadata metadata, LazyThreadSafetyMode mode);
  public: void ctor(Func<T> valueFactory, TMetadata metadata, LazyThreadSafetyMode mode);
  private: TMetadata _metadata;
};
} // namespace LazyNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using Lazy = LazyNamespace::Lazy<T1, T2, T3>;
} // namespace System::Private::CoreLib::System
