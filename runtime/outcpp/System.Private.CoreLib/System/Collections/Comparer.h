#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Collections {
namespace ComparerNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(Comparer) {
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Int32 Compare(Object a, Object b);
  private: CompareInfo _compareInfo;
  public: static Comparer Default;
  public: static Comparer DefaultInvariant;
};
} // namespace ComparerNamespace
using Comparer = ComparerNamespace::Comparer;
} // namespace System::Private::CoreLib::System::Collections
