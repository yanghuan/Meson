#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IReadOnlyList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IVectorNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(IVector, T) {
  public: UInt32 get_Size();
  public: T GetAt(UInt32 index);
  public: IReadOnlyList<T> GetView();
  public: Boolean IndexOf(T value, UInt32& index);
  public: void SetAt(UInt32 index, T value);
  public: void InsertAt(UInt32 index, T value);
  public: void RemoveAt(UInt32 index);
  public: void Append(T value);
  public: void RemoveAtEnd();
  public: void Clear();
  public: UInt32 GetMany(UInt32 startIndex, Array<T> items);
  public: void ReplaceAll(Array<T> items);
};
} // namespace IVectorNamespace
template <class T>
using IVector = IVectorNamespace::IVector<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
