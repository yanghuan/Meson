#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace WeakReferenceNamespace {
using namespace System::Runtime::Serialization;
CLASS_FORWARD(WeakReference, T1, T2)
CLASS_(WeakReference) : public object {
  public: using interface = rt::TypeList<ISerializable>;
  public: Boolean get_IsAlive();
  public: Boolean get_TrackResurrection();
  public: Object get_Target();
  public: void set_Target(Object value);
  protected: void ctor();
  protected: void Finalize();
  private: void Create(Object target, Boolean trackResurrection);
  private: Boolean IsTrackResurrection();
  public: void ctor(Object target);
  public: void ctor(Object target, Boolean trackResurrection);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: IntPtr m_handle;
};
CLASS_(WeakReference, T) : public object {
  public: using interface = rt::TypeList<ISerializable>;
  private: T get_Target();
  private: void set_Target(T value);
  public: void SetTarget(T target);
  protected: void Finalize();
  private: void Create(T target, Boolean trackResurrection);
  private: Boolean IsTrackResurrection();
  public: void ctor(T target);
  public: void ctor(T target, Boolean trackResurrection);
  private: void ctor(SerializationInfo info, StreamingContext context);
  public: Boolean TryGetTarget(T& target);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: IntPtr m_handle;
};
} // namespace WeakReferenceNamespace
template <class T1 = void, class T2 = void>
using WeakReference = WeakReferenceNamespace::WeakReference<T1, T2>;
} // namespace System::Private::CoreLib::System
