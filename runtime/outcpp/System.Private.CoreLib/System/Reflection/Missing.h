#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace MissingNamespace {
using namespace System::Runtime::Serialization;
CLASS(Missing) : public object {
  public: using interface = rt::TypeList<ISerializable>;
  public: void ctor();
  private: void GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context);
  public: static void cctor();
  public: static Missing Value;
};
} // namespace MissingNamespace
using Missing = MissingNamespace::Missing;
} // namespace System::Private::CoreLib::System::Reflection
