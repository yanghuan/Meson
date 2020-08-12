#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
namespace SZArrayHelperNamespace {
using namespace System::Collections::Generic;
CLASS(SZArrayHelper) : public Object::in {
  public: template <class T>
  IEnumerator<T> GetEnumerator();
  private: template <class T>
  void CopyTo(Array<T> array, Int32 index);
  public: template <class T>
  Int32 get_Count();
  public: template <class T>
  T get_Item(Int32 index);
  public: template <class T>
  void set_Item(Int32 index, T value);
  private: template <class T>
  void Add(T value);
  private: template <class T>
  Boolean Contains(T value);
  private: template <class T>
  Boolean get_IsReadOnly();
  private: template <class T>
  void Clear();
  private: template <class T>
  Int32 IndexOf(T value);
  private: template <class T>
  void Insert(Int32 index, T value);
  private: template <class T>
  Boolean Remove(T value);
  private: template <class T>
  void RemoveAt(Int32 index);
};
} // namespace SZArrayHelperNamespace
using SZArrayHelper = SZArrayHelperNamespace::SZArrayHelper;
} // namespace System::Private::CoreLib::System
