#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARDS(Guid)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CustomQueryInterfaceResult;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IVectorView, T)
FORWARD(IIterator, T)
FORWARD(IBindableVector)
FORWARD(IVector_Raw, T)
FORWARD(IBindableVectorView)
enum class InterfaceForwardingSupport;
namespace ICustomPropertyProviderProxyNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(ICustomPropertyProviderProxy, T1, T2) {
  private: CLASS(IVectorViewToIBindableVectorViewAdapter, T) {
    private: UInt32 get_SizeOfIBindableVectorView();
    private: IVectorView<T> _vectorView;
  };
  private: CLASS(IteratorOfTToIteratorAdapter, T) {
    public: Boolean get_HasCurrent();
    public: Object get_Current();
    public: Boolean MoveNext();
    private: IIterator<T> _iterator;
  };
  private: UInt32 get_SizeOfIBindableVector();
  private: UInt32 get_SizeOfIBindableVectorView();
  public: static Object CreateInstance(Object target);
  public: String ToString();
  public: CustomQueryInterfaceResult GetInterface(Guid& iid, IntPtr& ppv);
  public: IEnumerator GetEnumerator();
  private: IBindableVector GetIBindableVectorNoThrow();
  private: IVector_Raw<T1> GetVectorOfT();
  private: IBindableVectorView GetIBindableVectorViewNoThrow();
  private: IVectorView<T2> GetVectorViewOfT();
  private: Object _target;
  private: InterfaceForwardingSupport _flags;
};
} // namespace ICustomPropertyProviderProxyNamespace
template <class T1, class T2>
using ICustomPropertyProviderProxy = ICustomPropertyProviderProxyNamespace::ICustomPropertyProviderProxy<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
