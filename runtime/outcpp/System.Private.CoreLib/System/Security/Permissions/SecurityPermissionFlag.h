#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityPermissionFlag : int32_t {
  AllFlags = 16383,
  Assertion = 1,
  BindingRedirects = 8192,
  ControlAppDomain = 1024,
  ControlDomainPolicy = 256,
  ControlEvidence = 32,
  ControlPolicy = 64,
  ControlPrincipal = 512,
  ControlThread = 16,
  Execution = 8,
  Infrastructure = 4096,
  NoFlags = 0,
  RemotingConfiguration = 2048,
  SerializationFormatter = 128,
  SkipVerification = 4,
  UnmanagedCode = 2,
};
} // namespace System::Private::CoreLib::System::Security::Permissions
