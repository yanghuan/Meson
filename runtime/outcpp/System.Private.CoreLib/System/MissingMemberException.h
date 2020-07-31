#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MemberAccessException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD(String)
namespace MissingMemberExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingMemberException) : public MemberAccessException::in {
  public: String get_Message();
  public: static String FormatSignature(Array<Byte> signature);
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  public: void Ctor(String className, String memberName);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  protected: String ClassName;
  protected: String MemberName;
  protected: Array<Byte> Signature;
};
} // namespace MissingMemberExceptionNamespace
using MissingMemberException = MissingMemberExceptionNamespace::MissingMemberException;
} // namespace System::Private::CoreLib::System
