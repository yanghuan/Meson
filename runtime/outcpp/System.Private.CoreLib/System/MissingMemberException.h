#pragma once

#include <System.Private.CoreLib/System/MemberAccessException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD(String)
namespace MissingMemberExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(MissingMemberException) : public MemberAccessException::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: String get_Message();
  public: static String FormatSignature(Array<Byte> signature);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String className, String memberName);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  protected: String ClassName;
  protected: String MemberName;
  protected: Array<Byte> Signature;
};
} // namespace MissingMemberExceptionNamespace
using MissingMemberException = MissingMemberExceptionNamespace::MissingMemberException;
} // namespace System::Private::CoreLib::System
