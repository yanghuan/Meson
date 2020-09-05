#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Reflection {
namespace StrongNameKeyPairNamespace {
using namespace System::IO;
using namespace System::Runtime::Serialization;
CLASS(StrongNameKeyPair) : public object {
  public: using interface = rt::TypeList<IDeserializationCallback, ISerializable>;
  public: Array<Byte> get_PublicKey();
  public: void ctor(FileStream keyPairFile);
  public: void ctor(Array<Byte> keyPairArray);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void ctor(String keyPairContainer);
};
} // namespace StrongNameKeyPairNamespace
using StrongNameKeyPair = StrongNameKeyPairNamespace::StrongNameKeyPair;
} // namespace System::Private::CoreLib::System::Reflection
