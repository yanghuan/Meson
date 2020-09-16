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
namespace OrdinalCaseSensitiveComparerNamespace {
using namespace System::Runtime::Serialization;
CLASS(OrdinalCaseSensitiveComparer) : public OrdinalComparer::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: void ctor();
  public: Int32 Compare(String x, String y);
  public: Boolean Equals(String x, String y);
  public: Int32 GetHashCode(String obj);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static void cctor();
  public: static OrdinalCaseSensitiveComparer Instance;
};
} // namespace OrdinalCaseSensitiveComparerNamespace
using OrdinalCaseSensitiveComparer = OrdinalCaseSensitiveComparerNamespace::OrdinalCaseSensitiveComparer;
} // namespace System::Private::CoreLib::System
