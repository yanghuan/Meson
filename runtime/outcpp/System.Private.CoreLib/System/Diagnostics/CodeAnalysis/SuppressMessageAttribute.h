#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace SuppressMessageAttributeNamespace {
CLASS(SuppressMessageAttribute) {
  public: String get_Category() { return Category; }
  public: String get_CheckId() { return CheckId; }
  public: String get_Scope() { return Scope; }
  public: void set_Scope(String value) { Scope = value; }
  public: String get_Target() { return Target; }
  public: void set_Target(String value) { Target = value; }
  public: String get_MessageId() { return MessageId; }
  public: void set_MessageId(String value) { MessageId = value; }
  public: String get_Justification() { return Justification; }
  public: void set_Justification(String value) { Justification = value; }
  private: String Category;
  private: String CheckId;
  private: String Scope;
  private: String Target;
  private: String MessageId;
  private: String Justification;
};
} // namespace SuppressMessageAttributeNamespace
using SuppressMessageAttribute = SuppressMessageAttributeNamespace::SuppressMessageAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
