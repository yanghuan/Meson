#pragma once

#include <System.Private.CoreLib/System/OrdinalComparer.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
namespace OrdinalIgnoreCaseComparerNamespace {
using namespace Runtime::Serialization;
CLASS(OrdinalIgnoreCaseComparer) : public OrdinalComparer::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: void Ctor();
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace OrdinalIgnoreCaseComparerNamespace
using OrdinalIgnoreCaseComparer = OrdinalIgnoreCaseComparerNamespace::OrdinalIgnoreCaseComparer;
} // namespace System::Private::CoreLib::System
