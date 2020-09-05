#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace EnumEqualityComparerNamespace {
using namespace System::Runtime::Serialization;
CLASS(EnumEqualityComparer, T) : public EqualityComparer<T>::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: Boolean Equals(T x, T y);
  public: Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: void ctor();
  public: void ctor(SerializationInfo information, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Int32 GetHashCode(T obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace EnumEqualityComparerNamespace
template <class T>
using EnumEqualityComparer = EnumEqualityComparerNamespace::EnumEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
