#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace InterfaceImplementedInVersionAttributeNamespace {
CLASS(InterfaceImplementedInVersionAttribute) {
  public: Type get_InterfaceType();
  public: Byte get_MajorVersion();
  public: Byte get_MinorVersion();
  public: Byte get_BuildVersion();
  public: Byte get_RevisionVersion();
  private: Type m_interfaceType;
  private: Byte m_majorVersion;
  private: Byte m_minorVersion;
  private: Byte m_buildVersion;
  private: Byte m_revisionVersion;
};
} // namespace InterfaceImplementedInVersionAttributeNamespace
using InterfaceImplementedInVersionAttribute = InterfaceImplementedInVersionAttributeNamespace::InterfaceImplementedInVersionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
