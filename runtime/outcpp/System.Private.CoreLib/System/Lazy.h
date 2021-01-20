#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func)
FORWARD(LazyHelper)
FORWARDS_(Nullable)
FORWARD(String)
namespace LazyNamespace {
using namespace System::Threading;
CLASS_FORWARD(Lazy)
CLASS_(Lazy, T) : public object {
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
  public: void ctor(Func<T> valueFactory, LazyThreadSafetyMode mode, Boolean useDefaultConstructor);
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
template <class ...T>
using Lazy = LazyNamespace::Lazy<T...>;
} // namespace System::Private::CoreLib::System
