#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
namespace MissingMemberExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(MissingMemberException) {
  public: String get_Message();
  public: static String FormatSignature(Array<Byte> signature);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  protected: String ClassName;
  protected: String MemberName;
  protected: Array<Byte> Signature;
};
} // namespace MissingMemberExceptionNamespace
using MissingMemberException = MissingMemberExceptionNamespace::MissingMemberException;
} // namespace System::Private::CoreLib::System
