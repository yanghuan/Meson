#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Security/Permissions/CodeAccessSecurityAttribute.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(IPermission)
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Security::Permissions {
enum class SecurityAction : int32_t;
enum class SecurityPermissionFlag : int32_t;
namespace SecurityPermissionAttributeNamespace {
CLASS(SecurityPermissionAttribute) : public CodeAccessSecurityAttribute::in {
  public: Boolean get_Assertion() { return Assertion; }
  public: void set_Assertion(Boolean value) { Assertion = value; }
  public: Boolean get_BindingRedirects() { return BindingRedirects; }
  public: void set_BindingRedirects(Boolean value) { BindingRedirects = value; }
  public: Boolean get_ControlAppDomain() { return ControlAppDomain; }
  public: void set_ControlAppDomain(Boolean value) { ControlAppDomain = value; }
  public: Boolean get_ControlDomainPolicy() { return ControlDomainPolicy; }
  public: void set_ControlDomainPolicy(Boolean value) { ControlDomainPolicy = value; }
  public: Boolean get_ControlEvidence() { return ControlEvidence; }
  public: void set_ControlEvidence(Boolean value) { ControlEvidence = value; }
  public: Boolean get_ControlPolicy() { return ControlPolicy; }
  public: void set_ControlPolicy(Boolean value) { ControlPolicy = value; }
  public: Boolean get_ControlPrincipal() { return ControlPrincipal; }
  public: void set_ControlPrincipal(Boolean value) { ControlPrincipal = value; }
  public: Boolean get_ControlThread() { return ControlThread; }
  public: void set_ControlThread(Boolean value) { ControlThread = value; }
  public: Boolean get_Execution() { return Execution; }
  public: void set_Execution(Boolean value) { Execution = value; }
  public: SecurityPermissionFlag get_Flags() { return Flags; }
  public: void set_Flags(SecurityPermissionFlag value) { Flags = value; }
  public: Boolean get_Infrastructure() { return Infrastructure; }
  public: void set_Infrastructure(Boolean value) { Infrastructure = value; }
  public: Boolean get_RemotingConfiguration() { return RemotingConfiguration; }
  public: void set_RemotingConfiguration(Boolean value) { RemotingConfiguration = value; }
  public: Boolean get_SerializationFormatter() { return SerializationFormatter; }
  public: void set_SerializationFormatter(Boolean value) { SerializationFormatter = value; }
  public: Boolean get_SkipVerification() { return SkipVerification; }
  public: void set_SkipVerification(Boolean value) { SkipVerification = value; }
  public: Boolean get_UnmanagedCode() { return UnmanagedCode; }
  public: void set_UnmanagedCode(Boolean value) { UnmanagedCode = value; }
  public: void ctor(SecurityAction action);
  public: IPermission CreatePermission();
  private: Boolean Assertion;
  private: Boolean BindingRedirects;
  private: Boolean ControlAppDomain;
  private: Boolean ControlDomainPolicy;
  private: Boolean ControlEvidence;
  private: Boolean ControlPolicy;
  private: Boolean ControlPrincipal;
  private: Boolean ControlThread;
  private: Boolean Execution;
  private: SecurityPermissionFlag Flags;
  private: Boolean Infrastructure;
  private: Boolean RemotingConfiguration;
  private: Boolean SerializationFormatter;
  private: Boolean SkipVerification;
  private: Boolean UnmanagedCode;
};
} // namespace SecurityPermissionAttributeNamespace
using SecurityPermissionAttribute = SecurityPermissionAttributeNamespace::SecurityPermissionAttribute;
} // namespace System::Private::CoreLib::System::Security::Permissions
