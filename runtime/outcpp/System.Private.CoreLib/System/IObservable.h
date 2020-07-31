#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARD(IObserver, T)
namespace IObservableNamespace {
CLASS(IObservable, T) : public Object::in {
  public: IDisposable Subscribe(IObserver<T> observer);
};
} // namespace IObservableNamespace
template <class T>
using IObservable = IObservableNamespace::IObservable<T>;
} // namespace System::Private::CoreLib::System
