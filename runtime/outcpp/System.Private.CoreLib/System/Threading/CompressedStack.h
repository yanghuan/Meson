#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
namespace CompressedStackNamespace {
using namespace Runtime::Serialization;
CLASS(CompressedStack) : public Object::in {
  private: void Ctor();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static CompressedStack Capture();
  public: CompressedStack CreateCopy();
  public: static CompressedStack GetCompressedStack();
  public: static void Run(CompressedStack compressedStack, ContextCallback<> callback, Object state);
};
} // namespace CompressedStackNamespace
using CompressedStack = CompressedStackNamespace::CompressedStack;
} // namespace System::Private::CoreLib::System::Threading
