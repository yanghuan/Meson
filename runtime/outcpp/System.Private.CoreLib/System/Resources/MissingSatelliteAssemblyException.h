#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

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
using namespace System::Runtime::Serialization;
CLASS(MissingSatelliteAssemblyException) : public SystemException::in {
  public: String get_CultureName();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, String cultureName);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: String _cultureName;
};
} // namespace MissingSatelliteAssemblyExceptionNamespace
using MissingSatelliteAssemblyException = MissingSatelliteAssemblyExceptionNamespace::MissingSatelliteAssemblyException;
} // namespace System::Private::CoreLib::System::Resources
