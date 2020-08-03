#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
namespace StrongNameKeyPairNamespace {
using namespace IO;
using namespace Runtime::Serialization;
CLASS(StrongNameKeyPair) : public Object::in {
  public: Array<Byte> get_PublicKey();
  public: void Ctor(FileStream keyPairFile);
  public: void Ctor(Array<Byte> keyPairArray);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void Ctor(String keyPairContainer);
};
} // namespace StrongNameKeyPairNamespace
using StrongNameKeyPair = StrongNameKeyPairNamespace::StrongNameKeyPair;
} // namespace System::Private::CoreLib::System::Reflection
