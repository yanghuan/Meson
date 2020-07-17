#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Resources {
namespace MissingSatelliteAssemblyExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(MissingSatelliteAssemblyException) {
  public: String get_CultureName();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, String cultureName);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  private: String _cultureName;
};
} // namespace MissingSatelliteAssemblyExceptionNamespace
using MissingSatelliteAssemblyException = MissingSatelliteAssemblyExceptionNamespace::MissingSatelliteAssemblyException;
} // namespace System::Private::CoreLib::System::Resources
