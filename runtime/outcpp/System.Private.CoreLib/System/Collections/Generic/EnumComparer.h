#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/Comparer.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace EnumComparerNamespace {
using namespace System::Runtime::Serialization;
template <class T>
using Comparer = Generic::Comparer<T>;
CLASS(EnumComparer, T) : public Comparer<T>::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: Int32 Compare(T x, T y);
  public: void ctor();
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace EnumComparerNamespace
template <class T>
using EnumComparer = EnumComparerNamespace::EnumComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
