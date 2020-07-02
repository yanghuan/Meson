#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Collections::Generic {
namespace EnumComparerNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(EnumComparer, T) {
  public: Int32 Compare(T x, T y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace EnumComparerNamespace
template <class T>
using EnumComparer = EnumComparerNamespace::EnumComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
